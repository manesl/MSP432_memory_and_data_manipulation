/******************************************************************************
 * Copyright (C) 2017 by Shweta Mane
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Shweta Mane is not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief data manipulation operations
 *
 * This header file provides function declarations of ascii to integer and 
 * integer to ascii conversion functions.
 *
 * @author Shweta Mane
 * @date August 4, 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#include <stdint.h>

/**
 * @brief Converts standard integer type to ASCII string
 *
 * Given a int data which can be 32 bit signed, with a desired conversion
 * base, and pointer location to save the 32 bit signed converted ASCII string.
 * 
 * @param data you want to convert to ASCII
 * @param ptr Pointer to data array where the string will be copied
 * @param base base you wish to convert to
 *
 * @return length of the string
 * 
 * @notes 1. don't use any string functions or lib.
 * 2. needs to handle signed data.
 * 3. function should return the length of the data string (incl null char).
 * 4. for that you should place a null char at the end. Append!
 * 5. signed 32 bit number will have max string size. 
 * 6. use *ptr location and copy the converted string there.
 * 7. support bases 2 to 16
 * 8. use pointer arithmetic and not array indexing.
 */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief Converts ASCII string to standard integer type 
 *
 * Given a a ptr location which points to an ASCII string ending in null char, the no of digits(including the null and minus sign only).
 * and base of the current ascii form. This can be converted to a decimal integer.
 * 
 * 
 * @param ptr Pointer to data array where the string is stored
 * @param  digits the no of digits incl the null char and minus sign only
 * @param base base the string format has for ex. 1101 is base 2
 *
 * @return decimal integer
 * 
 * @notes 1. don't use any string functions or lib.
 * 2. needs to handle signed data.
 * 3. function should return a 32 bit signed data.
 * 4. the length of the string is passed as a parameter. 
 * 5. the char string location is passed with *ptr.
 * 6. support bases 2 to 16.
 * 7. use pointer arithmetic and not array indexing.
 */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);
#endif /* __MEMORY_H__ */
