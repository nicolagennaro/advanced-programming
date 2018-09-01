#include <iostream>
#include <date.h>


int main(){
 Date today{19,oct,2017};
 Date d;


 
 std::cout << d << std::endl;

 while(1){
   d.read_Date();
   d.add_day(1);
   std::cout << d << std::endl;
 }
 
return 0;
}
