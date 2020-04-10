#ifndef LAB03_H_INCLUDED
#define LAB03_H_INCLUDED


#endif // LAB03_H_INCLUDED
#pragma once
#include <vector>
#include <string>

using namespace std;

void find_minmax(vector<double> numbers, double& min, double& max);
void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
