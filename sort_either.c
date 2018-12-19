#include<stdio.h>
main(){
int a[100],i,temp,max,j,n;
printf("enter how many number :\n");
scanf("%d",&n);

for(i=0;i<n;i++){
    scanf("%d",&a[i]);

}
printf("entered data :\n");
for(i=0;i<n;i++){
    printf("%d\n",a[i]);

}
printf("sorted data:\n");
for(i=n-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(a[j]>a[j+1]){
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
        }
      }
   }
for(i=0;i<n;i++){
    printf("%d\n",a[i]);

}

}

