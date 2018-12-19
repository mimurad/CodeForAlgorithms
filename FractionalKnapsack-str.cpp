#include<stdio.h>

typedef struct
{
    int ind;
    float weight, profit, pup;
}object;

void knapsack(int n, object objects[], float capacity)
{
    float x[100], tp = 0.0;
    int i, j, u, k = 0;
    int granted[100];

    u = capacity;
    for(i=0;i<n;i++)
        x[i] = 0.0;
    for(i=0;i<n;i++)
    {
        if(objects[i].weight > u)
            break;
        else{
            x[i] = 1.0;
            granted[k++] = objects[i].ind;
            tp = tp + objects[i].profit;
            u = u - objects[i].weight;
        }
    }
    if(i < n)
    {
        granted[k++] = objects[i].ind;
        x[i] = u / objects[i].weight;
        tp = tp + (x[i] * objects[i].profit);
    }
    printf("\nGranted Packages:\n");
    for(i=0;i<k;i++)
        printf("P%d\t", granted[i]+1);
    printf("\nMaximum Profit: %.2f\n", tp);
}

int main()
{
    object objects[100], t;
    float capacity, temp;
    int n, i, j;
    printf("Enter the no. of objects: ");
    scanf("%d", &n);

    printf("Enter weights and profits of each object: \n");
    for(i=0;i<n;i++)
    {
        objects[i].ind = i;
        scanf("%f %f", &objects[i].weight, &objects[i].profit);
        objects[i].pup = objects[i].profit/objects[i].weight;
    }

    printf("Enter the capacity: ");
    scanf("%f", &capacity);

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(objects[i].pup<objects[j].pup)
            {
                t = objects[i];
                objects[i] = objects[j];
                objects [j] = t;
            }
        }
    }

    knapsack(n, objects, capacity);


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
