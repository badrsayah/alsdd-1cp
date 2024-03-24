#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct element{
int val;
struct element* next; 
}element;
typedef element* liste;

void create_liste(liste *tete,int n){
    int v;
    liste p,prd;
    *tete = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d",&v);
        p = (liste)malloc(sizeof(element));
        p->val = v;
        p->next = NULL; // Initialize the 'suiv' pointer to NULL before inserting the element.
        if (*tete == NULL) {
            *tete = p;
            prd = p;
        } else {
            prd->next = p;
            prd = p;
        }
    }   
}
void deleteLinkedList(liste * head) {
    liste current = *head;
    liste p;

    while (current != NULL) {
        p = current->next;  // Store the next node
        free(current);        // Delete the current node
        current = p;       // Move to the next node
    }

    *head = NULL;  // Set head to NULL to indicate the list is empty
}
void display_liste(liste tete){
liste tmp;
tmp = tete;
while(tmp != NULL){
printf("%d -> ",tmp->val);
tmp=tmp->next;
}
printf("\n");
}
int main(){
int n;
liste l;
l=NULL;
printf("enter taille of ur lista");
scanf("%d",&n);
create_liste(&l,n);
printf("ur liste before supp is : \n");
display_liste(l);
deleteLinkedList(&l);
printf("ur liste after supp is : \n");
display_liste(l);

return 0;
}

