#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <string.h>

int sigTermCounter = 0;

char *sigNames[] = {"", "HUP", "INT", "QUIT", "ILL", "TRAP", "ABRT", "BUS", "FPE", "KILL",
                "USR1", "SEGV", "USR2", "PIPE", "ALRM", "TERM", "STKFLT", "CHLD"
                "CONT", "STOP", "TSTP", "TTIN", "TTOU", "URG", "XCPU", "XFSZ",
                "VTALRM", "PROF", "WINCH", "IO", "PWR", "SYS"};

void handler(int sig){
  static int counter = 0;
  time_t timer;
  timer = time(NULL);
  signal(sig, handler);
  counter++;

  if(sig == SIGTERM)
    sigTermCounter++;
  else
    sigTermCounter = 0;

  if(sigTermCounter == 3)
    printf("catcher: Total signals counter = %d\n", counter);
  else
    printf("SIG%s caught at %ld\n", sigNames[sig], timer);
}

int getIndex(char *word){
  //if(word == "ABRT" || word == "IOT")
  //if(strcasecmp(word, "ABRT") ||
  if(strcasecmp(word, "IOT")){
    return 6;
}
  //else if
    for(int i = 1; i <= 28; i++){
      //if(sigNames[i] == word)
      if(strcasecmp(word, sigNames[i]) == 0)
        return i;
    }

    return -1;
}

int main(int argc, char *argv[]){
// = getpid();
  if(argc < 2)
    exit(EXIT_FAILURE);

  for(int i = 1; i < argc; i++){
    int index = getIndex(argv[i]);
    if(index == -1){
      exit(EXIT_FAILURE);
    }
      signal(index, handler);
  }

  fprintf(stderr, "%s: $$ = %d\n", argv[0], getpid()); //idk if this will work
// int sigTermCounter = 0;
// int counter = 0;

//  print("%s: $$ %i\n", argv[0], counter);
  //return 0;

//else{

  while(sigTermCounter != 3){
    pause();
  }

// if(argv[1] == "TERM")
//   signal(SIGTERM, handle_signint);
// if(argv[2]  == "USR1")
//   signal(SIGUSR1, handle_signint);
// if(argv[3] == "USR2")
//   signal(SIGUSR2, handle_signint);

  exit(EXIT_SUCCESS);
}
