mainTask : ipc inputProcess outputProcess mainTask.o
	gcc $(CFLAGS) -o mainTask mainTask.o -L. -lipc

ipc : ipc_SharedMemory.o
	ar cr libipc.a ipc_SharedMemory.o 

ipc_SharedMemory.o : ipc_SharedMemory.c
	gcc $(CFLAGS) -c ipc_SharedMemory.c 

mainTask.o : mainTask.c
	gcc $(CFLAGS) -c mainTask.c

inputProcess : inputThread.o inputProcess.o
	gcc $(CFLAGS) -o inputProcess inputProcess.o inputThread.o -lpthread -L. -lipc

inputThread.o : inputThread.c
	gcc $(CFLAGS) -c inputThread.c 

outputProcess : outputThread.o outputProcess.o
	gcc $(CFLAGS) -o outputProcess outputProcess.o outputThread.o -lpthread -L. -lipc

outputThread.o : outputThread.c
	gcc $(CFLAGS) -c outputThread.c 

inputProcess.o : inputProcess.c
	gcc $(CFLAGS) -c inputProcess.c

outputProcess.o : outputProcess.c
	gcc $(CFLAGS) -c outputProcess.c

clean :
	rm -f *.o mainTask inputProcess outputProcess libipc.a
