/*
 * reversed.c

 * This program calculates the reversed
 * of an integer number provided as
 * standard input
 *
 *  Created on: 28 Jan 2017
 *      Author: liliana
 */

#include <stdio.h>
#include <math.h>

int insertInputNumber(void);
int reverseIntNumber(int);


int main(int argc, char* argv[]) {

	int inputNumber, reversedNumber;
	//invoke the function requiring
	//to insert the number as input
	inputNumber = insertInputNumber();

	//invokes the function that reverse the input
	reversedNumber = reverseIntNumber(inputNumber);

	printf("The reserve of %d is %d", inputNumber, reversedNumber);
}

/* Reads and returns an integer number
 * from the standard input
 */
int insertInputNumber() {
	int inputNumber;
	printf("%s", "Please insert an integer number as input:\n");
	if (scanf_s("%d", &inputNumber) != 1) {
		printf("Invalid input.\n");
		return 0;
	}
	//scanf("%d", &inputNumber);
	return inputNumber;
}

/* Performs the reversed of an integer number
 * Input: the number to be reserved
 * Output: the reversed number
 */
int reverseIntNumber(int inputNumber) {
	int result = 0;
	while (inputNumber > 0) {
		result = result * 10 + inputNumber % 10;
		inputNumber = inputNumber / 10;
	}
	return result;

}




