#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
  float *stack_top = malloc((argc-1)*sizeof(float));
  
  for(int i = 1; i < argc ; i++)
    {
      if (isdigit(*argv[i]) || ((*argv[i] == '-') && (isdigit(*(argv[i]+1)))))
	{
	  *stack_top++ = atof(argv[i]);
	}
      else {
	float val1 = *--stack_top;
	float val2 = *--stack_top;

	if( *argv[i] == '+')
	  {
	    *stack_top++ = (val1 + val2);
	  }
	else if( *argv[i] == '-')
	  {
	    *stack_top++ = (val2 - val1);
	  }
	else if( *argv[i] == '*')
	  {
	    *stack_top++ = (val1 * val2);
	  }
	else if( *argv[i] == '/')
	  {
	    *stack_top++ = (val2 / val1);
	  }
      }
    }

  fprintf(stdout,"Resultat : %f\n",*--stack_top);
  free(stack_top);
  
  return EXIT_SUCCESS;
}
