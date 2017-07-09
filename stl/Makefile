CC=g++ -g -W

BIN=Vector List Map Deque

all:$(BIN)

%.o:%.cpp
	$(CC) -c $<

Vector:vector.o
	$(CC) -o $@ vector.o

List:list.o
	$(CC) -o $@ list.o

Map:map.o
	$(CC) -o $@ map.o

Deque:deque.o
	$(CC) -o $@ deque.o

clean:
	rm -f $(BIN) *.o
