/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA4															   *
* Date: September 29, 2017                                                                 *
* Description:This program fulfills the requirements for the fourth programming assignment *
********************************************************************************************/
#include "header.h"


void enqueue(Queue *lane, int customerNumber) {


	//variable decalration of the node we'll be adding to the queue
	QueueNode *newNode = NULL, *oldTail = lane->pTail;


	//set newNode to the QueueNode that makeNode returns
	newNode = makeNode();

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

	//set the new customer's service time via random
	//1 - 5	
	newNode->pData->serviceTime = generateRandom(5);

	//set the new customer total time based on if this is the head of the queue or not
	if (newNode == lane->pHead) {

		//if head queue, set total time to service time
		newNode->pData->totalTime = newNode->pData->serviceTime;

	}
	else {

		//add the new node's service time to the previous tail pointer's total time
		newNode->pData->totalTime = newNode->pData->serviceTime + oldTail->pData->totalTime - 1;
	}
	
	

	//set the customer number
	newNode->pData->customerNumber = customerNumber;
}

void enqueueNORM(Queue *lane, int customerNumber) {


	//variable decalration of the node we'll be adding to the queue
	QueueNode *newNode = NULL, *oldTail = lane->pTail;


	//set newNode to the QueueNode that makeNode returns
	newNode = makeNode();

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

	//set the new customer's service time via random
	//1 - 5	
	newNode->pData->serviceTime = generateRandomNORM();

	//set the new customer total time based on if this is the head of the queue or not
	if (newNode == lane->pHead) {

		//if head queue, set total time to service time
		newNode->pData->totalTime = newNode->pData->serviceTime;

	}
	else {

		//add the new node's service time to the previous tail pointer's total time
		newNode->pData->totalTime = newNode->pData->serviceTime + oldTail->pData->totalTime - 1;
	}



	//set the customer number
	newNode->pData->customerNumber = customerNumber;

}

void dequeue(Queue *lane) {

	QueueNode *currentNode = lane->pHead;

	//precondiiton - there MUST be at least one queueNode in the Queue
	if (lane->pHead != NULL && lane->pTail != NULL) {

		//Queue has only one queueNode in it
		if (lane->pHead == lane->pTail) {

			//free the queueNode
			free(currentNode);

			//pointing the head and tail pointers to NULL
			lane->pHead = NULL;
			lane->pTail = NULL;

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

void printQueue(Queue *lane) {

	//Pointer to be used for moving aling the queueNodes in lane
	QueueNode *currentNode = NULL;

	//Point currentNode to the first queueNode in lane
	currentNode = lane->pHead;

	if (currentNode == NULL) {

		printf("Empty Line\n");

	}else{
	
		//Point to each queueNode in lane and print the _____
		while (currentNode != NULL) {

			//print out ______
			printf("Customer Number: %d, service time: %d, total time: %d\n", currentNode->pData->customerNumber,
				currentNode->pData->serviceTime, currentNode->pData->totalTime);

			//Move on to the next queueNode
			currentNode = currentNode->pNext;

		}
	
	}
}

void initializeQueues(Queue *expressLane, Queue *normalLane) {

	//initialize the two Queue's head and tail pointers to NULL
	expressLane->pHead = NULL;
	expressLane->pTail = NULL;
	normalLane->pHead = NULL;
	normalLane->pTail = NULL;


	//GET OUT
}

int simulationPrompt(void) {

	//integer variable to be returning user's input 
	int option = 0;

	do {

		//clear the screen and prompt for sim run time 
		system("cls");
		printf("Enter simulation run time: ");

		//assign the input to option
		scanf_s("%d", &option);


		//continue this loop until option is greater than 1
	} while (option < 1);


	//returrn the user's input run time
	return option;

}

int generateRandom(int maxNumber) {

	//initialize the randomNumber variable to a random number from 1 to MaxNumber
	int randomNumber = (rand() % maxNumber) + 1;

	//return the random number generated from above
	return randomNumber;

}

int generateRandomNORM(void) {

	//random range structure code found at http://c-faq.com/lib/randrange.html
	//M + rand() / (RAND_MAX / (N - M + 1) + 1)
	//generatea random numnber between 3 and 8
	int random = 3 + rand() / (RAND_MAX / (8 - 3 + 1) + 1);

	//return the random number generated
	return random;

}

void runSimulation(Queue *expressLane, Queue *normalLane, int simulationTime) {

	//customer counts for Express and Nornal lanes
	//will be used to assign customer ID's
	int expressCustomerCount = 0, normalCustomerCount = 0;

	//generate the nxtCustCountdownNORM and nxtCustCountdownEXP
	//These two varibales will decrement with each pass of the loop
	//within the loop there will be a check for when either of these are 
	//zero. If so, new randoms will generate
	int nxtCustCountdownNORM = 0, nxtCustCountdownEXP = 0;

	//Varible used to indicate if a customer has been added
	//if so, we don't want to decrement the next customer countdown
	bool newExpressCustomer = false, newNormalCustomer = false;

	//generate a random between 1 and 5 for the next customer countdown in the express lane
	nxtCustCountdownEXP = generateRandom(5);

	//Generate the random between 3 and 8 for the next customer countdown in the normal lane
	nxtCustCountdownNORM = generateRandomNORM();



	//each pass through the loop will simulated one minute
	for (int i = 1; i <= simulationTime; i++) {

		//******************************************************************************EXPRESS LANE
		//*******************************************************************************vvvvvvvvvvv
		//countdown check for the time for a new customer to arrive
		if (nxtCustCountdownEXP == 0) {

			//increment customer number
			expressCustomerCount += 1;

			//push this new customer to the express queue
			enqueue(expressLane, expressCustomerCount);

			//genrate  a new random number and assign it to 
			//our expess countdown
			nxtCustCountdownEXP = generateRandom(5);
			
			//indicate that a new customer was added so as to not decrement the 
			//next customer coutdown
			newExpressCustomer = true;
		}
	
	
		//******************************************************************************************
		//*******************************************************************************NORMAL LANE
		//*******************************************************************************vvvvvvvvvvv

		//countdown check for the time for a new customer to arrive
		if (nxtCustCountdownNORM == 0) {

			//increment customer number
			normalCustomerCount += 1;

			//push this new customer to the express queue
			enqueueNORM(normalLane, normalCustomerCount);

			//genrate  a new random number and assign it to 
			//our expess countdown
			nxtCustCountdownNORM = generateRandomNORM();

			//indicate that a new customer was added so as to not decrement the 
			//next customer coutdown
			newNormalCustomer = true;
		}

		//******************************************************************************************
		//Decrementing values
		//******************************************************************************EXPRESS LANE
		//*******************************************************************************vvvvvvvvvvv
		//of course we dont want to pass any empty queue to that function
		if (expressLane->pHead != NULL && newExpressCustomer == false) {

			//the queue isn't empty and there were no new customers in this
			//minute so update the wait times
			updateWaitTimes(expressLane);

		}
		else {

			//the last queueNode in the Queue was just added this minute so do no decrement values
			updateWaitTimesNoTail(expressLane);

		}

		//Check for time for customer to leave the line
		if (expressLane->pHead != NULL && expressLane->pHead->pData->serviceTime == 0) {

			//dequeue that thang though
			dequeue(expressLane);
		
		}

		//if there was not a new customer this minute then do not
		//decrement the countdown for a new customer
		if (newExpressCustomer == false) {

			nxtCustCountdownEXP -= 1;
		}
		else {

			//bypassing the decrementing of the next customer countdown
			newExpressCustomer = false;
		}
		//******************************************************************************************
		//*******************************************************************************NORMAL LANE
		//*******************************************************************************vvvvvvvvvvv
		//of course we dont want to pass any empty queue to that function
		if (normalLane->pHead != NULL && newNormalCustomer == false) {

			//the queue isn't empty and there were no new customers in this
			//minute so update the wait times
			updateWaitTimes(normalLane);

		}
		else {

			//the last queueNode in the Queue was just added this minute so do no decrement values
			updateWaitTimesNoTail(normalLane);

		}

		//Check for time for customer to leave the line
		if (normalLane->pHead != NULL && normalLane->pHead->pData->serviceTime == 0) {

			//dequeue that thang though
			dequeue(normalLane);

		}

		//if there was not a new customer this minute then do not
		//decrement the countdown for a new customer
		if (newNormalCustomer == false) {

			nxtCustCountdownNORM -= 1;
		}
		else {

			//bypassing the decrementing of the next customer countdown
			newNormalCustomer = false;
		}
		//******************************************************************************************
		//if this is the multiple of 10 minute, print the queue
		if ((i % 10 == 0)) {
			printf("\nExpress Lane Line at %d minutes:\n", i);
			printQueue(expressLane);

			printf("\nNormal Lane Line at %d minutes:\n", i);
			printQueue(normalLane);

			printf("**********************************************************");
		}
		
		
	}


	system("pause");


}

void updateWaitTimes(Queue *lane) {

	QueueNode *currentCustomer = lane->pHead;

	int curCustomerWaitTime = 0;//currentCustomer->pData->serviceTime;

	while (currentCustomer != NULL) {

		//if this function is being called one minute has passed so:
		//Decrement the current customer's service time by 1
		//ONLY IF THE CURRENT CUSTOMER IS PHEAD
		if (currentCustomer == lane->pHead) {
			currentCustomer->pData->serviceTime -= 1;
		}
		

		//calculate the current customer's wait time based on the requirements
		//totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

	
		curCustomerWaitTime = curCustomerWaitTime + currentCustomer->pData->serviceTime;

	

		//assign that wait time to the current customer's wait time
		currentCustomer->pData->totalTime = curCustomerWaitTime;

		currentCustomer = currentCustomer->pNext;
	}

}

void updateWaitTimesNoTail(Queue *lane) {

	//this variation of the original method has a small change in the while 
	//loop condition that makes it so the loop will run of the last 
	//queueNode of the Queue
	if (lane->pHead != lane->pTail) {

		QueueNode *currentCustomer = lane->pHead;

		int curCustomerWaitTime = 0;
		
		while (currentCustomer->pNext != NULL) {

			//if this function is being called one minute has passed so:
			//Decrement the current customer's service time by 1
			//ONLY IF THE CURRENT CUSTOMER IS PHEAD
			if (currentCustomer == lane->pHead) {
				currentCustomer->pData->serviceTime -= 1;
			}

			//calculate the current customer's wait time based on the requirements
			//totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
			curCustomerWaitTime = curCustomerWaitTime + currentCustomer->pData->serviceTime;

			//assign that wait time to the current customer's wait time
			currentCustomer->pData->totalTime = curCustomerWaitTime;

			currentCustomer = currentCustomer->pNext;
		}

	}
	

}