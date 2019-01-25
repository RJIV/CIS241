#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PRODUCT_H
#define PRODUCT_H

typedef int ElemType;

struct LNode
{
    char name[100];
    char unit[100];
    ElemType price;
    ElemType quantity;
    struct LNode *next;
};

typedef struct LNode LL;

LL* init(LL *L);

LL* delete(LL *L, char *name);

LL* insert(LL *L, char *name, char *unit, ElemType price, ElemType quantity);

void display(LL *l);

void make_empty(LL *L);

void purchase(LL *l, char *name);

void sell(LL* l, char *name);

int search(LL* l, char *name);

#endif
