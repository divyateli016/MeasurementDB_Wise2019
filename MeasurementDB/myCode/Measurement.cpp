/*
 * Measurement.cpp
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#include "Measurement.h"

Measurement::Measurement(long timestamp) :
		timestamp(timestamp)
{
}

int Measurement::toTimestamp(int hour, int minute)
{
	int timeinminte;
	if (hour > 24 || minute > 60)
	{
		throw std::invalid_argument("parameters are out of range");
	}
	else if (hour < 24)
	{
		timeinminte = (hour * 60) + minute;
	}
	else if (hour == 24)
	{
		timeinminte = (0 * 60) + minute;
	}
	return timeinminte;
}

std::string Measurement::toTimeOfDay(int timestamp)
{
	std::string time;
	std::ostringstream oss;
	int hour;
	int minute;
	hour = timestamp / 60;
	minute = timestamp % 60;
	oss << std::setw(2) << std::setfill('0') << std::to_string(hour) << ":"
			<< std::setw(2) << std::setfill('0') << std::to_string(minute);
	return oss.str();
}

long Measurement::getTimestamp() const
{
	return this->timestamp;
}

std::ostream& operator <<(std::ostream &lhs, Measurement &rhs)
{
	lhs << rhs.toTimeOfDay(rhs.getTimestamp()) << " " << rhs.toString()
			<< std::endl;
	return lhs;
}

void Measurement::parseLine(const std::string &line, long &timestamp,
		std::string &type, std::string &remainder)
{
	auto pos = line.find(';');
	std::string time = line.substr(0, pos);
	//Debugging
	std::cout << pos << " " << time << std::endl;
	timestamp = stol(time);
	auto pos2 = line.find(':');
	if (pos2 != std::string::npos)
	{
		std::string type = line.substr(pos + 1, pos2 - (pos + 1));
		std::cout << "Type is " << type << std::endl;
	}
	std::string toremove = line.substr(pos2 + 1, *line.rbegin());
	std::cout << "To remove is " << toremove << std::endl;
}

Measurement::~Measurement()
{
	// TODO Auto-generated destructor stub
}

