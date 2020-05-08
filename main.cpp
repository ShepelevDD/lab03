#include <iostream>
#include <vector>
#include "lab03.h"
#include "svg.h"
#include <string>
using namespace std;


vector<double>
input_numbers(istream& in, size_t count)
  {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
  }

Input
read_input(istream& in,  bool prompt) {
    Input data;
    if (prompt==true)
    {
    size_t number_count;
    cerr << "Enter number count ";
	cin >> number_count;
	size_t bin_count;
	 cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    cerr << "Enter bucket count" << endl;
	cin >> data.bin_count;
    }
    else
    {size_t number_count;
	cin >> number_count;
	size_t bin_count;
    data.numbers = input_numbers(in, number_count);
	cin >> data.bin_count;
    }
	return data;
}

vector <size_t> make_histogram(struct Input data)
    {
        double min;
        double max;

        find_minmax(data.numbers,min,max);
        vector<size_t>bins(data.bin_count, 0);
        for (double x : data.numbers)
	  {
		size_t bin_index = ((x - min) / (max - min)) * data.bin_count;
		if (bin_index == data.bin_count)
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
show_histogram_svg(const vector<size_t>& bins) {
const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
double top = 0;
svg_begin(400, 300);
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
    const auto input = read_input(cin, true);
    const auto bins = make_histogram(input);
    show_histogram_svg (bins);
	return 0;
}
