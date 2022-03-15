#include<stdio.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

extern struct address_t* search(struct address_t*, struct address_t*, int);//function defined in "search.c"
extern void user_alias_input(struct address_t*);//function defined in "user_ip_alias_input.c"
extern void user_ip_input(struct address_t*, const int);//function defined in user_ip_alias_input.c"
extern void display_list(struct address_t*);//function defined in "display_list.c"


void update_address(struct address_t *head)
{
	struct address_t temp = {{[0 ... 3]=-1},""}, *ptr_to_alias_match=NULL, *ptr_to_ip_match=NULL;
	int ind; //to indicate if only `alias` is in the list OR both `ip` and `alias` is in the list

    printf("Please enter the alias (not case sensitive) corresponding to the address which is to be updated: ");

    user_alias_input(&temp);

	ind = 1;
    ptr_to_alias_match = search(head, &temp, ind);

	if(ptr_to_alias_match)
	{
		printf("\n\nIP address corresponding to alias \"%s\" is: %d.%d.%d.%d\n",temp.alias,ptr_to_alias_match->octet[0],\
                                                                                       ptr_to_alias_match->octet[1],\
                                                                                       ptr_to_alias_match->octet[2],\
                                                                                       ptr_to_alias_match->octet[3]);
		printf("\n\nPlease enter the new IP address: ");
		user_ip_input(&temp,4);

		ind = 0;
		ptr_to_ip_match = search(head, &temp, ind);
			
		if(ptr_to_ip_match)
		{
			printf("\n+---------------------------------------------+\n");
			printf("|Entered IP address already exists in the list|\n");
			printf("+---------------------------------------------+\n");
			display_list(head);
			return;
		}	
		ptr_to_alias_match->octet[0] = temp.octet[0];
		ptr_to_alias_match->octet[1] = temp.octet[1];
		ptr_to_alias_match->octet[2] = temp.octet[2];
		ptr_to_alias_match->octet[3] = temp.octet[3];
	}
	else
	{
		printf("\n+----------------------------------+\n");
		printf("| Alias does not exist in the list |\n");
		printf("+----------------------------------+\n");
		display_list(head);
		return;
	}
	printf("\n\n+----------+\n");
	printf("| Updated! |\n");
	printf("+----------+\n\n");
    printf("\n\nEnter any key to go back to the menu: ");
    while((ind = getchar()) != EOF)
    {
        if(ind == '\n')
            break;
    }
}
