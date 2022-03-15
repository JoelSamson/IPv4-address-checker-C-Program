#include<stdio.h>
#include<stdlib.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

extern struct address_t* search(struct address_t*, struct address_t*, int);//function defined in "search.c"
extern void user_alias_input(struct address_t*);//function defined in "user_ip_alias_input.c"
extern void user_ip_input(struct address_t*, const int);//function defined in "user_ip_alias_input.c"
extern void display_list(struct address_t*);//function defined in "display_list".c

void delete_address(struct address_t** temp_head)
{
	struct address_t temp = {{[0 ... 3]=-1},""}, *ptr_to_alias_match, *head;
	int ind, input_char;

	head = *temp_head;

	printf("Please enter the alias (not case sensitive) corresponding to which IP-alias pair is to be deleted: ");
	user_alias_input(&temp);

	ind = 1;
    ptr_to_alias_match = search(head, &temp, ind);

	if(ptr_to_alias_match)
	{
		printf("IP address corresponding to alias \"%s\" is: %d.%d.%d.%d\n",temp.alias,ptr_to_alias_match->octet[0],\
                                                                                       ptr_to_alias_match->octet[1],\
                                                                                       ptr_to_alias_match->octet[2],\
                                                                                       ptr_to_alias_match->octet[3]);

		printf("Please press Y/y to proceed with delete: ");

		while((ind = getchar()) != EOF)//to read input and clear the stream
		{
			if((ind == 'y')||(ind == 'Y'))
				input_char = ind;
			if(ind == '\n')
				break;
		}
		if((input_char == 'Y')||(input_char == 'y'))
		{
			if(head == ptr_to_alias_match)      //first node of the list is to be deleted
			{
				(*temp_head) = head->next;
				free(head);
			}
			else
			{
				while(head)
				{
					if(head->next != ptr_to_alias_match)
					{
						head = head->next;
					}
					else
					{
						head->next = ptr_to_alias_match->next;
						free(ptr_to_alias_match);
						break;
					}
				}
			}
		}
	}
	else
	{
		printf("\n+----------------------------------+\n");
		printf("| Alias does not exist in the list |\n");
		printf("+----------------------------------+\n");
		display_list(*temp_head);
		return;
	}
	if((input_char == 'y')||(input_char == 'Y'))
	{
		printf("\n\n+----------+\n");
		printf("| Deleted! |\n");
		printf("+----------+\n");
	}
	printf("\n\nEnter any key to go back to the menu: ");
    while((ind = getchar()) != EOF)
    {
        if(ind == '\n')
            break;
    }

	
}
