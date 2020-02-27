#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/times.h>
#include <inttypes.h>
#include <sys/wait.h>

//struct tms {
  //clock_t tms_utime;
  //clock_t tms_stime;
  //clock_t tms_cutime;
  //clock_t tms_cstime;
//};

int main(){
  struct tms start_tms;
  struct tms end_tms;

  pid_t cpid; //, processid, pprocessid;
  int status;
  time_t seconds;

//fork a child process
  times(&start_tms);
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
    //processid = getpid();
    //pprocessid = getppid();
//Printing out the Parent Process ID and Process ID of the child
    //printf("PPID: %i PID: %i\n",  pprocessid, processid);
    printf("PPID: %i PID: %i\n",  getpid(), getppid());
    exit(EXIT_SUCCESS);
  }

  //parent process
else{
//gets the status of the child and the return value. Parent waits for the child to complete (symetrical)
  waitpid(cpid, &status, 0);
  times(&end_tms);
  //pprocessid = getppid();
  //processid = getpid();
//displays the Parrent Process ID, Process ID, Child Process ID, and the Return Value of the child in the parent process
  printf("PPID: %i PID: %i CPID: %i RETVAL: %i\n",  getppid(), getpid(), cpid, status);
  printf("USER: %jd, SYS: %jd\nCUSER: %jd, CSYS:%jd\n", (intmax_t)end_tms.tms_utime, (intmax_t)end_tms.tms_stime, (intmax_t)end_tms.tms_cutime, (intmax_t)end_tms.tms_cstime);
  seconds = time(NULL);
  printf("STOP: %li\n", seconds);
  }
  return 0;
}
