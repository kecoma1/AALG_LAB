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
#include "permutations.h"

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

    for (i = 0; i < n_keys; i++)
        keys[i] = 1 + (i % max);

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

    for (i = 0; i < n_keys; i++)
    {
        keys[i] = .5 + max / (1 + max * ((double)rand() / (RAND_MAX)));
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
PDICT init_dictionary(int size, char order) {

    PDICT pdict;
    int i = 0;

    if (size <= 0 || (order != SORTED || order != NOT_SORTED))
        return NULL;

    pdict = (PDICT)malloc(sizeof(DICT));
    if (pdict == NULL)
        return NULL;

    /* Initializing the variables */
    pdict->n_data = 0;
    pdict->size = size;
    pdict->order = order;

    /* Reserving memory for the table */
    pdict->table = (int *)malloc(size * sizeof(pdict->table[0]));
    if (pdict->table == NULL) {
        free(pdict);
        return NULL;
    }

    /* Initializing the table */
    for (i = 0; i < size; i++) pdict->table[i] = 0;

    return pdict;
}

/**
 * @brief Function to free the resources of the dictionary
 * 
 * @param pdict Dictionary to free 
 */
void free_dictionary(PDICT pdict) {
    if (pdict == NULL) return;

    if (pdict->table != NULL) free(pdict->table);
    free(pdict);
}

/**
 * @brief Function to insert a key into a dictionary
 * 
 * @param pdict Dictionary where the key is going to be inserted
 * @param key Key to insert
 * @return int Basic operations done
 */
int insert_dictionary(PDICT pdict, int key) {
    
    int j = 0, BO = 0;

    if (pdict == NULL || key <= 0) return ERR;

    /* Checking how the table is sorted and if it is full */
    if (pdict->order == NOT_SORTED && pdict->n_data < pdict->size) {

        pdict->table[pdict->n_data] = key;
        pdict->n_data += 1;

        /* We didn't do any basic operation */
        return BO;
    } else if (pdict-/* your code */>order == NOT_SORTED && pdict->n_data < pdict->size) {

        pdict->table[pdict->size - 1] = key;
        j = pdict->size - 1;
        
        while (j >= 0) {
            if (pdict->table[j] > key) {
                pdict->table[j+1] = pdict->table[j];
                j--;
            } else break;
            BO++;
        }
        pdict->table[j+1] = key;
        pdict->n_data += 1;
    }

    return ERR;
}

/**
 * @brief Function to insert several keys into a dictionary
 * 
 * @param pdict Dictionary where the keys are going to be inserted
 * @param keys Keys to be inserted
 * @param n_keys Number of keys to be inserted
 * @return int Basic operations done
 */
int massive_insertion_dictionary(PDICT pdict, int *keys, int n_keys) {
    
    int i = 0, BO = 0, ret = 0;

    if (pdict == NULL || keys == NULL || n_keys <= 0) return ERR;

    /* Checking if there's enough space */
    if (pdict->size < (pdict->n_data + n_keys)) return ERR;

    /* Inserting keys */
    for (i = 0; i < n_keys; i++) {

        if (keys[i] <= 0) return ERR;
        ret = insert_dictionary(pdict, keys[i]);
        if (ret == ERR) return ERR;
        BO += ret;
    }

    return BO;
}

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
int search_dictionary(PDICT pdict, int key, int *ppos, pfunc_search method) {
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
int bin_search(int *table, int F, int L, int key, int *ppos) {
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
int lin_search(int *table, int F, int L, int key, int *ppos) {
    
    int i = 0, BO = 0;

    if (table == NULL || F < 0 || L < 0 || L < F || key <= 0 || ppos == NULL)
        return ERR;

    /* Iterating through all the elements of the array */
    for (i = 0; i <= L; i++) {
        BO++;

        /* Key found, saving index */
        if (table[i] == key) {
            *ppos = i;
            return BO;
        }
    }

    /* If we reach this point it means that we didn't find the key */
    *ppos = NOT_FOUND;
    return BO;
}

/**
 * @brief Function that searches a key as its done in the linear search 
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
int lin_auto_search(int *table, int F, int L, int key, int *ppos) {
    
    int i = 0, BO = 0;

    if (table == NULL || F < 0 || L < 0 || L < F || key <= 0 || ppos == NULL)
        return ERR;

    /* Iterating through all the elements of the array */
    for (i = 0; i <= L; i++) {
        BO++;

        /* Key found, saving index */
        if (table[i] == key) {
            *ppos = i;

            /* Swapping */
            if (i > 0) swap(table[i], table[i-1]);
            
            *ppos = i;
            return BO;
        }
    }

    /* If we reach this point it means that we didn't find the key */
    *ppos = NOT_FOUND;
    return BO;
}
