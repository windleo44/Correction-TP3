#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE_MAX 1024

int main(int argc, char *argv[])
{
  float stack[STACK_SIZE_MAX];
  int position = 0;
  
  for(int i = 1; i < argc ; i++)
    {
      if (isdigit(argv[i][0]) || ((argv[i][0] == '-') && (isdigit(argv[i][1]))))
        {
	  if(position == STACK_SIZE_MAX)
	    {
	      fprintf(stdout,"Stack overflow\n");
	      abort();
	    }
	  else{
	    stack[position++] = atof(argv[i]);
	  }
	}
      else {
	if( argv[i][0] == '+')
          {
	    stack[position-2] += stack[position-1];
          }	
        else if( argv[i][0] == '-')
          {
	    stack[position-2] -= stack[position-1];
          }
        else if( argv[i][0] == '*')
          {
	    stack[position-2] *= stack[position-1];
          }
        else if( argv[i][0] == '/')
          {
	    stack[position-2] /= stack[position-1];
          }
	position--;
      }
    }

  fprintf(stdout,"Resultat : %f\n",stack[--position]);
  return EXIT_SUCCESS;
}
