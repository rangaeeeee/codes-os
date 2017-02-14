mainTask : inputProcess outputProcess mainTask.o
	gcc $(CFLAGS) -o mainTask mainTask.o

mainTask.o : mainTask.c
	gcc $(CFLAGS) -c mainTask.c

inputProcess : inputThread.o inputProcess.o
	gcc $(CFLAGS) -o inputProcess inputProcess.o inputThread.o -lpthread 

inputThread.o : inputThread.c
	gcc $(CFLAGS) -c inputThread.c 

outputProcess : outputThread.o outputProcess.o
	gcc $(CFLAGS) -o outputProcess outputProcess.o outputThread.o -lpthread

outputThread.o : outputThread.c
	gcc $(CFLAGS) -c outputThread.c 

inputProcess.o : inputProcess.c
	gcc $(CFLAGS) -c inputProcess.c

outputProcess.o : outputProcess.c
	gcc $(CFLAGS) -c outputProcess.c

clean :
	rm -f *.o mainTask inputProcess outputProcess
