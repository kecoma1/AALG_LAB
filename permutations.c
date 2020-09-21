/**
 * @file permutations.c
 * @author  Marcos Bernuy
 *          Kevin de la Coba Malam
 * @brief File where the permutations are created
 * @version 1.0
 * @date 2020-09-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "permutations.h"

/**
 * @brief Gives a random number 
 * 
 * @param inf Lower limit
 * @param sup Upper limit
 * @return int Random number
 */
int random_num(int inf, int sup) {
  /* your code */
}

/**
 * @brief Generates a permutations with size N
 * 
 * @param N Size of the permutation
 * @return int* Pointer to the permutation
 */
int* generate_perm(int N) {
  /* your code */
}

/**
 * @brief Generates n_perms permutations of size N
 * 
 * @param n_perms Number of permutations
 * @param N Size of the array
 * @return int** Pointer to the array of permutations
 */
int** generate_permutations(int n_perms, int N) {
  int i = 0, **perms = NULL;

  if (n_perms <= 0 || N <= 0) return NULL;

  /* Reserving memory for the permutations */
  perms = (int**)malloc(n_perms*sizeof(int*));
  if (perms == NULL) return NULL;

  /* Loop for creating the permutations */
  for (i = 0; i < n_perms; i++) {
    perms[i] = (int) /* Aqui pongo algo */ /* */
  }
}
