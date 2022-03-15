#include<stdio.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

extern struct address_t* search(struct address_t*, struct address_t*, int);//function defined "search.c"
extern void user_ip_input(struct address_t*, const int);//function defined in "user_ip_alias_input.c"
extern void display_list(struct address_t*);//function defined in "display_list.c"


/*in this function the user would enter the value of first two octets and then if the list contains IP addresses whose first two octets
are same as the user input then alias values corresponding to those IP addresses will be displayed*/
void location_alias_link(struct address_t *head)
{
	struct address_t temp = {{[0 ... 3]=-1},""};
	char arr[8]="";
	int  ind = 0;
    printf("Please enter the location (first two octets) to see the list of aliases corresponding to the location: ");

    user_ip_input(&temp,2);
	sprintf(arr,"%d.%d",temp.octet[0],temp.octet[1]);
	
	if(head)
	{
		printf("\n+-----------------------------------+\n");
		printf("| Alias list for location - %-7s |",arr);
		printf("\n+-----------------------------------+\n");
	
		while(head)
		{
			if((head->octet[0] == temp.octet[0])&&(head->octet[1] == temp.octet[1]))
			{
				printf("|             %-10s            |\n",head->alias);
				printf("+-----------------------------------+\n");
				ind = 1;
			}
			head = head->next;
		}
	}
	if(!ind)
	{
		printf("\n+---------------------------------------------------------------+\n");
		printf("| No data corresponding to alias %-7s is present in the list |\n",arr);
		printf("+---------------------------------------------------------------+\n");
	}
	printf("\n\nEnter any key to go back to the menu: ");
    while((ind = getchar()) != EOF)
    {
        if(ind == '\n')
            break;
    }

}

