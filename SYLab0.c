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

char *charVal[] = {"     NUL", "     SOH", "     STX", "     ETX", "     EOT", "     ENQ", "     ACK",  //Dictionary for 0-32 ASCII characters
		   "     BEL", "      BS", "      HT", "      LF", "      VT", "      FF", "      CR",
		   "      SO", "      SI", "     DLE", "     DC1", "     DC2", "     DC3", "     DC4",
		   "     NAK", "     SYN", "     ETB", "     CAN", "      EM", "     SUB", "     ESC", 
		   "      FS", "      GS","      RS", "      US", "   SPACE"};
char lastVal[] = "     DEL"; //Dictionary for 127 ASCII character

void calcStuff(char input[]){ //if the flags are good, we can now start to print out the converted output

char ASCIIstr[8];
  char* copiedstr = input;
  unsigned length = (unsigned)strlen(input);
  if(length < 9){
    for(int j = length; j <= 8; j++)
      copiedstr[j] = '0';
    copiedstr[8] = '\0';
  }
  
  int sumoforiginal = 0;
  for(int k = 0; k < 8; k++){
    ASCIIstr[k] = copiedstr[k+1];
    sumoforiginal += (int)copiedstr[k];
  }

  char *ASCIIptr;
  char ASCIIchar = strtol(ASCIIstr, &ASCIIptr, 2);
  int decimal = (int)ASCIIchar;

  
  if(decimal < 10)
    printf("%s %s        %i ", copiedstr, charVal[decimal], decimal);
  if((decimal > 9) && (decimal < 33))
    printf("%s %s       %i ", copiedstr, charVal[decimal], decimal);
  if((decimal > 32) && (decimal < 100))
    printf("%s        %c       %i ", copiedstr, ASCIIchar, decimal);
  if((decimal > 101) && (decimal <127) ) 
    printf("%s        %c      %i ", copiedstr, ASCIIchar, decimal);
  if(decimal == 127)
    printf("%s %s      %i ", copiedstr, lastVal, decimal);

  if(sumoforiginal%2 == 0)
    printf("EVEN\n");
  else
    printf("ODD\n");
}


void padRight(char *byteRaw){
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
  calcStuff(arrSize);
  
}


int main(int argc, char *argv[]) {
  //read the command input
  if(argc > 1){
  
    int file = 1; //assume there is a file
    int readfromfile = open(argv[1], O_RDONLY);
    if(readfromfile < 0){
      file = 0; //set the flag;
    }
    
    //it's cli input
    if(file == 0){
      if(argc > 2){
        printHeader();
	      if(*argv[1] == '-'){
	    for(int i = 2; i < argc; ++i)
		    padRight(argv[i]);
    }
	    else{
      for (int i = 1; i < argc; ++i)
        padRight(argv[i]);
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
      while(read(readfromfile, &readchar, 1)){
        index++;
        if(readchar == '0' || readchar == '1'){
          currentByte[index-1] = readchar;
        }
        if(readchar == ' '){ //found a space, then we calculate
          padRight(currentByte);
          index = 0;
          for(int i = 0; i < 8; i++){ //null the array
            currentByte[i] = 0;
          }
        }
      }
   	if(currentByte[0] == '0' || currentByte[0] == '1')
		padRight(currentByte);
    }
 
  else{
    exit(0);
  }
  return 0;
  }
}
