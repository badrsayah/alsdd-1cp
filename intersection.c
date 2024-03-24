#include <stdio.h>
#include <stdlib.h>
#include "mylibc.h"
#include <stdbool.h>
int main(){
int A[50],V[50],T[50];
int i,j,k;
int n,m;
printf("enter taille of array T and V");
scanf("%d %d",&n,&m);
printf("enter array T \n");
for(i=0;i<n;i++){scanf("%d",&T[i]);}
printf("enter array V \n");
for(j=0;j<m;j++){scanf("%d",&V[j]);}
intersection_array(T,V,A,n,m,&k);
for(j=0;j<k;j++){printf("%d ->",A[j]);}
    return 0;
}
