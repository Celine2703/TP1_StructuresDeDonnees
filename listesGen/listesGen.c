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
