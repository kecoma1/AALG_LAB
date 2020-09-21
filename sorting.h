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

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

/* type definitions */
typedef int (* pfunc_sort)(int*, int, int);

/* Functions */

/**
 * @brief Function which sorts an array
 *        with the algorithm InsertSort
 * 
 * @param table Array to be sorted
 * @param ip 
 * @param iu 
 * @return int Basic operations done
 */
int InsertSort(int* table, int ip, int iu);

/**
 * @brief Function which sorts an array
 *        with the algorithm InsertSort
 *        (Reverse order)
 * 
 * @param table Array to be sorted
 * @param ip 
 * @param iu 
 * @return int Basic operations done
 */
int InsertSortInv(int* table, int ip, int iu);

#endif