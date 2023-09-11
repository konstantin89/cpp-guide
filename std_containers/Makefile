CC = g++
CFLAGS = -std=c++17 -Wall -Wextra

app: Array.o main.o ForwardList.o List.o PriorityQueue.o examples.h
	$(CC) $(CFLAGS) Array.o main.o ForwardList.o List.o PriorityQueue.o -o app

main.o: main.cpp examples.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

Array.o: Array.cpp examples.h
	$(CC) $(CFLAGS) -c Array.cpp -o Array.o

ForwardList.o: ForwardList.cpp examples.h
	$(CC) $(CFLAGS) -c ForwardList.cpp -o ForwardList.o

List.o: List.cpp examples.h
	$(CC) $(CFLAGS) -c List.cpp -o List.o

PriorityQueue.o: PriorityQueue.cpp examples.h
	$(CC) $(CFLAGS) -c PriorityQueue.cpp -o PriorityQueue.o

.PHONY: clean
clean:
	rm -f app *.o