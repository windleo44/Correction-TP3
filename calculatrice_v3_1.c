#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct el {
  float value;
  struct el *prev;
};

struct el *push(float value,struct el *top)
{
  struct el *tmp = malloc(sizeof(struct el));
  tmp->value = value;
  tmp->prev = top;
  return tmp;
}

struct el *pop(float *value,struct el *top)
{
  struct el *tmp = NULL;
  if(top){
    tmp = top->prev;
    *value = top->value;
    free(top);
  }

  return tmp;
}


int main(int argc, char *argv[])
{
  struct el *stack = NULL;
  float resultat = 0;
  
  while(*++argv)
    {
      if (isdigit(**argv) || ((**argv == '-') && (isdigit(*(*argv+1)))))
	{
	  stack = push(atof(*argv),stack);
	}
      else {
	float val1 = 0;
	float val2 = 0;
	
	stack = pop(&val1,stack);
	stack = pop(&val2,stack);
	
	if( **argv == '+')
	  {
	    stack = push(val1+val2,stack);
	  }
	else if( **argv == '-')
	  {
	    stack = push(val2-val1,stack);
	  }
	else if( **argv == '*')
	  {
	    stack = push(val1*val2,stack);
	  }
	else if( **argv == '/')
	  {
	    stack = push(val2/val1,stack);
	  }
      }
    }	          
  
  stack = pop(&resultat,stack);
  fprintf(stdout,"Resultat : %f\n",resultat);
  
  return EXIT_SUCCESS;
}
