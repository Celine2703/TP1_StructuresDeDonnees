#ifndef LISTESGEN_H
#define LISTESGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct maillon 
{
    void *data;
    struct maillon *suiv;
}       maillon_t;

#endif