
typedef struct Vector Vector;


Vector *vector_create();

void vector_push_back();

void *vector_get(Vector *, int idx);

int vector_size(Vector *);

void vector_destroy(Vector *);