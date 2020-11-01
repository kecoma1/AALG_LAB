#include "utils.h"

/**
 * @brief Function which swaps two elements
 *
 * @param first element to be swapped
 * @param second element to be swapped
 * @return int Basic operations done
 */
int swap(int *el1, int *el2) {

    int *aux = NULL;

    /* Checking arguments */
    if (el1 == NULL || el2 == NULL)
        return ERR;

    /* The swap */
    *aux = *el1;
    *el1 = *el2;
    *el2 = *aux;

    return OK; /* Doubt if three should be returned or not */
}
