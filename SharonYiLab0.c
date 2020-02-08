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
                        printf("Program name: %s\n", argv[0]);
                        printf("Variable: %s\n", argv[1]);

                        if(argc > 1){
                        if((open(argv[1], O_RDONLY ) == -1)){
                        int result = strcmp(argv[1], "-");
                                if(result == 0){
                                for(int i = 2; i < argc; i++){
                                printf("%s\n", argv[i]);
                                }
                                }
                                else{

                                for(int i = 1; i < argc; i++){
                                        printf("%s\n", argv[i]);
                                        }
                                        }

                                        //read(argc[2]);
                                        printf("hello\n");

                                                                }
                                                                //read(    , \n);

                                                                }
                                                                return 0;

}

