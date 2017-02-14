#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

extern void spawnInputThreads(void);

int main(int argc,char *argv[]){
  
  printf("Inside the input process started \n");
  
  spawnInputThreads();
    
  printf("Inside the input process ended \n");
  
  return 0;
}
