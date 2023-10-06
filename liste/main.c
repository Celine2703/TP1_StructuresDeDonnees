#include "listes.h"

int main()
{
    maillon_t *liste = NULL;

    // Ajouter des éléments au début
    liste = ajouter_début(liste, 1);
    liste = ajouter_début(liste, 2);
    liste = ajouter_début(liste, 3);

    // Afficher la liste
    afficher(liste);

    // Rechercher un élément
    maillon_t *resultat = rechercher(liste, 2);
    if (resultat != NULL) {
        printf("Element trouvé : %d\n", resultat->x);
    } else {
        printf("Element non trouvé\n");
    }

    // Supprimer un élément
    int val_supprimee;
    liste = supprimer_val(liste, 2);
    afficher(liste);

    // Supprimer le premier élément
    liste = supprimer_debut(liste, &val_supprimee);
    printf("Element supprimé du début : %d\n", val_supprimee);
    afficher(liste);

    // Supprimer le dernier élément
    liste = supprimer_fin(liste, &val_supprimee);
    printf("Element supprimé de la fin : %d\n", val_supprimee);
    afficher(liste);

    return 0;
}