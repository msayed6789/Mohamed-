
#include"LCS.h"


int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    uint8_t max=0;
    uint8_t count=0;
    uint8_t i=0;
    uint8_t j=0;
    int8_t array_Status;
    array_Status=insertionSort (array,arraySize);
    if (array_Status==-1)
    {
        return -1;
    }
    else if (array_Status==-2)
    {
        return -2;
    }
    for (i=0; i<arraySize; i++)
    {
        if (array[i+1]-array[i]==1)
        {
            count++;
        }
        else
        {
            if (max<count)
            {
                max=count+1;
            }
            count=0;
        }

    }
    if (max==0)
    {
        return -3;
    }
    *sizeofLCS=max;
}
