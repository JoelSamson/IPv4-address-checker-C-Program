#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

extern void display_list(struct address_t*);//function defined in "display_list.c"
extern void user_ip_input(struct address_t*, int);//function defined in "user_ip_alias_input.c"
extern void user_alias_input(struct address_t*);//function defined in "user_ip_alias_input.c"
extern struct address_t* search(struct address_t*, struct address_t*, int);//function defined in "search.c"

void add_address(struct address_t* head, struct address_t **tail)
{
	struct address_t *temp;
	int ind;

	temp = malloc(sizeof(*temp));
	temp->octet[0]=temp->octet[1]=temp->octet[2]=temp->octet[3]=-1;
	memset(temp->alias,'\0',sizeof(temp->alias));

	printf("Please enter the complete IP address: ");
	user_ip_input(temp,4);//4 has been passed to take four octets as input from user

	ind = 0;
	if(search(head, temp, ind))
	{
		printf("\n\n+----------------------------------------------------+\n");
		printf("|Error: entered IP address already exists in the list|\n");
		printf("+----------------------------------------------------+\n\n");
		printf("Enter any key to go back to the menu: ");
	    while((ind = getchar()) != EOF)
   		{
    	    if(ind == '\n')
        	    break;
    	}
		return;
	}
	printf("\nEntered IP address is %d.%d.%d.%d\n\n",temp->octet[0],temp->octet[1],temp->octet[2],temp->octet[3]);
	printf("\nPlease enter the alias value: ");
	user_alias_input(temp);//takes alias value as input from user

    ind = 1;
    if(search(head, temp, ind))
    {
        printf("\n\n+-----------------------------------------------+\n");
        printf("|Error: entered alias already exists in the list|\n");
        printf("+-----------------------------------------------+\n\n");
	    printf("Enter any key to go back to the menu: ");
	    while((ind = getchar()) != EOF)
	    {
    	    if(ind == '\n')
        	    break;
   		}
		return;
    }
	printf("\n\nAlias entered is %s\n\n",temp->alias);

	temp->next = NULL;
	if(head)
		(*tail)->next = temp;
	*tail = temp;
	printf("\nAddress-Alias pair has ben successfully added!!!\n\n\n");

	printf("Enter any key to go back to the menu: ");
	while((ind = getchar()) != EOF)
	{
		if(ind == '\n')
			break;
	}
}
