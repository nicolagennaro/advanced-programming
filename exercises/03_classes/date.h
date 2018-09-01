#ifndef __MYDATE__
#define __MYDATE__

#include <iostream>


enum Months : unsigned int { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };


inline bool is_leap(unsigned int year){
  return ( year % 4 == 0 && year % 400 != 0);
}


inline bool has_30_days(Months m){
  return (m == nov || m == apr || m == jun || m == sep);
}



class Date {

  unsigned int day;
  Months month;
  unsigned int year;

public:
     
 Date(const unsigned int d, const Months m, const unsigned int y): day{d}, month{m}, year{y} {}
 Date(): day{1}, month{jan}, year{1970} {}
     
	unsigned int Day() const {return day;}
	Months Month() const {return month;}
	unsigned int Year() const {return year;}

	void add_one_day();
	void add_day( unsigned int );

	bool operator==(const Date& ) const;
	bool operator!=(const Date& ) const;

	void read_Date();
	
        friend std::ostream& operator<<(std::ostream& os, const Date);
};


std::ostream& operator<<(std::ostream& os, const Date d){
  os << d.day << "/" << d.month << "/" << d.year;
  return os;
}


void Date::read_Date(){
  unsigned int a;
  std::cout << "insert day: ";
  std::cin >> a;
  day = a;

  std::cout << "insert month: ";
  
  std::cin >> a;
  month = Months(a);

  std::cout << "insert year: ";
  std::cin >> a;
  year = a;
}


/* void Date::add_one_day1(){ */
/*   if( has_30_days( month ) ){ */
/*     month += 1; */
/*     day=1; */
/*   } */
/*   else if( month == feb ){ */
/*     if( is_leap( year) && day == 28 ){ */
/*       day++;} */
/*     else if( is_leap( year ) && day == 29 ){ */
/*       month += 1; */
/*       day = 1; */
/*     } */
/*     else if( day == 28){ */
/*       day = 1; */
/*       month++; */
/*     } */
/*     else{ */
/*       day++; */
/*     } */
/*   } */
/*   else{ */
/*     if( day == 31){ */
/*       if( month == dec){ */
/* 	month = Months::jan; */
/* 	year++; */
/* 	day = 1; */
/* 	} */
/*       else{ */
/* 	month++; */
/* 	day = 1; */
/*       } */
/*     } */
/*     else */
/*       day++; */
/*   } */
/* } */




void Date::add_one_day(){
	switch(month){
		case jan:
			if(day==31){
				month=feb;
				day=1;
				break; }
			else{
				day++;
				break; }
		case feb:
		        if( day==28   &&  is_leap( year ) ){
				day=29;
				break; }
			else if( (day==29 && is_leap( year )) || (day==28 && !is_leap(year))   ){
			  day=1;
			  month = mar;
			  break;
			}
			else if( day== 29 && !is_leap( year ) ){
			  std::cout << "found feb with 29 in non-leap year" << std::endl;
			  exit(1);
			}
			else{
				day++;
				break; }
		case mar:
			if(day==31){
				month=apr;
				day=1;
				break; }
			else{
				day++;
				break;
			}
		case apr:
			if(day==30){
				month=may;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case may:
			if(day==31){
				month=jun;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case jun:
			if(day==30){
				month=jul;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case jul:
			if(day==31){
				month=aug;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case aug:
			if(day==31){
				month=sep;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case sep:
			if(day==30){
				month=oct;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case oct:
			if(day==31){
				month=nov;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case nov:
			if(day==30){
				month=dec;
				day=1;
				break;
			}
			else{
				day++;
				break;
			}
		case dec:
			if(day==31){
				month=jan;
				day=1;
				year++;
				break;
			}
			else{
				day++;
				break;
			}
	} // switch
}


void Date::add_day(unsigned int n){
	while(n--)
		add_one_day();
}


bool Date::operator==(const Date& rhs) const{
  return day==rhs.day && month==rhs.month && year==rhs.year;
}

bool Date::operator!=(const Date& rhs) const{
  return !(*this == rhs);
}


#endif // __DATE__
