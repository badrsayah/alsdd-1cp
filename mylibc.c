// mylibc.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct element {
int val;
struct element * next;
}element;
typedef element* liste;

typedef struct box {
int val;
struct box * next;
struct box * prec;
}box;
typedef box* bliste;

typedef struct {
    int exp;
    int coef;
} data;

typedef struct poly {
    data val;
    struct poly* next;
} poly;

typedef poly* polynome;

//structure of les files statique

typedef struct Tfile{
int taille;
int tab[50];
int T,Q;
}Tfile;

//structure of files dynamique

typedef struct maillon {
    int val;
    struct maillon* next;
} maillon;
typedef maillon* fliste;

typedef struct file{
    fliste tete;
    fliste queue;
}file;

typedef struct pila* pile;
typedef struct pila{
int info;
pile suiv;
}pila;

float puissance(float a,int b){
float p;
int i;
p=1;
i=0;
while(i<=b){
p=p*a;
i++;
}
return p;
}

void fill(int matrix[][100], int row, int column) {
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("Row %d column %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printmat(int matrix[][100], int row, int column) {
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void intersection_array(int V[],int T[],int A[],int n,int m,int *k){
int i,j;
bool yes;
i=0;*k=0;
while(i<n){
j=0; yes=false;
 while((j<m) && (yes==false)){
   if(V[i]==T[j]) {
   yes=true;
    A[*k]=V[i];
    (*k)++;
   }
   j++;
  }
  i++;
}
}
void merge_sorted_array(int V[], int T[], int A[], int n, int m) {
    int i, j, k;
    i = 0; 
    j = 0; 
    k = 0;

    while ((i < n) && (j < m)) {
        if (V[i] < T[j]) {
            A[k] = V[i];
            i++;
        } else {
            A[k] = T[j];
            j++;
        }
        k++;
    }

    while (j < m) {
        A[k] = T[j];
        j++;
        k++;
    }

    while (i < n) {
        A[k] = V[i];
        i++;
        k++;
    }
}

int reverse(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}
//dabord on va ecrire la machine abstraite; 
/* valeur(P); 
   suivant(P);
   Aff_val(P,val);
   Aff_adr(P,Q);
   allouer(P);
   liberer(P);
*/
int valeur(liste p){
return p->val;
}
liste suivant(liste p){
return p->next;
}
void Aff_adr(liste *p,liste q){
((*p)->next)=q;
}
void Aff_val(liste *p,int val){
((*p)->val)=val;
}
void allouer(liste *p){
(*p) = (liste)malloc(sizeof(element));
}
void liberer(liste *p){
free(*p);
}
int length_liste(liste tete){
liste p;
p=tete;
int cpt;
cpt=0;
while(p!=NULL){
cpt++;
p=p->next;
}
return cpt;
}
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
liste ajoute_tete(liste tete , int e){
liste new;
new = (liste)malloc(sizeof(element));
if (new != NULL){
new->val = e;
new->next = tete;
tete = new;
}
else printf("memoire pleine sorry");
return tete;
}
liste ajoute_fin(liste tete , int e){
liste tmp,new;

new=(liste)malloc(sizeof(element));
new->val=e;
new->next=NULL;
if (tete == NULL) {
tete=new;
}
else {
tmp=tete;
while(tmp->next != NULL){
tmp=tmp->next;
}
tmp->next=new;
}
return tete;
}
void ajoute_apres(liste *tete, int e){
liste new,p;

new=(liste)malloc(sizeof(element));
p=(*tete)->next;
(new)->next=p;
(*tete)->next=(new);
new->val = e;

}

liste ajoute_apres_element(liste tete, int ele, int e) {
    liste new, tmp;
    tmp = tete;
    while(tmp != NULL && tmp->val != ele) {
        tmp = tmp->next;
    }

    // If the element to insert after is not found, return the original list
    if (tmp == NULL) {
        printf("Element %d not found in the list\n", ele);
    }
    else{
    // Allocate memory for the new node
    new = (liste)malloc(sizeof(element));
    if (new == NULL) {
        printf("Memory allocation failed\n");
    }
    else{
    // Assign values and update pointers
    new->val = e;
    new->next = tmp->next;
    tmp->next = new;
    }
    }
    return tete;
}
void supprime_debut(liste *tete) {
    if (*tete != NULL) {
        liste temp = *tete;
        *tete = (*tete)->next;
        free(temp);
    }
}
/*
liste supprime_val(liste tete,int v){
if (tete != NULL){
liste tmp= tete;
if (tmp->val == v) {
            tete = tmp->next; // Update the head pointer
            free(tmp); // Free the node
        }
while (tmp->next != NULL && ((tmp->next)->val != v)) {
tmp=tmp->next;
}
if (tmp->next != NULL) {
tmp->next=(tmp->next)->next;
free(tmp->next);
}
else printf("it doesnt exist");

}
else printf("ur list is empty hh");
return tete;
}*/
liste supprime_fin(liste tete){
if(tete != NULL) {
if(tete->next == NULL) {
free(tete);
tete=NULL;
}
else{
liste tmp = tete;
while((tmp->next)->next != NULL)
tmp=tmp->next;
free(tmp->next);
tmp->next=NULL;
}

}
else printf("ur list is literaly empty");
return tete;
}

void display_liste(liste tete){
liste tmp;
if (tete == NULL){
 printf("nothing dommage");
 }
 else {
tmp = tete;
while(tmp != NULL){
printf("%d -> ",tmp->val);
tmp=tmp->next;
}
printf("\n");
}
}

//fonction li t5rj ladresse p li fih kyn number val access by value hh
liste access_value(liste tete,int val){
liste p;
bool existe;
p=tete;
existe=false;
  while((p!=NULL)&&(!existe)){
  if(valeur(p)==val)
  existe=true;
   else 
   p=suivant(p);
  }
  return (p);
} 
void access_value2(liste tete,int val,bool *trouve,liste *pred,liste *p){
*p=tete;
*trouve=false;
*pred=NULL;
while((*p != NULL) && (!trouve)){
  if(valeur(*p)==val)
    *trouve=true;
    else
      {
      *pred=*p;
      *p=suivant(*p);
      }
}
}
void delete_by_value(liste *tete,int val){
liste pred,p;
bool trouve;
access_value2(*tete,val,&trouve,&pred,&p);
if(trouve == false)
printf("supp impossi");
 else {
   if (p==*tete)
      *tete=suivant(p);
     else
       Aff_adr(&pred,suivant(p));
 }
liberer(&p);
}
liste access_pos1(liste tete,int pos){
liste p;
int i;
p=tete;
while((p!=NULL) && (i<pos)){
p=suivant(p);
i++;
}
if(p==NULL)
printf("position not found");
return p;
} 
void access_pos2(liste *prd, liste *p,bool *trouve,liste tete,int pos){
int i;
*trouve=true;
i=1;
*p=tete;
*prd=NULL;
while((*p!=NULL) && (i<pos)){
*prd = *p;
*p = suivant(*p);
i++;
}
if(p==NULL){printf("position not found");
*trouve = false;
}
}
liste access_position(liste tete,int pos){
liste p;
int i;
i=1;
p=NULL;
if (pos<=length_liste(tete)){
  p=tete;
  while(i<pos){
  p=suivant(p);
  i++;
  }
}
return p;

}

void delete_by_position(liste *tete,int pos){
liste p,pred;
bool find;
access_pos2(&pred,&p,&find,*tete,pos);
}
void supprime_par_valeur(liste *tete,int v){
liste p,prd;
p=(*tete);
prd=NULL;
while((valeur(p)!=v) && (p!=NULL)){
prd=p;
p=suivant(p);
}
if(valeur(p)==v){
//suppression
Aff_adr(&prd,suivant(p));
liberer(&p);
}
else
printf("the value doesnt exist in the liste");
}

//Insert by position in a linked list
void insert_by_position(liste *tete,int v,int pos){
liste p,prd,q;
int i;
prd=NULL;
if((pos >= 1) && (pos<=length_liste(*tete))){
  p=*tete;
   i=1;
  while(i<pos){
  prd=p;
  p=suivant(p);
  i++;
  }
  allouer(&q);
  Aff_adr(&prd,q);
  Aff_val(&q,v);
  Aff_adr(&q,p);
}
else printf("your position entred is not valid");

}

void merge_sorted_listes(liste L1, liste L2,liste *L3){//with alocation
    liste p,q,prd,t;
p=L1;
q=L2;
*L3=NULL;
    while ((p!=NULL) && (q!=NULL)) {
    allouer(&t);
    Aff_adr(&t,NULL);
        if (valeur(p) <= valeur(q)) {
         Aff_val(&t,valeur(p));
            if(*L3 == NULL)
            (*L3)=t;
            else 
            Aff_adr(&prd,t);
            
            prd=t;
            p=suivant(p);
           }
        else{
        Aff_val(&t,valeur(q));
            if(*L3 == NULL)
            (*L3)=t;
            else 
            Aff_adr(&prd,t);
            
            prd=t;
            q=suivant(q);
           }
           }
           
            

    while (p!=NULL) {
        allouer(&t);
        Aff_val(&t,valeur(p));
        
        if((*L3)!=NULL)
        Aff_adr(&prd,t);
        else
        *L3=t;
        
        prd=t;
       p=suivant(p); 
    }

        while (q!=NULL) {
        allouer(&t);
        Aff_val(&t,valeur(q));
        
        if((*L3)!=NULL)
        Aff_adr(&prd,t);
        else
        *L3=t;
        
        prd=t;
       q=suivant(q); 
    }
}
/*
void tri_bulle(liste * tete){
bool modif;
liste p,q;
int x;
q=NULL;
modif=true ;

while ((modif) || (suivant(p)!=NULL)){
      modif = false;
      p=*tete;
      while(q!=NULL){
      if (valeur(q)>valeur(suivant(p))){
           x=valeur(q);
           Aff_val(&q,valeur(suivant(q)));
           Aff_val(&suivant(q),x);
          modif= true;}
          q=suivant(q);
          }
          p=suivant(p);
          }
          }*/
          void tri_bulle(liste *tete) {
    bool modif = true;
    liste p, q;
    int x;
    
    if (*tete == NULL)
        return;  // Empty list, nothing to sort
    
    while (modif) {
        modif = false;
        p = *tete;
        q = suivant(p);
        
        while (q != NULL) {
            if (valeur(p) > valeur(q)) {
                x = valeur(p);
                Aff_val(&p, valeur(q));
                Aff_val(&q, x);
                modif = true;
            }
            p = suivant(p);
            q = suivant(q);
        }
    }
}
//dabord on va ecrire la machine abstraite de biderctionnel liste; 
/* valeur(P); 
   suivant(P);
   precedent(p);
   Aff_val(P,val);
   Aff_dadr(P,Q); suiv
   Aff_gadr(P,Q); prec
   allouerb(P);
   libererb(P);
*/
int valeurb(bliste p){
return p->val;
}
bliste suivantb(bliste p){
return p->next;
}
bliste precedentb(bliste p){
return p->prec;
}
void Aff_dadr(bliste *p,bliste q){
((*p)->next)=q;
}
void Aff_gadr(bliste *p,bliste q){
((*p)->prec)=q;
}
void Aff_valb(bliste *p,int val){
((*p)->val)=val;
}
void allouerb(bliste *p){
(*p) = (bliste)malloc(sizeof(box));
}
void libererb(bliste *p){
free(*p);
}
int length_bliste(bliste tete){
bliste p;
p=tete;
int cpt;
cpt=0;
while(p!=NULL){
cpt++;
p=p->next;
}
return cpt;
}
void create_bliste(bliste *tete,bliste *queue,int n){
int i,v;
bliste p;

for(i=0;i<n;i++){
scanf("%d",&v);
allouerb(&p);
Aff_valb(&p,v);
Aff_dadr(&p,NULL);
if ((*tete)==NULL)
 { *tete = p;
   *queue = p;
   }
 else 
  {
  Aff_dadr(queue,p);
  Aff_gadr(&p,*queue);
  }
}
}
void split_pair_impair(liste tete,liste *L1,liste *L2){
liste l,t,prd1,prd2;
// L1 for pair L2 for impair
l=tete;
prd1=NULL;
prd2=NULL;
while(l!=NULL){
allouer(&t);
Aff_val(&t,valeur(l));
Aff_adr(&t,NULL);
 if(valeur(t) % 2 == 0){
   if(*L1==NULL){
     *L1=t;
      }
    else {
    Aff_adr(&prd1,t);
    }
    prd1=t; 
 }
 else {
  if(*L2==NULL){
  *L2=t;
  }
  else {
  Aff_adr(&prd2,t);
  }
 prd2=t;
 }
 l=suivant(l);
}
}
void merge_liste(liste *L1,liste *L2,liste *L3){ //changing chainage
liste p,q,t,pred;
p=*L1;
q=*L2;
if(valeur(p)<valeur(q)) {
*L3 = p;
p=suivant(p);
t=*L3;
}
else{

*L3=q;
t=*L3;
q=suivant(q);
}
pred=*L3;
while((p!=NULL) && (q!=NULL)){
if(valeur(p)<=valeur(q)){
Aff_adr(&pred,p);
pred=p;
p=suivant(p);
}
else{
Aff_adr(&pred,q);
pred=q;
q=suivant(q);
}
}
if(p==NULL){
Aff_adr(&pred,q);
}
else Aff_adr(&pred,p);
}
/*13. A polynomial can be represented by a linked list. Say how. Write the following algorithms:
- Calculate the value of the polynomial at a given point x.
- Find the derivative of a polynomial.
- Calculate the sum of two polynomials.
- Calculate the product of two polynomials.*/

/*
void create_polynom(poly *tete,int deg){
    float v;
    int i;
    poly p,prd;
    for (i = deg ;i > 0; i--) {
       printf("enter coeff of deg %d :",i);
        scanf("%f", &v);
        if(v!=0){
        p = (poly)malloc(sizeof(polynom));
        p->puiss = i;
        p->coef = v;
        if (*tete == NULL)
            *tete = p;
        else
           prd->next = p;
           prd = p;  
        }
       
    }  
    prd->next = NULL; 
}
//Calculate the value of the polynomial at a given point x.

float calculate_value(poly tete,float x){
poly p;
float result;
p=tete;
result=0;
while(p!=NULL){
result=result+(p->coef)*puissance(x,p->puiss);
p=p->next;
}
return result;
}

poly derivate_polynom(poly tete){
poly derive,p,q,prd;
p=tete;
derive=NULL;
while(p!=NULL){
  q = (poly)malloc(sizeof(polynom));
  (q->coef)=(p->coef)*(p->puiss);
  (q->puiss)=(p->puiss)-1;
  if(derive==NULL)
    derive=q;
   else 
    (q->next)=prd;
    
    prd=q;
}
(prd->next)=NULL;
return derive;
}

//Calculate the sum of two polynomials.
*/
void create_polynome(polynome *tete,int deg){
    float v;
    int i;
    polynome p,prd;
    for (i = 0 ; i <= deg ; i++) {
       printf("enter coeff of deg %d :",i);
        scanf("%f", &v);
        if(v!=0){
        p = (polynome)malloc(sizeof(poly));
        (p->val).exp = i;
        (p->val).coef = v;
        if (*tete == NULL)
            *tete = p;
        else
           prd->next = p;
           prd = p;  
        }
       
    }  
    prd->next = NULL; 
}

polynome derivate_polynom(polynome tete){
polynome derive,p,q,prd;
p=tete;
derive=NULL;
while(p!=NULL){
  if((p->val).exp > 0){
  q = (polynome)malloc(sizeof(poly));
  (q->val).coef=(p->val).coef*(p->val).exp;
  (q->val).exp=(p->val).exp -1;
  if(derive==NULL)
    derive=q;
   else 
    (q->next)=prd;
    
    prd=q;
    }
    p=p->next;
}
(prd->next)=NULL;
return derive;
}

void somme_polynomes(polynome p1,polynome p2,polynome *p3){
polynome p,q,t,pred;
*p3=NULL;
p=p1;
q=p2;

while((p!=NULL) && (q!=NULL)){

t = (polynome)malloc(sizeof(poly));

  if((p->val).exp < (q->val).exp){
  (t->val).exp = (p->val).exp;
  (t->val).coef = (p->val).coef;
   
   p=p->next;
  }
   else 
    if((p->val).exp < (q->val).exp){
  (t->val).exp = (q->val).exp;
  (t->val).coef = (q->val).coef;
   
  q=q->next;
  }
  else {
  (t->val).exp = (q->val).exp;
  (t->val).coef = (q->val).coef + (p->val).coef;
  
  
  q=q->next;
  p=p->next;
  }
  
  if(*p3 !=NULL)
   (pred->next) = t;
   else
   *p3 = t;
   pred=t;

}

while(p!=NULL){
t = (polynome)malloc(sizeof(poly));
 (t->val).exp = (p->val).exp;
  (t->val).coef = (p->val).coef;
  
   if(*p3 !=NULL)
   (pred->next) = t;
   else
   *p3 = t;
   pred=t;
   
   p=p->next;

}
while(q!=NULL){
t = (polynome)malloc(sizeof(poly));
 (t->val).exp = (q->val).exp;
  (t->val).coef = (q->val).coef;
  
   if(*p3 !=NULL)
   (pred->next) = t;
   else
   *p3 = t;
   pred=t;
   
   q=q->next;

}

}

void product_polynomes(polynome p1,polynome p2,polynome * p3){
polynome p,q,t,pred;
*p3 = NULL;
p=p1;

 while(p!=NULL){
  q=p2;
   while(q!=NULL){
    t = (polynome)malloc(sizeof(poly));
 (t->val).exp = (q->val).exp + (p->val).exp;
  (t->val).coef = (q->val).coef * (p->val).coef;
  
   if(*p3 !=NULL)
   (pred->next) = t;
   else
   *p3 = t;
   pred=t;
   
   q=q->next;

}
 p=p->next;
   }
   pred->next = NULL;
   }
   
   void display_polynome(polynome p){
polynome tmp;
if (p == NULL){
 printf("nothing dommage");
 }
 else {
tmp = p;
while(tmp != NULL){
printf("%dx^%d -> ",(tmp->val).coef,(tmp->val).exp);
tmp=tmp->next;
}
printf("\n");
}
}

//les files functions
bool Filevide(Tfile F){
return (F.Q < F.T);
}
bool Fileplein(Tfile F){
return F.Q == F.taille;
}
void Enfiler(Tfile* F,int val){
if(!Fileplein(*F)){
(F->Q)=(F->Q)+1;
(F->tab)[F->Q]=val;
}
else 
printf("over flow");
}
int defiler(Tfile* F){ //we didnt specify int v because its obvious that we supprime from the beginning
int d;
d=(F->tab)[F->T];
F->T=F->T+1;
return d;
}
//dynamique
bool filevide_dyn(file f){
return (f.tete == NULL);
}
void creer_file(file *f){
(*f).tete = NULL;
(*f).queue = NULL;
}
bool filevide(file f){
return (f.tete == NULL);
}

void enfiler_dyn(file *f, int val) {
    fliste p = (fliste)malloc(sizeof(maillon));
    if (p == NULL) {
        // Handle memory allocation failure
        return;
    }
    p->val = val;
    p->next = NULL;

    if (!filevide_dyn(*f)) {
        ((*f).queue)->next = p;
    } else { //vide
        (*f).tete = p;
    }
    (*f).queue = p;
}

void defiler_dyn(file *f,int *x){
if(!(filevide_dyn(*f)))
 *x=((*f).tete)->val;
 (*f).tete=((*f).tete)->next;
}

void create_file(file *f,int n){
    int v;
(*f).tete = NULL;
(*f).queue = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        enfiler_dyn(f,v);
    }   
}

void display_file(file f){
fliste p;
p = (f).tete;
while(p!=NULL){
printf("%d->",p->val);
p=p->next;
}
}

//les piles 
void initpile(pile *p){
*p=NULL;
}
void empiler(pile *p, int v){
pile new;
new = (pile)malloc(sizeof(pila));
new->info = v;
new->suiv =*p;
*p = new;
}
void depiler(pile *p,int *x){
pile tmp;
*x=(*p)->info;
tmp=*p;
*p=(*p)->suiv;
free(tmp);
}
int sommetpile(pile p){return p->info;}
int pilevide(pile p){
if(p == NULL) return 1;
else return 0;
}

void afficher_pile(pile p){
pile tmp;
tmp=p;
while(tmp!=NULL){
printf("%d->",tmp->info);
tmp = tmp->suiv;
}
}
// union trie et non triee
//suppression
//logique bollean avec un champ enreg eff ORDONNEE on initialise bool eff a faux en premier et lelement a supprimer a vrai 
//physique ecraser  *NON ORDONNEE* (on prend dernier element ecrase lelement qui on veut supprime et on - la taille


