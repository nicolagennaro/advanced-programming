#include <iostream>

int get_int(){
  int input;

  while(1){
    std::cout << "enter a number" << std::endl;
    if( !(std::cin >> input) ){
      std::cout << "invalid input" << std::endl;
      std::cin.clear();
      std::cin.ignore(100, '\n');
    }
    else
      break;
  }

  return input;
}


int main(){

  int input;

  input = get_int();
  std::cout << "from main: input " << input << std::endl;
  
  return 0;
}
