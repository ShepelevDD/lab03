#include "lab03.h"
#include "svg.h"
#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same(){
   double min = 0;
    double max = 0;
    find_minmax({1,1,1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_single(){
   double min = 0;
    double max = 0;
    find_minmax({3}, min, max);
    assert(min == 3);
    assert(max == 3);
}


void test_width() {
    assert(custome_width(50, 10, 10) == "Ooops! Width < 70. Enter the width again:");
    assert(custome_width(850, 10, 10) == "Ooops! Width > 800. Enter the width again:");
    assert(custome_width(75, 24, 10) == "Ooops! Width < BLOCK_WIDTH*number_count/3. Enter the width again:");

}

void test_nothing(){
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 3);
    assert(max == 3);
}



