#ifndef LISTECALCULE_H
#define LISTECALCULE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int digits;
    struct Node* next;
} Node;

typedef struct LargeNumber {
    Node* head;
} LargeNumber;

Node* ajouter_début(Node *pliste, int val);
Node* ajouter_fin(Node *pliste, int val);
void initializeLargeNumber(LargeNumber* ln, long int value);
void addLargeNumbers(const LargeNumber* ln1, const LargeNumber* ln2, LargeNumber* result);
void freeLargeNumber(LargeNumber* ln);
void afficher(LargeNumber *pliste);
void afficher_inverse(LargeNumber *pliste);
void afficher_rec(Node *courant);
LargeNumber *sumNumber(LargeNumber *n1, LargeNumber *n2);
void libererMemoire(LargeNumber *ln);

#endif