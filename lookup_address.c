#include<stdio.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

extern void display_list(struct address_t*);//difiniion in `display_list.c`
extern void user_alias_input(struct address_t*);//definition in `user_ip_alias_input.c`
extern struct address_t*  search(struct address_t*, struct address_t*, int);//definition in `search.c`


void lookup_address(struct address_t *head)
{
	struct address_t temp = {{[0 ... 3]=-1},""}, *ptr_to_list;
	int    ind = 1;

	printf("Please enter the alias (not case sensitive) corresponding to the address which is to be searched: ");
	
	user_alias_input(&temp);

	ptr_to_list = search(head, &temp, ind);//returns pointer to node which contains the value of alias entered by user OR it returns NULL

	if(ptr_to_list)
		printf("Address corresponding to alias \"%s\": %d.%d.%d.%d\n",temp.alias,ptr_to_list->octet[0],\
										ptr_to_list->octet[1],\
										ptr_to_list->octet[2],\
										ptr_to_list->octet[3]);
	else
	{
		printf("\n+---------------------------+\n");
		printf("|Alias not found in the list|\n");
		printf("+---------------------------+\n\n");
		display_list(head);
		return;
	}
    printf("\n\nEnter any key to go back to the menu: ");
    while((ind = getchar()) != EOF)
    {
        if(ind == '\n')
            break;
    }

}
