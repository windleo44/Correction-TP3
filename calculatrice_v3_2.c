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

float pop(struct el **top)
{
  if(*top){
    float val;
    struct el *tmp = (*top)->prev;
    val = (*top)->value;
    free(*top);
    *top = tmp;
    return val;
  } else {
    fprintf(stdout,"Pile vide !\n");
    exit(0);
  }
}


int main(int argc, char *argv[])
{
  struct el *stack = NULL;
  
  while(*++argv)
    {
      if (isdigit(**argv) || ((**argv == '-') && (isdigit(*(*argv+1)))))
	{
	  push(atof(*argv),&stack);
	}
      else {
	float val1 = pop(&stack);
	float val2 = pop(&stack);
	
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
    }

  fprintf(stdout,"Resultat : %f\n",pop(&stack));
  
  return EXIT_SUCCESS;
}
