/*
 * main.c
 *
 *  Created on: Jun 9, 2019
 *      Author: Eng Ali Gamal
 */

#include <stdio.h>

/* declaration  function reveres array  */
int  vidRevers(int array_size, int* array);

/*declaration function the last number of array*/
int FindLastNumber(int array_size, int *array, int Findnumber);

/*declaration function using odd or even number*/
int FunOddEven(int number);

/* declaration function bit four*/
int Fourhtbit(int num);

/* declaration function  counter for the bit*/
int u8counter(unsigned int number);

/* declaration this the Prototype function*/
int Liner_Sarch_Array(int array, int array_size, int elemant);

int main() {

	int y, x, z, f, s, t;
	int i = 0;
	int array_test[] = { 1, 4, 3, 4, 4, 4 };

	for (i = 0; i < 6; i++) {
		printf("the array befor that %d \n ", array_test[i]);
	}
	printf("**************************\n");

	y = Line_Sarch_Array(array_test, 6, 4);

	printf("\nThe liner of the function %d", y);
	x = u8counter(5);

	printf("\nthe count of fubction %d", x);
	z = FunOddEven(10);

	printf("\nthe fun odd and even %d ", z);

	f = Fourhtbit(23);

	printf("\nThe Fourbit number %d", f);

	s = FindLastNumber(6, array_test, 4);

	printf("\nThe FindLast Number %d ", s);

	t = vidRevers(6, array_test);

	printf("\nThe Void Revers array %d ", t);
	/*for (i = 0; i < 6; i++) {
	 printf("Test the revert array now ************ ");
	 printf("the array after that %d \n ", array_test[i]);
	 }
	 */
}

/* function impelemtion  */

int Line_Sarch_Array(int array[], int array_szie, int element) {

	int i = 0;    					      // Declaration this value
	for (i = 0; i < array_szie; i++)      //for loop the check all array
			{
		if (array[i] == element) {        // check this number how many that
			return (i);                   // return the number count for that
		}
	}
	return -1;
}

/* function the counter number */

int u8counter(unsigned int number) {
	unsigned int mask = 0x80000000;
	unsigned int i, ones_count = 0;

	for (i = 0; i < 32; i++) {
		if ((number << i) & mask) {
			++ones_count;
		}
	}
	return ones_count;
}

// function impelation
int Fourhtbit(int num) {
	return ((num & 0x0000008) >> 3);
}

int FunOddEven(int number) {
	if ((number % 2) == 0) {
		return 0;
	} else {
		return 1;
	}
}
int FindLastNumber(int array_size, int *array, int Findnumber) {
	int i, index = -1;

	for (i = 0; i < array_size; i++) {
		if (array[i] == Findnumber) {

			index = i;
		}
	}
	return index;
	//printf("the out put %d",index);
}

int vidRevers(int array_size, int* array) {
	int i = 0, temp;

	while (i < (array_size / 2)) {
		temp = array[i];
		array[i] = array[array_size - 1 - i];
		array[array_size - 1 - i] = temp;
		i++;
	}

}

/*

 int main()
 {
 int n , i , *ptr, sum= 0;
 printf("\n Enter number of elements:");
 scanf("%d",&n);
 ptr=(int*)calloc(n,sizeof(int));
 if(ptr == NULL)
 {
 printf("Error! memory not allocated.");
 exit(0);
 }
 printf("Enter the element of array ");
 for(i=0; i<n; i++)
 {
 scanf("%d",ptr+i);
 sum+=*(ptr+i);
 }
 printf("sum= %d",sum);
 free(ptr);
 return 0;
 }
 */

/*void tryToModify (int x , char text[])
 {
 x++;
 text[0]--;
 }

 int main()
 {
 int v = 5;
 char name[5] ="Good";
 printf("v = %d , name = %s\r\n", v , name);
 tryToModify(v , name);
 printf("v = %d, name = %s\r\n", v, name);
 }*/

