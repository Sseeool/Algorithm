#include <stdio.h>
#include <string.h>
#define MAX 1001

int recursion(const char *s, int l, int r, int *cnt)
{
    (*cnt)++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, cnt);
}

int isPalindrome(const char *s, int *cnt){
    return recursion(s, 0, strlen(s)-1, cnt);
}

int main()
{
    int t, cnt, rslt;
    char str[MAX];

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%s", str);
        cnt = 0;
        rslt = isPalindrome(str, &cnt);
        printf("%d %d\n", rslt, cnt);
    }
    return 0;
}