// Liam Knapp
//Assignment 4
//CSCN71000

#include <stdio.h>

int main(void) {
	int mysterynum, win;
	printf("Enter the number to be guessed (1 - 1000 inclusive): "); // gather the mysternum that will be guessed
	while (scanf_s("%d", &mysterynum) == 0) { // check to make sure it is not a alpabetical input
		printf("\nInvalid input. Please enter a number, such as 2, 10, or 5: ");
		scanf_s("%*s", &mysterynum);
	}

	win = playgame(mysterynum); // start game

	winorlose(win); // check who wins

}

int playgame(int mysterynum) {
	int timeguessed = 0, guesscounter = 6, correct = 0;
	while (timeguessed != 6) { // loop if the user has not guessed 6 times
		
		display(guesscounter); // display how many guess the user has left
		guesscounter--;

		correct = getuserguess(mysterynum); // gather user input

		if (correct == 1) { // if the guess is correct stop the loop
			return 1;
		}
		
		
		timeguessed++;
	}
	return 0; // if guess run out return 0
}

int display(int guesscounter) { // for the display of guesses left
	int i = 0, displayguesses = 1;
	printf("\nGuesses remaining: %d\n", guesscounter);

	return 0;
}

int getuserguess(int mysterynum) {
	int userguess, i = 0;
	printf("\nEnter the number to be guessed (1 - 1000 inclusive): "); // gather the useres guess

	while (scanf_s("%d", &userguess) == 0) { // check for alphabetical input
		printf("\nInvalid input. Input Must be a number between 1 - 1000 incluesive. ");
		scanf_s("%*s", &userguess);
	}
	

	if (userguess == mysterynum) { // if they guess the number
		return 1;
	}

	higherorlower(userguess, mysterynum); // find if the guess is higher or lower then the mystery num
	return 0;
}

int higherorlower(int userguess, int mysterynum) {
	if (userguess < 1 || userguess > 1000) { // if the guess is not in the range
		printf("\nInvalid Guess. Guess Must be a number between 1 - 1000 incluesive. ");
		return 0;
	}

	if (userguess >= 1 || userguess <= 1000) { // if the guess is in range

		if (userguess < mysterynum) { // if the guess is lower then the mystery num
			printf("\nGuess was to low\n");
			return 0;
		}
		if (userguess > mysterynum) {
			printf("\nGuess was to High\n");// if the guess is higher then the mystery num
			return 0;
		}

	}
	return 0;
}

int winorlose(int win) { // who wins display message
	if (win == 1) { // user won
		printf("\nYou guessed the mystery number!\n");
	}

	if (win == 0) { // user lost
		printf("\nYou lose!\n");
	}

}