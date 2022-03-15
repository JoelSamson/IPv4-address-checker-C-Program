#include<stdio.h>
#include<string.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

//this function would write the contents of the list in the file whose name is entered by the user as a response to prompt
void list_to_file(struct address_t *head)
{
	int  input;
	char temp_arr[50]="";
	int  index=0;
 
	printf("\n\nplease enter the name of the file to which you want the list to be written to: "); 
	
	while((input = getchar()) != EOF)
	{
		if(input == '\n')
		{
			if(!strlen(temp_arr))
			{		
				printf("No file name received, please re-enter the file name: ");
				memset(temp_arr,'\0',sizeof(temp_arr));
				index=0;
				continue;
			}
			else
				break;
		}	
		else
		{
			if(((input >= 'a')&&(input <= 'z'))||((input <= 'Z')&&(input >= 'A'))||((input >= '0')&&(input <= 9))
			  ||(input == '.')||(input == '_'))
			{
				temp_arr[index++] = input;
			}
			else
			{
				while((input = getchar()) != EOF)//clearing the input stream
				{
					if(input == '\n')
						break;
				}
				printf("\n\nError: please enter characters '0-9', 'A/a - Z/z', '.' & '_', please re-enter: ");
				memset(temp_arr,'\0',sizeof(temp_arr));
				index=0;
				continue;
			}
		}
	}
	
	FILE *fptr = fopen(temp_arr,"w");
	if(!fptr)
	{
		printf("\n\n+------------------------------+\n");
		printf("| Error: Unable to create file |\n");
		printf("+------------------------------+\n");
	}	
	else
	{
		while(head)
		{
			fprintf(fptr,"%d.%d.%d.%d %s",head->octet[0], head->octet[1], head->octet[2], head->octet[3], head->alias);
			if(head->next)
				fprintf(fptr,"\n");
			head = head->next;
		}
		printf("\n\n+------------------------------------+\n");
		printf("| Data has been written to the file! |\n");
		printf("+------------------------------------+\n");
		fclose(fptr);
	}
	printf("\n\nEnter any data to go back to the menu: ");
    while((input = getchar()) != EOF)
    {
        if(input == '\n')
            break;
    }
}
