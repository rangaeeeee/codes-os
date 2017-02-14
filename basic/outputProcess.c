#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

extern void spawnOutputThreads(void);

int main(int argc,char *argv[]){
  
  printf("Inside the output process started \n");

  spawnOutputThreads();

  printf("Inside the output process ended \n");

  return 0;

}
