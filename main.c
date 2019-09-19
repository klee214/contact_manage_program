/* -------------------------------------------
Name: Kimin Lee
Student number: 1332221184
Email: klee214
Section: SJJ
Date: 2019 3 15
Description:
This program is contact management system for saving contact information.
Users can save their names, address and phone numbers. There are options of whether they
enter middle initials, apartment numbers and home, business and cell phone numbers.

---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Contact contact = { { "" },{ 0,"",0,"","" },{ "" } };


	// Display the title
	printf("Contact Management System\n");
	printf("=========================\n");

	// Call the Contact function getName to store the values for the Name member
	getName(&contact.name);

	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&contact.address);

	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumber(&contact.numbers);

	// Display Contact summary details
	printf("\nContact Details\n");
	printf("===============");

	printf("\nName Details\n");
	printf("------------\n");
	printf("First name: %s\n", contact.name.firstName);
	printf("Middle initial(s): %s\n", contact.name.middleInitial);
	printf("Last name: %s\n", contact.name.lastName);

	printf("\nAddress Details\n");
	printf("---------------\n");
	printf("Street number: %d\n", contact.address.streetNumber);
	printf("Street name: %s\n", contact.address.street);
	printf("Apartment: %d\n", contact.address.apartmentNumber);
	printf("Postal code: %s\n", contact.address.postalCode);
	printf("City: %s\n", contact.address.city);

	printf("\nPhone Numbers\n");
	printf("-------------\n");
	printf("Cell phone number: %s\n", contact.numbers.cell);
	printf("Home phone number: %s\n", contact.numbers.home);
	printf("Business phone number: %s\n", contact.numbers.business);

	// Display Completion Message
	printf("\nStructure test for Contact using functions done!\n");

	return 0;
}

