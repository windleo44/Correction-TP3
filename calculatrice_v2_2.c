#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int tree_height(char **argv)
{
  int height = 0;
  int temp = 0;
  while(*++argv)
    if (isdigit(**argv) || ((**argv == '-') && (isdigit(*(*argv+1)))))
      temp = 0;
    else 
      if(++temp > height)
	height = temp;
  return (height + 1);
}

int main(int argc, char *argv[])
{
  int height = tree_height(argv);  
  float *stack_top = malloc(height*sizeof(float));
    
  while(*++argv)
    {
      if (isdigit(**argv) || ((**argv == '-') && (isdigit(*(*argv+1)))))
	{
	  *stack_top++ = atof(*argv);
	}
      else {
	float val1 = *--stack_top;
	float val2 = *--stack_top;
	
	if(**argv == '+')
	  {
	    *stack_top++ = (val1 + val2);
	  }
	else if (**argv == '-')
	  {
	    *stack_top++ = (val2 - val1);
	  }
	else if (**argv == '*')
	  {
	    *stack_top++ = (val1 * val2);
	  }
	else if (**argv == '/')
	  {
	    *stack_top++ = (val2 / val1);
	  }
      }      
    }
  
  fprintf(stdout,"Resultat : %f\n",*--stack_top);
  free(stack_top);
  
  return EXIT_SUCCESS;
}
