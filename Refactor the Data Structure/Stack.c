
#include "Stack.h"


void createEmptyStack(ST_stack_t *stack)
{
    stack->top=-1;
}
int8_t push(ST_stack_t *stack, uint8_t data)
{
    if (stack->top ==Stack_size-1)
    {
        return -2;
    }
    else
    {
        stack->top++;
        stack->str[stack->top]=data;
        return 0;
    }

}
int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    if (stack->top==-1)
    {
        return -2;
    }
    else
    {

        *data= stack->str[stack->top];
        stack->top--;
        return 0;
    }
}


int8_t isFull(ST_stack_t *stack)
{
    if (stack->top==Stack_size-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int8_t isEmpty(ST_stack_t *stack)
{
    if (stack->top==-1)
    {
        return -2;
    }
    else
    {
        return 0;
    }
}
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    int8_t Stack_status;
    Stack_status=isEmpty(stack);
    if (Stack_status==-2)
    {
        return -2;
    }
    else
    {
        *topData=stack->str[stack->top];
        return 0;
    }

}
void Stack_Test(void)
{
    int8_t ch;
    uint8_t data;
    int8_t result;
    ST_stack_t * s= malloc(sizeof(ST_stack_t));
    createEmptyStack(s);

    while(1)
    {
        printf ("Enter 0-End 1-push  2-pop  3-print 4-check full  5-check empty  6-getTop\n");
        scanf ("%d",&ch);
        if (ch==1)
        {
            printf("Enter data\n");
            scanf(" %c",&data);
            result=push(s,data);
            if (result==-2)
            {
                printf ("The stack is full\n");
            }
            else
            {
                printf("The data is pushed \n");
            }
            result=-5;
        }
        else if (ch==2)
        {
            result=pop(s,&data);
            if (result==-2)
            {
                printf ("The stack is empty\n");
            }
            else
            {
                printf ("The poped data is %c\n",data);
            }
            result=-5;
        }
        else if (ch==3)
        {
            result=printStack(s);
            if (result==-1)
            {
                printf ("The stack is full\n");
            }
            else if(result==-2)
            {
                printf ("The stack is empty\n");
            }
            result=-5;
        }
        else if (ch==4)
        {
            result=isFull(s);
            if (result==-1)
            {
                printf ("The stack is full\n");
            }
            else
            {
                printf("The Stack may be empty or not \n");
            }
            result=-5;
        }
        else if (ch==5)
        {
            result=isEmpty(s);
            if (result==-2)
            {
                printf ("The stack is empty\n");
            }
            else
            {
                printf("The Stack may be full or not \n");
            }
            result=-5;
        }
        else if (ch==6)
        {
            result= getStackTop(s,&data);
            if (result==-2)
            {
                printf ("The stack is empty\n");
            }
            else if (result==0)
            {
                printf("The top data =%c \n",data);
            }
            result=-5;
        }
        else if (ch==0)
        {
            break;
        }
    }
}
