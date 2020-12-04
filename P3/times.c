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

    /* Initializing ptime values */
    ptime->min_ob = __INT_MAX__;
    ptime->max_ob = 0;

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
        if (ptime->min_ob > BOs) ptime->min_ob = BOs;
        if (ptime->max_ob < BOs) ptime->max_ob = BOs;

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
    ptime->time = total / (double) n_perms;
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
    if (method == NULL || file == NULL || num_min < 0 || num_max <= 0 || num_min > num_max || incr < 1 || n_perms < 1)
        return ERR;

    /* Allocating memory for the array of ptimes */
    counter = ((num_max - num_min) / incr) + 1;
    ptime = (PTIME_AA)malloc(counter * sizeof(TIME_AA));
    if (ptime == NULL)
        return ERR;

    /* Calling the function to get the ptimes */
    for (i = num_min; i <= num_max; i += incr, n++) {
        if (average_sorting_time(method, n_perms, i, &ptime[n]) == ERR) {
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

    int i = 0, ret = 0;
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
        fprintf(fp, "%d\t %d\t %e\t %f\t %d\t %d\t\n",
                ptime[i].n_elems, ptime[i].N, ptime[i].time, ptime[i].average_ob, ptime[i].min_ob, ptime[i].max_ob);
    }

    /* Closing the file */
    ret = fclose(fp);
    while (ret != 0) ret = fclose(fp);

    return OK;
}

/**
 * @brief Given a method to search, the function searches keys generated by a given generator
 *        The data related with the performance of the searching is stored in a given file
 * 
 * @param method Function to use in order to search keys
 * @param generator Generator which generates keys
 * @param order Order of the table. It can be ordered or dissordered
 * @param file File name where the data related with the performance is going to be stored
 * @param num_min Minumum size of the tables
 * @param num_max Maximum size of the table 
 * @param incr Increment in the table size per iteration
 * @param n_times Number of times to search in each table
 * @return short Status of the function
 */
short generate_search_times(pfunc_search method, pfunc_key_generator generator, 
                                int order, char* file, 
                                int num_min, int num_max, 
                                int incr, int n_times) {
    int i = 0, size = 0, n = 0;
    PTIME_AA ptime = NULL;

    if (method == NULL || generator == NULL || (order != NOT_SORTED && order != SORTED) || num_min < 0
        || num_max <= 0 || num_max < num_min || incr <= 0 || n_times <= 0) return ERR;
    
    /* Allocating memory for the array of ptimes */
    size = ((num_max - num_min) / incr) + 1;
    ptime = (PTIME_AA)malloc(size * sizeof(TIME_AA));
    if (ptime == NULL) return ERR;

    /* Getting the average searching time for each size */
    for (i = num_min; i <= num_max; i += incr, n++) {
        if (average_search_time(method, generator, order, i, n_times, &ptime[n]) == ERR) {
            free(ptime);
            ptime = NULL;
            return ERR;
        }
    }

    /* Saving the times in a file */
    if (save_time_table(file, ptime, size) == ERR) {
        free(ptime);
        ptime = NULL;
        return ERR;
    }

    free(ptime);
    ptime = NULL;
    return OK;
}

/**
 * @brief Given a size, a method and a key generator, the function searches in a table
 *        the generated keys n_times times 
 * 
 * @param method Function to use in order to search keys
 * @param generator Generator which generates keys 
 * @param order Order the table
 * @param N Size of the table
 * @param n_times Number of times to search in each table
 * @param ptime Time structure to store the data related with the performance
 * @return short Status of the function
 */
short average_search_time(pfunc_search metodo, pfunc_key_generator generator,
                              int order,
                              int N, 
                              int n_times,
                              PTIME_AA ptime) {
    clock_t start = 0, end = 0;
    double total = 0;
    int *perm = NULL, *keys = NULL, i = 0, ppos = 0;
    long BO = 0, total_BO = 0;
    PDICT dict = NULL;

    if (metodo == NULL || generator == NULL || (order != NOT_SORTED && order != SORTED)
        || N < 0 || n_times <= 0 || ptime == NULL) return ERR;

    /* Creating a dictionary */
    dict = init_dictionary(N, (char)order);
    if (dict == NULL) return ERR;
    
    /* Creating a permutation */
    perm = generate_perm(N);
    if (perm == NULL) {
        free_dictionary(dict);
        return ERR;
    }

    /* Inserting the elements of the permutation into the dictionary */
    total_BO = massive_insertion_dictionary(dict, perm, N);
    if (total_BO == ERR) {
        free(perm);
        perm = NULL;
        free_dictionary(dict);
        return ERR;
    }

    /* Creating an array for the keys */
    keys = (int*)malloc((n_times*N)*sizeof(int));
    if (keys == NULL) {
        free(perm);
        perm = NULL;
        free_dictionary(dict);
        return ERR;
    }

    /* Generating keys */
    generator(keys, n_times*N, N);

    /* Initializing ptime values */
    ptime->min_ob = __INT_MAX__;
    ptime->max_ob = 0;

    start = clock();
    if (start == (clock_t) -1) {
        free(perm);
        free(keys);
        keys = NULL;
        perm = NULL;
        free_dictionary(dict);
        return ERR;
    }

    /* Searching for the keys */
    for (i = 0; i < n_times*N; i++) {
        BO = search_dictionary(dict, keys[i], &ppos, metodo);
        if (BO == ERR || BO == NOT_FOUND) {
            free(perm);
            free(keys);
            keys = NULL;
            perm = NULL;
            free_dictionary(dict);
            return ERR;
        }

        if (ptime->min_ob > BO) ptime->min_ob = BO;
        if (ptime->max_ob < BO) ptime->max_ob = BO;

        total_BO += BO;
    }

    end = clock();
    if (end == (clock_t)-1) {
        free(perm);
        free(keys);
        keys = NULL;
        perm = NULL;
        free_dictionary(dict);
        return ERR;
    }

    /* Assingning the values to the structure */
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    ptime->time = total / (double) (n_times*N);
    ptime->N = N;
    ptime->average_ob = total_BO/(n_times*N);
    ptime->n_elems = n_times*N;

    free_dictionary(dict);
    free(perm);
    free(keys);
    keys = NULL;
    perm = NULL;
    return OK;
}