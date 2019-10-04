/*
 ============================================================================
 Name        : TestC.c
 Author      : Eng Ali Gamal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
 /* this the Prototype function*/
int Liner_Sarch_Array(int array , int array_size , int elemant);

int main(void) {

	int array[] = {3, 5, 5, 5, 3, 5 , 6 };


     Liner_Sarch_Array( array , 6 , 5);

}

int Line_Sarch_Array(int array , int array_szie , int element)
{
	int i = 0;   /*Declaration this value*/

	for( i = 0; i < array_szie; i++)   /*for loop the check all array*/
	{
		if (array[i] == element)     /*check this number how many that*/
			return(i);                 /* return the number count for that*/
	}
	return -1;
}
