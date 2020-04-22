#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[]){
  int status1, status2, counter = 0;
  int pipefd[2];
  pid_t cpid1, cpid2;
  char buf;

  // int fileD = open("filename", O_WRONLY | O_APPEND);
  // if(fileD < 0)
  //   printf("Error opening the file\n");

  if(argc < 2)
    exit(EXIT_FAILURE);

  if (pipe(pipefd) == -1){
    perror("Pipe");
    exit(EXIT_FAILURE);
  }

   while(strcmp(argv[counter], ",") != 0){
      counter++;
    }
  //counter = 1;
  //printf("this: %i \n", counter);
  char *nArgv1[counter];
  char *nArgv2[argc - counter - 1];

  int increment = 1;
  for(int i = 0; i < counter - 1; i++){
    nArgv1[i] = argv[increment++];
  }
  nArgv1[counter - 1] = NULL;

  for(int i = 0; i < (argc - counter -1); i++){
    nArgv2[i] = argv[++increment];
  }
  nArgv2[argc - counter - 1] = NULL;

  cpid1 = fork();

  if (cpid1 < 0){
    printf("Fork Failed.\n");
    exit(EXIT_FAILURE);
  }

  //child process
  else if (cpid1 > 0){
    //close(pipefd[1]);

    cpid2 = fork();

    if (cpid2 < 0){
      printf("Fork Failed.\n");
      exit(EXIT_FAILURE);
    }
    else if (cpid2 == 0){

      dup2(pipefd[0], STDIN_FILENO);

      if(close(pipefd[1] == -1)){
        fprintf(stderr, "Cannot read pipe.\n");
        exit(EXIT_FAILURE);
      }

      //char *vArg[argc-1];
      char *pEnv[] = {NULL};

      // for(int i = 0; i < (argc - 1); i++){
      //   vArg[i] = argv[i+1];
      // }

      // while(read(pipefd[0], &buf, 1) > 0)
      //   write(STDOUT_FILENO, &buf, 1);

    //  write(STDOUT_FILENO, NULL, 1);

      //close(pipefd[0]);
      read(pipefd[0], nArgv2, (sizeof(nArgv2) + 1));
      execve(nArgv2[0], nArgv2, pEnv);

      //dup2(pipefd[1], 1);
      // while(read(pipefd[0], &buf, 1) > 0)
      //   write(STDOUT_FILENO, &buf, 1);
      //
      // write(STDOUT_FILENO, NULL, 1);
      // close(pipefd[0]);
    //  read(filefd[0],); //still working here!
      //_exit(EXIT_SUCCESS);

      // vArg[argc - 1] = NULL;
      // execve(vArg[0], vArg, pEnv);
      // execve(vArg[0], vArg, pEnv);

      //exit(EXIT_SUCCESS);
    }
    else{

    fprintf(stderr, "%s: $$ = %i\n", nArgv1[0], cpid1);
    fprintf(stderr, "%s: $$ = %i\n", nArgv2[0], cpid2);

    close(pipefd[0]);

    write(pipefd[1], nArgv1, sizeof(nArgv1));
    write(pipefd[1], nArgv2, sizeof(nArgv2));

    close(pipefd[1]);

    waitpid(cpid1, &status1, 0);
    waitpid(cpid2, &status2, 0);
    fprintf(stderr, "%s: $? = %i\n", nArgv1[0], status1);
    fprintf(stderr, "%s: $? = %i\n", nArgv2[0], status2);


    //write(p[1], argv[1],strlen(argv[1]));
    //write(pipefd[1], nArgv2[1],strlen(argv[1]));
    //close(pipefd[1]);
    wait(NULL);
    exit(EXIT_SUCCESS);
    }
  }
  //parent process
  else if (cpid1 == 0){

    char *vArg[argc-1];
    char *ppEnv[] = {NULL};

    // for(int i = 0; i < (argc - 1); i++){
    //   nArgv1[i] = argv[i+1];
    // }
    // for(int i = 0; i < (argc - counter - 1); i++){
    //   nArgv2[i] = argv[i+1];
    // }
    // nArgv1[argc - 1] = NULL;
    // execve(nArgv1[0], nArgv1, pEnv);
    // nArgv2[argc - 1] = NULL;
    // execve(nArgv2[0], nArgv2, pEnv);

    if(close(pipefd[1] == -1)){
      fprintf(stderr, "Cannot read pipe.\n");
      exit(EXIT_FAILURE);
    }

    dup2(pipefd[0], STDIN_FILENO);
    read(pipefd[0], nArgv1, (sizeof(nArgv1) + 1));
    close(pipefd[1]);

    execve(nArgv1[0], nArgv1, ppEnv);
  //  _exit(EXIT_SUCCESS);


    exit(EXIT_SUCCESS);
  }
  return 0;
}
