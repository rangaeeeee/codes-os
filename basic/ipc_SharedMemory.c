#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "ipc_SharedMemory.h"

void shm_write(struct shm_data *shmPtr, struct ipc_data *ipc_data){
  /* Determine the segment’s size. */
  shmctl (shmPtr->segment_id, IPC_STAT, &shmPtr->shmbuffer);
  shmPtr->segment_size = shmPtr->shmbuffer.shm_segsz;
  /* Write a ipc data to the shared memory segment. */
  memcpy(&shmPtr->data->mem_data, &ipc_data->mem_data,ipc_data->size);
}
void shm_allocate(struct shm_data *shmPtr){
  /* Allocate a shared memory segment. */
  shmPtr->segment_id = shmget (IPC_PRIVATE, shmPtr->segment_size,IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
}

void shm_deallocate(struct shm_data *shmPtr){
  /* Deallocate the shared memory segment.*/
  shmctl (shmPtr->segment_id, IPC_RMID, 0);
}

void shm_attach(struct shm_data *shmPtr){
  /* Attach the shared memory segment. */
  shmPtr->data = (struct ipc_data *)shmat (shmPtr->segment_id, 0, 0);
}

void shm_detach(struct shm_data *shmPtr){
  /* Detach the shared memory segment. */
  shmdt(shmPtr->data);
}
