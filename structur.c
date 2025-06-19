#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define MAX_FACTURES 100
#define MAX_CHAINE 100

typedef struct {
    char numero[MAX_CHAINE];
    float montant;
    char objet[MAX_CHAINE];
    char id_etudiant[MAX_CHAINE];
    int inscription; // 1 pour oui, 0 pour non
    char scolarite[MAX_CHAINE];
} Facture;

Facture tab_factures[MAX_FACTURES];
int nb_factures = 0;

void remplir_tab() {
    printf("\n--- Remplissage du tableau des factures ---\n");
    printf("Nombre de factures à saisir (max %d) : ", MAX_FACTURES - nb_factures);
    int a_ajouter;
    scanf("%d", &a_ajouter);
    getchar(); // Pour consommer le '\n'

    if (a_ajouter <= 0 || a_ajouter + nb_factures > MAX_FACTURES) {
        printf("Nombre invalide ou tableau plein.\n");
        return;
    }

    for (int i = 0; i < a_ajouter; i++) {
        printf("\nFacture %d:\n", nb_factures + 1);
        
        printf("Numéro : ");
        fgets(tab_factures[nb_factures].numero, MAX_CHAINE, stdin);
        tab_factures[nb_factures].numero[strcspn(tab_factures[nb_factures].numero, "\n")] = 0;
        
        printf("Montant : ");
        scanf("%f", &tab_factures[nb_factures].montant);
        getchar();
        
        printf("Objet : ");
        fgets(tab_factures[nb_factures].objet, MAX_CHAINE, stdin);
        tab_factures[nb_factures].objet[strcspn(tab_factures[nb_factures].objet, "\n")] = 0;
        
        printf("ID Étudiant : ");
        fgets(tab_factures[nb_factures].id_etudiant, MAX_CHAINE, stdin);
        tab_factures[nb_factures].id_etudiant[strcspn(tab_factures[nb_factures].id_etudiant, "\n")] = 0;
        
        printf("Inscription (oui/non) : ");
        char reponse[MAX_CHAINE];
        fgets(reponse, MAX_CHAINE, stdin);
        tab_factures[nb_factures].inscription = (strcmp(reponse, "oui\n") == 0) ? 1 : 0;
        
        printf("Scolarité (nom de l'établissement) : ");
        fgets(tab_factures[nb_factures].scolarite, MAX_CHAINE, stdin);
        tab_factures[nb_factures].scolarite[strcspn(tab_factures[nb_factures].scolarite, "\n")] = 0;
        
        nb_factures++;
    }

    printf("\n%d factures ont été ajoutées. Total = %d\n", a_ajouter, nb_factures);
}