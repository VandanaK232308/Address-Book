#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[100];
    char phone[11];
    char mail[100];
} Contact;


void save();
void loadContactsFromFile();
int isValidPhoneNumber(char *phone);
int isValidEmail(char *email);