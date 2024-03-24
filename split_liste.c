#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylibc.h"

int main(){
int n;
liste l1,l2,l;
l1=NULL;
l2=NULL;
printf("enter taille of ur lista");
scanf("%d",&n);
create_liste(&l,n);
display_liste(l);
split_pair_impair(l,&l1,&l2);
printf("pair liste is : \n");
display_liste(l1);
printf("impair liste is : \n");
display_liste(l2);
return 0;
}
