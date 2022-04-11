#include "cities.h"
#include <fstream>
#include <iostream>

using namespace std;

//performs the actual search
//reads in a cities file as first argument
//each iteration, new random permutation, evaluates the dist to travel
static const int ITERATIONS = 1e6; //1 million iterations default


int main(int argc, char *argv[]) {
    argc = 0;
    fstream fs{argv[1]};
    Cities cit{};
    fs >> cit;
    auto shortest_perm = Cities::random_permutation(cit.size());
    double distance = numeric_limits<double>::max(); //highest initial value
    for (int i = 1; i < ITERATIONS + 1; i++) {
        auto perm = Cities::random_permutation(cit.size());
        double temp_distance = cit.total_path_distance(perm);
        if (temp_distance < distance) {
            distance = temp_distance;
            cout << i << "\t" << distance << "\n";
            shortest_perm = perm;
        }
    }
    //save ordering to a file called "shortest.tsv"
    ofstream MyFile("shortest.tsv");
    for (unsigned int i: shortest_perm) {
        MyFile << i << " ";
    }
    MyFile.close();
    return argc;
}