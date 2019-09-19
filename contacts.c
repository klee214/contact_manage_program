/* -------------------------------
Name: Kimin Lee
Student number: 133221184
Email: klee214
Section:SJJ
Date: 2019 3 15

---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include"contactHelpers.h"
#include"contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:

void getName(struct Name* name)
{
	int option = 0;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]s", name->firstName);

	// asking if users want to enter a middle initial. 
	// if yes, enter the number
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	clearKeyboard();
	option = yes();

	switch (option) {
	case 1:
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]s", name->middleInitial);
		clearKeyboard();
		break;
	default:
		name->middleInitial[0] = '\0';
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]s", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{

	int option = 0;

	printf("Please enter the contact's street number: ");
	address->streetNumber = getPosInt(1);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", address->street);

	clearKeyboard();
	// asking if users want to enter an apartment number. 
	// if yes, enter the number
	printf("Do you want to enter an apartment number? (y or n): ");
	option = yes();

	switch (option) {
	case 1:
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getPosInt(0);
		break;
	default:
		address->apartmentNumber = 0;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]s", address->city);
	clearKeyboard();
}

// getNumbers:
void getNumber(struct Numbers* number)
{
	int option = 0;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(number->cell);

	// asking if users want to enter a home phone number.
	// if yes, enter the number
	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();

	switch (option) {
	case 1:
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(number->home);
		break;
	default:
		number->home[0] = '\0';
	}

	// asking if users want to enter a business phone number. 
	// if yes, enter the number
	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();

	switch (option) {
	case 1:
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(number->business);
		break;
	default:
		number->business[0] = '\0';
	}
}


// getContact:
void getContact(struct Contact *contact)
{
	// Call the Contact function getName to store the values for the Name member
	getName(&contact->name);

	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&contact->address);

	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumber(&contact->numbers);
}
