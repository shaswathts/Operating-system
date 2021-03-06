#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define a_size 10
#define b_size 10

struct parm_arr 
{
	int arr1[a_size];
	int arr2[b_size];
	int Size_a;
	int Size_b;
}; typedef struct parm_arr array;

void *replaceArray_evn(array *array)
{	
	/* In Even index of b[] replace with odd index of a[]*/
	printf("\n");
	int buffer[array->Size_b];
	for (int i = 0; i < array->Size_b; i++) {
		if((i % 2) == 0) {
			buffer[i] = array->arr1[i + 1]; //Putting odd index value of a[]	
		} else {
			buffer[i] = array->arr2[i]; //putting the odd index value of b[]
		}
		printf("Replacing Even index's of b[%d] = %d\n", i, buffer[i]);
	}
	return NULL;
}

void *replaceArray_odd(array *array)
{	
	/* In Odd index of b[] replace with even index of a[]*/
	printf("\n");
	int buffer[array->Size_b];
	for (int j = 0; j < array->Size_b; j++) {
		if ((j % 2) != 0) {
			buffer[j] = array->arr1[j - 1];
		} else {
			buffer[j] = array->arr2[j];
		}
		printf("Replacing Odd index's of b[%d] = %d\n", j, buffer[j]);
	}
	return NULL;
}

int main(int argc, int *argv[]) 
{
	int size_a, size_b;

	printf("Enter the size of arrays a[] & b[]: ");
	scanf("%d""%d", &size_a, &size_b);

	array arr[size_a + size_b]; 
	int t_size = size_a + size_b;
	
	printf("Enter the number for a[]: ");
	for(int i = 0; i < size_a; i++) {
		scanf("%d", &arr->arr1[i]); 
	}

	printf("Enter the number for b[]: ");
	for(int j = 0; j < size_b; j++) {
		scanf("%d", &arr->arr2[j]); 
	}

	arr->Size_a = size_a;
	arr->Size_b = size_b;	

	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, replaceArray_evn, arr);
	pthread_create(&thread2, NULL, replaceArray_odd, arr);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return EXIT_SUCCESS;
}
