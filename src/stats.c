
/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 *
 * @brief It consists of seven functions which are as follows:
 * 	1. print_statistics()
 *	2. print_array()
 *	3. find_median()
 *	4. find_mean()
 *	5. find_maximum()
 *	6. find_minimum()
 *	7. sort_array()
 * 
 * @author Shweta Satyasheel Mane
 *
 * @date 07.07.2020
 *
 */




//#example:"make all PLATFORM=HOST VFLAG=VERBOSE COURSE=STATS"




#include <stdio.h>
#include "stats.h"
#include "platform.h" //for the dependency on PRITNF macro

/* Size of the Data Set */
#define SIZE (40)
/* Global Variables */
unsigned char temp_test_d[SIZE];//declaring it as empty

void stats_main(void) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100, 90 };

  /* Other Variable Declarations Go Here */
  unsigned char median_test;
  unsigned char mean_test;
  unsigned char max_test;
  unsigned char min_test;
  unsigned char *new_arr;

  /* Statistics and Printing Functions Go Here */
  if (SIZE==0) {
  	PRINTF("Statistics cannot be performed on empty arrays \n");
  }
  else {
	//PRINTF("%d\n", 39/2);//numbers are rounded down
	#ifdef VERBOSE
  		print_array(test, SIZE); //if the VERBOSE flag is defined, then only print
	#endif 
  	median_test = find_median(test, SIZE);
 
 	mean_test = find_mean(test, SIZE);

  	max_test = find_maximum(test, SIZE);

  	min_test = find_minimum(test, SIZE);

  	new_arr=  sort_array(test, SIZE); //a pointer here takes the pointer which is returned.

  	print_statistics(median_test, mean_test, max_test, min_test, new_arr, SIZE);
  }
}


/* Add other Implementation File Code Here */
void print_array( unsigned char *arr, unsigned int n ) {
	int i=0;
	PRINTF("The test array values are:");
	for(i=0; i<n; i++) {
		PRINTF("%d ", *arr); 
		arr++;
	}
	PRINTF("\n");
	PRINTF("\n");
}

unsigned char find_median( unsigned char *arr, unsigned int n) {
	int med=0;
	//load values into a temp_test array
	unsigned char temp_test[n];
	for(int i=0; i<n; i++) {
		temp_test[i]=*arr;
		arr++;
	}
	//arranging numbers low to high
	int temp, swapped;
	while(1) {
		swapped=0;
		for(int i=0; i<n-1; i++) {
				if(temp_test[i]>temp_test[i+1]) {
					temp=temp_test[i];
					temp_test[i]=temp_test[i+1];
					temp_test[i+1]=temp;
				swapped=1;
				}	
		}
		if(swapped==0){
			break;
		}
	}
	//finding median
	if ( n%2==0 ) {
		int n1 = temp_test[(n/2)-1];//the 19th or actual 20th ele
		int n2 = temp_test[(n/2)];//the 20th or actual 21st ele
		med=(n1+n2)/2;
		return med;
	}
	else if ( n%2!=0 ) {
		med = temp_test[(n/2) + 1];
		return med;
	}
}

unsigned char find_mean( unsigned char *arr, unsigned int n) {
	int sum=0;
	int avg=0;
	for(int i=0; i<n; i++) {
		sum=sum+(*arr);
		arr++;
	}
	avg=sum/n;
	return avg;
}

unsigned char find_maximum( unsigned char *arr, unsigned int n) {
	//load values into a temp_test array

	for(int i=0; i<n; i++) {
		temp_test_d[i]=*arr;
		arr++;
	}	
	//arranging numbers high to low
	int temp, swapped;
	while(1) {
		swapped=0;
		for(int i=0; i<n-1; i++) {
				if(temp_test_d[i]<temp_test_d[i+1]) {
					temp=temp_test_d[i];
					temp_test_d[i]=temp_test_d[i+1];
					temp_test_d[i+1]=temp;
					swapped=1;
				}	
			}
		if(swapped==0){
			break;
		}
	}
return temp_test_d[0];
}

unsigned char find_minimum( unsigned char *arr, unsigned int n) {
	//load values into a temp_test array

	for(int i=0; i<n; i++) {
		temp_test_d[i]=*arr;
		arr++;
	}
	//arranging numbers high to low
	int temp, swapped;
	while(1) {
		swapped=0;
		for(int i=0; i<n-1; i++) {
				if(temp_test_d[i]<temp_test_d[i+1]) {
					temp=temp_test_d[i];
					temp_test_d[i]=temp_test_d[i+1];
					temp_test_d[i+1]=temp;
					swapped=1;
				}	
			}
		if(swapped==0){
			break;
		}
	}
return temp_test_d[n-1];
}

unsigned char * sort_array( unsigned char *arr, unsigned int n) {
	//load values into a temp_test array

	for(int i=0; i<n; i++) {
		temp_test_d[i]=*arr;
		arr++;
	}
	//arranging numbers high to low
	int temp, swapped;
	while(1) {
		swapped=0;
		for(int i=0; i<n-1; i++) {
				if(temp_test_d[i]<temp_test_d[i+1]) {
					temp=temp_test_d[i];
					temp_test_d[i]=temp_test_d[i+1];
					temp_test_d[i+1]=temp;
					swapped=1;
				}	
			}
		if(swapped==0){
			break;
		}
	}
return temp_test_d;
}


void print_statistics(unsigned char median, unsigned char mean, unsigned char max, unsigned char min, unsigned char *new_arr, unsigned int n ) {
	PRINTF("Statistics are as follows:\n");
	PRINTF("median:%d\n",median);
	PRINTF("mean:%d\n",mean);
	PRINTF("maximum:%d\n",max);
	PRINTF("minimum:%d\n",min);
	PRINTF("\n");
	//displaying the sorted array
	PRINTF("sorted array:");
	for(int i=0; i<n; i++) {
		PRINTF("%d ", *new_arr);
		new_arr++;
	}

}


