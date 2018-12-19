#include<stdio.h>
#include<string.h>

#define diag 1
#define up 2
#define left 3
#define subs 2
#define ins 1
#define del 1
int mn(int a, int b)
{
    if(a < b)
        return a;
    return b;
}
int EditDistance(char s1[], char s2[])
{
    int i, j, len1, len2;
    len1 = strlen(s1);
    len2 = strlen(s2);

    int L[len1+1][len2+1], D[len1+1][len2+1];

    for(i=0;i<=len1;i++)
    {
        L[i][0] = i;
    }
    for(i=0;i<=len2;i++)
    {
        L[0][i] = i;
    }
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                L[i][j] = L[i-1][j-1];
                D[i][j] = diag;
            }
            else
            {
                L[i][j] = mn(mn(L[i-1][j] + ins, L[i][j-1] + del), L[i-1][j-1] + subs);
                if(L[i][j] == L[i-1][j]+ins)
                    D[i][j] = up;
                else if(L[i][j] == L[i][j-1]+del)
                    D[i][j] = left;
                else
                    D[i][j] = diag;
            }
        }
    }

    for(i=len1,j=len2;i>=0&&j>=0;)
    {
        if(D[i][j] == diag)
        {
            printf("%c", s1[i-1]);
            i--;
            j--;
        }
        else if(D[i][j] == left)
            j--;
        else
            i--;
    }
    printf("\n");

    return L[len1][len2];
}

int main()
{
    char str1[100], str2[100];
    int length;
    printf("Enter first string:\n");
    gets(str1);
    printf("Enter second string:\n");
    gets(str2);

    length = EditDistance(str1, str2);

    printf("Minimum Edit Distance: %d\n", length);

    return 0;
}
