#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED



#endif // SVG_H_INCLUDED
#pragma once
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;
void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height, string stroke, string fill);

string make_info_text();
