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
 * @brief Function which swaps two elements
 *
 * @param first element to be swapped
 * @param second element to be swapped
 * @return int Basic operations done
 */
int swap(int *el1, int *el2)
{

    int *aux = NULL;

    /* Checking arguments */
    if (el1 == NULL || el2 == NULL)
        return -1;

    /* The swap */
    aux = el1;
    el1 = el2;
    el2 = aux;

    return 3; /* Doubt if three should be returned or not */
}

/**
 * @brief Function which sorts an array
 *        with the algorithm InsertSort
 * 
 * @param table Array to be sorted
 * @param ip 
 * @param iu 
 * @return int Basic operations done
 */
int InsertSort(int *table, int ip, int iu)
{

    int i = 0, j = 0, A = 0, counter = 0;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip)
        return ERR;

    for (i = ip + 1; i <= iu; i++)
    {
        A = table[i];
        j = i - 1;
        while (j >= ip)
        {
            counter++;
            if (table[j] > A)
            {
                table[j + 1] = table[j];
                j--;
            }
            else
                break;
        }
        table[j + 1] = A;
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
int InsertSortInv(int *table, int ip, int iu)
{

    int i = 0, j = 0, A = 0, counter = 0;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip)
        return ERR;

    for (i = ip + 1; i <= iu; i++)
    {
        A = table[i];
        j = i - 1;
        while (j >= ip)
        {
            if (table[j] < A)
            {
                counter++;
                table[j + 1] = table[j];
                j--;
            }
            else
                break;
        }
        counter++;
        table[j + 1] = A;
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
int mergesort(int *table, int ip, int iu) {

    int m = 0, bo = 0, ret = 0;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip)
        return ERR;

    /* In case there's only one integer in the array */
    if (ip == iu)
        return OK;

    /* Getting the middle value of the array */
    m = (ip + iu) / 2;

    ret = mergesort(table, ip, m);
    if (ret == ERR) return ERR;
    bo += ret;

    ret = mergesort(table, m + 1, iu);
    if (ret == ERR) return ERR;
    bo += ret;

    ret = merge(table, ip, iu, m);
    if (ret == ERR) return ERR;
    bo += ret;

    return bo;
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
int merge(int *table, int ip, int iu, int imiddle) {

    int i, j, k, size, counter = 0, *table2 = NULL;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip || imiddle < 0 || ip > imiddle || iu < imiddle)
        return ERR;

    /* In case there's only one integer in the array */
    if (ip == iu)
        return OK;

    size = iu - ip + 1;
    table2 = (int *)malloc(size * sizeof(table2[0]));
    if (table2 == NULL)
        return ERR;

    i = ip;
    j = imiddle + 1;
    k = iu;
    while (i <= imiddle && j <= iu) {
        if (table[i] < table[j]) {
            table2[k] = table[i];
            i++;
            counter++;
        }
        else {
            table2[k] = table[j];
            j++;
        }
        k++;
    }

    if (i > imiddle) {
        while (j <= iu) {
            table2[k] = table[j];
            j++;
            k++;
        }
    }
    else if (j > iu){
        while (i <= imiddle) {
            table2[k] = table[i];
            i++;
            k++;
        }
    }

    /* Copying table2 on table */
    for (i = ip; i < iu; i++){
        table[i] = table2[i];
    }

    free(table2);
    return counter;
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
int quicksort(int *table, int ip, int iu){

    int m = 0, *pivot = NULL, counter = 0;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip)
        return ERR;

    if (ip == iu)
        return m;

    pivot = (int)malloc(sizeof(int *));
    if (pivot == NULL)
        return m;

    m = split(table, ip, iu, pivot);
    if (f < m - 1)
        counter = quicksort(table, ip, m - 1);
    if (m + 1 < iu)
        counter = quicksort(table, m + 1, iu);

    return counter;
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
int split(int *table, int ip, int iu, int *pos) {

    int counter = 0, k = 0;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip || pos == NULL)
        return ERR;

    counter = median(table, ip, iu, pos);
    k = *pos;

    counter = swap(table(ip), pos);
    if (counter == ERR)
        return ERR;

    pos = &ip;
    for (i = ip + 1; i < iu; i++)
    {
        if (table[i] < k)
        {
            *pos = *pos + 1;
            if (swap(table[i], table[*pos]) == -1)
                return ERR;
        }
    }

    if (swap(table[ip], table[*pos]) == -1)
        return ERR;

    return counter;
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

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip || pos == NULL)
        return ERR;

    pos = &ip;

    return 0;
}
