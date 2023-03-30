#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "LCS.h"
#include "main.h"

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









