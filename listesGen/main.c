#include "listes.h"

int comparer_entiers(void *a, void *b)
{
    int *x = (int*)a;
    int *y = (int*)b;
    return (*x == *y) ? 0 : 1;
}

void liberer_entier(void *data)
{
    free(data);
}

void afficher_entier(void *data)
{
    int *x = (int*)data;
    printf("%d", *x);
}

maillon_t* ajouter_debut(maillon_t *pliste, void *data)
{
    maillon_t *nouveau_maillon = (maillon_t*)malloc(sizeof(maillon_t));
    if (nouveau_maillon == NULL) {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau_maillon->data = data;
    nouveau_maillon->suiv = pliste;
    return nouveau_maillon;
}

maillon_t* ajouter_fin(maillon_t *pliste, void *data)
{
    maillon_t *nouveau_maillon = (maillon_t*)malloc(sizeof(maillon_t));
    if (nouveau_maillon == NULL)
    {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau_maillon->data = data;
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

maillon_t* rechercher(maillon_t *pliste, void *data, int (*compar)(void*, void*))
{
    maillon_t *courant = pliste;
    while (courant != NULL)
    {
        if (compar(courant->data, data) == 0)
        {
            return courant;
        }
        courant = courant->suiv;
    }
    return NULL;
}

maillon_t* supprimer_debut(maillon_t *pliste, void (*liberer)(void*))
{
    maillon_t *temp;
    
    temp = pliste->suiv;
    if (pliste == NULL)
    {
        return NULL;
    }
    liberer(pliste->data);
    free(pliste);
    return temp;
}

maillon_t* supprimer_fin(maillon_t *pliste, void (*liberer)(void*))
{
    maillon_t *courant;
    
    if (pliste == NULL)
    {
        return NULL;
    }
    if (pliste->suiv == NULL)
    {
        liberer(pliste->data);
        free(pliste);
        return NULL;
    }

    courant = pliste;
    while (courant->suiv->suiv != NULL) 
    {
        courant = courant->suiv;
    }

    liberer(courant->suiv->data);
    free(courant->suiv);
    courant->suiv = NULL;
    return pliste;
}

maillon_t* supprimer_val(maillon_t *pliste, void *data, int (*compar)(void*, void*), void (*liberer)(void*))
{
    maillon_t *temp;
    maillon_t *courant;
    
    if (pliste == NULL)
    {
        return NULL;
    }
    if (compar(pliste->data, data) == 0) 
    {
        temp = pliste->suiv;
        liberer(pliste->data);
        free(pliste);
        return temp;
    }
    courant = pliste;
    while (courant->suiv != NULL && compar(courant->suiv->data, data) != 0)
    {
        courant = courant->suiv;
    }
    if (courant->suiv != NULL)
    {
        temp = courant->suiv;
        courant->suiv = courant->suiv->suiv;
        liberer(temp->data);
        free(temp);
    }
    return pliste;
}

void afficher(maillon_t *pliste, void (*afficher_data)(void*))
{
    maillon_t *courant;
    
    courant = pliste;
    while (courant != NULL)
    {
        afficher_data(courant->data);
        printf(" -> ");
        courant = courant->suiv;
    }
    printf("NULL\n");
}

int main(){
    maillon_t *liste = NULL;

    // Ajouter des éléments au début
    int *a = (int*)malloc(sizeof(int));
    int *b = (int*)malloc(sizeof(int));
    int *c = (int*)malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;
    liste = ajouter_debut(liste, a);
    liste = ajouter_debut(liste, b);
    liste = ajouter_debut(liste, c);

    // Afficher la liste
    afficher(liste, afficher_entier);

    // Rechercher un élément
    int recherche = 2;
    maillon_t *resultat = rechercher(liste, &recherche, comparer_entiers);
    if (resultat != NULL) {
        printf("Element trouvé : %d\n", *((int*)resultat->data));
    } else {
        printf("Element non trouvé\n");
    }

    // Supprimer un élément
    liste = supprimer_val(liste, &recherche, comparer_entiers, liberer_entier);
    afficher(liste, afficher_entier);

    // Supprimer le premier élément
    liste = supprimer_debut(liste, liberer_entier);
    afficher(liste, afficher_entier);

    // Supprimer le dernier élément
    liste = supprimer_fin(liste, liberer_entier);
    afficher(liste, afficher_entier);

    return 0;
}
