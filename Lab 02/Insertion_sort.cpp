#include<stdio.h>

void insertion(int a[],int n){
   int i,j,t;
   for(i=1;i<n;i++){
      j=i-1;
      t=a[i];
      while(j>=0 && a[j]>t){
         a[j+1]=a[j];
         j--;
      }
      a[j+1]=t;
   }
}

int main(){
   int a[6]={9,8,7,6,5,1};
   insertion(a,6);
   for(int i=0;i<6;i++)
      printf("%d ",a[i]);
}
