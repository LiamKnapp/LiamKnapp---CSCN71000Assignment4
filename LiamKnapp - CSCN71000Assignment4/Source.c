// Liam Knapp
//Assignment 4
//CSCN71000

#include <stdio.h>

int main(void) {
	int misterynum, win;
	printf("Enter the number to be guessed (1 - 1000 inclusive): ");
	while (scanf_s("%d", &misterynum) == 0) {
		printf("\nInvalid input. Please enter a number, such as 2, 10, or 5: ");
		scanf_s("%*s", &misterynum);
	}

	win = playgame(misterynum);

	winorlose(win);

}

int playgame(int misterynum) {
	int timeguessed = 0, guesscounter = 6, correct = 0;
	while (timeguessed != 6) {
		display(guesscounter);
		guesscounter--;

		correct = getuserguess(misterynum);

		if (correct == 1) {
			return 1;
		}
		
		
		timeguessed++;
	}
	return 0;
}

int display(int guesscounter) {
	printf("\nGuesses remaining: %d\n", guesscounter);
	return 0;
}

int getuserguess(int misterynum) {
	int userguess;
	printf("Enter the number to be guessed (1 - 1000 inclusive): ");
	while (scanf_s("%d", &userguess) == 0) {
		printf("\nInvalid input. Input Must be a number between 1 - 1000 incluesive: ");
		scanf_s("%*s", &userguess);
	}
	
	if (userguess == misterynum) {
		return 1;
	}

	higherorlower(userguess, misterynum);
	return 0;
}

int higherorlower(int userguess, int misterynum) {
	if (userguess < 1 || userguess > 1000) {
		printf("\nInvalid Guess. Guess Must be a number between 1 - 1000 incluesive: ");
		return 0;
	}

	if (userguess >= 1 || userguess <= 1000) {

		if (userguess < misterynum) {
			printf("\nGuess was to low\n");
			return 0;
		}
		if (userguess > misterynum) {
			printf("\nGuess was to High\n");
			return 0;
		}

	}
	return 0;
}

int winorlose(int win) {
	if (win == 1) {
		printf("\nYou guessed the mystery number!\n");
	}

	if (win == 0) {
		printf("\nYou lose!\n");
	}

}