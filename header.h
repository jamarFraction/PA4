/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA4															   *
* Date: September 29, 2017                                                                 *
* Description:This program fulfills the requirements for the fourth programming assignment *
********************************************************************************************/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


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


/*************************************************************
* Function: enqueue
* Input parameters: Queue *lane, int customerNumber
* Returns: nothing
* Precondiitons: there MUST be at least one queueNode in the Queue
*************************************************************/
void enqueue(Queue *lane, int customerNumber);

/*************************************************************
* Function: dequeue
* Input parameters: Queue *lane
* Returns: nothing
* Precondiitons: there MUST be at least one queueNode in the Queue
*************************************************************/
void dequeue(Queue *lane);

/*************************************************************
* Function: makeNode
* Input parameters: none
* Returns: A pointer to a QueueNode* type
*************************************************************/
QueueNode *makeNode(void);

/*************************************************************
* Function: isEmpty
* Input parameters: Queue *lane
* Returns: boolean true if the lane is empty, boolean false if not
*************************************************************/
bool isEmpty(Queue *lane);

/*************************************************************
* Function: printQueue
* Input parameters: Queue *lane
* Returns: nothing
*************************************************************/
void printQueue(Queue *lane);

/*************************************************************
* Function: initializeQueues
* Input parameters: Queue *expressLane, Queue *normalLane
* Returns: nothing
*************************************************************/
void initializeQueues(Queue *expressLane, Queue *normalLane);

/*************************************************************
* Function: simulationPrompt
* Input parameters: void
* Returns: an integer
*************************************************************/
int simulationPrompt(void);

/*************************************************************
* Function: generateRandom
* Input parameters: maxNumber
* Returns: a random integer max of maxNumber
*************************************************************/
int generateRandom(int maxNumber);

/*************************************************************
* Function: generateRandomNORM
* Input parameters: void
* Returns: a random integer 3 - 8
*************************************************************/
int generateRandomNORM(void);

/*************************************************************
* Function: runSimulation
* Input parameters: Queue *expressLane, Queue *normalLane, int simulationTime
* Returns: nothing
*************************************************************/
void runSimulation(Queue *expressLane, Queue *normalLane, int simulationTime);

/*************************************************************
* Function: updateWaitTimes
* Input parameters: Queue *lane
* Returns: nothing
*************************************************************/
void updateWaitTimes(Queue *lane);

/*************************************************************
* Function: updateWaitTimesNoTail
* Input parameters: Queue *lane
* Returns: nothing
*************************************************************/
void updateWaitTimesNoTail(Queue *lane);

/*************************************************************
* Function: enqueueNORM
* Input parameters: Queue *lane, int customerNumber
* Returns: nothing
*************************************************************/
void enqueueNORM(Queue *lane, int customerNumber);