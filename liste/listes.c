#include "listes.h"


maillon_t* ajouter_début(maillon_t *pliste, int val)
{
    maillon_t *nouveau_maillon = (maillon_t*)malloc(sizeof(maillon_t));
    if (nouveau_maillon == NULL) {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau_maillon->x = val;
    nouveau_maillon->suiv = pliste;
    return nouveau_maillon;
}

maillon_t* ajouter_fin(maillon_t *pliste, int val)
{
    maillon_t *nouveau_maillon = (maillon_t*)malloc(sizeof(maillon_t));
    if (nouveau_maillon == NULL)
    {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau_maillon->x = val;
    nouveau_maillon->suiv = NULL;

    if (pliste == NULL)
    {
        return nouveau_maillon;
    }

    maillon_t *courant = pliste;
    while (courant->suiv != NULL)
    {
        courant = courant->suiv;
    }
    courant->suiv = nouveau_maillon;
    return pliste;
}

maillon_t* rechercher(maillon_t *pliste, int val)
{
    maillon_t *courant = pliste;
    while (courant != NULL)
    {
        if (courant->x == val)
        {
            return courant;
        }
        courant = courant->suiv;
    }
    return NULL;
}

maillon_t* supprimer_debut(maillon_t *pliste, int *pval)
{
    maillon_t *temp;
    
    temp = pliste->suiv;
    if (pliste == NULL)
    {
        *pval = -1;
        return NULL;
    }
    *pval = pliste->x;
    free(pliste);
    return temp;
}

maillon_t* supprimer_fin(maillon_t *pliste, int *pval)
{
    maillon_t *courant;
    
    if (pliste == NULL)
    {
        *pval = -1;
        return NULL;
    }
    if (pliste->suiv == NULL)
    {
        *pval = pliste->x;
        free(pliste);
        return NULL;
    }

    courant = pliste;
    while (courant->suiv->suiv != NULL) 
    {
        courant = courant->suiv;
    }

    *pval = courant->suiv->x;
    free(courant->suiv);
    courant->suiv = NULL;
    return pliste;
}

maillon_t* supprimer_val(maillon_t *pliste, int val)
{
    maillon_t *temp;
     maillon_t *courant;
    
    if (pliste == NULL)
    {
        return NULL;
    }
    if (pliste->x == val) 
    {
        temp = pliste->suiv;
        free(pliste);
        return temp;
    }
    courant = pliste;
    while (courant->suiv != NULL && courant->suiv->x != val)
    {
        courant = courant->suiv;
    }
    if (courant->suiv != NULL)
    {
        temp = courant->suiv;
        courant->suiv = courant->suiv->suiv;
        free(temp);
    }
    return pliste;
}

void afficher(maillon_t *pliste)
{
    maillon_t *courant;
    
    courant = pliste;
    while (courant != NULL)
    {
        printf("%d -> ", courant->x);
        courant = courant->suiv;
    }
    printf("NULL\n");
}
