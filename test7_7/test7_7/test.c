#include <stdio.h>
int missingNumber(int* nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += *(nums + i);
    }
    for (int i = 0; i <= numsSize; i++)
    {
        sum -= i;
    }
    return -sum;
}
int main()
{
    int a[11] = { 3,0,1,2,5,6,11,10,8,7,9 };
    int size = sizeof(a)/sizeof(0); 
    missingNumber(a, size);
    return 0;
}