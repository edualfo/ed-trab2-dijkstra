
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


HeapNode *_heap_node_construct(void *data, double priority)
{
  HeapNode *n = (HeapNode *)calloc(1, sizeof(HeapNode));

  n->data = data;
  n->priority = priority;

  return n;
}


void _heap_node_destroy(HeapNode *n)
{
  if(n->data != NULL)
  {
    free(n->data);
  }

  free(n);
}


Heap *heap_construct()
{
  Heap *h = (Heap *)calloc(1, sizeof(Heap));

  h->capacity = 2;

  h->nodes = (HeapNode *)calloc(h->capacity, sizeof(HeapNode));

  return h;
}


void _heap_realloc(Heap *h)
{
  h->capacity *= 2;

  h->nodes = (HeapNode *)calloc(capacity, sizeof(HeapNode));
}


void heap_push(Heap *h, void *data, double priority)
{
  if(h->size == h->capacity)
  {
    _heap_realloc(h);
  }

  h->nodes[h->size] = _heap_node_construct(data, priority);

  _heapify_up(h);
}

void *heap_pop(Heap *h)
{
  if(h->size == 0)
  {
    printf("ERROR: TRYING TO POP EMPTY HEAP!\n");
    return NULL;
  }

  void *data = h->nodes[0]->data;

  _heap_node_destroy(h->nodes[0]);
  h->size--;

  h->nodes[0] = h->nodes[h->size-1];
  h->nodes[h->size-1] = NULL;

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


int _heap_node_cmp(HeapNode *n1, HeapNode *n2)
{
  if((int)n1->data > (int)n2->data)
  {
    return 1;
  }

  if((int)n1->data < (int)n2->data)
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

    if( /* (h->nodes[i]->priority) * */ _heap_node_cmp(h->nodes[i], h->nodes[(i-1)/2]) )
    {
      Node *n = h->nodes[i];
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
    if(1)
    {
      break
    }
  }
}