 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int arr[3] = { 0 };
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    printf("score1 = %d, score2 = %d, score3 = %d",arr[0],arr[1],arr[2]);
}