#include "listeCalcule.h"

Node* ajouter_fin(Node *pliste, int val)
{
    Node *nouveau_noeud = (Node*)malloc(sizeof(Node));
    if (nouveau_noeud == NULL)
    {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau_noeud->digits = val;
    nouveau_noeud->next = NULL;

    if (pliste == NULL)
        return nouveau_noeud;

    Node *courant = pliste;
    while (courant->next != NULL)
    {
        courant = courant->next;
    }
    courant->next = nouveau_noeud;
    return pliste;
}

void initializeLargeNumber(LargeNumber* ln, long int value)
{
    ln->head = NULL; // Initialisez le pointeur de la liste à NULL

    if (value == 0) {
        // Si la valeur est zéro, créez un seul nœud avec la valeur zéro
        ln->head = (Node*)malloc(sizeof(Node));
        ln->head->digits = 0;
        ln->head->next = NULL;
        return;
    }

    Node* current = NULL;

    while (value > 0)
    {
        int digit = value % 100000;
        current = ajouter_fin(current, digit);
        value /= 100000;
    }

    ln->head = current;
}

LargeNumber *sumNumber(LargeNumber *n1, LargeNumber *n2)
{
    LargeNumber *result;

    result = malloc(sizeof(LargeNumber));

    Node *result1;
    Node *node1 = n1->head;
    Node *node2 = n2->head;
    int retenu = 0;

    result->head = malloc(sizeof(Node));
    result1 = result->head;
    result1->digits = 0;

    while (node1 || node2)
    {
        if (node1)
        {
            result1->digits += retenu;
                retenu = 0;
            result1->digits += node1->digits;
            node1 = node1->next;
        }
        if (node2)
        {
            result1->digits += node2->digits;
            node2 = node2->next;
        }
        printf("nombre : %d\n", result1->digits);
        if (node1 || node2)
        {
            if ( result1->digits % 100000 > 0)
            {
                retenu = retenu /100000;
                result1->digits %= 100000;
            }
            result1->next = malloc(sizeof(Node));
            result1 = result1->next;
            result1->digits = 0;
        }
        else
        {
            result1->next = NULL;
        }

    }
    return result;
}

void afficher(LargeNumber *pliste)
{
    Node *courant;
    
    courant = pliste ->head;
    while (courant != NULL)
    {
        printf("%d -> ", courant->digits);
        courant = courant->next;
    }
    printf("NULL\n");
}

void libererMemoire(LargeNumber *ln)
{
    Node *courant = ln->head;
    while (courant != NULL) {
        Node *temp = courant;
        courant = courant->next;
        free(temp);
    }
    ln->head = NULL; // Réinitialisez la tête à NULL pour indiquer que la liste est vide.
}

void afficher_inverse(LargeNumber *pliste)
{
    afficher_rec(pliste->head);
}

void afficher_rec(Node *courant)
{
    if (courant == NULL)
        return ;
    afficher_rec(courant->next);
    printf("%d -> ", courant->digits);
}