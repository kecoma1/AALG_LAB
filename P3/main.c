#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "permutations.h"
#include "search.h"
#include "times.h"

int main(int argc, char** argv) {
    short ret;
    
    srand(time(NULL));

    printf("UNIFORM KEY GENERATOR - BINARY SEARCH - 1000 --+100--> 10.000 | n_times=1\n");
    ret = generate_search_times(bin_search, uniform_key_generator, SORTED, 
                                "UNIFORM_KEY_BINARY_SEARCH.log", 1000, 10000, 100, 1);
    if (ret == ERR) { 
        printf("Error in function generate_search_times UNIFORM KEY GENERATOR - BINARY SEARCH\n");
        exit(-1);
    }

    printf("UNIFORM KEY GENERATOR - LINEAR SEARCH - 1000 --+100--> 10.000 | n_times=1\n");
    ret = generate_search_times(lin_search, uniform_key_generator, NOT_SORTED, 
                                "UNIFORM_KEY_LINEAR_SEARCH.log", 1000, 10000, 100, 1);
    if (ret == ERR) { 
        printf("Error in function generate_search_times UNIFORM KEY GENERATOR - BINARY SEARCH\n");
        exit(-1);
    }

    printf("POTENTIAL KEY GENERATOR - LINEAR AUTO SEARCH - 1000 --+100--> 10.000 | n_times=1\n");
    ret = generate_search_times(lin_auto_search, potential_key_generator, NOT_SORTED, 
                                "POTENTIAL_KEY_LIN_AUTO_SEARCH_1.log", 1000, 10000, 100, 1);
    if (ret == ERR) { 
        printf("Error in function generate_search_times POTENTIAL KEY GENERATOR - LINEAR AUTO SEARCH\n");
        exit(-1);
    }

    printf("POTENTIAL KEY GENERATOR - LINEAR AUTO SEARCH - 1000 --+100--> 10.000 | n_times=100\n");
    ret = generate_search_times(lin_auto_search, potential_key_generator, NOT_SORTED, 
                                "POTENTIAL_KEY_LIN_AUTO_SEARCH_100.log", 1000, 10000, 100, 100);
    if (ret == ERR) { 
        printf("Error in function generate_search_times POTENTIAL KEY GENERATOR - LINEAR AUTO SEARCH\n");
        exit(-1);
    }

    printf("POTENTIAL KEY GENERATOR - LINEAR AUTO SEARCH - 1000 --+100--> 10.000 | n_times=10000\n");
    ret = generate_search_times(lin_auto_search, potential_key_generator, NOT_SORTED, 
                                "POTENTIAL_KEY_LIN_AUTO_SEARCH_10000.log", 1000, 10000, 100, 10000);
    if (ret == ERR) { 
        printf("Error in function generate_search_times POTENTIAL KEY GENERATOR - LINEAR AUTO SEARCH\n");
        exit(-1);
    }

    printf("POTENTIAL KEY GENERATOR - BINARY SEARCH - 1000 --+100--> 10.000 | n_times=1\n");
    ret = generate_search_times(bin_search, potential_key_generator, SORTED, 
                                "POTENTIAL_KEY_BINARY_SEARCH_1.log", 1000, 10000, 100, 1);
    if (ret == ERR) { 
        printf("Error in function generate_search_times POTENTIAL KEY GENERATOR - BINARY SEARCH\n");
        exit(-1);
    }

    printf("POTENTIAL KEY GENERATOR - BINARY SEARCH - 1000 --+100--> 10.000 | n_times=100\n");
    ret = generate_search_times(bin_search, potential_key_generator, SORTED, 
                                "POTENTIAL_KEY_BINARY_SEARCH_100.log", 1000, 10000, 100, 100);
    if (ret == ERR) { 
        printf("Error in function generate_search_times POTENTIAL KEY GENERATOR - BINARY SEARCH\n");
        exit(-1);
    }

    printf("POTENTIAL KEY GENERATOR - BINARY SEARCH - 1000 --+100--> 10.000 | n_times=10000\n");
    ret = generate_search_times(bin_search, potential_key_generator, SORTED, 
                                "POTENTIAL_KEY_BINARY_SEARCH_10000.log", 1000, 10000, 100, 10000);
    if (ret == ERR) { 
        printf("Error in function generate_search_times POTENTIAL KEY GENERATOR - BINARY SEARCH\n");
        exit(-1);
    }

    printf("Correct output \n");

    return 0;
}