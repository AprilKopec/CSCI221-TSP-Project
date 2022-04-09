#include <cmath>
#include "cities.h"
#include <iterator>
#include <vector>
#include <sstream>

//using namespace Cities;
using namespace std;


istream &operator<<(istream &is, Cities &cities) {
    string line;
    while(getline(is,line)){
        istringstream line_stream{line};
        Cities::coord_t coord;
        line_stream >> coord.first >> coord.second;
        cities.city_vec.push_back(coord);
    }
    return is;
}

ostream &operator<<(ostream &os, const Cities &cities) {
    for (Cities::coord_t coord : cities.city_vec) {
        os << "city_vec: " << coord.first << "," << coord.second << "\n";
    }
    return os;
}

//MAYBE!!!! on thin ice!!!
Cities Cities::reorder(const Cities::permutation_t &ordering) const {
    Cities reordered;
    for (const unsigned int i : ordering){
        reordered.city_vec.push_back(city_vec[i]);
    }
    return reordered;
}

double Cities::total_path_distance(const Cities::permutation_t &ordering) const {
    double dist = 0.0;
    for (unsigned int i = 0; i<ordering.size();i++){
        dist+=hypot(ordering[i],ordering[(i+1)%ordering.size()]);
    }
    return dist;
}