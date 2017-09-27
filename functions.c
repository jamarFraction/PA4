#include "header.h"


void enqueue(Queue *lane, int customerNumber) {


	//variable decalration of the node we'll be adding to the queue
	QueueNode *newNode = NULL;


	//set newNode to the QueueNode that makeNode returns
	newNode = makeNode();

	//testing
	newNode->pData->customerNumber = customerNumber;

	//decision time..
	//is the lane empty?
	//if empty, lane's pHead and pTail will both point to NULL.. is it necessary to check for both?
	//My guess is that it's best to check for both in the condition for total validaiton of NULL pointers
	if (lane->pHead == NULL && lane->pTail == NULL) {

		//empty queue
		//point the pHead and pTail to our newNode
		lane->pTail = newNode;
		lane->pHead = newNode;

		//sho ain't empty no mo' now is it?
		//no sir!

	}
	else {

		//Queue has at least one queueNode in it, so insert from pTail
		lane->pTail->pNext = newNode;

		//point the Queue's pTail to our newNode
		lane->pTail = newNode;

	}
}

void dequeue(Queue *lane) {

	QueueNode *currentNode = lane->pHead;

	//precondiiton - there MUST be at least one queueNode in the Queue
	if (lane->pHead != NULL && lane->pTail != NULL) {

		//Queue has only one queueNode in it
		if (lane->pTail == lane->pTail) {

			//free the queueNode
			free(currentNode);

			//pointing the head and tail pointers to NULL
			lane->pHead == NULL;
			lane->pTail == NULL;

		}
		//Queue has more than one queueNode in it
		else {
			
			//update the head pointer to the headPointer's pNext
			lane->pHead = lane->pHead->pNext;

			//free the current queueNode
			free(currentNode);
		}
		
	}
 

}

QueueNode *makeNode(void) {

	QueueNode *newNode = NULL;

	//let's allocate some memory, shall we?
	newNode = (QueueNode*)malloc(sizeof(QueueNode));

	if (newNode != NULL) {

		//malloc did not fail to make a QueueNode
		//now let's attempt to allocate more memory for Data
		newNode->pData = (Data*)malloc(sizeof(Data));

		if (newNode->pData != NULL) {

			//initialize the next pointer to NULL
			newNode->pNext = NULL;

			//return the newly created node
			//off you go little one.. you'll do great things
			return newNode;

		}

	}

	return NULL;
	

}

bool isEmpty(Queue *lane) {

	//check if the pointers to the head and tail are NULL
	//if they are, the list must be empty
	if (lane->pHead == NULL && lane->pTail == NULL) {

		//Queue is empty, return true
		return true;

	}
	else {

		//Queue is not empty, return false
		return false;
	}


}