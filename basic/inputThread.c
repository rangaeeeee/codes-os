#include <stdio.h>
#include <pthread.h>

void *inputThread1(void *argm) {
  printf("Inside input thread 1 \n");
}

void *inputThread2(void *argm) {
  printf("Inside input thread 2 \n");
}

void spawnInputThreads(void){
  pthread_t thread_id1, thread_id2;

  /* creating the input threads */
  pthread_create(&thread_id1,NULL,&inputThread1,NULL);
  pthread_create(&thread_id2,NULL,&inputThread2,NULL);

  /* joining the created threads */
  pthread_join(thread_id1,NULL);
  pthread_join(thread_id2,NULL);

}
