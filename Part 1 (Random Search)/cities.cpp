#include <cmath>
#include "cities.h"

double Cities::total_path_distance(const Cities::permutation_t &ordering) const {
    double dist = 0.0;
    for (unsigned int i = 0; i<ordering.size();i++){
        dist+=hypot(ordering[i],ordering[(i+1)%ordering.size()]);
    }
    return dist;
}
