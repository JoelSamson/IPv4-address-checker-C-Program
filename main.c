#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

extern void display_list(struct address_t*);//function defined in "display_list.c"
extern void add_address(struct address_t*, struct address_t**);//function defined in "add_address.c"
extern void lookup_address(struct address_t*);//function defined in "lookup_address.c"
extern void update_address(struct address_t*);//function defined in "update_address.c"
extern void delete_address(struct address_t**);//function defined in "delete_address.c"
extern void location_alias_link(struct address_t*);//function defined in "location_alias_link.c"
extern void list_to_file(struct address_t*);//function defined in "list_to_file.c"
extern void exit_program();//function defined in "exit_program.c"

int main()
{
	FILE *f_ptr = fopen("CS531_Inet.txt","r");
	int  input, inp;
	char temp_arr[10]="";

    struct address_t *head, *tail, *temp;
    int    count_octet=0;
    int    index=0;

	head = tail = temp = NULL;
    
	if(f_ptr)
	{
		//this `while` loop will read input from file pointed by file pointer and then create a linked list with the data read from that file
		while((input = fgetc(f_ptr)) != EOF)
		{	
			if(input == '\n')
			{
				strcpy(temp->alias,temp_arr);
				memset(temp_arr,'\0',sizeof(temp_arr));	
                index = 0;
                count_octet = 0;
			}
			else
			{
				if(count_octet <= 3)
				{
					if((input != '.')&&(input != ' ')&&(input != '\t'))
					{		
						if((!count_octet)&&(!index))
						{
							temp = malloc(sizeof(*temp));
							if(!temp)				
							{
								printf("Error in allocating memory\n");
								return 0;
							}

							if(!head)
								head = tail = temp;
							else
								tail->next = temp;

							tail = temp;
						}
						temp_arr[index++] = input;
					}
					if((input == '.')||(input == ' '))
					{
						(temp->octet)[count_octet++] = atoi(temp_arr);
						memset(temp_arr,'\0',sizeof(temp_arr));
						index=0;
					}
					while((input == ' ')||(input == '\t'))
					{
						input = fgetc(f_ptr);
						count_octet++;
                        index = 0;
					}
				}
				if(count_octet > 3)
					temp_arr[index++] = input;
			}	
		}
	}
	else
		printf("Error encountered while opening the file\n");

	fclose(f_ptr);
	do
	{	
		printf("\e[1;1H\e[2J");
		printf("\n\n                                          MENU\n");
        printf("1) Add address\n");
        printf("2) Look up address\n");
        printf("3) Update address\n");
        printf("4) Delete address\n");
        printf("5) Display list\n");
        printf("6) Display aliases for location\n");
        printf("7) Save to file\n");
        printf("8) Quit\n\n");
        printf("\n\nPlease choose an option and enter it's serial number to proceed with that option: ");

		while((inp = getchar()) != EOF)
		{
			if(inp == '\n')
				break;
			else
				input = inp;
		}        

		switch(input-'0')
		{
			case 1:
			{
				printf("\e[1;1H\e[2J");
				add_address(head,&tail);
				if(!head)
					head = tail;
				break;
			}
			case 2:
			{
				printf("\e[1;1H\e[2J");
				lookup_address(head);
				break;
			}
			case 3:
			{
				printf("\e[1;1H\e[2J");
				update_address(head);
				break;
			}
			case 4:
			{
				printf("\e[1;1H\e[2J");
				delete_address(&head);
				break;
			}
			case 5:
			{
				printf("\e[1;1H\e[2J");
				display_list(head);
				break;
			}
			case 6:
			{
				printf("\e[1;1H\e[2J");
				location_alias_link(head);
				break;
			}
            case 7:
            {
                printf("\e[1;1H\e[2J");
                list_to_file(head);
                break;
            }

			case 8:
			{
				exit_program();
			}
			default:
			{
				printf("\n\n+----------------------------------+\n");
				printf("| Please enter a value between 0-8 |\n");
				printf("+----------------------------------+\n\n");
			}
		}
	}
	while(1);

	return 0;

}
