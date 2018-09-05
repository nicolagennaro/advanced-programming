#include <iostream>
#include "constants.h"

double area_circle(const double);
double golden_ratio(const double);
extern int circle_counter;

int main() {
  std::cout << area_circle(1) << std::endl;
  std::cout << area_circle(2) << std::endl;

  std::cout << golden_ratio(1) << std::endl;

  std::cout << circle_counter << std::endl;
  return 0;
}