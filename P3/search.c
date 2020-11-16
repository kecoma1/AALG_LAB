/**
 *
 * Description: Implementation of functions for search
 *
 * File: search.c
 * Author: Carlos Aguirre and Javier Sanz-Cruzado
 * Version: 1.0
 * Date: 14-11-2016
 *
 */

#include "search.h"

#include <stdlib.h>
#include <math.h>

/**
 *  Key generation functions
 *
 *  Description: Receives the number of keys to generate in the n_keys
 *               parameter. The generated keys go from 1 to max. The
 * 				 keys are returned in the keys parameter which must be 
 *				 allocated externally to the function.
 */
  
/**
 *  Function: uniform_key_generator
 *               This function generates all keys from 1 to max in a sequential
 *               manner. If n_keys == max, each key will just be generated once.
 */
void uniform_key_generator(int *keys, int n_keys, int max)
{
  int i;

  for(i = 0; i < n_keys; i++) keys[i] = 1 + (i % max);

  return;
}

/**
 *  Function: potential_key_generator
 *               This function generates keys following an approximately
 *               potential distribution. The smaller values are much more 
 *               likely than the bigger ones. Value 1 has a 50%
 *               probability, value 2 a 17%, value 3 the 9%, etc.
 */
void potential_key_generator(int *keys, int n_keys, int max)
{
  int i;

  for(i = 0; i < n_keys; i++) 
  {
    keys[i] = .5+max/(1 + max*((double)rand()/(RAND_MAX)));
  }

  return;
}

/**
 * @brief Function to initialize the dictionary, reserves memory for it
 * 
 * @param size Size of the dictionary
 * @param order Order of the table. Ordered or not ordered
 * @return PDICT Created dictionary  
 */
PDICT init_dictionary (int size, char order)
{
	/* your code */
}

/**
 * @brief Function to free the resources of the dictionary
 * 
 * @param pdict Dictionary to free 
 */
void free_dictionary(PDICT pdict)
{
	/* your code */
}

/**
 * @brief Function to insert a key into a dictionary
 * 
 * @param pdict Dictionary where the key is going to be inserted
 * @param key Key to insert
 * @return int Status of the function, OK or ERR
 */
int insert_dictionary(PDICT pdict, int key)
{
	/* your code */
}

/**
 * @brief Function to insert several keys into a dictionary
 * 
 * @param pdict Dictionary where the keys are going to be inserted
 * @param keys Keys to be inserted
 * @param n_keys Number of keys to be inserted
 * @return int Status of the function, OK or ERR
 */
int massive_insertion_dictionary (PDICT pdict,int *keys, int n_keys)
{
	/* your code */
}

/**
 * @brief Function to search in the dictionary a key given an function
 * 
 * @param pdict Dictionary where we are going to search the key
 * @param key Key to search
 * @param ppos Variable passed by reference where we are going 
 *             to store the index of the key
 * @param method Method to use for searching
 * @return int Status of the function, OK or ERR
 */
int search_dictionary(PDICT pdict, int key, int *ppos, pfunc_search method)
{
	/* your code */
}


/* Search functions of the Dictionary ADT */
/**
 * @brief Function that searches into a table using the 
 *        binary search algorithm
 * 
 * @param table Table where we have to search
 * @param F First index of the table
 * @param L Last index of the table
 * @param key Key to search
 * @param ppos Variable passed by reference where we are going 
 *             to store the index of the key
 * @return int Basic operations done
 */
int bin_search(int *table,int F,int L,int key, int *ppos)
{
	/* your code */
}

/**
 * @brief Function that searches into a table using the 
 *        linear search algorithm
 * 
 * @param table Table where we have to search
 * @param F First index of the table
 * @param L Last index of the table
 * @param key Key to search
 * @param ppos Variable passed by reference where we are going 
 *             to store the index of the key
 * @return int Basic operations done
 */
int lin_search(int *table,int F,int L,int key, int *ppos)
{
	/* your code */
}

/**
 * @brief Function that searches a key as its done in the linear sort 
 *        algorithm but when the key is founded we swap it with the previous one
 * 
 * @param table Table where we have to search
 * @param F First index of the table
 * @param L Last index of the table
 * @param key Key to search
 * @param ppos Variable passed by reference where we are going 
 *             to store the index of the key
 * @return int Basic operations done
 */
int lin_auto_search(int *table,int F,int L,int key, int *ppos)
{
	/* your code */
}


