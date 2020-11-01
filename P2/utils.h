/**
 * @file sorting.h
 * @author Marcos Bernuy
 *         Kevin de la Coba Malam
 * @brief File where the prototypes of functions and types are defined
 * @version 1.0
 * @date 2020-09-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef ORDENACION_H
#define ORDENACION_H

/* constants */

#include <stdlib.h>
#include <stdio.h>

#ifndef ERR
#define ERR -1
#define OK (!(ERR))
#endif

/**
 * @brief Function which swaps two elements
 *
 * @param el1 First element to be swapped
 * @param el2 Second element to be swapped
 * @return int Basic operations done
 */
int swap(int *el1, int *el2);

#endif