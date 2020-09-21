/**
 * @file times.h
 * @author Marcos Bernuy 
 *         Kevin de la Coba Malam
 * @brief File where the prototypes of functions are defined
 * @version 1.0
 * @date 2020-09-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef TIEMPOS_H
#define TIEMPOS_H

/* constants */
#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

#include "sorting.h"

/* type definitions */
typedef struct time_aa {
  int N;           /* size of each element */
  int n_elems;     /* number of elements to average */
  double time;   /* average clock time */
  double average_ob; /* average number of times that the OB is executed */
  int min_ob;      /* minimum of executions of the OB */
  int max_ob;      /* maximum of executions of the OB */
} TIME_AA, *PTIME_AA;


/* Functions */
/**
 * @brief Calculates and saves in a TIME_AA the average, 
 *        minimun and maximun times to run an algorithim
 * 
 * @date 2020-09-21
 * @author Kevin de la Coba Malam and Marcos Bernuy
 * @param method Function to be measured in time
 * @param n_perms Number of permutations
 * @param N Size of each permutation
 * @param ptime Structure with all the data of the times and OBs
 * @return short Flag
 */
short average_sorting_time(pfunc_sort method, int n_perms,int N, PTIME_AA ptime);

/**
 * @brief Generates sorting times in a specific file 
 * 
 * 
 * @date 2020-09-21
 * @author Kevin de la Coba and Marcos Bernuy
 * @param method Function to be measured
 * @param file Name of the file where the info is going to be saved
 * @param num_min Minimun size
 * @param num_max Maximun size
 * @param incr Nummber that increments the size from the minimun to the maximun
 * @param n_perms Number of permutations
 * @return short Flag
 */
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms);

/**
 * @brief Saves all the info in a TIME_AA structure
 *  
 * @date 2020-09-21
 * @author Kevin de la Coba and Diego Toral
 * @param file Name of the file where the data is going to be saved
 * @param ptime Structure with all the data to be saved
 * @param n_times Times to print
 * @return short Flag
 */
short save_time_table(char* file, PTIME_AA time, int n_times);

#endif
