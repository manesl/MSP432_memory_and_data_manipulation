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
 * @file stats.h 
 *
 * @brief This contain the function definitions of following functions:
 *	1. print_array()
 *	2. find_median()
 *	3. find_mean()
 *	4. find_maximum()
 *	5. find_minimum()
 *	6. sort_array()
 *	7. print_statistics()
 *
 * 
 * @author Shweta Satyaheel Mane
 *
 * @date 07.08.2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief This function takes an array and the size of the array 
 *	and displays all the elements of the array in a line separated by 
 *	spaces.
 *
 * @param unsigned char *arr, this points to the first element of the array.
 *	  unsigned int n, this takes the length of the array.
 *	  
 * @return None.
 */

void print_array( unsigned char *arr, unsigned int n );

/**
 * @brief This function takes an array and the size of the array 
 *	and sort the numbers from low to high.
 *      Then performs either of the following functions:
 *	1. if the size is odd, look for the middle number.
 *	2. if the size is even, look for the middle two numbers and
 *	take average.
 *
 * @param unsigned char *arr, this points to the first element of the array.
 *	  unsigned int n, this takes the length of the array.
 *	  
 * @return (unsigned char) median of the array.
 */

unsigned char find_median( unsigned char *arr, unsigned int n);

/**
 * @brief This function takes an array and the size of the array 
 *	and adds up all the elements, dividing them by the size to get 
 *	average/mean.
 *
 * @param unsigned char *arr, this points to the first element of the array.
 *	  unsigned int n, this takes the length of the array.
 *	  
 * @return (unsigned char) mean of the array.
 */

unsigned char find_mean( unsigned char *arr, unsigned int n);

/**
 * @brief This function takes an array and the size of the array 
 *	and sorts out the array in high to low and returns the first element of the array back.
 *	 
 * @param unsigned char *arr, this points to the first element of the array
 *	  unsigned int n, this takes the length of the array
 *	  
 * @return (unsigned char) maximum number of the array.
 */

unsigned char find_maximum( unsigned char *arr, unsigned int n);

/**
 * @brief This function takes an array and the size of the array 
 *	and sorts out the array in high to low and returns the last element of the array back.
 *	
 * @param unsigned char *arr, this points to the first element of the array.
 *	  unsigned int n, this takes the length of the array.
 *	  
 * @return (unsigned char) minimum number of the array.
 */

unsigned char find_minimum( unsigned char *arr, unsigned int n);

/**
 * @brief This function takes an array and the size of the array 
 *	and then compare all the elements to sort them in descending order.
 *	
 * @param unsigned char *arr, this points to the first element of the array
 *	  unsigned int n, this takes the length of the array
 *	  
 * @return (unsigned char *) a pointer pointing to the first element of this new sorted array is returned.
 * 	
 */

unsigned char * sort_array( unsigned char *arr, unsigned int n);


/**
 * @brief This function takes all the results of functions like 
 *	 median, mean, maximum, minimum, sorted array pointer to display the 
 * 	 statistics performed.
 *	
 * @param unsigned char median, median of the array.
 * 	  unsigned char mean, mean of the array.
 * 	  unsigned char maximum, max number of the array.
 * 	  unsigned char minimum, min number of the array.
 * 	  unsigned char *new_arr, a pointer that points to the first element 
 * 	  of the sorted array (descending order).
 * 	  unsigned int n, size of the sorted array.
 *
 * @return None
 */
void print_statistics(unsigned char median, unsigned char mean, unsigned char max, unsigned char min, unsigned char *new_arr, unsigned int n );

/**
 * @brief This function is the stats main function which perform statistics when called
 * @param void
 * @return void
 */

void stats_main(void);
#endif /* __STATS_H__ */
