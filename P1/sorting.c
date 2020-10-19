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