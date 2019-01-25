#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

//Initialize an empty list
LL* init(LL *L)
{
    if(L!=NULL)
        free(L);
    L= (LL*)malloc(sizeof(LL));
    if(L==NULL)
        exit(1);
    L->next=NULL;
    printf("An empty list has been created.\n");
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
    printf("The list is：\n");
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

int main()
{ 
    LL *L=NULL;
    FILE *in, *out;
    int option;
    char c;
    char name[100], unit[100];
    int price,quantity;
    while(1)
    {
        option = 0;
        printf("\n1: Create an empty list    2: Insert a product \n3: Delete a product        4: Delete the entire list  \n5: Search a product        6: Display products in the list \n7: Purchase a product      8: Sell a product \n9: Save to file            0: Exit\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                L = init(L);
             //   list_print(L) ;
             //   printf("An empty list has been created!\n");
                break;

            case 2:
                if(L!=NULL)
                {
                    printf("Please enter the product's information. Example: <product_name> <product_unit> <product_price> <product_quantity>\n\nExample: water gallon 2 2\n");
                    scanf("%s %s %d %d", name, unit, &price, &quantity);
                    if(search(L, name) == 1)
                    {
                        printf("This product already exists!\n");
                    }
                    else
                    {
                        L = insert(L,name,unit,price,quantity);
                    }
                }
                else
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");
                }
                break;

            case 3:
                if (L==NULL)
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");;
                }
                else if(L->next!=NULL)
                {
                    printf("Please enter the product's name:\n");
                    scanf("%s", name);
                    delete(L,name);
                }
                
                else if (L->next == NULL)
                {
                    printf("This list is empty.\n");
                }
                break;

            case 4:
                if (L==NULL)
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");
                }
                else if (L->next!=NULL)
                {
                    make_empty(L);
                    L=NULL;
                    printf("The entire list has been deleted!\n");
                }
                
                else if (L->next == NULL)
                {
                    printf("This list is empty.\n");
                }
                break;

            case 5:
                if (L==NULL)
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");
                }
                else if (L->next!=NULL)
                {
                    printf("Please enter the product's name:\n");
                    scanf("%s", name);
                    search(L,name);
                }
                else if (L->next==NULL)
                {
                    printf("This list is empty.!\n");
                }
                break;

            case 6:
                if(L!=NULL)
                    display(L);
                else
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");
                }
                break;
                
            case 7:
                if (L==NULL)
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");
                }
                else if (L->next!=NULL)
                {
                    printf("Please enter the product's name:\n");
                    scanf("%s", name);
                    purchase(L,name);
                }
                else if (L->next==NULL)
                {
                    printf("This list is empty.\n");
                }
                break;
                

            case 8:
                if (L==NULL)
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");
                }
                else if (L->next!=NULL)
                {
                    printf("Please enter the product's name:\n");
                    scanf("%s", name);
                    sell(L,name);
                }
                else if (L->next==NULL)
                {
                    printf("This list is empty.\n");
                }
                break;

            case 9:
            {
                out=fopen("list.txt","w");
                if (out==NULL)
                {
                    printf("Cannot open the output file!\n");
                }
                if (L==NULL)
                {
                    printf("The list does not exist. Please press 1 to initialize!\n");
                }
                else
                {
                    LL *p=L->next;
                    while(p!=NULL)
                    {
                        fprintf(out,"%s ",p->name);
                        fprintf(out,"%s ",p->unit);
                        fprintf(out,"%d ",p->price);
                        fprintf(out,"%d \n",p->quantity);
                        p=p->next;
                    }
                    fclose(out);
                    printf("The list has been saved to a file!\n");
                }
                break;
            }
                
            case 0:
                if(L!=NULL)
                    make_empty(L);
                L = NULL;
                exit(1);
                
            default:
                exit(1);
        }
    }
    return 1;
}
