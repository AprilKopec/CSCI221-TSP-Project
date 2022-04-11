#include <cmath>
#include "cities.h"
#include <iterator>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

Cities::Cities() = default;



istream &operator>>(istream &is, Cities &cities) {
    Cities::coord_t coord;
    while (is >> coord.first){ //if I just do while(is), I get an extra (0,0) coord
        is >> coord.second;
        cities.city_vec.push_back(coord); //add the coord to the end of city_vec
    }
    return is;
}

ostream &operator<<(ostream &os, const Cities &cities) {
    for (Cities::coord_t coord : cities.city_vec) {
        os << "city_vec: " << coord.first << "," << coord.second << "\n";
    }
    return os;
}

Cities Cities::reorder(const Cities::permutation_t &ordering) const {

    Cities new_city;
    for (const unsigned int i : ordering){
        new_city.city_vec.push_back(city_vec[i]);
    }
    return new_city;
}

//Compute the distance using the already existing ordering
double Cities::total_path_distance() const {
    double dist = 0.0;
    //for (auto coord : city_vec){
    for (unsigned long i = 0; i<city_vec.size();i++){
        double delta_y = city_vec[(i+1)%city_vec.size()].second - city_vec[i].second;
        double delta_x = city_vec[(i+1)%city_vec.size()].first - city_vec[i].first;
        dist+=hypot(delta_y,delta_x); //dist of 1 to the next and back to the first
    }
    return dist;
}


double Cities::total_path_distance(const Cities::permutation_t &ordering) const {
    auto cit = reorder(ordering);
    return cit.total_path_distance();
}
    //return dist;

    //this should run it thru reorder first and then run thru total path dist
//}



int main(){
    auto fin = ifstream("five.tsv");
    Cities cities;
    fin >> cities;
    //cout << cities;
    //cout << cities.total_path_distance();
    cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
    cout << cities.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.43
    return 0;
}



