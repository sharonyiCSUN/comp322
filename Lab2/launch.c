#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[]){

int status;

if(argc < 2){
  return 1;
}

  pid_t cpid;
  cpid = fork();

  if (cpid < 0){
    printf("Fork Failed.\n");
    return 1;
  }

  //child process
  else if (cpid == 0){

    char *vArg[argc-1];
    char *pEnv[] = {NULL};

    for(int i = 0; i < (argc - 1); i++){
      vArg[i] = argv[i+1];
    }
    vArg[argc - 1] = NULL;
    execve(vArg[0], vArg, pEnv);

    exit(EXIT_SUCCESS);
  }
  //parent process
  else{

    fprintf(stderr, "%s: $$ = %i\n", argv[1], cpid);
    waitpid(cpid, &status, 0);
    fprintf(stderr, "%s: $? = %i\n", argv[1], status);
  }
  return 0;
}
