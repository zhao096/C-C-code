 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int maxRotateFunction(int* nums, int numsSize) {
    int number[1000] = {0};
    int n_size = numsSize;
    while (n_size--)
    {
        int tmp = nums[numsSize - 1];
        int i = 0;
        for (i = numsSize - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1];
        }
        nums[i] = tmp;
        for (int p = 0; p < numsSize; p++)
        {
            number[n_size] += (nums[p] * p);
        }
    }
    int max = -100000;
    for (int i = 0; i < numsSize; i++)
    {
        if (max < number[i])
        {
            max = number[i];
        }
    }
    return max;

}
int main() {

    int arr[4] = { 4,3,2,6 };
    maxRotateFunction(arr, 4);
    return 0;
}