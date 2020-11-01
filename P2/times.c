/**
 * @file times.c
 * @author Marcos Bernuy
 *         Kevin de la Coba Malam
 * @brief File where the prototypes of functions are defined
 * @version 1.0
 * @date 2020-09-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "times.h"
#include "sorting.h"

/**
 * @brief Calculates and saves in a TIME_AA the average, 
 *        minimun and maximun times to run an algorithim
 * 
 * @param method Function to be measured in time
 * @param n_perms Number of permutations
 * @param N Size of each permutation
 * @param ptime Structure with all the data of the times and OBs
 * @return short Flag
 */
short average_sorting_time(pfunc_sort method,
                           int n_perms,
                           int N,
                           PTIME_AA ptime) {

    clock_t start = 0, end = 0;
    double total = 0;
    int **perms = NULL, i = 0, n = 0;
    long BOs = 0, total_BOs = 0;

    if (method == NULL || n_perms <= 0 || N <= 0 || ptime == NULL)
        return ERR;

    /* Creating all the permutations */
    perms = generate_permutations(n_perms, N);
    if (perms == NULL)
        return ERR;

    start = clock();
    if (start == (clock_t)-1)
    {
        for (i = 0; i < n_perms; n++)
            free(perms[i]);
        free(perms);
        return ERR;
    }

    /* Loop to sort all the permutations */
    for (i = 0; i < n_perms; i++)
    {

        /* Using the function to sort the array */
        BOs = method(perms[i], 0, N - 1);
        if (BOs == ERR)
        {
            for (n = 0; n < n_perms; n++)
                free(perms[n]);
            free(perms);
            return ERR;
        }

        /* Checking the maximum and minimum values of the structure */
        if (ptime->min_ob == 0 || ptime->min_ob > BOs)
            ptime->min_ob = BOs;
        if (ptime->max_ob == 0 || ptime->max_ob < BOs)
            ptime->max_ob = BOs;

        total_BOs += BOs;
    }

    end = clock();
    if (end == (clock_t)-1)
    {
        for (i = 0; i < n_perms; n++)
            free(perms[i]);
        free(perms);
        return ERR;
    }

    /* Assingning the values to the structure */
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    ptime->time = total / n_perms;
    ptime->N = N;
    ptime->n_elems = n_perms;
    ptime->average_ob = ((double)total_BOs) / n_perms;
    for (i = 0; i < n_perms; i++)
        free(perms[i]);
    free(perms);

    return OK;
}

/**
 * @brief Generates sorting times in a specific file 
 * 
 * @param method Function to be measured
 * @param file Name of the file where the info is going to be saved
 * @param num_min Minimun size
 * @param num_max Maximun size
 * @param incr Nummber that increments the size from the minimun to the maximun
 * @param n_perms Number of permutations
 * @return short Flag
 */
short generate_sorting_times(pfunc_sort method, char *file,
                             int num_min, int num_max,
                             int incr, int n_perms) {
    int i = 0, counter = 0, n = 0;
    PTIME_AA ptime = NULL;

    /* Checking arguments */
    if (method == NULL || file == NULL || num_min < 0 || num_max < 0 || incr < 1 || n_perms < 1)
        return ERR;

    /* Allocating memory for the array of ptimes */
    counter = ((num_max - num_min) / incr) + 1;
    ptime = (PTIME_AA)malloc(counter * sizeof(TIME_AA));
    if (ptime == NULL)
        return ERR;

    /* Initializing ptime */
    for (i = 0; i < counter; i++)
    {
        ptime[i].average_ob = 0;
        ptime[i].max_ob = 0;
        ptime[i].min_ob = 0;
        ptime[i].N = 0;
        ptime[i].n_elems = 0;
        ptime[i].time = 0;
    }

    /* Calling the function to get the ptimes */
    for (i = num_min; i <= num_max; i += incr, n++)
    {
        if (average_sorting_time(method, n_perms, i, &ptime[n]) == ERR)
        {
            free(ptime);
            return ERR;
        }
    }

    /* Calling save_time_table so the information is displayed in the file */
    if (save_time_table(file, ptime, counter) == ERR)
    {
        free(ptime);
        return ERR;
    }

    free(ptime);
    return OK;
}

/**
 * @brief Saves all the info in a TIME_AA structure
 *  
 * @param file Name of the file where the data is going to be saved
 * @param ptime Structure with all the data to be saved
 * @param n_times Times to print
 * @return short Flag
 */
short save_time_table(char *file, PTIME_AA ptime, int n_times) {

    int i = 0;
    FILE *fp = NULL;

    /* Checking arguments */
    if (file == NULL || ptime == NULL || n_times < 0)
        return ERR;

    /* Opening the file */
    fp = fopen(file, "w");
    if (fp == NULL)
        return ERR;

    /* Printing all the ptimes */
    for (i = 0; i < n_times; i++) {
        fprintf(fp, "%d\t, %d\t, %e\t, %f\t, %d\t, %d\t\n",
                ptime[i].n_elems, ptime[i].N, ptime[i].time, ptime[i].average_ob, ptime[i].min_ob, ptime[i].max_ob);
    }

    /* Closing the file */
    fclose(fp);

    return OK;
}
