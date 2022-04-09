#include <cmath>
#include "cities.h"
#include <iterator>
#include <vector>
#include <math.h>

using namespace Cities;
using namespace std;

Cities reorder(const permutation_t& ordering){

}

double total_path_distance(const permutation_t& ordering) const {
	path = reorder(ordering);
	return path.total_path_distance();
}


double Cities::total_path_distance(const Cities::permutation_t &ordering) const {
    double dist = 0.0;
    for (unsigned int i = 0; i<ordering.size();i++){
        dist+=hypot(ordering[i],ordering[(i+1)%ordering.size()]);
    }
    return dist;
}
