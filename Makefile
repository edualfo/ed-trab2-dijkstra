
TARGET = dijkstra-heap

all: $(TARGET)

$(TARGET):
	gcc -o $(TARGET) *.c

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind ./$(TARGET)

clean:
	rm $(TARGET)