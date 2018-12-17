#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct el {
  float value;
  struct el *prev;
};

void push(float value,struct el **top)
{
  struct el *tmp = malloc(sizeof(struct el));
  tmp->value = value;
  tmp->prev = *top;
  *top = tmp;
}

int pop(float *value,struct el **top)
{
  if(*top){
    struct el *tmp = (*top)->prev;
    *value = (*top)->value;
    free(*top);
    *top = tmp;
    return 1;
  } else {
    return 0;
  }
}


int main(int argc, char *argv[])
{
  struct el *stack = NULL;
  float result;
  
  while(*++argv)
    {
      if (isdigit(**argv) || ((**argv == '-') && (isdigit(*(*argv+1)))))
	{
	  push(atof(*argv),&stack);
	}
      else {
	float val1; 
	float val2;

	if(pop(&val1,&stack) && pop(&val2,&stack))
	  {
	    if(**argv == '+')
	      {
		push(val1+val2,&stack);
	      }
	    else if(**argv == '-')
	      {
		push(val2-val1,&stack);
	      }
	    else if(**argv == '*')
	      {
		push(val1*val2,&stack);
	      }
	    else if(**argv == '/')
	      {
		push(val2/val1,&stack);
	      }
	  }
	else
	  goto end;
      }
    }

  if (pop(&result,&stack))
    {
      fprintf(stdout,"Resultat : %f\n",result);
    }
  else
    {
    end:
      fprintf(stdout,"Stack error\n");
    }
  
  return EXIT_SUCCESS;
}
