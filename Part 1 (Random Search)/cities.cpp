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

double total_path_distance() const {
	distances = copy(city_vec);
	// I would like to just for_each this and then sum the resulting vector
	// But we need to loop back to the start at the end
	// So I'm not sure exactly what to do
}
