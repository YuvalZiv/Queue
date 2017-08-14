// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Functions.h"

int _tmain(int argc, _TCHAR* argv[]) {
	queue_t* queue = create_queue();
	push(queue, 10);
	push(queue, 50);
	push(queue, 20);
	printf("length: %d\n", get_length(queue));
	printf("pop: %d\n", pop(queue));
	printf("length: %d\n", get_length(queue));
	printf("peek: %d\n", get_first_value(queue));
	printf("length: %d\n", get_length(queue));
	destroy_queue(queue);
	return 0;
}
