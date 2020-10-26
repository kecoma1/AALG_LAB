/**
 * @file sorting.c
 * @author Marcos Bernuy
 *         Kevin de la Coba Malam
 * @brief File where the functions which sort are defined
 * @version 1.0
 * @date 2020-09-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "sorting.h"

/**
 * @brief Function which sorts an array
 *        with the algorithm InsertSort
 * 
 * @param table Array to be sorted
 * @param ip 
 * @param iu 
 * @return int Basic operations done
 */
int InsertSort(int* table, int ip, int iu) {

  int i = 0, j = 0, A = 0, counter = 0;

  if (table == NULL || ip < 0 || iu < 0 || iu < ip) return ERR;
  
  for (i = ip+1; i <= iu; i++) {
    A = table[i];
    j = i-1;
    while(j >= ip) {
      counter++;
      if (table[j] > A) {
        table[j+1] = table[j];
        j--;
      }
      else break;
    }
    table[j+1] = A;
  }
  return counter;
}

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
int InsertSortInv(int* table, int ip, int iu) {
  
  int i = 0, j = 0, A = 0, counter = 0;

  if (table == NULL || ip < 0 || iu < 0 || iu < ip)
    return ERR;

  for (i = ip + 1; i <= iu; i++){
    A = table[i];
    j = i - 1;
    while (j >= ip){
      if(table[j] < A){
        counter++;
        table[j+1] = table[j];
        j--;
      } else break;
    }
    counter++;
    table[j+1] = A;
  }
  return counter;
}

/**
 * @brief Function which sorts an array
 *        with the mergesort algorithm
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @return int Basic operations that the algorithm performs
 */
int mergesort(int* table, int ip, int iu) {

  if (table == NULL || ip < 0 || iu < 0 || iu < ip) 
    return ERR;

}

/**
 * @brief Function used by mergesort which
 *        merges (sorts) two tables
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @param imiddle Middle index that separates both tables
 * @return int Basic operations that the algorithm performs
 */
int merge(int* table, int ip, int iu, int imiddle) {

  if (table == NULL || ip < 0 || iu < 0 || iu < ip || imiddle < 0 || ip > imiddle || iu < imiddle) 
    return ERR;

}

/**
 * @brief Function which sorts an array
 *        with the quicksort algorithm
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @return int Basic operations that the algorithm performs
 */
int quicksort(int* table, int ip, int iu) {

  if (table == NULL || ip < 0 || iu < 0 || iu < ip)
    return ERR;
}

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
int split(int* table, int ip, int iu, int* pos) {

  if (table == NULL || ip < 0 || iu < 0 || iu < ip || pos == NULL)
    return ERR;
}

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
int median(int *table, int ip, int iu, int *pos) {
  
  if (table == NULL || ip < 0 || iu < 0 || iu < ip || pos == NULL)
    return ERR;
}