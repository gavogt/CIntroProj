#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ui.h"
#include "cyborg.h"


#define MAX_CYBORGS 10

int main(void)
{
	char name[50] = { 0 };
	int age = 0;
	char choice;
	int count = 0;
	char ageStr[10] = { 0 };
	FILE* file = NULL;

	AlienCyborg cyborgs[MAX_CYBORGS] = { 0 }; // Array to hold multiple cyborg records

	errno_t err = fopen_s(&file, "cyborgs.txt", "w");
	if (err != 0 || file == NULL) {
		printf("Error opening file\n");
		return EXIT_FAILURE;
	}

	WelcomeMessage();

	choice = GetUserChoice();

	do {
		if (choice == 'Y') {
			printf("You chose Yes.\n");
			printf("Please enter your name: ");
			if (fgets(name, sizeof(name), stdin) != NULL) {
				size_t len = strlen(name);
				if (len > 0 && name[len - 1] == '\n') {
					name[len - 1] = '\0';
				}
				else {
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
				}
			}
			else {
				printf("Error reading name\n");
				return 1;
			}

			printf("Please enter your age: ");
			if (fgets(ageStr, sizeof(ageStr), stdin) != NULL) {
				ageStr[strcspn(ageStr, "\n")] = '\0';
				age = atoi(ageStr);
			}
			else {
				printf("Error reading age\n");
				return 1;
			}

			strcpy_s(cyborgs[count].name, sizeof(cyborgs[count].name), name);
			cyborgs[count].age = age;
			count++;

			choice = GetUserChoice();
		}
		else if (choice == 'N') {
			printf("You chose No.\n");
			return 0;
		}
	} while (choice == 'Y' && count < MAX_CYBORGS);

	

	for (int i = 0; i < count; i++) {
		const char* ageMessage = GetAge(cyborgs[i].age);
		printf("Welcome, your name is %s and %s \n", cyborgs[i].name, ageMessage);
		fprintf(file, "Cyborg %d: Name: %s, Age:%d, %s\n", i + 1, cyborgs[i].name, cyborgs[i].age, ageMessage);
	}

	printf("\nSUMMARY:\n");
	for (int i = 0; i < count; i++) {
		const char* ageMessage = GetAge(cyborgs[i].age);
		printf("Cyborg %d: Name: %s, Age:%d, %s\n", i + 1, cyborgs[i].name, cyborgs[i].age, ageMessage);
	}

	fclose(file);

	printf("Data written to file successfully.\n");

	EXIT_SUCCESS;
}

/*

Assignment: Advanced Alien Cyborg Program Enhancements
Objective:
Expand your existing Alien Cyborg program to handle multiple cyborg records, organize the data using structures, and persist the information by writing it to a file. This assignment will develop your skills in data management, loops, and file operations in C.

Requirements:
Define a Structure for Cyborg Data:

Create a structure (e.g., AlienCyborg) that contains at least:

A character array for the name.

An integer for the age.

You may include additional fields (such as an ID or status flag) if desired.

Allow for Multiple Records:

Instead of reading a single name and age, modify your program so that it can accept data for multiple cyborgs.

Use an array of your structure to store all the records.

Define a reasonable maximum number of records (for example, 10 cyborgs).

Implement a Loop for Data Entry:

Set up a loop (e.g., a do-while or for loop) that prompts the user to enter data for each cyborg.

After each record, ask the user if they want to add another.

Ensure that your program handles the user’s decision and prevents exceeding the pre-defined maximum.

Enhance Input Validation and Buffer Management:

As you already check the return value of scanf_s, ensure that input is properly validated.

Make sure the input buffer is correctly managed (clear it when necessary) between inputs, especially if you mix numeric and string inputs.

Extend the Age Category Function:

Reuse your existing logic (or enhance it) to generate an age-based message for each cyborg.

This function should be called for each record to print (or store) the corresponding message, such as “you are a minor”, “you are an adult”, or “you are a senior citizen”.

Implement File Input/Output:

Introduce functionality to write the collected data to an external file (such as cyborgs.txt).

Format the output in the file in a human-readable way, including each cyborg’s name, age, and the output from your age categorization function.

Include error handling for file operations (for instance, what happens if the file cannot be opened).

Display a Summary Report:

After all data has been entered, display a summary of all the cyborg records on the screen.

Each record should include the name, age, and associated age message.

Document Your Program:

Add comments throughout your code to explain each step.

Include a header with your name, the assignment title, date, and a brief description of what the program does.

Stretch Goals (Optional):
Dynamic Memory Allocation:
Instead of using a fixed-size array for cyborgs, consider dynamically allocating memory (using malloc/free) to handle a varying number of records.

Additional Data Fields:
You can extend your structure to include more details (for example, a “cyborg ID”, “year of creation”, etc.), and adjust the rest of your program accordingly.

Modularization:
Refactor your code into separate functions or even separate source files (if you’re comfortable with that) to enhance the organization and reusability of your code.
*/