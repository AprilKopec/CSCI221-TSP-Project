#include <cmath>
#include "cities.h"
#include <iterator>
#include <sstream>
#include <algorithm>
#include <random>

using namespace std;

Cities::Cities() = default;

istream &operator>>(istream &is, Cities &cities) {
    Cities::coord_t coord;
    while (is >> coord.first) { //if I just do while(is), I get an extra (0,0) coord
        is >> coord.second;
        cities.city_vec.push_back(coord); //add the coord to the end of city_vec
    }
    return is;
}

ostream &operator<<(ostream &os, const Cities &cities) {
    for (Cities::coord_t coord: cities.city_vec) {
        os << coord.first << " " << coord.second << "\n";
    }
    return os;
}

Cities Cities::reorder(const Cities::permutation_t &ordering) const {

    Cities new_city;
    for (const unsigned int i: ordering) {
        new_city.city_vec.push_back(city_vec[i]);
    }
    return new_city;
}

//Compute the distance using the already existing ordering
double Cities::total_path_distance() const {
    double dist = 0.0;
    for (unsigned long i = 0; i < city_vec.size(); i++) {
        double delta_y = city_vec[(i + 1) % city_vec.size()].second - city_vec[i].second;
        double delta_x = city_vec[(i + 1) % city_vec.size()].first - city_vec[i].first;
        dist += hypot(delta_y, delta_x); //dist of 1 to the next and back to the first
    }
    return dist;
}


double Cities::total_path_distance(const Cities::permutation_t &ordering) const {
    const Cities cit = reorder(ordering);
    return cit.total_path_distance();
}

size_t Cities::size() const {
    return city_vec.size();
}

//generates and returns a new permutation of all the numbers from 0 to len-1 (with no skipped or repeated indices). Note that the ordering needs to be "very random" for the search to work well in the next step.
Cities::permutation_t Cities::random_permutation(unsigned len) {
    Cities::permutation_t perm(len); //vector unsigned ints of size len
    for (unsigned int i = 0; i < len; i++) {
        perm[i] = i;
    } //now perm is simply {0,1,2,3,...,len-1}

    //random shuffle array
    auto rd = random_device{}; //new seed every run
    auto rng = default_random_engine{rd()}; //implements seed in engine
    shuffle(begin(perm), end(perm), rng); //uses std::shuffle
    return perm;
}

//int main(){
//    //auto fin = ifstream("five.tsv");
//    //Cities cities;
//    //fin >> cities;
//    //cout << cities;
//    //cout << cities.total_path_distance();
//    //cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
//    //cout << cities.total_path_distance(random_permutation(5)) << "\n"; // Should be 53.43
//    Cities::permutation_t perm = Cities::random_permutation(5);
//    return 0;
//}



