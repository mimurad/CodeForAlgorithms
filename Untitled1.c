#include<stdio.h>
main()
{
    int n,m,c=0;
    scanf("%d %d",&n,&m);

    if(n>=m)
    {
        c=n-m;
    }
    else{
    while(n!=m){
     if(n<=0)
     return 0;
    if(2*n>m)
    {
        n--;
    }
    else
        n*=2;
    c++;
    }
    }
    printf("%d",c);
}
