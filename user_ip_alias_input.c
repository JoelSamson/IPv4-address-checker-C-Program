#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"address_t.h"

//HW2_CS531 - Gaurav Singh (G01340489)

/* 
   If `octet_count_indicator` = n -> then this function will accept an input of 'n' octets and return that value.
   Also, it will clear the unwanted characters from the stream before returning the IP address to the callee function.
*/
void user_ip_input(struct address_t* temp, const int octet_count_indicator)
{
	char input_arr[11]="";
	char input_char;
	int  index = 0;
	int  octet_count = 0;
	int  entered_octet_val   = 0;
	

	while((input_char = getchar()) != EOF)
	{
		if((input_char >= '0')&&(input_char <= '9')) //only this block will store any value in `input_arr`
		{
			input_arr[index++] = input_char;
		}
		else if((input_char != '.')||(octet_count == octet_count_indicator -1))
		{				                                 //to handle unwanted characters (characters other then decimal digits and '.')
                                                         //...in the IP address

			if(octet_count == octet_count_indicator - 1) //last octet case
			{
                /*
	               Data validation is done in this block:
				   
							- if some digits have been correctly entered in the last 
							  octet then it will be saved as the value in the octet and 
				              the other unwanted characters will be discarded, then user 
							  will be propted to re-enter
				   
				              example: if 123.43.45.56xyz(newline) has been entered, then 123.43.45.56 
							           will be returned as the entered IP value, rest of the 
									   characters (including newline) will be discarded.
									   
							- if none of the characters entered in the last octet, then this block
							  will prompt the user to enter all the required octets correctly.
							  
							  example: 123.43.45.(newline)
				*/
				
				if(strlen(input_arr)) //few DIGITS are present in the `input_arr`
				{
					entered_octet_val = atoi(input_arr);

					do
                    {
                    	if(input_char == '\n')
                        	break;
                    }
                    while((input_char = getchar()) != EOF);
	
					if(entered_octet_val > 255)
					{
						printf("Error: value of octets should lie between 0 to 255, please re-enter the IP address\n");
						memset(input_arr,'\0',sizeof(input_arr));
						index = 0;
						octet_count = 0;
						temp->octet[0] = temp->octet[1] = temp->octet[2] = temp->octet[3] = -1;
				
						continue;
					}
					temp->octet[octet_count++] = entered_octet_val;
					index = 0;
					break;
				}
				else
				{
						if(input_char != '\n')
						{
							while((input_char = getchar()) != EOF)
							{
								if(input_char == '\n')
									break;
							}
						}
						printf("Error: no digits have been entered in the last octet, please re-enter the address\n");
						memset(input_arr,'\0',sizeof(input_arr));
						index = 0;
						octet_count = 0;
						temp->octet[0] = temp->octet[1] = temp->octet[2] = temp->octet[3] = -1;
				
						continue;
				}
			}
			else
			{
				/*
					this block will handle cases where characters other than digits have been entered before the last octet
					
					example: 123abc(newline)
				*/
			
					do
					{
						if(input_char == '\n')
							break;
					}
					while((input_char = getchar()) != EOF);
					
					printf("Error: please re-enter all the octet values (between 0-255)\n");
					memset(input_arr,'\0',sizeof(input_arr));
					index = 0;
					octet_count = 0;
					temp->octet[0] = temp->octet[1] = temp->octet[2] = temp->octet[3] = -1;
				
					continue;
			}
		}
		if(input_char == '.')       //after encountering the '.' character, the octets needs to be filled with the entered data 
		{				            //...this block does that
			if(input_arr[0] == '\0')
			{
				/*
					This block has been written to handle cases like user input 12..43
                    - consecutive '.' hasn't been mentioned by mistake
               */
				printf("Error: no value has been entered for an octet, please re-enter\n");
				while((input_char = getchar()) != EOF)
                {
                    if(input_char == '\n')
                        break;
                }
                memset(input_arr,'\0',sizeof(input_arr));
                index = 0;
                octet_count = 0;
                temp->octet[0] = temp->octet[1] = temp->octet[2] = temp->octet[3] = -1;

                continue;
			}
			entered_octet_val = atoi(input_arr);

			if(entered_octet_val > 255)
			{
				while((input_char = getchar()) != EOF)
				{
					if(input_char == '\n')
						break;
				}
				printf("Error: value of octets should lie between 0 to 255, please re-enter the IP address\n");
				memset(input_arr,'\0',sizeof(input_arr));
				index = 0;
				octet_count = 0;
				temp->octet[0] = temp->octet[1] = temp->octet[2] = temp->octet[3] = -1;
				
				continue;
			}
			temp->octet[octet_count++] = entered_octet_val;
			memset(input_arr,'\0',sizeof(input_arr));
			index = 0;
		}
	}
}

void user_alias_input(struct address_t* temp)//function to read alias value from user input
{
	char input_arr[11]="";
	int  input_char;
	int  index = 0;
	
	do
	{
		input_char = getchar();
		if((index > 9)&&(input_char != '\n'))
		{
			printf("Error: entered value is greater than 10 characters, please re-enter\n");
			memset(input_arr,'\0',sizeof(input_arr));
			index=0;
			
			while((input_char = getchar()) != EOF)
			{
				if(input_char == '\n')
					break;
			}
			continue;
		}

		if(input_char == EOF)   //This `if` block is for detecting EOF and again restart input by resetting the stream
        {
			printf("Error: please re-enter alias value as end-of-file character has been entered\n");
			memset(input_arr,'\0',sizeof(input_arr));
			index=0;
            clearerr(stdin);
            putchar('\n');
            continue;
        }
		if(input_char == '\n')
		{
			if(strlen(input_arr))
			{
				break;
			}
			else
			{
				printf("Error: no value for alias entered, please re-enter\n");
				memset(input_arr,'\0',sizeof(input_arr));
				index=0;
			}
		}
		else
		{
			input_arr[index++] = input_char;
			if(input_arr[0] == ' ')
			{
				while((input_char = getchar()) != EOF)
				{
					if(input_char == '\n')
						break;
				}
				printf("Error: the first character entered is a space, please re-enter\n");
				memset(input_arr,'\0',sizeof(input_arr));
				index=0;
			}
		}
	}
	while(1);
	strcpy(temp->alias, input_arr);
}
