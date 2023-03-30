#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define Stack_size   10

typedef   signed short     int8_t;
typedef   char           uint8_t;
typedef struct
{
    uint8_t str[Stack_size];
    int8_t top;

} ST_stack_t;

void createEmptyStack(ST_stack_t *stack);
int8_t push(ST_stack_t *stack, uint8_t data);
int8_t pop(ST_stack_t *stack, uint8_t *data);

int8_t isFull(ST_stack_t *stack);
int8_t isEmpty(ST_stack_t *stack);
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
void Stack_Test(void);



#endif
