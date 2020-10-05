
/******************************************************************************
 * Copyright (C) 2020 by Shweta Mane
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Shweta Mane is not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file course1.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Shweta Mane
 * @date August 4, 2020
 *
 */


//#example:"make all PLATFORM=HOST VFLAG=VERBOSE COURSE=COURSE1"



#include "data.h"
#include <stdint.h>
//#include <stdio.h>
#include <stdbool.h>

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){
	if(base==10){
		//printf("base 10\n");
		uint8_t digits=0;//counter

		int i=0;
		int j=0;

		char buffer[33];
		char ch;
		char *start;
		char *end;
		if(data>0 || data<0){
			bool isNeg= data<0;
			uint32_t n= isNeg ? -data : data; //making it positive
			while(n!=0){
				buffer[i]=n%10+'0'; //rem+48
				n=n/10;
				i++;
 				digits++;
			}

			if(isNeg){
				buffer[i]='-';
				i++;
				digits++;
			}
			//buffer[i]='\0';
			//digits++;//big mistake, always append null in the end
			start=&buffer[0];
			end=&buffer[digits-1];
			for(j=0; j<digits/2; j++){
				ch=*start;
				*start=*end;
				*end=ch;
				start++;
				end--;
			}	
			buffer[i]='\0';//appended null
			digits++;
			//ptr=&buffer[0];//storing
			//return digits;
		}
		else{//number is zero
			buffer[0]='0';
			buffer[1]='\0';
			digits=2;
			////printf("%s", buffer);
		}
		for(i=0;i<digits;i++){
			ptr[i]=buffer[i];//maybe its understood to store the address of buffer[0]
		}
		return digits;
	}
	else if(base==2){
		//printf("base 2\n");
		uint8_t digits=0;//counter

		int i=0;
		int j=0;

		char buffer[33];
		char ch;
		char *start;
		char *end;
		if(data>0 || data<0){
			bool isNeg= data<0;
			uint32_t n= isNeg ? -data : data; //making it positive
			while(n!=0){
				if(n%2==0){
					buffer[i]='0'; //rem+48
				}
				else{
					buffer[i]='1';
				}
				n=n/2;
				i++;
 				digits++;
			}

			if(isNeg){
				buffer[i]='-';
				i++;
				digits++;
			}
			//buffer[i]='\0';
			//digits++;//big mistake, always append null in the end
			start=&buffer[0];
			end=&buffer[digits-1];
			for(j=0; j<digits/2; j++){
				ch=*start;
				*start=*end;
				*end=ch;
				start++;
				end--;
			}	
			buffer[i]='\0';//appended null
			digits++;
			////printf("%s", buffer);
			//ptr=&buffer[0];//storing
			//return digits;
		}
		else{//number is zero
			buffer[0]='0';
			buffer[1]='\0';
			digits=2;
			////printf("%s", buffer);
		}
		for(i=0;i<=digits;i++){
			ptr[i]=buffer[i];//maybe its understood to store the address of buffer[0]
		}
		return digits;
	}
	else if(base==16){//hex
		//printf("base 16\n");
		uint8_t digits=0;//counter

		int i=0;
		int j=0;
		int rem=0;

		char buffer[33];
		char ch;
		char *start;
		char *end;
		if(data>0 || data<0){
			bool isNeg= data<0;
			uint32_t n= isNeg ? -data : data; //making it positive
			while(n!=0){
				rem=n%16;
				if(rem<10){
					buffer[i]=48+rem; //rem+48
				}
				else{
					buffer[i]=55+rem;
				}
				n=n/16;
				i++;
 				digits++;
			}

			if(isNeg){
				buffer[i]='-';
				i++;
				digits++;
			}
			//buffer[i]='\0';
			//digits++;//big mistake, always append null in the end
			start=&buffer[0];
			end=&buffer[digits-1];
			for(j=0; j<digits/2; j++){
				ch=*start;
				*start=*end;
				*end=ch;
				start++;
				end--;
			}	
			buffer[i]='\0';//appended null
			digits++;
			////printf("%s", buffer);
			////printf("%d", digits);
			//ptr=&buffer[0];//storing
			//return digits;
		}
		else{//number is zero
			buffer[0]='0';
			buffer[1]='\0';
			digits=2;
			//printf("%s", buffer);
		}
		for(i=0;i<digits;i++){
			ptr[i]=buffer[i];//maybe its understood to store the address of buffer[0]
		}
		return digits;
	}		
	else if(base==8){
		//printf("base 8\n");
		uint8_t digits=0;//counter

		int i=0;
		int j=0;
		int rem=0;

		char buffer[33];
		char ch;
		char *start;
		char *end;
		if(data>0 || data<0){
			bool isNeg= data<0;
			uint32_t n= isNeg ? -data : data; //making it positive
			while(n!=0){
				rem=n%8;
				buffer[i]=rem+'0'; //rem
				n=n/8;
				i++;
 				digits++;
			}

			if(isNeg){
				buffer[i]='-';
				i++;
				digits++;
			}
			//buffer[i]='\0';
			//digits++;//big mistake, always append null in the end
			start=&buffer[0];
			end=&buffer[digits-1];
			for(j=0; j<digits/2; j++){
				ch=*start;
				*start=*end;
				*end=ch;
				start++;
				end--;
			}	
			buffer[i]='\0';//appended null
			digits++;
			//printf("%s", buffer);
			//ptr=&buffer[0];//storing
			//return digits;
		}
		else{//number is zero
			buffer[0]='0';
			buffer[1]='\0';
			digits=2;
			//printf("%s", buffer);
		}
		for(i=0;i<digits;i++){
			ptr[i]=buffer[i];//maybe its understood to store the address of buffer[0]
		}
		return digits;
	}
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base){
	int32_t sign=1;
	int32_t index=0;
	int32_t data=0;

	int i;
	char buffer[33];
	//char *src;
	for(i=0; i<digits; i++){
		buffer[i]=*ptr;
		ptr++;
	}
	////printf("received");
	////printf("%s", buffer);
	//src=&buffer[0];
	if(base==10){
		if(buffer[0]=='-'){
			sign=-1;
			index=1;
		}
		while(buffer[index]!='\0'){
			if(buffer[index]>='0' && buffer[index]<='9'){
				data=data*10+buffer[index]-'0';
				//printf("\n%d\n",data);
			}
			else{
				break;
			}
			index++;
		}
		////printf("\n%d\n",data);
		data=data*sign;
		////printf("\n%d\n",data);
	}	
	////printf("\n%d\n",data);
	else if(base==2){
		int32_t power=1;
		int j=0;
		if(buffer[0]=='-'){
			sign=-1;
			index=1;
			digits++;//compensating for one
		}
		for(j=digits-2-index; j>=0; j--){
			if(buffer[j]=='1' || buffer[j]=='0'){
				data=data+power*(buffer[j]-'0');
				//printf("\n%d\n",data);
			}
			else if(buffer[j]=='-'){
				break;
			}
			power=power*2;
		}
		////printf("\n%d\n",data);
		data=data*sign;
		////printf("\n%d\n",data);
	}		
	else if(base==16){
		int32_t power=1;
		if(buffer[0]=='-'){
			sign=-1;
			index=1;
			digits++;
		}
		for(int i=digits-2-index; i>=0; i--){
			if(buffer[i]>='0' && buffer[i]<='9'){
				data=data+(buffer[i]-48)*power;
				power=power*16;
			}
			else if(buffer[i]>='A' && buffer[i]<='F'){
				data=data+(buffer[i]-55)*power;
				power=power*16;
			}
			else if(buffer[i]=='-'){
				break;
			}
		}
		////printf("\n%d\n",data);
		data=data*sign;
		////printf("\n%d\n",data);
	}
	else if(base==8){
		int32_t power=1;
		int i=0;
		if(buffer[0]=='-'){
			sign=-1;
			index=1;
			digits++;
		}
		for(i=digits-2-index; i>=0; i--){
			if(buffer[i]=='-'){
				break;
			}
			data=data+(buffer[i]-48)*power;
			power=power*8;
	
		}
		////printf("\n%d\n",data);
		data=data*sign;
		////printf("\n%d\n",data);
	}
	return data;
}
