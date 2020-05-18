#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <syslog.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <sys/resource.h>

pid_t moleC, mole1pid, mole2pid;
char cwd[PATH_MAX];

// void deamonize(const char *cmd){
//
//   int i, fd0, fd1, fd2;
//   pid_t pid;
//   struct rlimit rl;
//   struct sigaction sa;
//
//   umask(0);
//
//   if(getrlimit(RLIMIT_NOFILE, &rl) < 0)
//     err_quit("%s: can't get file limit", cmd);
//
//   if((pid = fork()) < 0)
//     err_quit("%s: can't fork", cmd);
//   else if(pid != 0)
//     exit(0);
//
// signal(SIGTERM, handler);
// signal(SIGUSR1, handler);
// signal(SIGUSR2, handler);
//
//   setsid();
//
// sa.sa_handler = SIG_IGN;
// sigemptyset(&sa.sa_mask);
// sa.sa_flags = 0;
// if(sigaction(SIGHUP, &sa, NULL) < 0)
//   err_quit("%s: can't ignore SIGHUP", cmd);
//
// if((pid = fork()) < 0)
//   err_quit("%s: can't fork", cmd);
// else if(pid != 0)
//   exit(0);
//
// if(chdir("/") < 0)
//     err_quit("%s: can't change directory to /", cmd);
//
//   if(rl.rlim_max == RLIM_INFINITY)
//     rl.rlim.max = 1024;
//   for(int i = 0; i < rl.rlim_max; i++)
//     close(i);
//
//   fd0 = open("/dev/null", O_RDWR);
//   fd1 = dup(0);
//   fd2 = dup(0);
//
//   openlog(cmd, LOG_CONS, LOG_DAEMON);
//   if(fd0 != 0 || fd1 != 1 || fd2 != 2){
//     syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fd0, fd1, fd2);
//     exit(1);
//   }
// }

//this function handles the signal handler and creates mole depending on the signal
void handler(int sig){
  signal(sig, handler);

  if(sig == SIGTERM){

    kill(mole1pid, SIGKILL);
    kill(mole2pid, SIGKILL);
    kill(moleC, SIGKILL);
  }
  //if signal = SIGUSR1, then it creates a mole
  else if(sig == SIGUSR1){
    int mole1Status;
    if(waitpid(mole1pid, &mole1Status, 0) == 0)
      kill(mole1pid, SIGKILL);
    // else if(waitpid(mole2pid, &mole1Status, 0) == 0)
    //   return;
    createMole();
  }
  //if signal = SIGUSR2, then it creates a mole
  else if(sig == SIGUSR2){
    int mole2Status;
    if(waitpid(mole2pid, &mole2Status, 0) == 0)
      kill(mole2pid, SIGKILL);
    // else if(waitpid(mole1pid, &mole2Status, 0) == 0)
    //   return;
    createMole();
  }
}

void createMole(){
  char *arguments[3], moleNumb;
  int randNum;
  randNum = (rand() % 4);
  srand(time(0));

  if(randNum == 1){
    mole1pid = fork();
    moleNumb = 1;
    arguments[0] = cwd;
    arguments[1] = moleNumb;
    arguments[2] = NULL;
    if(mole1pid == 0)
      execv(arguments[0], arguments);
    signal(SIGUSR1, handler);
  }
  else{
    mole2pid = fork();
    moleNumb = 2;
    arguments[0] = cwd;
    arguments[1] = moleNumb;
    arguments[2] = NULL;
    if(mole2pid == 0)
      execv(arguments[0], arguments);
    signal(SIGUSR2, handler);
  }
}

int main(int argc, char *argv[]){

  (void)argc;
  (void)argv;
  pid_t pid, sid;
  struct rlimit rl;
  int fd0; //, fd1, fd2;;

  if((pid = fork()) < 0){
    fprintf(stderr, "Forking error\n");
    exit(1);
  }
  else if(pid > 0)
    exit(0);

  //daemon
  else if(pid == 0){

    umask(0); //rwe
    signal(SIGTERM, handler);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);


    if((sid = setsid()) < 0){
      fprintf(stderr, "Setsid error\n");
      exit(1);
    }

    if((chdir("/")) < 0)
      exit(1);
    // getcwd(cwd, sizeof(cwd));
    // strcat(cwd, "/mole");
    //chdir("/");

    // strcat(cwd, getenv("HOME"));
    // strcat(cwd, "/lab6.log");
    // log = open(cwd, O_CREAT, 0777); //rwxrwxrwx
    // if(log == -1)
    //   fprintf(stderr, "Error opening");

    getrlimit(RLIMIT_NOFILE, &rl);

    if(rl.rlim_max == RLIM_INFINITY)
      rl.rlim_max = 1024;

    for(int i = 0; i < rl.rlim_max; i++)
      close(i);

    fd0 = open("/dev/null", O_WRONLY); // O_RDWR);
    // fd0 = open("/dev/null", O_RDWR);
    // fd1 = dup(0);
    // fd2 = dup(0);

    dup2(fd0, 0);
    dup2(fd0, 1);
    dup2(fd0, 2);

    //openlog(cwd, LOG_CONS, LOG_DAEMON);

    }

    while(1)
      pause();
  //}
    return 0;
}
