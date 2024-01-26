#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[]) {
  ULListStr dat;
  dat.push_back("First");
  dat.push_back("Second");
  dat.push_back("Third");

  dat.push_front("C");
  dat.push_front("B");
  dat.push_front("A");

  std::cout << "Size: " << dat.size() << std::endl;
  std::cout << "Front: " << dat.front() << std::endl;
  std::cout << "Back: " << dat.back() << std::endl;

  dat.pop_back();
  dat.pop_front();

  std::cout << "Size: " << dat.size() << std::endl;
  std::cout << "Front: " << dat.front() << std::endl;
  std::cout << "Back: " << dat.back() << std::endl;

}
