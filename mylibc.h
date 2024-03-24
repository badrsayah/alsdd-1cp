// mylibc.h header li fih les entetes

#ifndef MYLIBC_H
#define MYLIBC_H
#include <stdbool.h>
// Define the structure for a singly linked list node
typedef struct element {
    int val;
    struct element *next; // Pointer to the next element in the list
} element;

// Define a pointer type for the singly linked list
typedef element* liste;

// Define the structure for a doubly linked list node
typedef struct box {
    int val;
    struct box *next; // Pointer to the next element in the list
    struct box *prev; // Pointer to the previous element in the list
} box;

// Define a pointer type for the doubly linked list
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
} file;
typedef struct pila* pile;
typedef struct pila{
int info;
pile suiv;
}pila;

float puissance(float a,int b);
void fill(int matrix[][100], int row, int column);
void printmat(int matrix[][100], int row, int column);
void intersection_array(int V[],int T[],int A[],int n,int m, int *k);
void merge_sorted_array(int V[],int T[],int A[],int n,int m);
int reverse(int n);
int valeur(liste p);
liste suivant(liste p);
void Aff_adr(liste *p,liste q);
void Aff_val(liste *p,int val);
void allouer(liste *p);
void liberer(liste *p);
int length_liste(liste tete);
void create_liste(liste *tete,int n);
liste ajoute_tete(liste tete, int e);
liste ajoute_fin(liste tete , int e);
void ajoute_apres(liste *tete, int e);
liste ajoute_apres_element(liste tete, int ele, int e);
void supprime_debut(liste * tete);
//liste supprime_val(liste tete,int v);
liste supprime_fin(liste tete);
void display_liste(liste tete);
liste access_value(liste tete,int val);
void access_value2(liste tete,int val,bool *trouve,liste *pred,liste *p);
void delete_by_value(liste *tete,int val);
liste acces_pos1(liste tete,int pos);
liste access_position(liste tete,int pos);
void delete_by_position(liste *tete,int pos);
//void supprime_val(liste *tete,int v);
void insert_by_position(liste *tete,int v,int pos);
void merge_sorted_listes(liste L1, liste L2,liste *L3);
void tri_bulle(liste *tete);
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
int valeurb(bliste p);
bliste suivantb(bliste p);
bliste precedentb(bliste p);
void Aff_dadr(bliste *p,bliste q);
void Aff_gadr(bliste *p,bliste q);
void Aff_valb(bliste *p,int val);
void allouerb(bliste *p);
void libererb(bliste *p);
int length_bliste(bliste tete);
void create_bliste(bliste *tete,bliste *queue,int n);
void split_pair_impair(liste tete,liste *L1,liste *L2);
void merge_liste(liste *L1,liste *L2,liste *L3);

void create_polynome(polynome *tete,int deg);
polynome derivate_polynom(polynome tete);
void somme_polynomes(polynome p1,polynome p2,polynome *p3);
void product_polynomes(polynome p1,polynome p2,polynome * p3);
 void display_polynome(polynome p);
 
bool Filevide(Tfile F);
bool Fileplein(Tfile F);
void Enfiler(Tfile* F,int val);
//dynamique
bool filevide_dyn(file f);
void creer_file(file *f);
bool filevide(file f);

void enfiler_dyn(file * f,int val);
void defiler_dyn(file *f,int *x);
void create_file(file *f,int n);
void display_file(file f);

void initpile(pile *p);
void empiler(pile *p, int v);
void depiler(pile *p,int *x);
int sommetpile(pile p);
int pilevide(pile p);
void afficher_pile(pile p);
#endif

