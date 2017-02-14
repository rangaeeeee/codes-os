#include <stdio.h>
#include <pthread.h>

void *outputThread1(void *argm) {
  printf("Inside output thread 1 \n");
}

void *outputThread2(void *argm) {
  printf("Inside output thread 2 \n");
}

void *outputThread3(void *argm) {
  printf("Inside output thread 3 \n");
}

void spawnOutputThreads(void){
  pthread_t thread_id1, thread_id2,thread_id3;
  
  /* creating the output threads */
  pthread_create(&thread_id1,NULL,&outputThread1,NULL);
  pthread_create(&thread_id2,NULL,&outputThread2,NULL);
  pthread_create(&thread_id3,NULL,&outputThread3,NULL);

  /* joining the output threads */
  pthread_join(thread_id1,NULL);
  pthread_join(thread_id2,NULL);
  pthread_join(thread_id3,NULL);

}
