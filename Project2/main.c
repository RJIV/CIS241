#include "product.h"
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
                    printf("Please enter the product's information.\nFormat: <product_name> <product_unit> <product_price> <product_quantity>\nExample: water gallon 2 2\n");
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
                    printf("This is an empty list.\n");
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
                    printf("This is an empty list.\n");
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
                    printf("This is an empty list.\n");
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
                    printf("This is an empty list.\n");
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
                    printf("This is an empty list.\n");
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
                    printf("The list has been saved to a file.\n");
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

