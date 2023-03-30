

#include"Paranthethes.h"


int8_t isBalancedParanthethes(uint8_t *expression)
{
    if (expression[0]=='}'||expression[0]==')')
    {
        return -1;
    }
    ST_stack_t * expression_stack= malloc(sizeof(ST_stack_t));
    createEmptyStack(expression_stack);
    uint8_t check=0;
    uint8_t flag=0;
    uint8_t flag_1=0;
    uint8_t flag_2=0;
    uint8_t i=0;
    uint8_t data;
    int8_t Stack_Status;

    for (i=0; expression[i]; i++)
    {
        if (expression[i]=='{'||expression[i]=='(')
        {
            push(expression_stack,expression[i]);
        }
        else if (expression[i]=='}'||expression[i]==')')
        {
            Stack_Status= pop(expression_stack,&data);
            if (Stack_Status==-2)
            {
                return -2;
            }
            else
            {
                if (expression[i]=='}')
                {
                    if (data!='{')
                    {
                        return -1;
                    }
                }
                else if (expression[i]==')')
                {
                    if (data!='(')
                    {
                        return -1;
                    }
                }
            }
        }

        else if (expression[i]=='['||expression[i]==']')
        {
            return -2;
        }
    }

    return 0;

}
