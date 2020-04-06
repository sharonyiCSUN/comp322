#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]){

if(argc < 2){
  exit(EXIT_FAILURE);
}

  pid_t cpid;
  cpid = fork();

  if (cpid < 0){
    printf("Fork Failed.\n");
    return 1;
  }

  //child process
  else if (cpid == 0){


    int execve(argc[0], argv, envp);

    char *vArg[argc-1];

    for(int i = 0; i < (argc - 1); i++){
      vArg[i] = argv[i+1];
    }

    
    exit(EXIT_SUCCESS);
  }
  //parent process
  else{
    waitpid(cpid, &status, 0);
    printf(stderr, "%s: $$ = %i", argc[1], cpid\n);
    printf("%s: $$ = %i", argc[1], status\n);
  }
}
