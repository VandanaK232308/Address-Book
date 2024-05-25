/*
NAME :
DATE :
DESCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "address.h"


Contact contacts[MAX_CONTACTS];

int contact_count = 0;

void save() 
{
    FILE *file = fopen("address_book.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        //return;
    }
    for (int i = 0; i < contact_count; i++) 
	{
        fprintf(file, "%s \t%s \t%s\n", contacts[i].name, contacts[i].phone, contacts[i].mail);
    }
    fclose(file);
}

void loadContactsFromFile() 
{
    FILE *file = fopen("address_book.txt", "r");
    if (file == NULL) 
	{
        //return;  // File doesn't exist, so start with an empty contact list
    }
    contact_count = 0;
    while (fscanf(file, "%s %s %s", contacts[contact_count].name, contacts[contact_count].phone, contacts[contact_count].mail) != EOF) 
	{
        contact_count++;
    }
    fclose(file);
}


int main() {
    printf("---------------------------------------------------------------------------------\n");
    printf("----------------------------WELCOME TO ADDRESS BOOK------------------------------\n");
    printf("---------------------------------------------------------------------------------\n");

    loadContactsFromFile();

    char choice;

    do {
        printf("1. Add Contact.\n2. Search Contact\n3. Edit Contact\n4. Delete Contact.\n5. List all contacts.\n6. Exit\n");
        int option;
        printf("Select the option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
				{
					//Add contact
					printf("\n");
					printf("------------------ADD CONTACT----------------------\n");
					printf("\n");
					if (contact_count >= MAX_CONTACTS) 
					{
						printf("Address book is full. Cannot add more contacts.\n");
						return 0;
					}
					printf("Enter the name of the contact: ");
					scanf("%s", contacts[contact_count].name);
					//printf("Enter the mobile number of the contact: ");
					do {
						printf("Enter the mobile number of the contact: ");
						scanf("%s", contacts[contact_count].phone);
						if (!isValidPhoneNumber(contacts[contact_count].phone)) 
						{
							printf("Invalid phone number. Please enter a 10-digit number only.\n");
						}
					} while (!isValidPhoneNumber(contacts[contact_count].phone));
					
					//scanf("%s", contacts[contact_count].phone);
					//printf("Enter the mail id of the contact: ");
					//scanf("%s", contacts[contact_count].mail);
					do {
						printf("Enter the mail id of the contact: ");
						scanf("%s", contacts[contact_count].mail);
						if (!isValidEmail(contacts[contact_count].mail)) 
						{
							printf("Invalid email. Please enter a valid email ending with .com and without spaces.\n");
						}
					} while (!isValidEmail(contacts[contact_count].mail));
					
					contact_count++;
					save();
					printf("Contact added successfully.\n");
				}
				break;
				
            case 2:
                //Search Contact
				{
					printf("\n");
					printf("------------------SEARCH CONTACT----------------------\n");
					printf("\n");
					
					char name[100];
					printf("Enter the name of the contact you are searching for: ");
					scanf("%s", name);

					for (int i = 0; i < contact_count; i++) 
					{
						if (strcmp(contacts[i].name, name) == 0) 
						{
							printf("Contact found: \nName: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].mail);
							//return;
						}
					}
					printf("Contact not found.\n");
				}
                break;
				
            case 3:
                //Edit contact
				{
					printf("\n");
					printf("------------------EDIT CONTACT----------------------\n");
					printf("\n");
					
					char name[100];
					printf("Enter the name of the contact you want to edit: ");
					scanf("%s", name);

					for (int i = 0; i < contact_count; i++) 
					{
						if (strcmp(contacts[i].name, name) == 0) 
						{
							/*printf("Enter the new mobile number of the contact: ");
							scanf("%s", contacts[i].phone);
							printf("Enter the new mail id of the contact: ");
							scanf("%s", contacts[i].mail);*/
							do {
								printf("Enter the new mobile number of the contact: ");
								scanf("%s", contacts[i].phone);
								if (!isValidPhoneNumber(contacts[i].phone)) 
								{
									printf("Invalid phone number. Please enter a 10-digit number.\n");
								}
							} while (!isValidPhoneNumber(contacts[i].phone));

							do {
								printf("Enter the new mail id of the contact: ");
								scanf("%s", contacts[i].mail);
								if (!isValidEmail(contacts[i].mail)) 
								{
									printf("Invalid email. Please enter a valid email ending with .com and without spaces.\n");
								}
							} while (!isValidEmail(contacts[i].mail));
							
							save();
							printf("Contact edited successfully.\n");
							//return;
						}
					}
					printf("Contact not found.\n");
				}
                break;
				
            case 4:
                //Delete contact
				{
					printf("\n");
					printf("------------------DELETE CONTACT----------------------\n");
					printf("\n");
					
					char name[100];
					printf("Enter the name of the contact you want to delete: ");
					scanf("%s", name);

					for (int i = 0; i < contact_count; i++) 
					{
						if (strcmp(contacts[i].name, name) == 0) 
						{
							for (int j = i; j < contact_count - 1; j++) 
							{
								contacts[j] = contacts[j + 1];
							}
							contact_count--;
							save();
							printf("Contact deleted successfully.\n");
							return 1;
						}
					}
					printf("Contact not found.\n");
				}
                break;
				
            case 5:
                //List contacts
				{
					printf("\n");
					printf("------------------LIST ALL CONTACTS----------------------\n");
					printf("\n");
					
					/*if (contact_count == 0) 
					{
						printf("No contacts found.\n");
						return 0;
					}
					printf("All contacts details:\n");
					for (int i = 0; i < contact_count; i++) 
					{
						printf("Name: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].mail);
					}*/
					
					if (contact_count == 0) 
					{
						printf("No contacts found.\n");
						return 0;
					}
					printf("All contacts details:\n");
					printf("------------------------------------------------------------------\n");
					printf("| %-20s | %-15s | %-30s |\n", "Name", "Phone", "Email");
					printf("------------------------------------------------------------------\n");
					for (int i = 0; i < contact_count; i++) {
						printf("| %-20s | %-15s | %-30s |\n", contacts[i].name, contacts[i].phone, contacts[i].mail);
					}
					printf("------------------------------------------------------------------\n");
				}
                break;
				
            case 6:
				{
					exit(0);
				}
				break;
				
            default:
                printf("Select the correct option from the above list.\n");
        }
        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

