#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void printHeader(){
  printf("Original ASCII    Decimal  Parity   \n");
  printf("-------- -------- -------- -------- \n");
}

char* charVal[] = {"     NUL", "     SOH", "     STX", "     ETX", "     EOT", "     ENQ", "     ACK",  //Dictionary for 0-32 ASCII characters
		   "     BEL", "      BS", "      HT", "      LF", "      VT", "      FF", "      CR",
		   "      SO", "      SI", "     DLE", "     DC1", "     DC2", "     DC3", "     DC4",
		   "     NAK", "     SYN", "     ETB", "     CAN", "      EM", "     SUB", "     ESC", 
		   "      FS", "      GS","      RS", "      US", "   SPACE"};
char* lastVal = "     DEL"; //Dictionary for 127 ASCII character

void convertStuff(char input[]){ //if the flags are good, we can now start to print out the converted output

char ASCIIstr[8];
  char* copiedstr = input;
  unsigned length = (unsigned)strlen(input);
  if(length < 9){ //padding right
    for(int j = length; j <= 8; j++){
      copiedstr[j] = '0';
    }
    copiedstr[8] = '\0';
  }
  
  int sumoforiginal = 0; //Converting to IASCII
  for(int k = 0; k < 8; k++){
    ASCIIstr[k] = copiedstr[k+1];
    sumoforiginal += (int)copiedstr[k];
  }

  char* ASCIIptr; //converting ASCIIchar to decimal
  char ASCIIchar = strtol(ASCIIstr, &ASCIIptr, 2);
  int decimal = (int)ASCIIchar;

  
  if(decimal < 10){ //Printing out converted data output
    printf("%s %s        %i ", copiedstr, charVal[decimal], decimal);
  }
  if((decimal > 9) && (decimal < 33)){
    printf("%s %s       %i ", copiedstr, charVal[decimal], decimal);
  }
  if((decimal > 32) && (decimal < 100)){
    printf("%s        %c       %i ", copiedstr, ASCIIchar, decimal);
  }
  if((decimal > 101) && (decimal <127)){ 
    printf("%s        %c      %i ", copiedstr, ASCIIchar, decimal);
  }
  if(decimal == 127){
    printf("%s %s      %i ", copiedstr, lastVal, decimal);
  }
  if(sumoforiginal%2 == 0){ //Printing out parity bit
    printf("EVEN\n");
  }
  else{
    printf("ODD\n");
  }
 }


void padRight(char *byteRaw){ //Verifying if the array contains 1's and 0's (8-bits), then continues on to the converting function to be printed out
  char arrSize[8]; //8 bits + 1 terminator
  int endFlag = 0;
  for(int i = 0; i < 8; i++){ //insert padding
    if((byteRaw[i] == '0' || byteRaw[i] == '1') && endFlag == 0){
      arrSize[i] = byteRaw[i];
    }
    else{
      endFlag = 1;
      arrSize[i] = '0';
    }
  }
  convertStuff(arrSize);
}


int main(int argc, char *argv[]){
  if(argc > 1){ //read the command input
    int file = 1; //assume there is a file
    int readfromfile = open(argv[1], O_RDONLY);
    if(readfromfile < 0){
      file = 0; //set the flag;
    }
   
    if(file == 0){  //it's cli input
      if(argc > 2){
        printHeader();
	      if(*argv[1] == '-'){
	    for(int i = 2; i < argc; ++i)
		    padRight(argv[i]);
    }
	    else{
      for (int i = 1; i < argc; ++i)
        padRight(argv[i]); //Passing in the values of the data from the user to the function to be checked if it is 8-bits
      }
  }
      else{
	      exit(0);
      }
    } 
    //it's a file
    if(file == 1){
      printHeader();
      char currentByte[8];
      char readchar;
      int index = 0;
      while(read(readfromfile, &readchar, 1)){ //runs while there is still content in the file
        index++;
        if(readchar == '0' || readchar == '1'){ //verifies that there are only characters of 1's & 0's
          currentByte[index-1] = readchar;
        }
        if(readchar == ' '){ //if there is a found space, then we proceed to converting
          padRight(currentByte);
          index = 0;
          for(int i = 0; i < 8; i++){ //null the array
            currentByte[i] = 0;
          }
        }
      }
   	if(currentByte[0] == '0' || currentByte[0] == '1'){ //this is to check if the last array is empty or not, if not then it proceeds to the convertion
		padRight(currentByte);
	}
    }
 
  else{
    exit(0);
  }
  return 0; //End of program
  }
}
