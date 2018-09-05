#include <iostream>


#define MAX_LENGTH 10

bool is_space(char c){
  return (c == ' ' || c == '\n' || c == '\t');
}

std::string break_string(std::string str, unsigned int max_len){

  unsigned int l {str.length()};

  if( l <= max_len )
    return str;

  unsigned int i = max_len;

  // std::cout << str[0] << std::endl;
  
  while( !is_space(str[i]) && i>0 ){
    i--;
  }

  if ( i>=1 )
    return str.substr(0, i);
  else
    return std::string{};
}


int main(){
  
  std::string word;
  std::cin >> word;
  std::cout << "original length: " << word.length() << std::endl;

  std::string broken = break_string(word, MAX_LENGTH);
  std::cout << "broken string:\n";
  std::cout << "<<" << broken << ">>" << std::endl;


  while( std::getline(std::cin, word)){
    broken = break_string(word, MAX_LENGTH);
    std::cout << broken << std::endl;
  }
  
  return 0;
}
