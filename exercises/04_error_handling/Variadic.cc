#include <iostream>
#include <string>


template<typename T>
void func(T t){
  std::cout << t << std::endl;
}



// recursive Variadic function
template<typename T, typename... Args>
void func(T t, Args... args){
  std::cout << t << std::endl;
  func(args...);
}



int main(){

  std::string s1{"hello"}, s2{" user "}, s3{"how are you?"};

  func(s1, s2 ,s3);

  return 0;
}
