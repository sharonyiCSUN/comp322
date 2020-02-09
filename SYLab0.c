#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){
	if (argc < 2){
		printf("You need to proide at least one parameter\n");
		exit(1);
	}
	if(argc > 1){
		if((open(argv[1], O_RDONLY) == -1)){
			int result = strcmp(argv[1], "-");
			if(result == 0){
				for(int i = 2; i < argc; i++){
					 char ASCIIstr[8];
					                                 printf("Original ASCII    Decimal  Parity   \n");
									                                 printf("-------- -------- -------- -------- \n");
													                                 for(int i = 1; i < argc; i++){
													
															       			 int sumoforiginal = 0;
															
																 		 char copiedstr[9];
																                                                                          char* copiedstr = argv[i];
																                                                                                                                 //strcpy(copiedstr, argv[i]);
																                                                                                                                                                              unsigned length = (unsigned)strlen(argv[i]);
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          char *charVal[] = {"     NUL", "     SOH", "     STX", "     ETX", "     EOT", "     ENQ", "     ACK",
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         "     BEL", "      BS", "      HT", "      LF", "      VT", "      FF", "      CR",
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 "      SO", "      SI", "     DLE", "     DC1", "     DC2", "     DC3", "     DC4",
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   "     NAK", "     SYN", "     ETB", "     CAN", "      EM", "     SUB", "     ESC",
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         "      FS", "      GS","      RS", "      US", "   SPACE"};
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  char lastVal[] = "     DEL";
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
																                         }
		                       }
	        }		
				}
			}
			else{
				char ASCIIstr[8];
				printf("Original ASCII    Decimal  Parity   \n");
				printf("-------- -------- -------- -------- \n");
				for(int i = 1; i < argc; i++){
//					int sumoforiginal = 0;
//					char copiedstr[9];	
					char* copiedstr = argv[i];					
					//strcpy(copiedstr, argv[i]);
					unsigned length = (unsigned)strlen(argv[i]);
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

					char *charVal[] = {"     NUL", "     SOH", "     STX", "     ETX", "     EOT", "     ENQ", "     ACK", 
							   "     BEL", "      BS", "      HT", "      LF", "      VT", "      FF", "      CR",
							   "      SO", "      SI", "     DLE", "     DC1", "     DC2", "     DC3", "     DC4",
							   "     NAK", "     SYN", "     ETB", "     CAN", "      EM", "     SUB", "     ESC", 
							   "      FS", "      GS","      RS", "      US", "   SPACE"};
					char lastVal[] = "     DEL";
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
			}
		}
	}
	return 0;
}

