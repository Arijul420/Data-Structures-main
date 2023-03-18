#include<stdio.h>
void Merge(int a[],int l, int m, int r){

   int n1, n2;
   n1 = m-l+1;
   n2 = r - m;
   int L[n1], R[n2];

   int i, j, k;

   for(i=0; i<n1; i++)
      L[i] = a[l+i];

   for(j=0; j<n2; j++)
      R[j]=a[m+j+1];

   i=0;
   j=0;
   k=l;

   while (i < n1 && j < n2){
      if(L[i] <= R[j]){
         a[k] = L[i];
         i++;
      }
      else{
         a[k] = R[j];
         j++;
      }
      k++;
   }
   while (i < n1){
      a[k] = L[i];
      i++;
      k++;
   }
   while (j < n2){
      a[k] = R[j];
      j++;
      k++;
   }
}

void mergesort(int a[],int l,int r){
   int m;
   if(l<r){
      m = l+(r-l)/2;
      mergesort(a, l, m);
      mergesort(a, m+1, r);
      Merge(a, l, m, r);
   }
}

int main(){
   int a[7]={9,8,0,6,5,1,13};
   mergesort (a,0,6);
   int i;
   for(i=0;i<7;i++)
      printf("%d ",a[i]);
}
