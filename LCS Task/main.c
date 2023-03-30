#include <stdio.h>
#include <stdlib.h>
#define array_Size  10
typedef unsigned char  uint8_t;
typedef signed short   int8_t;
typedef signed int     int32_t;

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

int main()
{
    uint8_t arraySize;
    uint8_t ch;
    uint8_t check;
    uint8_t i=0;
    uint8_t LCSSize;
    int8_t array_status;
    int32_t *arr;

    while (1)
    {
        printf ("0-End   1-Test the sorted function    2-LCS test cases\n");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter the size of array \n");
            scanf("%d",&arraySize);
            arr=(int32_t*)malloc(sizeof(int32_t)*arraySize);
            if (arraySize>0)
            {
                printf("enter array element \n");
            }
            for (i=0; i<arraySize; i++)
            {
                scanf("%d",&arr[i]);
            }
            array_status=insertionSort(arr,arraySize);
            if (array_status==-1)
            {
                printf("The array is empty\n");
            }
            else if (array_status==-2)
            {
                printf("The array is oversize\n");
            }
            else
            {
                printArray(arr,arraySize);
            }

        }
        else if (ch==2)
        {
            printf ("Enter the number of test case\n");
            scanf("%d",&check);
            while (1)
            {
                if (check==1)
                {
                    printf("Test case 1\n");
                    arraySize=10;
                    printf("The size of array = %d\n",arraySize);
                    int32_t array[]= {9,0,7,5,3,8,-10,4,2,1};
                    printf ("Array is ");
                    printArray(array,arraySize);
                    insertionSort(array,arraySize);
                    printf ("The sorted Array is");
                    printArray(array,arraySize);
                    array_status=lcsGetSize(array,arraySize,&LCSSize);
                    if (array_status==-1)
                    {
                        printf("The array is empty\n");
                    }
                    else if (array_status==-2)
                    {
                        printf("The size of array>10\n");
                    }
                    else if (array_status==-3)
                    {
                        printf("The size of LCS=%d\n",0);
                    }
                    else
                    {
                        printf("The size of LCS=%d\n",LCSSize);
                    }
                    LCSSize=0;
                    check=2;
                    printf("************************\n");
                }
                else if (check ==2)
                {
                    printf("Test case 2\n");
                    printf("The array is empty\n");
                    arraySize=0;
                    int32_t array[]= {0};
                    printArray(array,arraySize);
                    array_status=lcsGetSize(array,arraySize,&LCSSize);
                    if (array_status==-1)
                    {
                        printf("The array is empty\n");
                    }
                    else if (array_status==-2)
                    {
                        printf("The size of array>10/=0\n");
                    }
                    else if (array_status==-3)
                    {
                        printf("The size of LCS=%d\n",0);
                    }
                    else
                    {
                        printf("The size of LCS=%d\n",LCSSize);
                    }
                    printf("************************\n");
                    LCSSize=0;
                    check=3;
                }
                else if (check==3)
                {
                    printf("Test case 3\n");
                    arraySize=12;
                    printf("The size of array = %d\n",arraySize);
                    int32_t array[]= {9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12};
                    printf ("Array is ");
                    printArray(array,arraySize);
                    insertionSort(array,arraySize);
                    printf ("The sorted Array is");
                    printArray(array,arraySize);
                    array_status=lcsGetSize(array,arraySize,&LCSSize);
                    if (array_status==-1)
                    {
                        printf("The array is empty\n");
                    }
                    else if (array_status==-2)
                    {
                        printf("The size of array>10\n");
                    }
                    else if (array_status==-3)
                    {
                        printf("The size of LCS=%d\n",0);
                    }
                    else
                    {
                        printf("The size of LCS=%d\n",LCSSize);
                    }
                    printf("************************\n");
                    LCSSize=0;
                    check=4;

                }
                else if (check==4)
                {
                    printf("Test case 4\n");
                    arraySize=10;
                    printf("The size of array = %d\n",arraySize);
                    int32_t array[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
                    printf ("Array is ");
                    printArray(array,arraySize);
                    insertionSort(array,arraySize);
                    printf ("The sorted Array is");
                    printArray(array,arraySize);
                    array_status=lcsGetSize(array,arraySize,&LCSSize);
                    if (array_status==-1)
                    {
                        printf("The array is empty\n");
                    }
                    else if (array_status==-2)
                    {
                        printf("The size of array>10\n");
                    }
                    else if (array_status==-3)
                    {
                        printf("The size of LCS=%d\n",0);
                    }
                    else
                    {
                        printf("The size of LCS=%d\n",LCSSize);
                    }
                    printf("************************\n");
                    LCSSize=0;
                    check =5;

                }
                else if (check==5)
                {
                    printf("Test case 5\n");
                    arraySize=10;
                    printf("The size of array = %d\n",arraySize);
                    int32_t array[]= {2, 8, 4, 10, 6, 20, 16, 12, 14, 16};
                    printf ("Array is ");
                    printArray(array,arraySize);
                    insertionSort(array,arraySize);
                    printf ("The sorted Array is");
                    printArray(array,arraySize);
                    array_status=lcsGetSize(array,arraySize,&LCSSize);
                    if (array_status==-1)
                    {
                        printf("The array is empty\n");
                    }
                    else if (array_status==-2)
                    {
                        printf("The size of array>10\n");
                    }
                    else
                    {
                        printf("The size of LCS=%d\n",LCSSize);
                    }
                    printf("************************\n");
                    printf("************The LCS Test Cases finished************\n");
                    check=0;
                }
                else if (check==0)
                {
                    break;
                }
            }

        }
        else
        {
            break;
        }
    }

    return 0;
}










/****************************Test cases**************************************/
/*
1. Test Case 1
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1]
- Print the LCS size
2. Test Case 2
- Ask the user to enter array elements
- Press Enter without entering any element
3. Test Case 3
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12]
4. Test Case 4
- Ask the user to enter array elements
- Enter the following elements
- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
- Print the LCS size
5. Test Case 5
- Ask the user to enter array elements
- Enter the following elements
- [2, 8, 4, 10, 6, 20, 16, 12, 14, 16]
*/
/*******************************************************************************/
