#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED



#endif // SVG_H_INCLUDED
#pragma once
#include <vector>
#include <string>

using namespace std;
void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height, string stroke, string fill);

void show_histogram_svg(const vector<size_t>& bins, size_t number_count);

string custome_width(double width, double BLOCK_WIDTH, size_t number_count);
