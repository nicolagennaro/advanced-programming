#include <iostream>
#include <date.h>
#include <ap_error.h>



int main(){


  while(1){
    try{
      Date d;
      std::cout << "Insert date" << std::endl;
      d.read_Date();
      std::cout << d << std::endl << std::endl;;
    }
    catch(const std::runtime_error& e){
      std::cerr << e.what() << std::endl;
      std::cout << "Try again\n\n" << std::endl;
    }
    catch(...){
      std::cerr << "Unknown exception: return 1" << std::endl;
      return 1;
    }
  }
  
}
