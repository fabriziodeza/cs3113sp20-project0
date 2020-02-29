#include <stdlib.h>
#include <stdio.h>
#include "string.h"

typedef struct input{

	int count;
	int earliestPos;
	char letters[5];


};


struct input test[1200000];

int main (int argc, char* argv[]){


	char buffer[5];
	int position  =  0;
	char * buffer_pointer = buffer;
	
	//read in bytes until EOF
	//store 1 byte in buffer at a time
	
	while(fread(buffer, 1, 1, stdin) >  0 && buffer[0] != 10){

		printf("Current position: %d\n", position);

		//checks if the char being input has 4 bytes
                if((buffer[0] & 0XF0) == 0XF0){

			fread(buffer_pointer + 1, 1, 3, stdin);
                        *(buffer_pointer + 3) = '\0';
                        printf("%s saved in char array, 4 byte\n",buffer);
                        position = handleMember(buffer, position);

                }
                //checks if the char being input has 3 bytes
                else if((buffer[0] & 0XE0) == 0XE0){

			fread(buffer_pointer + 1, 1, 2, stdin);
                        *(buffer_pointer + 3) = '\0';
                        printf("%s saved in char array, 3 byte\n",buffer);
                        position = handleMember(buffer, position);
                }
                //checks if the char being input has 2 bytes
                else if((buffer[0] & 0XC0) == 0XC0){

                   	fread(buffer_pointer + 1, 1, 1, stdin);
			*(buffer_pointer + 2) = '\0';
			printf("%s saved in char array, 2 byte\n",buffer);
                        position = handleMember(buffer, position);

 		}
                //last case would be if char being input has 1 bytes
                else{
			if(buffer[0] <=  0X80){

				if(buffer[0] != 10){
				*(buffer_pointer + 1) = '\0';
                        	printf("%s saved in char array, 1 byte\n",buffer);
				position = handleMember(buffer, position);
				}

				//Adds new char to struct array or 
				//increments the count
			}
        	}
		
		//buffer[0] = '/0';
	}
	
	printList(position);

}

void printList(int pos){
	
	for(int i = 0; i < pos; i++){
		printf("%s -> %d\n",test[i].letters, test[i].count); 
	}

}

int handleMember(char* buf, int pos){

	for(int i = 0; i <= pos; i++){
		printf("looping through struct array\n");
		//Check if buf already exists in struct array
                if(strcmp(buf, test[i].letters)== 0){
			printf("already exists\n");
			//test[position].letters = buffer
			//increment count
                        test[i].count++;
			printf("Count of %s at test[%d]: %d\n\n", test[i].letters, i, test[i].count);
			return pos;
			printf("Shouldnt reach here");
                }
	}

	//if buf does not exist in struct array add to struct array
	printf("new letter\n");
	printf("Adding new letter to struct array at test[%d]\n\n", pos);
	//add buf to struct at position p*	
	//test[pos].letters = buf;
	test[pos].count = 1;
	test[pos].earliestPos = 0; 	
	strcpy(test[pos].letters, buf);
	//Update earliest position 
	//test[pos].earliestPos = pos;
	pos++;
	return pos;		
	printf("Shouldnt reach here");
		
		
		
	

}
