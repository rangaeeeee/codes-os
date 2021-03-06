#include "ipc.h"

struct shm_data {
  int segment_id;
  int segment_size;
  struct shmid_ds shmbuffer;
  int page_size;
  int key;
  struct ipc_data *data;
};

void shm_allocate(struct shm_data *shmPtr);
void shm_deallocate(struct shm_data *shmPtr);
void shm_attach(struct shm_data *shmPtr);
void shm_detach(struct shm_data *shmPtr);
