#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylibc.h"
typedef struct element {
int val;
struct element * next;
}element;
typedef element* liste;

int main(){
int n,m;
liste l1,l2,l;
l1=NULL;
l2=NULL;
l=NULL;
scanf("%d%d",&n,&m);
create_liste(&l1,n);
create_liste(&l2,m);
disply_liste(l1);
disply_liste(l2);
merge_sorted_listes(l1,l2,&l);
disply_liste(l2);
return 0;
}
