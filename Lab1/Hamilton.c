//R.J. Hamilton
//CIS 241-02 Lab 1
//September 7, 2018

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])   
{
      char ch;
      FILE *in, *out;
      in = fopen ("Input.txt","r" );
      out = fopen ("Output.txt", "w" );
      if ( in == NULL || out == NULL )	
      {
	printf ( "file could not be opened!\n" );
	exit (1);
      }
      if (argc > 1)
      {
	printf ("This program does not allow more than one command-line argument!\n");
     	exit (1);
      }
      while ( ! feof(in) )   {
	fscanf ( in, "%c", &ch );
	if (islower(ch))
	{
		ch = toupper(ch);
	}
	else if(isupper(ch))
	{
		ch = tolower(ch);
	}
	fprintf ( out, "%c", ch );
      }
      fclose(in);
      fclose(out);
      return 0;
}
