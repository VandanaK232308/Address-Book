/*
NAME :
DATE :
DESCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/

#include <stdio.h>
#include <string.h>
#include "address.h"
#include <ctype.h>


int isValidPhoneNumber(char *phone) 
{
    if (strlen(phone) != 10) 
	{
        return 0;
    }
    for (int i = 0; i < 10; i++) 
	{
        if (!isdigit(phone[i])) 
		{
            return 0;
        }
    }
    return 1;
}

int isValidEmail(char *email) 
{
    if (strchr(email, ' ') != NULL) 
	{
        return 0;
    }
    int len = strlen(email);
    if (len < 4 || strcmp(email + len - 4, ".com") != 0) 
	{
        return 0;
    }
    return 1;
}

