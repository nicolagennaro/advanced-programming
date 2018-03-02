#include <iostream>
#include <memory>
#include <ap_error.h> // defined in lectures

template <typename num>
class Vector{
  unsigned int _size;
  std::unique_ptr<num[]> elems;
public:
  explicit Vector(const unsigned int s): _size{s}, elems{new num[s]} {} // also _size(s), elems(new num[s]) will work, 
									//  also before c++11
									// new num[s]{} will set all elements to 0
  // Vector(std::initializer_list<num> lst);
  unsigned int size() const noexcept{ return _size; }

  num& operator[](const unsigned int i) noexcept{ return elems[i]; }
  const num& operator[](const unsigned int i) const noexcept { return elems[i]; }

	// this at operator is like [] but will throw an exception
  num& at(const unsigned int i);			// this will be called when vec is not const
  const num& at(const unsigned int i) const;		// this will be called when vec is const

  num* begin() noexcept{ return elems.get(); }		// return a pointer to the first element (for : ???)
  num* end() noexcept{ return elems.get() + _size; } 	// return a pointer to the last+1 element ( the block next to the end )
  
  const num* begin() const noexcept{ return elems.get(); }
  const num* end() const noexcept{ return elems.get() + _size; }

  void resize(const Vector& v);		// resize as another vector like v.resize(w)
  void resize(const unsigned int s);	// resize this vector v.resize(s)
};


// the template lasts to the end of the definition, 
template <typename num>
num& Vector<num>::at(const unsigned int i){
		
	if( i<_size)
		return elems[i];
	// Error("out of bound",i,"is not smaller than", _size);	// definition in ap_error
	AP_error("out of bound",i,"is not smaller than", _size);	// definition in ap_error
}


template <typename num>
const num& Vector<num>::at(const unsigned int i) const{
		
	if( i<_size)
		return elems[i];
	//Error("out of bound",i,"is not smaller than", _size);	// definition in ap_error
	AP_error("out of bound",i,"is not smaller than", _size);	// definition in ap_error
}




template <typename num>
void Vector<num>::resize(const unsigned int s){
	_size = s;
	elems.reset(new num[s]);
	// is equal to 
	// num* ptr= elems.release();
	// delete[] ptr;
	// elems = std::unique_ptr<num[]>(new num[s]);
}


template <typename num>
void Vector<num>::resize(const Vector<num>& v){
	resize( v.size() );
}



template <class num>
std::ostream& operator<<(std::ostream& os, const Vector<num>& v)
{
  for (const auto x : v)		// auto deduce the type of the variable ( : means for x in v )
    os << x << " ";
  os << std::endl;
  return os;
}

template <typename num>
void print_vector(const char* s,const Vector<num>& v)
{
  std::cout <<"-----------------------------------\n"
	    << s << "\n"
	    << " size : "<< v.size() << "\n"
	    << "elems : " << v
	    <<"-----------------------------------\n";
}


int main(){

try{
	Vector <int> v1(6);
	print_vector("v1",v1);

{
	int c=0;
	for (auto& x : v1 )
		x=c++;
	print_vector("v1",v1);
}

	std::cout << v1.at(11) << std::endl;
	std::cout << v1[11] << std::endl;

	// the explicit is needed to have only explicitly declarater objects
	// if we remove it this function call will create a new object an dprint it
	// print_vector<int>("vtest",7)

	return 0;
}
catch(std::runtime_error& e){
	std::cerr << e.what() << std::endl;
	return 1;
}

return 0;
}
