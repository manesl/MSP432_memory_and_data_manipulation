

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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */





//#example:"make all PLATFORM=HOST VFLAG=VERBOSE COURSE=COURSE1"





#include "memory.h"
//#include "platform.h"
#include <stddef.h>//for size_t
#include <stdint.h>//for int32_t
#include <stdbool.h>//for bool
#include <stdlib.h>//for free
//#include <stdio.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value; //ptr has address and *ptr holds the value
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t *src, uint8_t *dst, size_t length){
	int i=0;
	int j=0;
	int  m, n;
	int overlap_f_index;
	int overlap_b_index;
	uint8_t temp[32]={0};
	bool found_overlap=false;
	int o; //for loading values from temp to dst
	if(&src[0]<&dst[0]){
		for(m=0; m<length; m++){
			if(&dst[0]==&src[m]){
				overlap_f_index=m; //save that index in this case 8th
				found_overlap=true;
				//printf("overlap");
				break;
			}
		}	
		if(found_overlap){
			for(n=0; n<32-overlap_f_index; n++){
				temp[n]=src[overlap_f_index];
				overlap_f_index++;
			}
			
			for(i=0; i<length; i++){
				if(i==m){
					break;
				}
				dst[i]=src[i];
				src[i]=0;
			}
			
			for(o=0; o<32-m; o++){
				dst[i]=temp[o];
				i++;
				if(i==length){
					break;
				}
			}	
		}//saving all the temp values elsewhere in temp location(stack memory)
		else{
			for(i=0; i<length; i++){
				dst[i]=src[i];
				src[i]=0;
			}
		}//this is no overlap case for forward overlapping
	}
	else if(&dst[0]<&src[0]){
		for(m=0; m<length; m++){
			if(&src[0]==&dst[m]){
				overlap_b_index=m; //save that index in this case 8th
				found_overlap=true;
				break;
			}
		}	
		if(found_overlap){
			for(n=0; n<16-overlap_b_index; n++){
				temp[n]=src[j];
				j++;
			}
			for(i=0; i<16-overlap_b_index; i++){
				dst[i]=temp[i];
				src[i]=0; //moved first 8 bytes
			}	
			for(i=overlap_b_index; i<length; i++){
				dst[i]=src[i];
				src[i]=0;
			}
		}//saving all the temp values elsewhere in temp location(stack memory)
		else{
			for(i=0; i<length; i++){
				dst[i]=src[i];
				src[i]=0;
			}
		}//this is no overlap case for backward overlapping
	}
return dst; //eq to &dst[0] or the last  &dst[8]?? 
//we can make that as &dst[0]
}

uint8_t * my_memcopy(uint8_t *src, uint8_t *dst, size_t length){
	int i=0;
	for(i=0; i<length; i++){
		dst[i]=src[i];
	}
return &dst[0];//anything is fine &dst[0] or dst
}

uint8_t * my_memset(uint8_t *src, size_t length, uint8_t value){
	int i;
	for(i=0; i<length; i++){
		src[i]=value;
	}
return &src[0];
}

uint8_t * my_memzero(uint8_t *src, size_t length){
	int i;
	for(i=0; i<length; i++){
		src[i]=0;
	}
return &src[0];
}

uint8_t * my_reverse(uint8_t *src, size_t length){
	int i;
	uint8_t temp[32]={0};
	for(i=0; i<length; i++){
		temp[i]=src[i];
	}
	for(i=0; i<length; i++){
		src[i]=temp[length-i-1];
	}
return &src[0];//i can simply write src, yes you can
}

uint8_t * reserve_words(size_t length){
	uint8_t *ptr=NULL;
	
	ptr=(uint8_t*) malloc(length*sizeof(int32_t)); //32 bit long 10 words
	//return ptr;//returning the address, the ptr here of type int32_t is 
//typecasted there as uint8_t
	if(ptr==NULL){
		//printf("NULL returned");
		return NULL;
	}
	return ptr;
}

void free_words(uint8_t *src){  //uint32_t *ptr (ptr=uint8_t*)-> int32_t *src 
	free( (void *)src);
}

