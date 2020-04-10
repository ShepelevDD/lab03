#include <iostream>
#include <vector>
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

void find_minmax(vector<double> numbers, double& min, double& max)
    {
      min = numbers[0];
      max = numbers[0];
	  for (double x : numbers)
	  {
		if (x > max)
		{
			max = x;
		}
		else if (x < min)
		{
			min = x;
		}
	  }
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
    show_histogram_text (bins);
	return 0;
}
