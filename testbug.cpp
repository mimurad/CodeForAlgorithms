#include<stdio.h>
main()
{
    int i,j,k,temp;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    for(i=0,j=9;i<5,j>=5;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        for(k=0;k<10;k++)
    {
        printf("%d ",a[k]);
    }
    printf("\n");

    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }
}
