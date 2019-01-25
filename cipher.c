#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt_decrypt(char ch, int k[], int c);

int main(int argc, char* argv[]) {
    int choice;
    int key[4];
    char ch;
    FILE *fin, *fout;

    if (argc != 5) {
        printf("Usage: cipher inputFile key outputFile option(e or d)\n");
        printf("Option e for encryption and d for decryption");
        exit(1);
    }

    choice = atoi(argv[4]);

    for (int i = 0; i < strlen(argv[2]); i++){
        key[i] = argv[4][i];
        if (choice == 'd') {
            key[i] = -key[i];
        }

    }

        fin = fopen(argv[1], "r");
        fout = fopen(argv[3], "w");

        if (fin == NULL || fout == NULL) {
            printf("File could not be opened!\n");
            exit(1);
        }

        while (fscanf(fin, "%c", &ch) != EOF) {
            fprintf(fout, "%c", encrypt_decrypt(ch, key, choice));
        }

        fclose(fin);
        fclose(fout);

        return 0;
    }

char encrypt_decrypt(char ch, int k[], int c)
{

    int len = sizeof(k) / sizeof(int);
    //encryption
    for (int i = 0; i < len; i++) {
        if ( k[i] < 0)
            k[i] = k[i] + 26;
        if ( isupper(ch) )
            return  (ch - 'A'+ k[i]) % 26 + 'A';
        if ( islower(ch) )
                return  (ch - 'a' + k[i]) % 26 + 'a';
    }

}




