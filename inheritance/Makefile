CC = g++
CFLAGS = -std=c++17 -Wall -Wextra

app: Person.o Student.o main.o
	$(CC) $(CFLAGS) Person.o Student.o main.o -o app

Person.o: Person.cpp Person.h
	$(CC) $(CFLAGS) -c Person.cpp -o Person.o

Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS) -c Student.cpp -o Student.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

.PHONY: clean
clean:
	rm -f app Person.o Student.o main.o