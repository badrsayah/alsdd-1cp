#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylibc.h"

int main(){
int n,m;
liste l1,l2,l;
l1=NULL;
l2=NULL;
printf("enter taille of ur listas");
scanf("%d%d",&n,&m);
create_liste(&l1,n);
create_liste(&l2,m);
display_liste(l1);
printf("\n");
display_liste(l2);
merge_sorted_listes(l1,l2,&l);
printf("merged liste is : \n");
display_liste(l);

return 0;
}
