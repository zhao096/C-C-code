 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//  char * longestCommonPrefix(char ** strs, int strsSize){
//      if(strsSize == 1)
//         return strs[0];
//     int min = 0;
//     for(int i =0 ; i < strsSize ; i++)
//     {
//         if(strlen(strs[min]) > strlen(strs[i]))
//         {
//             min = i;
//         }
//     }
//     int len = strlen(strs[min]);
//     for(int i = len; i >0 ;i--)
//     {
//         strs[min][i] = '\0';
//         int tag = 0;
//         for(int j = 0; j < strsSize ; j++)
//         {
//             if(j == min)
//                 continue;
//             if(strstr(strs[j],strs[min]) != NULL)
//                 tag++;
//         }
//         if(tag == i)
//             return strs[min];
//         tag = 0;
//     }
//     return "";
// }


char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 1)
        return strs[0];
    int i = 0;
    int j = 0;
    int len = 0;
    for (int i = 0; i < strsSize; i++)
    {
        int j = 0;
        if (strlen(strs[j]) >= strlen(strs[i]))
        {
            j = i;
            len = strlen(strs[i]);
        }
    }
    for (i = 0; i < len; i++)
    {
        for (j = 1; j < strsSize; j++)
        {
            if (strs[j][i] != strs[j - 1][i])
                break;
        }
        if (j != strsSize)
            break;
    }
    strs[0][i] = '\0';
    return strs[0];
}