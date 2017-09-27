#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


typedef struct data
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
} Data; // This memory needs to be allocated on the heap!

typedef struct queueNode
{
	Data *pData;    // The memory for Data will need to be allocated on the heap as well!

	struct queueNode *pNext;
} QueueNode;


typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

void enqueue(Queue *lane, int customerNumber);

//precondiiton - there MUST be at least one queueNode in the Queue
void dequeue(Queue *lane);

QueueNode *makeNode(void);

bool isEmpty(Queue *lane);