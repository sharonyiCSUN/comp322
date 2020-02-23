#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>

int main(){
  pid_t cpid, processid, pprocessid;
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
    processid = getpid();
    pprocessid = getppid();
//Printing out the Parent Process ID and Process ID of the child
    printf("PPID: %i PID: %i\n",  pprocessid, processid);
    exit(EXIT_SUCCESS);
  }

  //parent process
else{
//gets the status of the child and the return value. Parent waits for the child to complete (symetrical)
  waitpid(cpid, &status, 0);

  pprocessid = getppid();
  processid = getpid();
//displays the Parrent Process ID, Process ID, Child Process ID, and the Return Value of the child in the parent process
  printf("PPID: %i PID: %i CPID: %i RETVAL: %i\n",  pprocessid, processid, cpid, status);
  
  seconds = time(NULL);
  printf("STOP: %li\n", seconds);
  }
  return 0;
}
