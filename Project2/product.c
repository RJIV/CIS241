#include "product.h"

LL* init(LL *L)
{
    if(L!=NULL)
        free(L);
    L= (LL*)malloc(sizeof(LL));
    if(L==NULL)
        exit(1);
    L->next=NULL;
    printf("An empty list has been created!\n");
    return L;
}

//Delete a product
LL* delete(LL *L,char *name)
{
    LL *p,*q;
    p = L;
    while (p->next!=NULL)
    {
        if (strcmp(p->next->name, name)==0)
        {
            q=p->next;
            p->next=q->next;
            free(q);
            printf("Product %s has been deleted!\n", name);
            return L;
        }
        p = p->next;
    }
    if (p->next==NULL)
    {
        printf("\"%s\" does not exist!\n", name);
    }
    return L;
}

//Insert a product
LL* insert(LL *L,char *name,char *unit,ElemType price,ElemType quantity)
{
    if (quantity<=0)
    {
        printf("The quantity of a product should be greater than 0!\n");
        return L;
    }
    if (price<=0)
    {
        printf("The price of a product should be greater than 0!\n");
        return L;
    }
    LL *q;
    q=(LL*)malloc(sizeof(LL));
    q->price=price;
    q->quantity=quantity;
    
    strcpy(q->name, name);
    strcpy(q->unit, unit);
    
    q->next = L->next;
    L->next = q;
    printf("Product %s has been inserted!\n", name);
    return L;
}

//Display the list
void display(LL* l)
{
    LL *p = l;
    printf("The list contains：\n");
    while(p->next!=NULL)
    {
        printf("%s %s %d %d\n", p->next->name, p->next->unit, p->next->price, p->next->quantity);
        p=p->next;
    }
}

//Delete the entire list
void make_empty(LL *L)
{
    while(L!=NULL)
    {
        LL *p=L;
        L=L->next;
        free(p);
    }
}

//Purchase a product
void purchase(LL* l, char *name)
{
    LL *p = l;
    while(p->next!=NULL)
    {
        if(strcmp(p->next->name,name)==0)
        {
            p->next->quantity+=1;
            printf("%s %s %d %d\n", p->next->name, p->next->unit, p->next->price, p->next->quantity);
            return;
        }
        p=p->next;
    }
    if (p->next==NULL)
    {
        printf("\"%s\" does not exist!\n", name);
        return;
    }
}

//Sell a product
void sell(LL* l,char *name)
{
    LL* p=l;
    //   printf("Please enter the product's name!\n");
    while(p->next!=NULL)
    {
        if(strcmp(p->next->name,name)==0)
        {
            p->next->quantity-=1;
            printf("%s %s %d %d\n", p->next->name, p->next->unit, p->next->price, p->next->quantity);
            if (p->next->quantity<=0)
            {
                delete(l,name);
            }
            return;
        }
        p=p->next;
    }
    if (p->next==NULL)
    {
        printf("\"%s\" does not exist!\n", name);
        return;
    }
}

//Search a product
int search(LL* l,char *name)
{
    if(l==NULL)
        printf("The list has not been created! Please press 1 to initialize!\n");
    else
    {
        LL* p = l;
        while(p->next!=NULL)
        {
            if(strcmp(p->next->name,name)==0)
            {
                printf("Found: %s %s %d %d\n", p->next->name, p->next->unit, p->next->price, p->next->quantity);
                return 1;
            }
            p=p->next;
        }
        if (p->next==NULL)
        {
            printf("\"%s\" does not exist!\n", name);
            return 0;
        }
    }
}
