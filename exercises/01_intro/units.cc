#include <iostream>
#include <string>



std::string convert(std::string in){

  unsigned int length{in.length()};
  unsigned int i{0};
  
  while( i < length && in[i] != ' ')
    i++;

  double x{ stod(in.substr(0, i)) };
  std::cout << x << std::endl;

  unsigned int j{i+1};

  while( j < length && in[j] != ' ')
    j++;

  std::string old_units{ in.substr(i+1, j)};
  std::cout << old_units << std::endl;
  
  if( old_units == "inch" ){
    return std::string{ std::to_string(0.23*x) + " m"};
  }
  else if( old_units == "feet" ){
    return std::string{ std::to_string(3.4*x) + " m"};
  }
  else{
      return std::string{"unable to convert " + old_units};
  }

  return in;
}



int main(){

  std::string line;

  std::getline(std::cin, line);

  std::cout << line << std::endl;

  std::string converted = convert(line);

  std::cout << converted << std::endl;
  
  return 0;
}
