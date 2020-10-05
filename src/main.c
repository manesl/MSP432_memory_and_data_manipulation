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
 * @file main.c
 * @brief Main entry point to the final assessment
 *
 * This file contains the main code for the final assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * There is only one calling function in this file, while running the exe 
 * file you need to write -DCOURSE1 for compile time switch
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
//NOTE!!!!!!!!!!#example:"make all PLATFORM=HOST VFLAG=VERBOSE COURSE=COURSE1"
#include "course1.h"
#include "stats.h"

void main(){
#ifdef COURSE1
course1();   //where are the include files?
#endif

#ifdef STATS
stats_main();
#endif
}
