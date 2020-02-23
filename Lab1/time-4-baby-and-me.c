#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>

int main(){
  pid_t cpid, cprocessid, processid,pprocessid;
  int status;
  time_t seconds;

//fork a child process
  seconds = time(NULL);
  printf("START: %li\n", seconds);
  cpid = fork();

//an error has occurred
if (cpid < 0){
    printf("Fork Failed\n");
    return 1;
  }

  //child process
else if (cpid == 0){
    cprocessid = getpid();
    pprocessid = getppid();

    printf("PPID: %i PID: %i\n",  pprocessid, cprocessid);
    exit(EXIT_SUCCESS);
  }

  //parent process
  //parent waits for the child to complete (symetrical)
else{
  waitpid(cpid, &status, 0);

  pprocessid = getppid();
  processid = getpid();

  printf("PPID: %i PID: %i CPID: %i RETVAL: %i\n",  pprocessid, processid, cpid, status);


  seconds = time(NULL);
  printf("STOP: %li\n", seconds);
  }
  return 0;
}
