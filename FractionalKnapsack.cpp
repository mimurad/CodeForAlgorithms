#include<stdio.h>

int main()
{
    int n, profit[100], weight[100], i, j, capacity, temp;
    float pup[100], temp1, fraction, c, tp;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &weight[i], &profit[i]);
        pup[i] = profit[i]/(float)weight[i];
    }
    scanf("%d", &capacity);
    printf("Weight\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t", weight[i]);
    }
    printf("\n");
    printf("Profit\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t", profit[i]);
    }
    printf("\n");
    printf("Profit/Unit\t");
    for(i=0;i<n;i++)
    {
        printf("%.2f\t", pup[i]);
    }
    printf("\n");

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pup[i]<pup[j])
            {
                temp1 = pup[i];
                pup[i] = pup[j];
                pup [j] = temp1;

                temp = profit[i];
                profit[i] = profit[j];
                profit [j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight [j] = temp;
            }
        }
    }

    printf("\n\nAfter Sorting\n");
    printf("Weight\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t", weight[i]);
    }
    printf("\n");
    printf("Profit\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t", profit[i]);
    }
    printf("\n");
    printf("Profit/Unit\t");
    for(i=0;i<n;i++)
    {
        printf("%.2f\t", pup[i]);
    }
    printf("\n");


    c = capacity;
    tp = 0;
    for(i=0;i<n;i++)
    {
        if(weight[i] > c)
            break;
        else
        {
            tp = tp + profit[i];
            c = c - weight[i];
            printf("\nganting object of weight %d\n", weight[i]);
            printf("adding profit %d\n", profit[i]);
        }
    }
    if(i < n)
    {
        fraction = c;
        tp = tp + (fraction * pup[i]);
        printf("\ngranting %.2f of object of weight %d\n", fraction, weight[i]);
        printf("adding profit %.2f\n", (fraction * pup[i]));
    }



    printf("Maximum Profit: %f\n", tp);


    return 0;
}
/*
5
5 10
2 6
3 13
4 10
7 15
15
*/
