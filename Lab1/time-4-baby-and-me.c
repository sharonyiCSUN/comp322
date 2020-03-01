#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/times.h>
#include <inttypes.h>

void displaypinfo(pid_t cpid, int status){

//displays the Parent Process ID, Process ID, Child Process ID, and the Return Value of the child in the parent process
  printf("PPID: %i PID: %i CPID: %i RETVAL: %i\n",  getppid(), getpid(), cpid, status);
}

int main(){
  struct tms start_tms;
  struct tms end_tms;

  pid_t cpid; //, processid, pprocessid;
  int status;
  time_t seconds;

//fork a child process
  times(&start_tms);
  seconds = time(NULL);
//displays the start time of the program
  printf("START: %li\n", seconds);
  cpid = fork();

//an error has occurred
if (cpid < 0){
    printf("Fork Failed\n");
    return 1;
  }

  //child process
else if (cpid == 0){

//Printing out the Parent Process ID and Process ID of the child
    //printf("PPID: %i PID: %i\n",  pprocessid, processid);
    printf("PPID: %i PID: %i\n",  getpid(), getppid());
    exit(EXIT_SUCCESS);
  }

  //parent process
else{
//gets the status of the child and the return value. Parent waits for the child to complete (symmetrical)
  waitpid(cpid, &status, 0);
  times(&end_tms);
//displays parent ID, process ID,child's process ID, and return value of child
  displaypinfo(cpid, status);

//displays the User, System, Child User, Child System time
  printf("USER: %jd, SYS: %jd\nCUSER: %jd, CSYS:%jd\n", (intmax_t)end_tms.tms_utime, (intmax_t)end_tms.tms_stime, (intmax_t)end_tms.tms_cutime, (intmax_t)end_tms.tms_cstime);
  seconds = time(NULL);
//displays the end time of the program
  printf("STOP: %li\n", seconds);
  }
  return 0;
}
