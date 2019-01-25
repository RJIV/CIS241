#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PRODUCT_H
#define PRODUCT_H

struct ProductNode
{
	char name[20];
	char units[20];
	int price;
	int quantity;
	struct ProductNode *next;
};

typedef struct ProductNode linkedList;

linkedList* init(linkedList *list);

linkedList* insert(linkedList *list, char *name, char *units, int price, int quantity);

linkedList* delete(linkedList *list, char *name);

void deleteList(linkedList *list);

void search(linkedList *list, char *name);

void display(linkedList *list);

void purchase(linkedList *list, char *name);

void sell(linkedList *list, char *name);

#endif
