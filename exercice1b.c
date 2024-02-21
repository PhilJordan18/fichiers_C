#include <stdio.h>

int sommeDansFichier(const char *nomFichier);
void ecrireSommeFichier(const char *nomFichier, int somme);

int main(){
    char nomFichierEntree[] = "nombre.txt";
    char nomFichierSortie[] = "resultat.txt";
    int somme = sommeDansFichier(nomFichierEntree);

    if(somme > 0){
        printf("La somme des nombres des fichiers est : %d\n", somme);
    }

    ecrireSommeFichier(nomFichierSortie, somme);
    printf("La somme a été écrite dans le fichier %s", nomFichierSortie);
}

int sommeDansFichier(const char *nomFichier){
    int nombre, somme = 0;
    FILE *fichier = fopen(nomFichier, "r");
    if(fichier == NULL){
        printf("Une erreur est survenu lors de l'ouverture  du fichier %s\n", nomFichier);
        return 0;
    }

    while (fscanf(fichier, "%d", &nombre) == 1){
        somme += nombre;
    }
    fclose(fichier);
    return somme;
}
void ecrireSommeFichier(const char *nomFichier, int somme){
    FILE *fichier = fopen(nomFichier, "r");
    if(fichier == NULL){
        printf("Une erreur est survenu lors de l'ouverture  du fichier %s\n", nomFichier);
        return;
    }
    fprintf(fichier, "%d", somme);
    fclose(fichier);
}