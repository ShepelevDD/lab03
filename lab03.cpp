#include "lab03.h"
#include <iostream>
#include <string>
using namespace std;


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


