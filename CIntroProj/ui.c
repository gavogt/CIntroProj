#include "ui.h"

void WelcomeMessage(void)
{
	printf("Welcome to the program!\n");
	printf("I am an alien cyborg from the future.\n");
}

char GetUserChoice(void) {
	char choice;
	do {

		printf("Would you like to enter a cyborg? (y/n): ");
		if (scanf_s(" %c", &choice, (unsigned)sizeof(choice)) != 1) {
			printf("Error reading choice\n");
			return 1;
		}

		choice = toupper(choice);

		if (choice != 'Y' && choice != 'N') {
			printf("Invalid choice. Please enter Y or N.\n");
		}
		else {
			break;
		}

	} while (1);
}