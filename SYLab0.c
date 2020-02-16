#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

void calculateStuff(char filearray[], int counter) {
    if( counter < 8) {
        for(int i=counter-1; i<8; ++i) {
            filearray[i] = '0';
        }
    }
    char *charVal[] = {"     NUL", "     SOH", "     STX", "     ETX", "     EOT", "     ENQ", "     ACK", 
							   "     BEL", "      BS", "      HT", "      LF", "      VT", "      FF", "      CR",
							   "      SO", "      SI", "     DLE", "     DC1", "     DC2", "     DC3", "     DC4",
							   "     NAK", "     SYN", "     ETB", "     CAN", "      EM", "     SUB", "     ESC", 
							   "      FS", "      GS","      RS", "      US", "   SPACE"};
	char lastVal[] = "     DEL";
    int sumoriginal = 0;
    char ASCIIarray[8];
	for(int k = 0; k < 8; k++)
	{
		ASCIIarray[k] = filearray[k+1];
		sumoriginal += (int) filearray[k];
	}
	char *ASCIIpt;
    char ASCIIc = strtol(ASCIIarray, &ASCIIpt, 2);
    int dec = (int)ASCIIc;
	
	if(dec < 10){printf("%s %s        %i ", filearray, charVal[dec], dec);}
    if((dec > 9) && (dec < 33)){printf("%s %s       %i ", filearray, charVal[dec], dec);}
    if((dec > 32) && (dec < 100)){printf("%s        %c       %i ", filearray, ASCIIc, dec);}
    if((dec > 101) && (dec <127) ){printf("%s        %c      %i ", filearray, ASCIIc, dec);}
    if(dec == 127){printf("%s %s      %i ", filearray, lastVal, dec);}
    if(sumoriginal%2 == 0){printf("EVEN\n");}
	else{printf("ODD\n");}
}

int main(int argc, char *argv[]) {
	char readchar;
    int readfromfile;
    int arraycounter = 0;
    int bytes_read = -1;
    
	printf("Original ASCII    Decimal  Parity   \n");
    printf("-------- -------- -------- -------- \n");
    if(argc == 0) {
        exit(0);
    } else {
        if(argv[1] == '-' && argc == 1) exit(0);
        
	    readfromfile = open(argv[1], O_RDONLY);
	    if(readfromfile < 0) {
	        if(argc == 1) {
	            calculateStuff(argv[1], strlen(argv[1]));
	        } else {
	            int offset = 0;
	            if(argv[1] == '-') {
	                offset = 1;
	            }
                for(int i=offset; i<argc; ++i) {
                    calculateStuff(argv[i], strlen(argv[i]));
                }
	        }
	    } else {
	        char input[8];
            do {
                bytes_read = read(readfromfile, &readchar, 1);
                if(readchar != ' ') {
                    input[arraycounter] = readchar;
                    arraycounter++;
                }
                if(readchar == ' ' || bytes_read == 0) {   
                    calculateStuff(input, arraycounter);
                    arraycounter = 0;
                }
            } while(bytes_read != 0);
	    }
    }
	return 0;
}
