/*Names:
* Patricia Antlitz: Manager
* Eric Huynh: Presenter
* Dylan LeDrew: Reflector
* Aaron Roche: Recorder
*/
#include <iostream>
#include <string>

using namespace std;


// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****

// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.

class Month {
	friend class Date;
	
	friend ostream& operator<< (ostream&, Month);
	
    private:
        enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
            
        Month() : _month(Jan) {} // default constructor
        Month(int im) : _month( static_cast<EMonth>(im) ) {} // value constructor
        
        void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions
		void setMonth(int im) { _month = static_cast<EMonth>(im); }
		
		/* Private helper member functions */
        EMonth StringToEMonth(string);
        int MonthToInt() { return static_cast<int>(_month); }
		string MonthToString();
		string MonthToString2();

	    EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(string m) {
	if (m == "Jan") return Jan;
	else if (m == "Feb") return Feb;
	else if (m == "Mar") return Mar;
	else if (m == "Apr") return Apr;
	else if (m == "May") return May;
	else if (m == "Jun") return Jun;
	else if (m == "Jul") return Jul;
	else if (m == "Aug") return Aug;
	else if (m == "Sep") return Sep;
	else if (m == "Oct") return Oct;
	else if (m == "Nov") return Nov;
	else if (m == "Dec") return Dec;
	else {
		cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
		exit(1);
	}
}

string Month::MonthToString() {
	switch (_month) {
		case Jan: return "Jan";
		case Feb: return "Feb";
		case Mar: return "Mar";
		case Apr: return "Apr";
		case May: return "May";
		case Jun: return "Jun";
		case Jul: return "Jul";
		case Aug: return "Aug";
		case Sep: return "Sep";
		case Oct: return "Oct";
		case Nov: return "Nov";
		case Dec: return "Dec";
		default:
			cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
			exit(1);
	}
}

string Month::MonthToString2() {
	switch (_month) {
		case Jan: return "January";
		case Feb: return "February";
		case Mar: return "March";
		case Apr: return "April";
		case May: return "May";
		case Jun: return "June";
		case Jul: return "July";
		case Aug: return "August";
		case Sep: return "September";
		case Oct: return "October";
		case Nov: return "November";
		case Dec: return "December";
		default:
			cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
			exit(1);
	}
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, Month m) {
	out << m.MonthToString2();
	return out;
}


// ***** Add your Date class definition and driver program below. *****
class Date
{
public:
	Date() : day(1), month(1), year(2018) {} // default constructor
	Date(int initMonth, int initDay, int initYear); // value constructor with an integer parameter to represent month
	Date(string initMonth, int initDay, int initYear); // value constructor with a string parameter to represent month

	//mutators
	void setMonth(int newMonth);

	//accessors
	int getDay(void) const;
	int getYear(void) const;
	Month getMonth(void) const;
	string getMonthToString(void) const;

	// Member functions
	void outputDateAsInt(ostream& outputStream) const;
	void outputDateAsString(ostream& outputStream) const;

	// Operator Overloading
	friend ostream& operator<< (ostream& outputStream, const Date& date);
	const Date operator++ ();
private:
	int day;
	Month month;
	int year;
};

/* Definitions of constructors, helper member functions for class Date */
Date:: Date(int initMonth, int initDay, int initYear)
{
	day = initDay;
	month = Month(initMonth);
	year = initYear;
}

Date::Date(string initMonth, int initDay, int initYear)
{
	day = initDay;
	month = Month();
	month.setMonth(initMonth.substr(0,3));
	year = initYear;
}

void Date::setMonth(int newMonth)
{
	month.setMonth(newMonth);
}

int Date::getDay(void) const
{
	return day;
}

int Date::getYear(void) const
{
	return year;
}

Month Date::getMonth(void) const
{
	return month;
}

string Date::getMonthToString(void) const
{
	return getMonth().MonthToString2();
}

void Date::outputDateAsInt(ostream& outputStream) const
{
	outputStream << month._month << "/" << day << "/" << year;
}

void Date::outputDateAsString(ostream& outputStream) const
{
	outputStream << getMonth().MonthToString() << " " << day << ", " << year;
}


ostream& operator<< (ostream& outputStream, const Date& date)
{
	outputStream << date.getMonthToString() << " " << date.getDay() << ", " << date.getYear();
	return outputStream;
}

const Date Date::operator++ ()
{
	year = year + 1;
	return Date(getMonth().MonthToInt(), day, year);
}

int main() {
	cout << "With the following declarations:" << endl;
	cout << "\t Date d1, d2(2, 1, 2018), d3('Mar', 1, 2018); " << endl;
	cout << "...and using operator<< :" << endl;

	Date d1, d2(2, 1, 2018), d3("Mar", 1, 2018);

	cout << "d1 == " << d1 << endl;
	cout << "d2 == " << d2 << endl;
	cout << "d3 == " << d3 << endl;

	cout << endl << "After d3.setMonth(4):" << endl;
	d3.setMonth(4);
	cout << "d3 == " << d3 << endl;

	Date d4(12, 31, 2018);
	cout << "With the following declaration:" << endl;
	cout << "\tDate d4(12, 31, 2018);" << endl;

	cout << "d4.outputDateAsInt(cout) outputs ";
	d4.outputDateAsInt(cout);
	cout << endl;

	cout << "outputDateAsString(cout) outputs ";
	d4.outputDateAsString(cout);
	cout << endl;

	cout << endl << "++d4 == " << ++d4 << endl;
}