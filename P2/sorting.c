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
#include "permutations.h"

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

    int i = 0, j = 0, k = 0, size = 0, counter = 0, *table2 = NULL;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip || imiddle < 0 || ip > imiddle || iu < imiddle)
        return ERR;

    size = iu - ip + 1;
    table2 = (int *)malloc(size * sizeof(table2[0]));
    if (table2 == NULL)
        return ERR;

    i = ip;
    j = imiddle + 1;
    k = 0;
    while (i <= imiddle && j <= iu) {
        if (table[i] < table[j]) {
            table2[k] = table[i];
            i++;
        }
        else {
            table2[k] = table[j];
            j++;
        }
        k++;
        counter++;
    }

    if (i > imiddle) {
        while (j <= iu) {
            table2[k] = table[j];
            j++;
            k++;
            counter++;
        }
    }
    else if (j > iu){
        while (i <= imiddle) {
            table2[k] = table[i];
            i++;
            k++;
            /* TODO: Comprobar que esto es correcto counter++;*/
        }
    }

    /* Copying table2 on table */
    for (i = ip, j = 0; i <= iu; i++, j++){
        table[i] = table2[j];
    }

    free(table2);
    table2 = NULL;
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
int quicksort(int *table, int ip, int iu) {

    int pivot = 0, bo = 0, ret = 0;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip)
        return ERR;

    /* In case there's only one integer in the array */
    if (ip == iu)
        return OK;

    ret = split(table, ip, iu, &pivot);
    if (ret == ERR) return ERR;
    bo += ret;

    if (ip < pivot - 1) {
        ret = quicksort(table, ip, pivot - 1);
        if (ret == ERR) return ERR;
        bo += ret;
    }
    if (pivot + 1 < iu) {
        ret = quicksort(table, pivot + 1, iu);
        if (ret == ERR) return ERR;
        bo += ret;
    }

    return bo;
}

/**
 * @brief Function which sorts an array
 *        with the quicksort algorithm, 
 *        this version doesn't have recursion
 * 
 * @param table Array to be sorted
 * @param ip Index of the first element to be sorted
 * @param iu Index of the last element to be sorted
 * @return int Basic operations that the algorithm performs
 */
int quicksort_ntr(int *table, int ip, int iu) {
    
    while(){
        int pivot = 0, bo = 0, ret = 0;

        /* Checking arguments */
        if (table == NULL || ip < 0 || iu < 0 || iu < ip)
            return ERR;

        /* In case there's only one integer in the array */
        if (ip == iu)
            return OK;

        ret = split(table, ip, iu, &pivot);
        if (ret == ERR) return ERR;
        bo += ret;

        if (ip < pivot - 1) {
            ret = quicksort(table, ip, pivot - 1);
            if (ret == ERR) return ERR;
            bo += ret;
        }
        if (pivot + 1 < iu) {
            ret = quicksort(table, pivot + 1, iu);
            if (ret == ERR) return ERR;
            bo += ret;
        }
    }

    return bo;
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

    int ret = 0, counter = 0, k = 0, i = 0;

    /* Checking arguments */
    if (table == NULL || ip < 0 || iu < 0 || iu < ip || pos == NULL)
        return ERR;

    ret = median(table, ip, iu, pos);
    if (ret == ERR) return ERR;
    counter += ret;

    k = table[*pos];

    if (swap(&table[ip], &table[*pos]) == ERR) return ERR;

    *pos = ip;
    for (i = ip + 1; i <= iu; i++) {
        if (table[i] < k) {
            *pos += 1;
            if (swap(&table[i], &table[*pos]) == ERR)
                return ERR;
        }
        counter++;
    }

    if (swap(&table[ip], &table[*pos]) == ERR)
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

    *pos = ip;

    return OK;
}
