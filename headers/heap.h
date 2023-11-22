
typedef unsigned char bool;
typedef struct Heap Heap;


Heap *heap_construct(); // O(1)

void heap_push(Heap *heap, void *data, double priority); // O(log N)

void *heap_pop(Heap *heap); // O(log N)

bool heap_empty(Heap *heap); // O(1)

void heap_destroy(Heap *heap); // O(1)