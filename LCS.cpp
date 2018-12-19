#include<stdio.h>
#include<string.h>

#define diag 1
#define up 2
#define left 3

int mx(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
int LCS(char s1[], char s2[])
{
    int i, j, len1, len2;
    len1 = strlen(s1);
    len2 = strlen(s2);

    int L[len1+1][len2+1], D[len1+1][len2+1];

    for(i=0;i<=len1;i++)
    {
        L[i][0] = 0;
    }
    for(i=0;i<=len2;i++)
    {
        L[0][i] = 0;
    }
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                L[i][j] = L[i-1][j-1] + 1;
                D[i][j] = diag;
            }
            else
            {
                L[i][j] = mx(L[i-1][j], L[i][j-1]);
                if(L[i][j] == L[i-1][j])
                    D[i][j] = up;
                else
                    D[i][j] = left;
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
    printf("Enter first sequence:\n");
    gets(str1);
    printf("Enter second sequence:\n");
    gets(str2);

    length = LCS(str1, str2);

    printf("LCS Length: %d\n", length);

    return 0;
}
