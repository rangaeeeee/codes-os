#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int spawnTask(char *program, char** arg_list){

  pid_t child_pid;

  /* Duplicate this process. */
  child_pid = fork ();

  if (child_pid != 0){
    /* This is the parent process. */
    return child_pid;
  }
  else {
    /* Now execute PROGRAM, searching for it in the path. */
    execvp (program, arg_list);
    /* The execvp function returns only if an error occurs. */
    fprintf (stderr, "an error occurred in execvp\n");
    abort ();
  }
}
int main(int argc,char *argv[]){
  
  int child_status;

  /* The argument list to pass to the "ls" command. */
  char* arg_list[] = {
  "ls", 
  "-l",
  "/",
  NULL
  };

  printf("Inside the main task \n");
  
  /* Spawn a child process running the "ls" command.
  returned child process ID. */
 
  spawnTask("./inputProcess", arg_list);

  spawnTask("./outputProcess", arg_list);
 
  wait(&child_status);
  if(WIFEXITED(child_status)) {
    printf("the child process exited normally, with exit code %d\n",
      WEXITSTATUS(child_status));
  }
  else {
    printf("the child process exited abnormally \n");
  }

  return 0;
}
