/**
 *
 * Descriptions: Declarations of the search functions and data
 *
 * File: search.h
 * Author: Carlos Aguirre and Javier Sanz-Cruzado
 * Version: 1.0
 * Date: 14-11-2019
 *
 */

#ifndef SEARCH_H_
#define SEARCH_H_

/* constantes */

#ifndef ERR
#define ERR -1
#define OK (!ERR)
#endif


#define NOT_FOUND -2

#define SORTED 1
#define NOT_SORTED 0

/* type definitions */
typedef struct dictionary {
  int size; /* table size */
  int n_data; /* number of entries in the table */
  char order;  /* sorted or unsorted table */
  int *table;  /* data table */
} DICT, *PDICT;

typedef int (* pfunc_search)(int*, int, int, int, int*);
typedef void (* pfunc_key_generator)(int*, int, int);

/* Dictionary ADT */
/**
 * @brief Function to initialize the dictionary, reserves memory for it
 * 
 * @param size Size of the dictionary
 * @param order Order of the table. Ordered or not ordered
 * @return PDICT Created dictionary  
 */
PDICT init_dictionary (int size, char order);

/**
 * @brief Function to free the resources of the dictionary
 * 
 * @param pdict Dictionary to free 
 */
void free_dictionary(PDICT pdict);

/**
 * @brief Function to insert a key into a dictionary
 * 
 * @param pdict Dictionary where the key is going to be inserted
 * @param key Key to insert
 * @return int Basic operations done
 */
int insert_dictionary(PDICT pdict, int key);

/**
 * @brief Function to insert several keys into a dictionary
 * 
 * @param pdict Dictionary where the keys are going to be inserted
 * @param keys Keys to be inserted
 * @param n_keys Number of keys to be inserted
 * @return int Basic operations done
 */
int massive_insertion_dictionary (PDICT pdict,int *keys, int n_keys);

/**
 * @brief Function to search in the dictionary a key given an function
 * 
 * @param pdict Dictionary where we are going to search the key
 * @param key Key to search
 * @param ppos Variable passed by reference where we are going 
 *             to store the index of the key
 * @param method Method to use for searching
 * @return int Basic operations done
 */
int search_dictionary(PDICT pdict, int key, int *ppos, pfunc_search method);


/* Search functions for the Dictionary ADT */
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
int bin_search(int *table,int F,int L,int key, int *ppos);

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
int lin_search(int *table,int F,int L,int key, int *ppos);

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
int lin_auto_search(int *table,int F,int L,int key, int *ppos);

/**
 *  Key generation functions
 *
 *  Description: Receives the number of keys to generate in the n_keys
 *               parameter. The generated keys go from 1 to max. The
 * 				 keys are returned in the keys parameter which must be 
 *				 allocated externally to the function.
 */
void uniform_key_generator(int *keys, int n_keys, int max);
void potential_key_generator(int *keys, int n_keys, int max);


int print_dictionary(PDICT pdict);
#endif

