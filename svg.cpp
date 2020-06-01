#include "lab03.h"
#include <iostream>
#include <string>
using namespace std;

 void svg_begin(double width, double height)
  {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
  }
void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";

}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
  cout<<"<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

double zadanie (size_t number_count, double BLOCK_WIDTH, double idz )
{
	while (idz > 800 || idz < 70 || idz< (number_count * BLOCK_WIDTH/ 3))
	{
		cout << "Ooops! Try again: Width mustnt be less than 70, bigger than 800 or less than 1/3 of number count * 10. Enter image width: ";
		cin >> idz;
	}
    return idz;
}


void show_histogram_svg(const vector<size_t>& bins, size_t number_count) {
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
double top = 0;
double IMAGE_WIDTH;
double idz;
cerr<<"image width: ";
cin>>idz;
IMAGE_WIDTH=zadanie(number_count, BLOCK_WIDTH, idz);
svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
for (size_t bin : bins)
    {
    const double bin_width = BLOCK_WIDTH * bin;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffd700");
    top += BIN_HEIGHT;
}

    svg_end();
}

