 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    printf("The size of short is %u bytes.\nThe size of int is %u bytes.\nThe size of long is %u bytes.\nThe size of long long is %u bytes.\n", sizeof(short), sizeof(int), sizeof(long), sizeof(long long));

    return 0;
}   