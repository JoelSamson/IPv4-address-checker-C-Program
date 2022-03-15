#include<stdio.h>
#include<string.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

int  to_lower(unsigned char);//to convert case to lower
int  case_insensitive_cmp(const char*, const char*);//to compare two characters in case insensitive way

//`ind` = 0 then only IP address will be searched, `ind` = 1 - then only alias value will be searched
struct address_t* search(struct address_t *head, struct address_t *temp, int ind)//temp will contain user entered IP/alias
{
	char arr[8]="";
	if(head)
	{
		if(ind == 3)
		{
			sprintf(arr,"%d.%d",temp->octet[0],temp->octet[1]);
			printf("\n+-----------------------------------+\n");
			printf("| Alias list for location - %-7s |",arr);
			printf("\n+-----------------------------------+\n");
		}
		while(head)
		{
			if((ind == 1)&&(!case_insensitive_cmp(head->alias, temp->alias))) //searching for alias
			{	
				return head;
			}
			if((ind == 0)&&((head->octet[0] == temp->octet[0])&&           //searching for all 4 octets of IP
				      		     (head->octet[1] == temp->octet[1])&&
					    	     (head->octet[2] == temp->octet[2])&&
			   			         (head->octet[3] == temp->octet[3])))
			{
				return head;
            }
			if(ind == 3) //searching & printing all the aliases for a location entered by the user
			{
				if((head->octet[0] == temp->octet[0])&&(head->octet[1] == temp->octet[1]))
				{
					printf("|             %-10s            |\n",head->alias);
					printf("+-----------------------------------+\n");

				}
			}
			head = head->next;
		}
	}

	return head; 
}

//-----> `to_lower` converts the case of upper case characters to lower 
int to_lower(unsigned char chr) 
{
    if (chr >= 'A' && chr <= 'Z')
        chr = 'a' + (chr - 'A');
    return chr;
}


//-----> `case_insensitive_cmp` is for comparing two strings without case sensitivity
int case_insensitive_cmp(const char *str1, const char *str2)
{
    const char* ptr1 = str1;
    const char* ptr2 = str2;

    if(strlen(ptr1) != strlen(ptr2))
        return 1;

    while(to_lower(*ptr1) == to_lower(*ptr2))
    {
        ptr1++;
        ptr2++;
        if((*ptr1 == '\0')||(*ptr2 == '\0'))
            break;
    }

    if(*ptr1 != *ptr2)
        return 1;

    return 0;
}
