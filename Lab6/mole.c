#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

  (void)argc;
  FILE *logfile;

  char cwd[PATH_MAX];

  chdir("~/");
  strcat(cwd, getenv("HOME"));
  strcat(cwd, "/lab6.log");
  printf("Path to logfile: &\n", cwd);

  logfile = fopen(cwd, "a");

  if(logfile == NULL)
    perror("File Error\n");

  fprintf(logfile, "Pop %s\n", argv[0])
  fclose(logfile);

  return(0);
}
