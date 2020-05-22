#include <iostream>
#include <vector>
#include "lab03.h"
#include "svg.h"
#include <string>

using namespace std;

vector<double>
input_numbers(size_t count)
  {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
  }

vector <size_t> make_histogram(const vector<double>& numbers, size_t bin_count)
    {
        double min;
        double max;
        find_minmax(numbers,min,max);
        vector<size_t>bins(bin_count, 0);
        for (double x : numbers)
	  {
		size_t bin_index = ((x - min) / (max - min)) * bin_count;
		if (bin_index == bin_count)
		{
			bin_index--;
		}
		bins[bin_index]++;
      }
      return bins;
    }

void show_histogram_text(vector<size_t> bins)
{
    const size_t SCREEN_WIDTH = 80;
	const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
	size_t maxbin = 0;
	for (size_t bin : bins) {
		if (bin > maxbin) {
			maxbin = bin;
		}
	}
    double factor = MAX_ASTERISK/maxbin;
	for (size_t bin : bins)
	{
		if (bin < 100)
		{
			cout << " ";
			if (bin < 10)
			{
				cout << " ";
			}
		}
	cout << bin << '|';
	size_t height = bin * factor;
	for (int i = 0; i < height; i++)
	{
		cout << '*';
	}
	cout << endl;
}
}

void
show_histogram_svg(const vector<size_t>& bins, size_t number_count) {
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
double top = 0;
size_t zadanie;
cerr<<"image width: ";
cin >> zadanie;
	while (zadanie > 800 || zadanie < 70 || zadanie < (number_count * BLOCK_WIDTH/ 3))
	{
		cout << "Ooops! Try again: Width mustnt be less than 70, bigger than 800 or less than 1/3 of number count * 10. Enter image width: ";
		cin >> zadanie;
	}
const auto IMAGE_WIDTH = zadanie;
svg_begin(zadanie, 300);
for (size_t bin : bins)
    {
    const double bin_width = BLOCK_WIDTH * bin;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffd700");
    top += BIN_HEIGHT;
}

    svg_end();
}


int main()
{
	const size_t SCREEN_WIDTH = 80;
	const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
	size_t number_count;
	double min, max;
	cerr << "Enter number count ";
	cin >> number_count;
	const auto numbers = input_numbers(number_count);
	size_t bin_count;
	cerr << "Enter bucket count" << endl;
	cin >> bin_count;
    find_minmax(numbers, min, max);
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg (bins, number_count);
    return 0;
}
