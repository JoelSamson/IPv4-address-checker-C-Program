#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

void display_list(struct address_t *head)
{
	int  count = 0;
	char ip[16]="";

	if(!head)
	{
		printf("\n\n+-------------------------+\n");
		printf("| List is currently empty |\n");
		printf("+-------------------------+\n\n");
		count = -1;
	}
	
	if(count != -1)
	{
		printf("\n+-----------------+------------+\n");
		printf("|   IP Address    |    Alias   | \n");
		printf("+-----------------+------------+\n");

		while(head)
		{
			memset(ip,'\0',sizeof(ip));
			sprintf(ip,"%d.%d.%d.%d",head->octet[0],head->octet[1],head->octet[2],head->octet[3]);
			printf("| %-15s | %-10s |\n",ip, head->alias);
			printf("+-----------------+------------+\n");
			head=head->next;	
			count++;
		}
		printf("\nCurrent total number of address/alias pairs in the list = %d\n\n\n",count);
	}	
	printf("Enter any key to go back to the menu: ");
    while((count = getchar()) != EOF)
    {
    	if(count == '\n')
           	break;
    }
}
