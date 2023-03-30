#include <stdio.h>
#include <stdlib.h>
#include"stack.h"
#include"paranthethes.h"

int8_t printStack(ST_stack_t *stack)
{
    if (stack->top==Stack_size-1)
    {
        for ( uint8_t i=stack->top; i>=0; i--)
        {
            printf("%c\n",stack->str[i]);
        }
        return -1;
    }
    else if (stack->top==-1)
    {
        return -2;
    }

    for ( int8_t i=stack->top; i>=0; i--)
    {
        printf("%c\n",stack->str[i]);
    }

    return 0;
}


int main()
{

    uint8_t check;
    uint8_t expression[expression_Size];
    int8_t result;
    while (1)
    {
        printf("0-End the test      1-Test the stack       2-Test if expression is balance or not\n");
        scanf("%d",&check);
        if (check==1)
        {
            Stack_Test();
        }
        else if (check==2)
        {
            printf("Enter your expression\n");
            scanf(" %[^\n]s",expression);
            printf("%s\n",expression);
            result=isBalancedParanthethes(expression);
            if (result==0)
            {
                printf ("the parentheses are balanced\n");
            }
            else if (result==-1)
            {
                printf ("the parentheses are not balanced\n");
            }
            else if (result==-2)
            {
                printf("the neither of parenthese is used\n");
            }
        }
        else
        {
            break;
        }

    }

    return 0;
}


