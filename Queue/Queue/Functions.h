#include "Queue.c"

queue_t* create_queue(void);
void destroy_queue(queue_t* queue);
void push(queue_t* queue, int value);
int pop(queue_t* queue);
int get_length(queue_t* queue);
int get_first_value(queue_t* queue);