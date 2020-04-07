#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[]){

  int pipePara[2];
  pid_t cpid;

  if (pipe(pipePara) == -1){
    fprint(stderr, "Pipe Failed.\n");
    return 1;
  }

  cpid = fork();

  //
  if (cpid < 0){
    printf("Fork Failed.\n");
    return 1;
  }

  //child process
  else if (cpid > 0){
    close(pipePara[1]);

    fprintf(stderr, "%s: $$ = %i\n", argv[1], cpid);
    waitpid(cpid, status, 0);
    fprintf(stderr, "%s: $? = %i\n", argv[1], status);

    close(pipePara[0]);

    close(pipePara[1]);

  }
  //parent process
  else (cpid == 0){

    char *vArg[argc-1];
    char *pEnv[] = {NULL};

    for(int i = 0; i < (argc - 1); i++){
      vArg[i] = argv[i+1];
    }
    vArg[argc - 1] = NULL;
    execve(vArg[0], vArg, pEnv);

    exit(EXIT_SUCCESS);
  }
  return 0;
}
