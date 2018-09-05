#include <iostream>


template <typename T>
T* allocate(int size){
  T* pt = new T[size];
  for( int i=0; i<size; i++){
    T t;
    std::cin >> t;
    pt[i] = t;
  }
  return pt;
}


template <typename T>
void reverse(T* pt, int size){
  for( int i=size-1; i>=0; i--)
    std::cout << pt[i] << " ";
  std::cout << std::endl;
}


int main(){

  int size;
  std::cout << "insert array size: ";
  std::cin >> size;
  double *pd;
  pd = allocate<double>(size);
  reverse(pd, size);

  delete[] pd;
  
  int *pi;
  pi = allocate<int>(size);
  reverse(pi, size);
  delete[] pi;

  
  return 0;
}
