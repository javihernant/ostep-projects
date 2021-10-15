
#include "types.h"
#include "stat.h"
#include "user.h"

int spawn(int tickets) {
    int pid = fork();
    if (pid == 0) {
        settickets(tickets);
        //yield();
	while (1) {
		//yield();
	}
    } else if (pid != -1) {
        return pid;
    } else {
        printf(2, "error in fork\n");
        return -1;
    }
}

int
main(int argc, char *argv[])
{

  if(argc != 2){
    printf(1, "pass only one argument");
    exit();
  }

  //printf(0,"I am %d",getpid());
  settickets(atoi(argv[1]));
  for(int i=1;i<4;i++){
   spawn(i*10); 
  }

    struct pstat info;
    getpinfo(&info);
    printf(1, "PID\tTICKETS\tTICKS\n");
    for (int i = 0; i < NPROC; ++i) {
	    if(info.inuse[i]){
		printf(1, "%d\t%d\t%d\n", info.pid[i], info.tickets[i], info.ticks[i]);
	    }
    }
 
  exit();
}
