#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct swaping_numbers {
    int num1;
    int num2;
}; typedef struct swaping_numbers swap;

void *entry_Point(swap *value) 
{
    printf("\nSwapping inside thread 1 :XD \n");
    
    printf("Before swap: num1 = %d and num2 = %d\n", value->num1, value->num2); 
    swap temp;
    temp.num1 = value->num2;
    temp.num2 = value->num1;
    printf("After swap: num1 = %d and num2 = %d\n", temp.num1, temp.num2); 
}

int main(int argc, char *argv[]) 
{
    swap nNum;
    nNum.num1 = 123;
    nNum.num2 = 321;
    printf("Hello from the main thread :D \n");
    printf("Before swap: num1 = %d and num2 = %d\n", nNum.num1, nNum.num2);

    pthread_t thread1;
    pthread_create(&thread1, NULL, entry_Point, &nNum);
    pthread_join(thread1, NULL);

    printf("\nBack to main thread :D \n");
    printf("After swap: num1 = %d and num2 = %d\n", nNum.num1, nNum.num2);
    
    return EXIT_SUCCESS;
}