 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

char* replaceSpace(char* s) {
    int cunt = 0;
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (s[i] == ' ')
            cunt++;
    }

    char* ret = (char*)malloc(sizeof(char) * (strlen(s) + cunt * 2 + 1));
    if (ret == NULL)
    {
        perror("malloc");
        return NULL;
    }
    int j = 0;
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            ret[j++] = '%';
            ret[j++] = '2';
            ret[j++] = '0';
        }
        else
        {
            ret[j++] = s[i];
        }
    }
    return ret;
}

int main()
{
    char a[14] = "We are happy.";
    replaceSpace(a);

	return 0;
}