#include <stdio.h>
#include "ui.h"

// Prints a welcome message
void WelcomeMessage(void)
{
	printf("Welcome to the program!\n");
	printf("I am an alien cyborg from the future.\n");
}

// This function prompts the user for a choice and validates the input
char GetUserChoice(void) {
	char choice;
	char buffer[10];
	do {
		printf("Would you like to enter a cyborg? (y/n): ");
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			printf("Error reading choice\n");
			return 'N';
		}

		// Convert the first character to uppercase
		choice = toupper(buffer[0]);

		if (choice != 'Y' && choice != 'N') {
			printf("Invalid choice. Please enter Y or N.\n");
		}
		else {
			return choice;
		}
	} while (1);
}