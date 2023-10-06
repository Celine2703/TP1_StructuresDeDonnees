#include "listeCirculaire.h"

int main() {
    historique h;
    initialiserHistorique(&h);

    // Ajouter des actions à l'historique
    ajouterElement(&h, strdup("Action 1"));
    ajouterElement(&h, strdup("Action 2"));
    ajouterElement(&h, strdup("Action 3"));

    // Afficher l'historique
    printf("Historique initial :\n");
    afficherHistorique(&h);

    // Avancer et afficher l'historique
    printf("\nAvancer :\n");
    avancer(&h);
    afficherHistorique(&h);

    // Retirer un élément et afficher l'historique
    char *actionRetiree = (char*)retirerElement(&h);
    printf("\nAction retirée : %s\n", actionRetiree);
    free(actionRetiree);

    printf("Historique après retrait :\n");
    afficherHistorique(&h);

    // Reculer et afficher l'historique
    printf("\nReculer :\n");
    reculer(&h);
    afficherHistorique(&h);

    // Libérer l'historique
    libererHistorique(&h);

    return 0;
}
