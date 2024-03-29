/**
 * @file permutations.h
 * @author Marcos Bernuy
 *         Kevin de la Coba Malam
 * @brief File which defines types and prototypes of functions
 * @version 1.0
 * @date 2020-09-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef PERMUTACIONES_H
#define PERMUTACIONES_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

/* constants */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

/**
 * @brief Gives a random number 
 * 
 * @param inf Lower limit
 * @param sup Upper limit
 * @return int Random number
 */
int random_num(int inf, int sup);

/**
 * @brief Generates a permutations with size N
 * 
 * @param N Size of the permutation
 * @return int* Pointer to the permutation
 */
int* generate_perm(int N);

/**
 * @brief Generates n_perms permutations of size N
 * 
 * @param n_perms Number of permutations
 * @param N Size of the array
 * @return int** Pointer to the array of permutations
 */
int** generate_permutations(int n_perms, int N);

/**
 * @brief Function which swaps two elements
 *
 * @param el1 First element to be swapped
 * @param el2 Second element to be swapped
 * @return int Basic operations done
 */
int swap(int *el1, int *el2);

#endif
