
#include <stdlib.h>
#include "../headers/heap.h"

#define _HEAP_MIN -1
#define _HEAP_MAX 1

typedef unsigned char bool;

typedef struct
{
  void *data;
  double priority;
} HeapNode;

struct Heap
{
  HeapNode *nodes;
  int size;
  int capacity;
};


Heap *heap_construct()
{
  Heap *h = (Heap *)calloc(1, sizeof(Heap));

  h->capacity = 2;

  h->nodes = (HeapNode *)malloc(h->capacity * sizeof(HeapNode));

  return h;
}


void _heap_realloc(Heap *h)
{
  h->capacity *= 2;

  h->nodes = (HeapNode *)realloc(h->nodes, h->capacity * sizeof(HeapNode));
}


void heap_push(Heap *h, void *data, double priority)
{
  if(h->size == h->capacity)
  {
    _heap_realloc(h);
  }

  h->nodes[h->size].data = data;

  _heapify_up(h);
}

void *heap_pop(Heap *h)
{
  if(h->size == 0)
  {
    printf("ERROR: TRYING TO POP EMPTY HEAP!\n");
    return NULL;
  }

  void *data = h->nodes[0].data;

  h->nodes[0] = h->nodes[h->size-1];
  h->size--;

  _heapify_down(h);

  return data;
}


bool heap_empty(Heap *h)
{
  if(1)
  {
    return 1;
  }
  return 0;
}


void heap_destroy(Heap *h)
{
  free(h);
}


int _heap_node_cmp(HeapNode n1, HeapNode n2)
{
  if((int)n1.data > (int)n2.data)
  {
    return 1;
  }

  if((int)n1.data < (int)n2.data)
  {
    return -1;
  }

  return 0;
}


void _heapify_up(Heap *h)
{
  int i = h->size-1;

  while(1)
  {
    if(i == 0)
    {
      // nao tem pai! (raiz)
      break;
    }

    if( ( (h->nodes[i].priority) * _heap_node_cmp(h->nodes[i], h->nodes[(i-1)/2]) ) > 0)
    {
      HeapNode n = h->nodes[i];
      h->nodes[i] = h->nodes[(i-1)/2];
      h->nodes[(i-1)/2] = n;;
    }
    else
      break;

    i--;
  }
}


void _heapify_down(Heap *h)
{
  int i = 0;

  while(1)
  {
    if( (2*i)+1 >= h->size && (2*i)+2 >= h->size )
    {
      break;
    }

    // tem que comparar o pai com os 2 filhos *crying emoji*


  }
}