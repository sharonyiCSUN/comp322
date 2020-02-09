#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){
        if(argc < 2){
                printf("You need to provide at least one parameter\n");
                        exit(1);
                        }
                        //printf("Program name: %s\n", argv[0]);
                        //printf("Variable: %s\n", argv[1]);

                        if(argc > 1){
                        if((open(argv[1], O_RDONLY ) == -1)){
                        int result = strcmp(argv[1], "-");
                                if(result == 0){
                                for(int i = 2; i < argc; i++){
                                printf("%s\n", argv[i]);
				

				}
                                }
                                else{
					char ASCIIstr[8];
					int sumoforiginal = 0;
					printf("Original ASCII    Decimal  Parity   \n");
					printf("-------- -------- -------- -------- \n");
                                for(int i = 1; i < argc; i++){
                                        //char *copiedstr;
					//printf("%s", argv[i]);
                                	//strcpy(copiedstr, argv[i]);
					char* copiedstr = argv[i];
					unsigned length =(unsigned)strlen(argv[i]);
					//printf("%i\n", length);
					if(length < 9) {
						for(int j = length; j <= 8; j++)
							copiedstr[j] ='0';
						copiedstr[8] = '\0';
					}	
					//printf("%s ", copiedstr);
					for(int k = 0; k < 8; k++){
						ASCIIstr[k] = copiedstr[k+1];
						sumoforiginal += (int)ASCIIstr[k];
					}	
					char *ASCIIptr;
					char ASCIIchar = strtol(ASCIIstr, &ASCIIptr, 2);
					int decimal = (int)ASCIIchar;
					if(decimal < 10) 
						printf("%s        %c        %i ", copiedstr, ASCIIchar, decimal);
					if((decimal > 9) && (decimal < 100))
						printf("%s        %c       %i ", copiedstr, ASCIIchar, decimal);
					else	//(decimal > 101) 
						printf("%s        %c      %i ", copiedstr, ASCIIchar, decimal);
					if(sumoforiginal % 2 == 0)
						printf("EVEN\n");
					else
						printf("ODD\n");
					}	
                                   }
				
                                        //read(argc[2]);
                                        //pr:intf("hello\n");

                                                                }
                                                               }
                                                                return 0;

}

