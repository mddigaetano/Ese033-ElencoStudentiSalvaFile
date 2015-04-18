#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    studente alunni[N];
    FILE *pfile;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati in un array
    for(i=0;i<N;i++){
        printf("Inserisci il nome del %d° studente: ", i+1);
        scanf("%s", alunni[i].nome);
        printf("Inserisci il cognome del %d° studente: ", i+1);
        scanf("%s", alunni[i].cognome);
        printf("Inserisci l'eta' del %d° studente: ", i+1);
        scanf("%d", &alunni[i].eta);
        printf("Inserisci la classe del %d° studente: ", i+1);
        scanf("%s", alunni[i].classe);
        printf("\n");
    }
    // Codice per la scrittura dell'elenco su file
    pfile=fopen("elenco.dat","wb");
    
    if(pfile){
        fwrite(alunni, sizeof(studente), N, pfile);
        fclose(pfile);
        
        printf("Adesso inizio la stampa\n\n");
        
        pfile=fopen("elenco.dat","rb");
        fread(alunni, sizeof(studente), N, pfile);
        fclose(pfile);
        
        for(i=0;i<N;i++){
            printf("Nome: %s\n",alunni[i].nome);
            printf("Cognome: %s\n",alunni[i].cognome);
            printf("Eta': %d\n",alunni[i].eta);
            printf("Classe: %s\n",alunni[i].classe);
            printf("\n");
        }
    }
    else
        printf("Non sono riuscito ad aprire il file");
    
    return (EXIT_SUCCESS);
}
