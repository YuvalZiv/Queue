#include "stdafx.h"
#include "Functions.h"

#define MALLOC_ERR -1
#define MALLOC_ERR_MSG "Malloc error: Unable to associate memory.\n"
#define NULL_TYPE_ERR -2
#define NULL_TYPE_ERR_MSG "NULL type error: Cannot use NULL value.\n"
#define PUSH_DBG(x) printf("Pushing value %d.\n", x);
#define REMOVE_DBG(x) printf("Poping value %d.\n", x);

queue_t* create_queue(void) {
	/*
	Initiate a queue.
	first and last are NULL (since there are no nodes in the list).
	length is zero (ditto).
	input: void
	output: queue_t*
	*/
	printf("Creating Queue . . .\n");
	queue_t* queue = NULL;
	queue = malloc(sizeof(queue_t*));
	if (queue == NULL)
	{
		printf("%s", MALLOC_ERR_MSG);
		exit(MALLOC_ERR);
	}
	queue->first = queue->last = NULL;
	queue->length = 0;
	return queue;
}

void destroy_queue(queue_t* queue) {
	/*
	Destroying a queue.
	Iritate through all the nodes and free the memory.
	input: queue_t*
	output: void
	*/
	printf("Destroying Queue . . .\n");
	if (queue == NULL) {
		printf("%s", NULL_TYPE_ERR_MSG);
		exit(NULL_TYPE_ERR);
	}
	while (queue->first != NULL)
	{
		pop(queue);
	}
}

void push(queue_t* queue, int value) {
	/*
	Adding a node to a queue.
	input: queue_t*, int
	output: void
	*/
	node_t* node = NULL;
	PUSH_DBG(value);
	if (queue == NULL) {
		printf("%s", NULL_TYPE_ERR_MSG);
		return NULL_TYPE_ERR;
	}
	node = malloc(sizeof(node_t));
	node->value = value;
	node->next = NULL;
	if (queue->length == 0) {
		queue->first = queue->last = node;
	}
	else {
		queue->last = queue->last->next = node;
	}
	queue->length++;
}

int pop(queue_t* queue) {
	/*
	Removing a node from the queue.
	input: queue_t*
	output: int
	*/
	int value = 0;
	node_t* temp = NULL;
	if (queue == NULL) {
		printf("%s", NULL_TYPE_ERR_MSG);
		exit(NULL_TYPE_ERR);
	}
	if (queue->length == 0) {
		printf("Cannot remove from an empty queue.");
		return;
	}
	else if (queue->length == 1) {
		temp = queue->first;
		value = temp->value;
		queue->first = NULL;
		queue->last = NULL;
	}
	else {
		temp = queue->first;
		value = temp->value;
		queue->first = queue->first->next;
	}
	REMOVE_DBG(temp->value);
	free(temp);
	queue->length--;
	return value;
}

int get_length(queue_t* queue) {
	/*
	Returns the length of a queue.
	input: queue_t*
	output: int
	*/
	if (queue != NULL)
	{
		return queue->length;
	}
	printf("%s", NULL_TYPE_ERR_MSG);
	exit(NULL_TYPE_ERR);

}

int get_first_value(queue_t* queue) {
	/*
	Returns the value from the first node in a list.
	input: queue_t*
	output: int*
	*/
	if (queue != NULL)
	{
		return queue->first->value;
	}
	printf("%s", NULL_TYPE_ERR_MSG);
	return NULL_TYPE_ERR;

}