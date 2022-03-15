#ifndef ADDRESS_T_H
#define ADDRESS_T_H

//HW2_CS531 - Gaurav Singh (G01340489)

struct address_t
{
	int  octet[4];
    char alias[11];
    struct address_t *next;
};

#endif
