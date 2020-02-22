#include <stdio>
#include <sys.types.h>
#include <unistd.h>

int main(){
pid_t pid;

//fork a child process
  pid = fork();
//an error has occurred
  if (pid < 0){
    printf("Fork Failed\n");
    return 1;
  }
  //child process
  else if (pid == 0){
    execlp("/bin/ls", "ls", NULL);
  }
  //parent process
  //parent waits for the child to complete (symetrical)
else{
  wait(NULL);
  printf("Child Complete\n");
}
return 0;
}

