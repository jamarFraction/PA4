/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA4															   *
* Date: September 29, 2017                                                                 *
* Description:This program fulfills the requirements for the fourth programming assignment *
********************************************************************************************/
#include "header.h"

int main(void) {

	//Declare the normal and express lane Queues
	Queue expressLane, normalLane;

	//Simulation time variable to be set by user
	int simulationTime = 0;

	//Initialize the normal and express lane Queues by passing them to our
	//initialize function
	initializeQueues(&expressLane, &normalLane);

	//one time for randoms
	srand(time(NULL));


	do {

		//Prompt for time length of simulation
		simulationTime = simulationPrompt();


		//pass both lanes and the simluation time to the
		//runSimulations function
		runSimulation(&expressLane, &normalLane, simulationTime);


		//for (int i = 0; i = 10; i++) {

		//	//testing
		//	//printf("Randoms: %d\n", generateRandom((rand() % 100) + 1));

		//}




	//come on.. you know it's a great while condition
	} while (1 == 1);

	return 0;
}


//enqueue(&expressLane, 1);

//printf("Is the Queue empty? %s", isEmpty(&expressLane));

/*enqueue(&expressLane, 2);

enqueue(&expressLane, 3);

enqueue(&expressLane, 4);

enqueue(&expressLane, 5);

enqueue(&expressLane, 6);

enqueue(&expressLane, 7);

printQueue(expressLane);*/