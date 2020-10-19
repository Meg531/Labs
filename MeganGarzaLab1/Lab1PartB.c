/*
Author:                   Megan Garza(Iteration) and (Cameron Brumblay as Recursion)
Assignment Number:        Lab Assignment 1 Part B
File Name:                MeganGarzaLab1.zip
Course/Selection:         CS 2124 Section 0D1
Due Date:                 21 September 2020
Instructor:               Dr. Ku
*/

/* Recursively and Itteratively checks the digits in a number using Luhns algorithm so validate whether they could be a valid number. "
The Luhn algorithm or Luhn formula, also known as the "modulus 10" or "mod 10" algorithm, ... The device took the mod 10 sum by mechanical means." - Wikipedia*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int luhnAlg(char* number, int count, int i, int sum, int second) //Cameron Brumblay 
{ 
    int temp = number[i] - '0'; 
  if(i == -1){
    //printf("rec %d\n", sum); //test they are the same
	return (sum % 10 == 0);
  }
  else{
    if (second == 0){
	    temp *= 2;
    }
    sum = sum + temp/10;
    sum = sum + temp% 10;
    second = !second;
    
    //printf("REC i = %d and current %d\n", i, sum);// test they are the same
    return luhnAlg(number, count, i-1, sum, second) ;
   }
}

int luhnAlg2(char* number){//Megan Garza 
    
    int count = strlen(number);
    int sum = 0, second = 1, i; 
    
    for (i = count-1; i >= 0; i--) { 
   
        int temp = number[i] - '0'; 
  
        if (second == 0){ 
            temp = temp * 2; 
        }
        sum += temp / 10; 
        sum += temp % 10; 
        //printf("It i = %d and current %d\n", i, sum);// test they are the same
        second = !second; 
    } 
    //printf("it %d\n", sum); //test they are the same
    return (sum % 10 == 0); 
} 
        
int main() 
{ 
    clock_t t; 
    t = clock();
    int sum = 0, second = 1;
    char number[1000]; 
    int count = 0; 
    int i = 0; 
       
  
      
	printf("What number would you like to check in the Luhn Algorithm: ");
	scanf("%s", number);
	count = strlen(number);
	i = count-1;
  
	//Recursion
    //if (luhnAlg(number, count, i, sum, second)) 
     //   printf(" This is a valid card\n"); 
    //else
       // printf(" This is not a valid card\n");
       // printf("took %f seconds to execute \n", time_taken);  
    //Iteration
    if (luhnAlg2(number))
        printf(" This is a valid card"); 
    else
        printf(" This is not a valid card"); 
        
       //  printf("took %f seconds to execute \n", time_taken); 
         
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("took %f seconds to execute \n", time_taken);
    
    return 0; 
} 
