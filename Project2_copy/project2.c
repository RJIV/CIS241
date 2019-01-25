#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct productNode
{
	char[20] name;
	char[20] units;
	float price;
	int quantity;
	struct product *next;
};


