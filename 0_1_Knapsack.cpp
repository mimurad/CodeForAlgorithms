#include<stdio.h>

typedef struct
{
    int ind;
    int weight, profit;
}object;
int mx(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
void _0_1_knapsack(int n, object objects[], int capacity)
{
    int C[n+1][capacity+1], i, j;
    for(i=0;i<=n;i++)
    {
        C[i][0] = 0;
    }
    for(i=0;i<=capacity;i++)
    {
        C[0][i] = 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=capacity;j++)
        {
            if(objects[i].weight > j)
                C[i][j] = C[i-1][j];
            else
            {
                C[i][j] = mx(C[i-1][j], C[i-1][j-objects[i].weight] + objects[i].profit);
            }
        }
    }
    printf("Maximum Profit: %d\n", C[n][capacity]);

    j = capacity;
    for(i=n;i>0;i--)
    {
        if(C[i][j] != C[i-1][j])
        {
            printf("P%d, ", objects[i].ind);
            j = j - objects[i].weight;
        }
    }
}

int main()
{
    object objects[100], t;
    int capacity, temp;
    int n, i, j;
    printf("Enter the no. of objects: ");
    scanf("%d", &n);

    printf("Enter weights and profits of each object: \n");
    for(i=1;i<=n;i++)
    {
        objects[i].ind = i;
        scanf("%d %d", &objects[i].weight, &objects[i].profit);
    }
    printf("Enter the capacity: ");
    scanf("%d", &capacity);
    _0_1_knapsack(n, objects, capacity);

    return 0;
}
