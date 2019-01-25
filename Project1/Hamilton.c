/***********************************************************************
 * R.J. Hamilton
 * CIS241
 * Project 1
 * October 1, 2018
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf ("Usage: <program> <input_file> key "
			"<output_file> choice(e or d)\n");
        exit(1);
    }

    FILE *in, *out;
    in = fopen(argv[1],"r");
    out = fopen(argv[3],"w");

    if (in == NULL || out == NULL)
    {
        printf("The file can't be opened.");
        exit(1);
    }

    char encryptDecrypt[50];  
    char originalKey[50];     
    char encryptionArray[50]; 
    char decryptionArray[50]; 
    char lowercaseKey[50];     

    strcpy(originalKey, argv[2]);

    strcpy(encryptionArray, originalKey);
    int i;
    int j = 0;
    int index;
    char ch;

    for(i = 0; i < strlen(originalKey); i++)
    {
        if (isupper(originalKey[i]))
        {
	    encryptionArray[i] = encryptionArray[i] + 'a' - 'A';
        }
    }
    
    encryptionArray[i] = '\0';
    
    strcpy(lowercaseKey, encryptionArray); 
	
    for(i = strlen(argv[2]); i < 26;)
    {	
        if (strchr(lowercaseKey, 'z' - j) == NULL) 
        {
            encryptionArray[i] = 'z' - j;
            i++;
            j++;
        } 
        else
        {
            j++;
            continue;
        }
    }
    encryptionArray[i] = '\0';
    
    if (strcmp(argv[4],"e") == 0)
    {
        strcpy(encryptDecrypt, encryptionArray);
    }
    else
    {
        for(i = 0; i < strlen(encryptionArray); i++)
        {
            decryptionArray[encryptionArray[i] - 'a'] = 'a' + i;
        }
        decryptionArray[i] = '\0';
        strcpy(encryptDecrypt, decryptionArray);
    }

    while (fscanf(in, "%c", &ch) != EOF)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) 
        {
            if (islower(ch))
            {
                index = ch - 'a';		
                fprintf(out, "%c", encryptDecrypt[index]);
            }
            else
            {
                index = ch - 'A';
                fprintf(out, "%c", encryptDecrypt[index] + 'A' - 'a');
            }         
        }
        else
        {
            fprintf(out, "%c", ch);
        }        
    }
    fclose(in);
    fclose(out);
    return 0;
}
