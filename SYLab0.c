#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char *charVal[] = {"     NUL", "     SOH", "     STX", "     ETX", "     EOT", "     ENQ", "     ACK",
			   "     BEL", "      BS", "      HT", "      LF", "      VT", "      FF", "      CR",
			   "      SO", "      SI", "     DLE", "     DC1", "     DC2", "     DC3", "     DC4",
			   "     NAK", "     SYN", "     ETB", "     CAN", "      EM", "     SUB", "     ESC",
			   "      FS", "      GS","      RS", "      US", "   SPACE"};
	char lastVal[] = "     DEL";

char readchar;
    int readfromfile;
    char filearray[9];
    char ASCIIarray[8];
	int sumoriginal = 0;
    int arraycounter = 0;
	readfromfile = open(argv[1], O_RDONLY);

printf("Original ASCII    Decimal  Parity   \n");
    printf("-------- -------- -------- -------- \n");



    while((read(readfromfile, &readchar, 1)) != 0){
		if(readfromfile < 0){
			printf("Error handling file\n");
			exit(0);
		}
		if((readchar != ' ') || (readchar != '\n')){
			filearray[arraycounter] = readchar;
			arraycounter++;
		}

		if((readchar == ' ')) { //|| (readchar != '\n')){
			int sumoriginal = 0;
			unsigned leng = (unsigned) strlen(filearray);
			if(leng < 9){
				for(int z = leng; z < 9; z++){
					if((filearray[z] == ' '))// || (filearray[z] != '\n'))
					filearray[z] = '0';
				}
				filearray[8] = '\0';
			}
			
			for(int k = 0; k < 8; k++){
				ASCIIarray[k] = filearray[k+1];
				sumoriginal += (int)filearray[k];
			}
}

	char *ASCIIpt;
            char ASCIIc = strtol(ASCIIarray, &ASCIIpt, 2);
            int dec = (int)ASCIIc;

	if(dec < 10)
		printf("%s %s        %i ", filearray, charVal[dec], dec);
            if((dec > 9) && (dec < 33))
		printf("%s %s       %i ", filearray, charVal[dec], dec);
            if((dec > 32) && (dec < 100))
		printf("%s        %c       %i ", filearray, ASCIIc, dec);
            if((dec > 101) && (dec <127) )
		printf("%s        %c      %i ", filearray, ASCIIc, dec);
            if(dec == 127){printf("%s %s      %i ", filearray, lastVal, dec);
            if(sumoriginal%2 == 0)
		printf("EVEN\n");
			else
		printf("ODD\n");

			   arraycounter = 0;
		}
//	sumoriginal = 0;
	}
	return 0;
}

