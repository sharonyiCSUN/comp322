#include <stdio.h>
#include <stdlib.h>

int pageNumb(int numb){
  return (numb / 4096);
}

int offset(int numb){
  return (numb % 4096);
}

int main(int argc, char *argv[]){

if(argc < 2)
  return 0;

int number = atoi(argv[1]);

printf("The address %d contains:\n", number);
printf("page number = %d\n", pageNumb(number));
printf("offset = %d\n", offset(number));

return 0;
}
