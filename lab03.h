#ifndef LAB03_H_INCLUDED
#define LAB03_H_INCLUDED


#endif // LAB03_H_INCLUDED
#pragma once
#include <vector>
#include <string>

using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

void find_minmax(vector<double> numbers, double& min, double& max);
