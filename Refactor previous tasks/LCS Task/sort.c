

#include"sort.h"


int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
    uint8_t i=0;
    uint8_t j=0;
    uint8_t temp=0;
    uint8_t sorted_flag=0;
    if (array[0]==0&&array[1]==0)
    {
        return -1;
    }
    else if (arraySize>array_Size||arraySize==0)
    {
        return -2;
    }
    while (j<arraySize)
    {
        sorted_flag=1;
        for (i=0; i<arraySize-1-j; i++)
        {
            if (array[i]>array[i+1])
            {
                temp= array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                sorted_flag =0;
            }
        }
        if (sorted_flag==1)
        {
            return 0;
        }
        j++;
    }
}
void printArray(int32_t *array, uint8_t arraySize)
{
    uint8_t i=0;
    printf (" [ ");
    for (i=0; i<arraySize; i++)
    {
        printf("%d, ",array[i]);
    }
    printf (" ]\n");
}
