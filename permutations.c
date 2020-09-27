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

/* Private functions */
/**
 * @brief 
 * 
 * @param a Place with the value that we want to swap
 * @param b Second place with the value that we want to swap
 * @return short Status of the function
 */
short swap(int *a, int *b) {

    /* Local variables */
    int aux = 0;

    /* Checking arguments */
    if (a == NULL || b == NULL) return ERR;

    /* Swapping the values */
    aux = *b;
    *b = *a;
    *a = aux;

    return OK;
}


/* Public functions */
/**
 * @brief Gives a random number 
 * 
 * @param inf Lower limit
 * @param sup Upper limit
 * @return int Random number
 */
int random_num(int inf, int sup) {
    
  /* Variables used in the code */
  int random = 0;

  /* Checking arguments */
  if (inf < 0 || sup < 0 || inf > sup) return ERR;
  
  random = rand();
  if(random < 0) return ERR;

  /* Taking the random number between 0 and rand_max */
  random = inf + (int) (((sup - inf + 1.0) * random) / (RAND_MAX + 1.0));
  if (random < inf || random > sup) return ERR;

  return random;
}

/**
 * @brief Generates a permutations with size N
 * 
 * @param N Size of the permutation
 * @return int* Pointer to the permutation
 */
int* generate_perm(int N) {

  int i, random;
  int *perm = NULL;

  if(N <= 0)
    return NULL;
  
  perm = (int*)malloc(N * sizeof(int));
  if (perm == NULL)
    return NULL;

  for(i = 0; i < N; i++){
    perm[i] = i+1;
  }

  for(i = 0; i < N; i++){
    random = random_num(i, N-1);
    if (random == ERR) {
      free(perm);
      return NULL;
    }
    if (swap(&perm[i], &perm[random]) != OK){
      free(perm);
      return NULL;
    }
  }
  
  return perm;
}

/**
 * @brief Generates n_perms permutations of size N
 * 
 * @param n_perms Number of permutations
 * @param N Size of the array
 * @return int** Pointer to the array of permutations
 */
int** generate_permutations(int n_perms, int N) {
  int i = 0, n = 0, **perms = NULL;

  if (n_perms <= 0 || N <= 0) return NULL;

  /* Reserving memory for the permutations */
  perms = (int**)malloc(n_perms*sizeof(int*));
  if (perms == NULL) return NULL;

  /* Loop for creating the permutations */
  for (i = 0; i < n_perms; i++) {
    
    perms[i] = generate_perm(N);
    if (perms[i] == NULL) {
      for(n = 0; n < i; n++) free(perms[n]);
      free(perms);
      return NULL;
    }
  }
  
  return perms;
}