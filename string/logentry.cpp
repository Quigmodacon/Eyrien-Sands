//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) : LogEntry() {
    // ...
    std::vector<String> vec = s.split(' ');
	if (vec.size() == 10) {
//		std::cout << "host first\n";
		host = vec[0];
//		std::cout<<"start\n";
		std::vector<String> dateTime = vec[3].split('/');
		std::vector<String> dateTimeSplit = dateTime[2].split(':');
//		std::cout<<"Split date and time\n";
		date.setDate(dateTime[0].substr(1, 2), dateTime[1], dateTimeSplit[0].toInt());
		time.setTime(dateTimeSplit[1].toInt(), dateTimeSplit[2].toInt(), dateTimeSplit[3].toInt());
//		std::cout<<"Before building req string\n";
//		std::cout << vec[5] << std::endl;
//		request = vec[5] + ' ';
//		std::cout << vec[6] << std::endl;
//		request += vec[6];
//		request += ' ';
//		std::cout << vec[7] << std::endl;
//		request += vec[7];
		request = vec[5] + ' ' + vec[6] + ' ' + vec[7];
//		std::cout << request << std::endl;
//		std::cout<<"before status set\n";
		status = vec[8];
//		std::cout<<"Req string is built\n";
//		std::cout<<"Before bytes\n";
		if (vec[9] != '-')
			number_of_bytes = vec[9].toInt();
		else
			number_of_bytes = 0;
//		std::cout<<"End with 10 fields\n";
	}
	else{
//	  std::cout<<"End with less than 10 fields\n";
	}
}

std::ostream& operator<<(std::ostream& out, const LogEntry& log) {
	if (log.host != "") {
		out << log.host << ' ';
		out << log.date.getDay() << '/' << log.date.getMonth() << '/' << log.date.getYear() << ' ';
		out << log.time.getHour() << ':' << log.time.getMin() << ':' << log.time.getSec() << ' ';
		out << log.request << ' ';
		out << log.status << ' ';
		out << log.number_of_bytes;
	}
	else
		out << ' ';
	return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
	String log;
	LogEntry entry;
	int temporaryCount = 0;
	char temp[2048];
	while (!in.eof()){
		std::cout << ++temporaryCount << '\n';
//		std::cerr << "while entered\n";
		in.getline(temp , 2048);
//		std::cout << temp << '\n';	
		if (in.eof()) {
//			std::cerr << "eof after in.getline\n";
			break;
		}
		log = temp;
//		std::cout << log << '\n';
//		std::cerr << "push_back\n";
		entry = LogEntry(log);
		std::cout << entry << std::endl;
		result.push_back(entry);
//		std::cerr << "end of while\n";
	}
//	std::cerr << "while broke about to return\n";
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& logs) {
	for(std::vector<LogEntry>::const_iterator it = logs.begin(); it != logs.end(); ++it) {
    	out << *it << std::endl;
	} 
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
	for(std::vector<LogEntry>::const_iterator it = logs.begin(); it != logs.end(); ++it) {
    	out << it->getHost() << std::endl;
	} 
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry>& logs) {
    if(logs.size() > 0) {
		int result = 0;
		for(std::vector<LogEntry>::const_iterator it = logs.begin(); it != logs.end(); ++it) {
    		result += it->getByte();
		} 
		return result;
	}
    return 0;
}

