#include <stdio.h>
#include <string.h>
int main()
{
	
	int i, j = 0;
	//declare array values
    char* vow[] = {"a","e","i","o","u"};
    //string
	char mystring[100];
    
    //capture the string from user
    printf("Enter the String: ");
    scanf("%s", mystring);
 
   	//convert to lowercase, if string entered in CAPS
	for(i=0;i<=strlen(mystring);i++)
	{
      if(mystring[i]>=65&&mystring[i]<=90)
       mystring[i]=mystring[i]+32;
  	}
 
	//loop through 5 vowels
    for(i=0; i< 5; i++)
	{
		//if vowel exists in mystring then add + 1 to j
		if (strchr(mystring, *vow[i]) != NULL)
		{
			j++; 	
		}
    }
    //print total number of vowels exists in mystring
    printf("Total Vowels: %d \n", j);
    return 0;
}