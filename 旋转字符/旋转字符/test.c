 #define _CRT_SECURE_NO_WARNINGS 1

void rotate(int* nums, int numsSize, int k) {
    int tmp = k;
    int i = 0;
    int new_arr[1000] = { 0 };
    int n = (numsSize - k);

    while (tmp--)
    {
        new_arr[i] = nums[numsSize - i - 1];

        i++;

    }
    int t = n;
    i = 0;
    while (t--)
    {
        nums[numsSize - i - 1] = nums[n - i - 1];
        i++;
    }
    i = 0;
    tmp = k;
    while (tmp--)
    {
        nums[k - i - 1] = new_arr[i];
        i++;
    }

}
#include<stdio.h>
int main()
{
    int arr[6] = { 1,2,3,4,5,6 };
    int k = 0;
    scanf("%d", &k);
    int sz = sizeof(arr) / sizeof(arr[0]);
    rotate(arr,sz,k);
    int i = 0;
    while (sz--)
    {
        printf("%d ", arr[i++]);
    }
	return 0;
}