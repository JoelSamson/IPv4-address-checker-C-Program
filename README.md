# IPv4 Address Management System

This project is a command-line based IPv4 address management system implemented in C. It allows users to efficiently store, update, search, and delete IPv4 addresses along with their associated aliases (nicknames). The system is designed to handle IPv4 addresses represented in dotted decimal notation and manages them using a singly linked list data structure.

## Overview

IPv4 addresses, along with their corresponding aliases, are stored in a linked list. The program provides a user-friendly menu-driven interface for managing these address-alias pairs. Users can add new addresses, look up addresses using aliases, update existing entries, delete entries, display the list of stored pairs, find aliases associated with specific locations, save the list to a file, and quit the program.

## Linked List Structure

The linked list is defined as follows:

```c
struct address_t {
    int octet[4];
    char alias[11];
    struct address_t *next;
};

struct address_t *head = NULL;
```

In this structure:

- **Data**: Each node stores an IPv4 address (divided into four octets) and an associated alias (up to 10 characters long).
- **Reference (Pointer)**: The `next` pointer points to the next node in the list, forming a chain-like structure.

Using a **singly linked list** allows for dynamic allocation of memory, making it suitable for handling a variable number of address-alias pairs. It also simplifies insertion and deletion operations, making the management of address-alias pairs more efficient.



## File Structure

- **add_address.c**: Contains functions to add a new IPv4 address and alias pair.
- **delete_address.c**: Implements the deletion of an address-alias pair.
- **display_list.c**: Displays the list of stored address-alias pairs.
- **exit_program.c**: Handles program termination.
- **list_to_file.c**: Saves the current list to a file.
- **location_alias_link.c**: Provides functionalities related to location-based alias lookup.
- **lookup_address.c**: Looks up an alias and displays the corresponding IPv4 address.
- **main.c**: Main program file containing the user interface and menu logic.
- **user_ip_alias_input.c**: Contains functions for user input validation.
- **update_address.c**: Implements updating an existing address-alias pair.

## Usage

The program provides various functionalities:

- **Add Address**: Add a new IPv4 address and alias pair.
- **Look up Address**: Look up an alias to find the corresponding IPv4 address.
- **Update Address**: Update an existing alias's corresponding IPv4 address.
- **Delete Address**: Delete an address-alias pair.
- **Display List**: Display all stored address-alias pairs.
- **Display Aliases for Location**: List aliases associated with a specific location.
- **Save to File**: Save the current list to a file.
- **Quit**: Exit the program.

## How to Run

To compile the project, use the provided **Makefile**:

```bash
make
```

This will compile the source files and create an executable named **lList**. To run the program, use the following command:

```bash
./lList
```

## Contributing

Contributions are welcome! Please follow the existing code style and create a pull request for any new features or bug fixes.

## Screenshots

-**Main Menu**:

<img width="575" alt="Screenshot 2023-10-11 at 7 01 41 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/caa83b8e-83b1-49dd-9583-5000e3297f47">

-**Add Address**:

<img width="569" alt="Screenshot 2023-10-11 at 7 03 49 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/683b3e4f-0d01-4555-a668-966e620f0d30">
<img width="570" alt="Screenshot 2023-10-11 at 7 05 16 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/4df9750d-d9f2-47e5-a0a7-c3be471f671c">
<img width="569" alt="Screenshot 2023-10-11 at 7 06 08 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/2f25ee1a-e492-42d6-b43e-e4e05b5a6ce7">

-**Look up Address**:

<img width="464" alt="Screenshot 2023-10-11 at 7 07 24 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/dfa9ac4f-95d6-430e-b405-e2f7d1e696a6">
<img width="462" alt="Screenshot 2023-10-11 at 7 18 40 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/b39f4f0d-9297-4db1-bb31-643a59c49ccc">


-**Update Address**:

<img width="460" alt="Screenshot 2023-10-11 at 7 16 34 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/db098cdb-94f8-488d-be3f-dd59ceed2b60">
<img width="464" alt="Screenshot 2023-10-11 at 7 17 19 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/aca95089-53d2-48be-8f98-2a28dfd4689a">

-**Delete Address**:

<img width="455" alt="Screenshot 2023-10-11 at 7 20 12 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/aec3c637-09f7-472d-9d56-8cf8705570d9">
<img width="460" alt="Screenshot 2023-10-11 at 7 20 47 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/916a5b04-9e32-49db-aef6-6dc410fd5102">

-**Display List**:

<img width="465" alt="Screenshot 2023-10-11 at 7 21 55 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/f87ac03a-e2b0-4109-bd58-6b6e54a8ecfd">

-**Display Aliases for Location**:

<img width="464" alt="Screenshot 2023-10-11 at 7 23 54 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/9545caa3-628a-4f4d-a50c-b542906d05de">
<img width="455" alt="Screenshot 2023-10-11 at 7 24 50 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/38ead3b9-d6cf-4b2d-a496-f9449bca15f7">

-**Save to file**:

<img width="450" alt="Screenshot 2023-10-11 at 7 26 30 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/eb12d1ff-883f-4ae1-8666-6a8841b82c84">
<img width="681" alt="Screenshot 2023-10-11 at 7 28 44 PM" src="https://github.com/JoelSamson/IPv4-address-checker-C-Program/assets/55976489/f6e545ee-0ed9-4a93-9d66-16d1f96b4c2c">

The linked list is defined as follows:

```c
struct address_t {
    int octet[4];
    char alias[11];
    struct address_t *next;
};

struct address_t *head = NULL;
```

In this structure:

- **Data**: Each node stores an IPv4 address (divided into four octets) and an associated alias (up to 10 characters long).
- **Reference (Pointer)**: The `next` pointer points to the next node in the list, forming a chain-like structure.

Using a **singly linked list** allows for dynamic allocation of memory, making it suitable for handling a variable number of address-alias pairs. It also simplifies insertion and deletion operations, making the management of address-alias pairs more efficient.





