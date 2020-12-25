#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include <fstream>

////////////////////////////////////////////////////////////
class Date { 
public:
            Date() : day(""), month(""), year(0) {}
	String  getDay() const {return day;}
	String  getMonth() const {return month;}
	int     getYear() const {return year;}
	void    setDate(String _day, String _month, int _year) {day = _day; month = _month; year = _year;}
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() : hour(0), minute(0), second(0) {}
	int     getHour() const {return hour;}
	int     getMin() const {return minute;}
	int     getSec() const {return second;}
	void    setTime(int _hour, int _minute, int _second) {hour = _hour; minute = _minute; second = _second;}
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
            LogEntry() : host(""), date(), time(), request(""), status(""), number_of_bytes(0) {}
            LogEntry(String);
	String  getHost() const {return host;}
	int     getByte() const {return number_of_bytes;}
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

