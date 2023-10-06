#ifndef LISTECIRCULAIRE_H
#define LISTECIRCULAIRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct historique
{
    void                *action;
    struct historique   *suivant;
    struct historique   *precedent;
} historique;

void    initialiserHistorique(historique *h);
void    ajouterElement(historique *h, void *action);
void    *retirerElement(historique *h);
void    avancer(historique *h);
void    reculer(historique *h);
void    afficherHistorique(historique *h);
void    libererHistorique(historique *h);

#endif
