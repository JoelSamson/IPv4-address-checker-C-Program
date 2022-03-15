a.out: main.o add_address.o delete_address.o display_list.o exit_program.o list_to_file.o location_alias_link.o lookup_address.o search.o update_address.o user_ip_alias_input.o
	gcc -Wall -o a.out main.c add_address.c delete_address.c display_list.c exit_program.c list_to_file.c location_alias_link.c lookup_address.c search.c update_address.c user_ip_alias_input.c

clean:
	rm *.o a.out
