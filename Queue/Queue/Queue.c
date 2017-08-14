#include "Node.c"

typedef struct queue {
	node_t * first;
	node_t * last;
	int length;
} queue_t;