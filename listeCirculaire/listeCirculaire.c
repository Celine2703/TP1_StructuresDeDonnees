#include "listeCirculaire.h"

void    initialiserHistorique(historique *h)
{
    h->action = NULL;
    h->suivant = h;
    h->precedent = h;
}

void    ajouterElement(historique *h, void *action)
{
    historique *nouvelElement = (historique*)malloc(sizeof(historique));
    if (nouvelElement == NULL)
    {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouvelElement->action = action;
    nouvelElement->suivant = h->suivant;
    nouvelElement->precedent = h;
    h->suivant->precedent = nouvelElement;
    h->suivant = nouvelElement;
}

void    *retirerElement(historique *h)
{
    if (h->suivant == h)
    {
        return NULL; // Rien à retirer
    }

    historique *elementSupprime = h->suivant;
    void *action = elementSupprime->action;

    elementSupprime->precedent->suivant = elementSupprime->suivant;
    elementSupprime->suivant->precedent = elementSupprime->precedent;

    free(elementSupprime);

    return action;
}

void    avancer(historique *h)
{
    if (h->suivant != h)
    {
        h->suivant = h->suivant->suivant;
    }
}

void    reculer(historique *h)
{
    if (h->suivant != h->precedent)
    {
        h->suivant = h->suivant->precedent;
    }
}

void    afficherHistorique(historique *h)
{
    historique *element = h->suivant;
    while (element != h)
    {
        printf("%s\n", (char*)element->action);
        element = element->suivant;
    }
}

void    libererHistorique(historique *h)
{
    while (h->suivant != h)
    {
        retirerElement(h);
    }
}
