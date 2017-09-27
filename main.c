#include "header.h"

int main(void) {

	Queue expressLane, normalLane;

	expressLane.pHead = NULL;
	expressLane.pTail = NULL;

	//enqueue(&expressLane, 1);

	//printf("Is the Queue empty? %s", isEmpty(&expressLane));

	enqueue(&expressLane, 2);

	enqueue(&expressLane, 3);


	return 0;
}