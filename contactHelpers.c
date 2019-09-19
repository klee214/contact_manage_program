/* -------------------------------
Name: Kimin Lee
Student number: 133221184
Email: klee214
Section: SJJ
Date: 2019 3 15

---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"contactHelpers.h"
#include"contacts.h"
#include<string.h>
#include<ctype.h>

#define MAXCONTACTS 5

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();


}

// getInt: Empty function definition goes here:
int getInt(void)
{
	int giTest = 0;
	char flag = '\0';
	scanf("%d%c", &giTest, &flag);

	while (flag != '\n') {
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		clearKeyboard();
		scanf("%d%c", &giTest, &flag);
	}
	return giTest;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int girTest = getInt();

	while (girTest < min || girTest > max) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		scanf(" %d", &girTest);
		clearKeyboard();
	}
	return girTest;
}

// yes: Empty function definition goes here:
int yes(void)
{
	char yTest = 'c';
	char flag = '\0';
	scanf("%c%c", &yTest, &flag);

	while (flag != '\n') {
		do {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
			scanf("%c%c", &yTest, &flag);
		} while (yTest != 'y' && yTest != 'Y' && yTest != 'N' && yTest != 'n');
	}

	if (yTest == 'y' || yTest == 'Y') {
		return 1;
	}
	else {
		return 0;
	}
}

// menu: Empty function definition goes here:
int menu(void)
{
	int min = 0, max = 6;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");

	return getIntInRange(min, max);

}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	struct Contact employees[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },{ "4161112222", "4162223333", "4163334444" } },
	{ { "Maggie", "R.", "Greene" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },{ { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },{ "7051112222", "7052223333", "7053334444" } },
	{ { "Sasha",{ '\0' }, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } }, };

	int fin = 0;

	while (fin == 0) {

		int opt = menu();

		switch (opt) {
		case 1:
			displayContacts(employees, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(employees, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(employees, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(employees, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(employees, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(employees, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			fin = yes();
			if (fin == 0) {
				printf("\n");
			}
			else {
				printf("\nContact Management System: terminated\n");
			}
			break;
		default:
			clearKeyboard();
			;
		}
	}
}

// check if the vlaue is postive integer
int getPosInt(int no)
{
	int postiveNumber = getInt();

	while (postiveNumber < 0) {
		if (no == 1) {
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		}
		else {
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
		}
		postiveNumber = getInt();
	}
	return postiveNumber;
}

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
	int i = 0, flag = 1, needInput = 1;

	while (needInput == 1 && flag == 1) {
		scanf("%10s", phoneNum);
		clearKeyboard();

		for (i = 0; i < strlen(phoneNum); i++) {
			flag = isdigit(phoneNum[i]);

			if (flag == 0) {
				printf("Enter a 10-digit phone number: ");
				i = 10;
			}
		}

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10 && flag == 0) {
			flag = 1;
		}
		else if (strlen(phoneNum) != 10 && flag != 0) {
			printf("Enter a 10-digit phone number: ");
			flag = 1;
		}
		else if (strlen(phoneNum) == 10 && flag != 0) {
			needInput = 0;
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0;

	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			return i;
		}
	}
	return -1;
}


// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+");
	printf("\nTotal contacts: %d", count);
	printf("\n\n");
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	if (strlen(contact->name.middleInitial) > 0) {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	else {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

	if (contact->address.apartmentNumber > 1) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i = 0, count = 0;

	printf("\n");
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) > 0) {
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char phoneNum[11];
	int indexNum = 0;

	printf("\nEnter the cell number for the contact: ");

	getTenDigitPhone(phoneNum);

	indexNum = findContactIndex(contacts, size, phoneNum);

	if (indexNum != -1) {
		printf("\n");
		displayContact(&contacts[indexNum]);

		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int check = findContactIndex(contacts, size, "");
	if (check != -1) {
		printf("\n");
		getContact(&contacts[check]);
		printf("--- New contact added! ---\n\n");
	}
	else {
		printf("\n*** ERROR: The contact list is full! ***\n\n");
	}
}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char phoneNum[11];
	int indexNum = 0;
	int update = 10;

	printf("\nEnter the cell number for the contact: ");

	getTenDigitPhone(phoneNum);

	indexNum = findContactIndex(contacts, size, phoneNum);

	if (indexNum != -1) {

		printf("\n");
		printf("Contact found:\n");

		displayContact(&contacts[indexNum]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		update = yes();

		if (update == 1) {
			getName(&contacts[indexNum].name);
		}

		printf("Do you want to update the address? (y or n): ");
		clearKeyboard();
		update = yes();

		if (update == 1) {
			getAddress(&contacts[indexNum].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		update = yes();

		if (update == 1) {
			getNumber(&contacts[indexNum].numbers);
		}


		printf("--- Contact Updated! ---\n\n");

	}
	else {
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char phoneNum[11];
	int indexNum = 0;
	int del = 10;

	printf("\nEnter the cell number for the contact: ");

	getTenDigitPhone(phoneNum);

	indexNum = findContactIndex(contacts, size, phoneNum);

	if (indexNum != -1) {
		printf("\nContact found:\n");
		displayContact(&contacts[indexNum]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		del = yes();

		if (del == 0)
			printf("\n");

		if (del == 1) {
			contacts[indexNum].numbers.cell[0] = '\0';
			contacts[indexNum].name.middleInitial[0] = '\0';
			contacts[indexNum].numbers.business[0] = '\0';
			contacts[indexNum].numbers.home[0] = '\0';

			printf("--- Contact deleted! ---\n\n");
		}
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	struct Contact temp = contacts[1];
	int i = 0;
	int count = 0;

	while (count < 4) {
		for (i = 0; i < size - count; i++) {
			if (strcmp(contacts[count].numbers.cell, contacts[i + count].numbers.cell) > 0) {
				temp = contacts[i + count];
				contacts[i + count] = contacts[count];
				contacts[count] = temp;
			}
		}
		count++;
	}
	printf("\n--- Contacts sorted! ---\n\n");
}