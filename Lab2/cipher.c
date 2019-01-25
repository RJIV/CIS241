#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt_decrypt(char ch, int k);

int main(int argc, char* argv[])
{  
	int choice = 0;
	int key = 0;
	int index = 0;
	int length = 0;
	int integer_key[4];
	char string_key[4];
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher inputFile key outputFile option(e or d)\n");
		printf ("Option e for encryption and d for decryption\n");
		exit(1);
	}
	
	if (strlen(argv[2]) != 4)
	{
		printf("The key needs to be four characters long.\n"
			"e.g. FORK\n");
		exit(1);
	}
	
	length = strlen(argv[4]);
	strcpy(string_key, argv[2]);

	for (int i = 0; i < strlen(string_key); i++)
	{
		integer_key[i] = string_key[i] - 'A';
		printf("%d", integer_key[i]);
	}

    	fin = fopen(argv[1], "r");
	fout = fopen(argv[3], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened!\n");
		exit(1);
	}

	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		key = integer_key[index];
		if (strcmp(argv[4],"d")==0)
		{
			key = -key;
		}
		
		index =(index + 1)%4;
		fprintf(fout, "%c", encrypt_decrypt(ch, key));
	}
	
	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt_decrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
}

