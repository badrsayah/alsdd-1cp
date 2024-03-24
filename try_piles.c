#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylibc.h"

int main(){
int n,i,v;
pile p;
initpile(&p);
printf("enter number of elements");
scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&v);
  empiler(&p,v);
  }
  afficher_pile(p);
return 0;
}
