#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
int val;
bool supp;
}element;
int main(){
element V[50];
int n,i,v;
bool trouve;
printf("enter your value v");
scanf("%d",&v);
printf("enter your taille n");
scanf("%d",&n);
for(i=0;i<n;i++){scanf("%d",&V[i].val);
V[i].supp=false;
}
for(i=0;i<n;i++)
printf("%d ->",V[i].val);

trouve=false;
i=0;
while(!(trouve) && (i<n)){
    if(V[i].val == v){
        V[i].supp=true;
        trouve=true;
    }
    else i++;
}
i=0;
while(i<n){
    if(V[i].supp == false){
        printf("%d->",V[i].val);
    }
    i++;
}
return 0;
}