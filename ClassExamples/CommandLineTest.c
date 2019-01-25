#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])   
{
      char ch;
      FILE *in, *out;
      in = fopen ("1.txt","r" );
      out = fopen ("2.txt", "w" );
      if ( in == NULL || out == NULL )	
      {
	printf ( "file could not be opened!\n" );
	exit (1);
      }
      if ( argc != 3 )
      {
	      printf("This command must have two command-line arguments");
      }
      
      printf("%d\n%s\n%s\n%s\n", argc, argv[0], argv[1], argv[2]);

      fclose(in);
      fclose(out);
      return 0;
}
