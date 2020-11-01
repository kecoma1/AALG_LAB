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

/* type definitions */
typedef int (*pfunc_sort)(int *, int, int);

/* Functions */

/**
 * @brief Function which sorts an array
 *        with the algorithm InsertSort
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @return int Basic operations done
 */
int InsertSort(int *table, int ip, int iu);

/**
 * @brief Function which sorts an array
 *        with the algorithm InsertSort
 *        (Reverse order)
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @return int Basic operations done
 */
int InsertSortInv(int *table, int ip, int iu);

/**
 * @brief Function which sorts an array
 *        with the mergesort algorithm
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @return int Basic operations that the algorithm performs
 */
int mergesort(int *table, int ip, int iu);

/**
 * @brief Function used by mergesort which
 *        merges (sorts) two tables
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @param imiddle Middle index that separates both tables
 * @return int Basic operations that the function performs
 */
int merge(int *table, int ip, int iu, int imiddle);

/**
 * @brief Function which sorts an array
 *        with the quicksort algorithm
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @return int Basic operations that the algorithm performs
 */
int quicksort(int *table, int ip, int iu);

/**
 * @brief Function used by quicksort which
 *        splits the table in two parts
 * 
 * @param table Table to be splited
 * @param ip First index of the table
 * @param iu Last index of the table
 * @param pos Variable where we are going to store the value of the pivot
 * @return int Basic operations that the function performs
 */
int split(int *table, int ip, int iu, int *pos);

/**
 * @brief Function used by quicksort which
 *        calculates the pivot
 * 
 * @param table Table where the pivot is calculated
 * @param ip First index of the array
 * @param iu Last index of the array
 * @param pos Variable where we are going to store the value of the pivot
 * @return int Basic operations that the function performs
 */
int median(int *table, int ip, int iu, int *pos);

#endif