#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*      Cette partie est dédiée pour la définition des constantes utilisées         */
#define MAX_NAME_LENGTH 25  // Le plus grand nombre de caractères pouvant etre utilisés dans les noms des participants  
#define MAX_ATHLETES 13501  // Le nombre maximum des athlétes dans ces jeux universitaires
#define MAX_EPREUVE 20      //
#define MAX_UNIV 45
#define MAX_ATHLETES_PER_EVENT 15

typedef struct {
    int number;
    char surname[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
} student;
//structure of matrix should be changed later
typedef struct ath {
    student info;
    struct ath* next;
} ath;

typedef ath* athlete;

typedef struct {
	athlete data[MAX_EPREUVE][MAX_UNIV];
	int rows;
	int columns;
}mat;

//--------{ abstract machine }--------

student value(athlete p){
return p->info;
}

athlete suivant(athlete p){
return p->next;
}
void Aff_adr(athlete *p,athlete q){
((*p)->next)=q;
}
void Aff_val(athlete *p,student val){
((*p)->info)=val;
}

void allouer(athlete *p){
(*p) = (athlete)malloc(sizeof(ath));
}
void liberer(athlete *p){
free(*p);
}


void generate_random_name(char *name) {
    const char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int taille = rand() % (MAX_NAME_LENGTH - 1) + 1;

    for (int i = 0; i < taille; i++) {
        name[i] = alphabets[rand() % (sizeof(alphabets) - 1)];
    }
    name[taille] = '\0';
}

bool num_existe(int T[], int size, int val) {
    for (int i = 0; i < size; ++i) {
        if (T[i] == val) {
            return true;
        }
    }
    return false;
}

void create_list(athlete *head, int v[], int n, int *k) {
    int random_num;

    athlete p, prev;
    *head = NULL;
    char random_name[MAX_NAME_LENGTH + 1];

    for (int i = 0; i < n; i++) {
        p = (athlete)malloc(sizeof(ath));
        do {
            random_num = rand() % MAX_ATHLETES + 1;
        } while (num_existe(v, *k, random_num));
        v[*k] = random_num;
        (*k)++;
        p->info.number = random_num;
        generate_random_name(random_name);
        strcpy(p->info.surname, random_name);
        generate_random_name(random_name);
        strcpy(p->info.name, random_name);

        p->next = NULL;
        if (*head == NULL) {
            *head = p;
            prev = p;
        } else {
            prev->next = p;
            prev = p;
        }
    }
}

void create_arrays(mat * Tabjru, char univ[][100], char event[][100], int row, int column, int id[]) {
    char *epreuves[MAX_EPREUVE] = {
        "Aviron", "Athlétisme", "Badminton", "Basketball", "Boxe",
        "Cyclisme", "Echecs", "Escrime", "Football", "Gymnastique",
        "Haltérophilie", "Handball", "Judo", "Karaté", "Natation",
        "Taekwondo", "Tennis", "Tennis de table", "Tir à l'arc", "Volleyball"
    };
    Tabjru->columns = MAX_UNIV;
    Tabjru->rows = MAX_EPREUVE;
    char *universities[MAX_UNIV] = {
    "Centre universitaire d’Aflou",
    "Centre Universitaire d’Illizi-Cheikh Amoud ben Mokhtar",
    "Centre universitaire de Tipaza – Abdallah Morsli",
    "Ecole des hautes études commerciales",
    "Ecole Nationale Polytechnique",
    "Ecole nationale supérieure agronomique- Khalef Abdellah alias Kasdi Merbah",
    "Ecole nationale supérieure d’hydraulique – Arbaoui Abdellah",
    "Ecole nationale supérieure d’informatique",
    "Ecole nationale supérieure de journalisme et des sciences de l’information",
    "Ecole nationale supérieure de management",
    "Ecole Nationale Supérieure de Technologie",
    "Ecole nationale supérieure des sciences de la mer et de l’aménagement du littoral",
    "Ecole Nationale Supérieure des sciences politiques",
    "Ecole Nationale Supérieure des Technologies Avancées",
    "Ecole nationale supérieure des travaux publics – Francis Jeanson",
    "École Nationale Supérieure en Mathématique",
    "Ecole nationale supérieure en statistique et en économie appliquée",
    "École Nationale Supérieure en Intelligence Artificielle",
    "Ecole nationale supérieure vétérinaire – Rabie Bouchama",
    "Ecole normale supérieure de Bouzaréah – Cheikh Mubarak Ben Mohamed Brahimi ElMili",
    "Ecole normale supérieure de Kouba – Mohamed Bachir El Ibrahimi",
    "Ecole normale supérieure de Laghouat – Taleb Abderrahmane",
    "Ecole Polytechnique d’architecture et d’Urbanisme-Hocine Aït Ahmed",
    "Ecole Supérieure de Commerce-Mouloud Kacem Naït Belkacem",
    "Ecole Supérieure de Gestion et d’Economie Numérique",
    "Ecole Supérieure des Sciences appliquées d’Alger",
    "Ecole Supérieure des Sciences de l’Aliment et des Industries Agroalimentaires d’Alger",
    "École Supérieure en Sciences et Technologies de l’Informatique et du Numérique de Bejaia",
    "Université d’Alger 1 – Benyoucef Benkhedda",
    "Université d’Alger 2 – Abou el Kacem Saâdallah",
    "Université d’Alger 3 – Brahim Soltane Chaibout",
    "Université de Béjaia – Abderrahmane Mira",
    "Université de Blida 2 – Lounici Ali",
    "Université de Ghardaia",
    "Université de la Formation Continue",
    "Université de Tamenghasset",
    "Université de Tizi Ouzou – Mouloud Maameri",
    "Université des sciences et de la technologie d’Alger, Houari Boumediène",
    "Université Blida 1 – Saad Dahlab",
    "Université de Bouira – Akli Mohand Oulhadj",
    "Université de Boumerdès – M’hamed Bougara",
    "Université de Djelfa – Ziane Achour",
    "Université de Khemis Miliana – Djilali Bounaama",
    "Université de Laghouat – Amar Telidji",
    "Université Médéa – Yahia Farès"
};

    for (int i = 0; i < MAX_UNIV; i++) {
        strcpy(univ[i], universities[i]);
    }

    for (int i = 0; i < MAX_EPREUVE; i++) {
        strcpy(event[i], epreuves[i]);
    }

    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            Tabjru->data[i][j] = NULL;
            int random_number = rand() % MAX_ATHLETES_PER_EVENT + 1;
            // Assuming create_list is defined somewhere
            create_list(&Tabjru->data[i][j], id, random_number, &k);
        }
    }
}
int length_list(athlete head) {
    int count = 0;
    athlete current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void add_athlete(int numath, char* nameth, char* surnameath, int numet, int numep, mat* M, int id[]) {
    if (length_list(M->data[numep][numet]) < MAX_ATHLETES_PER_EVENT && !num_existe(id, MAX_ATHLETES, numath)) {
        athlete new_athlete = (athlete)malloc(sizeof(ath));
        if (new_athlete == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(new_athlete->info.name, nameth);
        strcpy(new_athlete->info.surname, surnameath);
        new_athlete->info.number = numath;
        new_athlete->next = M->data[numep][numet];
        M->data[numep][numet] = new_athlete;
    } else {
        printf("Cannot add athlete to the event.\n");
    }
}

void display_list(athlete head) {
    athlete tmp = head;
    if (tmp == NULL) {
        printf("List is empty.\n");
    } else {
        while (tmp != NULL) {
            printf("(number: %d, name: %s, surname: %s) -> \n", tmp->info.number, tmp->info.name, tmp->info.surname);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int institution_found(char *institution,char V[][100],int nb){
int i;
 for(i = 0; i < nb; i++) {
        if (strcmp(institution,V[i]) == 0) {
            return i; // Found the university, return its index
        }
    }
    return -1; // University not found
}

//bonus

int event_found(char *event,char V[][100],int nb){
int i;
 for(i = 0; i < nb; i++) {
        if (strcmp(event,V[i]) == 0) {
            return i; // Found the university, return its index
        }
    }
    return -1; // University not found
}
bool numet_exists(int num,mat M){
return(num >= 0 && num < M.columns);
}
bool numep_exists(int num,mat M){
return(num >= 0 && num < M.rows);
}
void listathet(char *institution,mat M,char Tabuniv[][100],char Tabevent[][100])
{
    int index = institution_found(institution,Tabuniv,M.columns);
    if(index != -1){
    //beginning of display all the events>>>
    for(int i=0;i<M.rows;i++)
    {
        printf("%s ",Tabevent[i]);
        display_list(M.data[index][i]);
        printf("\n");
    }  
}
else {
    printf("the institution doesnt existe\n");
}
}
bool withoutath(int ne,athlete Tabjru[][MAX_UNIV]){
    int j;
    bool trouve ;
    j=0; trouve = true;
        while((j < MAX_UNIV)&&(trouve==true)){
            if((Tabjru[ne][j])!= NULL) trouve=false;
            j++;
        }
        return trouve;
    }
   
void listjru(mat Tabjru,char univ[][100],char event[][100]) 
    {
        // Display each linked list individually
        for (int j = 0; j < Tabjru.rows; j++) 
        {
            
            printf("Event: %s\n", event[j]);
            for (int i = 0; i < Tabjru.columns; ++i)
            {
                printf("institutioon of: %s\n", univ[i]);
                display_list(Tabjru.data[j][i]);
            }
            printf("\n");
        }
}
void deleteLinkedList(athlete * head) {
    athlete current = *head;
    athlete p;

    while (current != NULL) {
        p = current->next;  // Store the next node
        free(current);        // Delete the current node
        current = p;       // Move to the next node
    }

    *head = NULL;  // Set head to NULL to indicate the list is empty
}
void deletInstitution(char *institution,mat* M,char Tabuniv[][100]){
             //decalage
             int index = institution_found(institution,Tabuniv,M->columns);
        if(index != -1){


        for(int i=0;i<(M->rows);i++)
        {
           //the institution is here haha so lets remove every liste
            deleteLinkedList(&(M->data[i][index])); // Delete the linked list
          //lets begin the decalage i guess!
          for(int j=index;j<(M->columns)-1;j++)
          {
          (M->data)[i][j]=(M->data)[i][j+1];
          }
         }
          for (int k = index; k <= M->columns-1 ; ++k)
          {
            strcpy(Tabuniv[k],Tabuniv[k+1]);
          }
         M->columns--; // Decrease the column count after shifting

        }
        else {
            printf("the institution doesnt existe");
        }
}
   void del_ath(mat *m, int numath, int numet, int numep) {
    athlete p, pred;
    bool found = false;

    if (numet_exists(numet, *m) && numep_exists(numep, *m)) {
        p = m->data[numep][numet]; // p will be used to traverse the linked list
        while ((p != NULL) && (!found)) {
            if (p->info.number == numath) { // if the player is found
                found = true;
                if (pred != NULL) {
                    pred->next = p->next; // Adjust pointers to skip the node to be deleted
                } else {
                    m->data[numep][numet] = p->next; // Update head pointer if deleting the first node
                }
                free(p); // freeing the memory used by that player
            }
            pred = p;
            p = p->next;
        }

        if (found) {
            printf("Deleting successful.\n");
        } else {
            printf("Athlete with number %d not found.\n", numath);
        }
    } else {
        printf("Institution and/or event not found.\n");
    }
}

void deletetEvent(int ind,mat* M,char Tabevent[][100])
{
       for(int i=0;i<(M->columns);i++)
        {
            deleteLinkedList(&(M->data[ind][i])); // Delete the linked list
          //lets begin the decalage i guess!
          for(int j=ind;j<(M->rows)-1;j++)
          {
          (M->data)[j][i]=(M->data)[j+1][i];
          }
         }
          for (int k = ind; k <= M->rows-1 ; ++k)
          {
            strcpy(Tabevent[k],Tabevent[k+1]);
          }
     M->rows--;
}
void deleteEmptyLignes(mat* M, char Tabevent[][100])
{
    for (int i = 0; i < M->rows; ++i)
    {
        if (withoutath(i,M->data))
        {
            deletetEvent(i,M,Tabevent);
        }
    }
}

void displaytab(char Tab[][100],int rr)
{
    for (int i = 0; i < rr; ++i)
    {
        printf("%d -->  %s \n",i,Tab[i] );
    }
}
int main() {
    int id[MAX_ATHLETES] = {0};
    char tabuniv[MAX_UNIV][100];
    char tabepreuve[MAX_EPREUVE][100];
    char name[25];
    char surname[25];
    char university[100];
    int uni;
    int event;
    int num;
    mat Tbjru;
    /*
    create_arrays(&Tbjru,tabuniv,tabepreuve, MAX_EPREUVE, MAX_UNIV, id);
    
    displayTab(tabepreuve,Tbjru.rows);
    
    displayTab(tabuniv,Tbjru.columns);
    
    deletetEvent(2,&Tbjru,tabepreuve);

    deleteEmptyLignes(&Tbjru,tabepreuve);
    
    listjru(Tbjru,tabuniv,tabepreuve);
    
    displayTab(tabepreuve,Tbjru.rows); */
    
     int choice;
    do {
        printf("\n**************** {MENU} ***************\n");
        printf("1: Create array tabju\n");
        printf("2: Add athlete\n");
        printf("3: display athletes by institution\n");
        printf("4: display athletes by event\n");
        printf("5: Delete institution\n");
        printf("6: Delete event\n");
        printf("7: Delete athlete\n");
        printf("8: Delete empty events (line full of NULL)\n");
        printf("9: display tabuniv\n");
        printf("10: display tabepreuve\n");
        printf("11: Exit\n");
        printf("******************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (Tbjru.columns == MAX_UNIV && Tbjru.rows == MAX_EPREUVE) {
                    printf("The arrays are already filled.\n");
                } else {
                    create_arrays(&Tbjru, tabuniv, tabepreuve, MAX_EPREUVE, MAX_UNIV, id);
                }
                break;
            case 2:
                printf("enter name : \n");
                scanf("%s",name);
                printf("enter surname : \n");
                scanf("%s",surname);
                printf("enter number : \n");
                scanf("%d",&num);
                printf("enter number of institution : \n");
                scanf("%d",&uni);
                printf("enter number of event : \n");
                scanf("%d",&event);
                add_athlete(num,name,surname,uni,event,&Tbjru,id);
                break;
            case 3:
                listathet("Université Médéa – Yahia Farès", Tbjru,tabuniv, tabepreuve);
                break;
            case 4:
                listjru(Tbjru, tabuniv, tabepreuve);
                break;
            case 5:
              printf("enter the institution you want to delete XDD : \n");  
             fgets(university, sizeof(university), stdin);
              // Print the entered phrase
               printf("You entered: %s",university);
               fgets(university, sizeof(university), stdin);
               strtok(university, "\n");  
               deletInstitution(university,&Tbjru,tabuniv);
                
                break;
                case 6:
                deletetEvent(5,&Tbjru,tabepreuve);
                break;
            case 7:
                printf("enter number : \n");
                scanf("%d",&num);
                printf("enter number of institution : \n");
                scanf("%d",&uni);
                printf("enter number of event : \n");
                scanf("%d",&event);
                del_ath(&Tbjru,num,uni,event);
                break;
            case 8:
                deleteEmptyLignes(&Tbjru, tabepreuve);
                break;
            case 9:
               displaytab(tabuniv,Tbjru.columns);
               break;
            case 10: 
               displaytab(tabepreuve,Tbjru.rows);
               break;
            
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 11);
    return 0;
}
