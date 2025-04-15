/*
 * Temperature.cpp
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#include "Temperature.h"



Temperature::Temperature(long timestamp, float temperature):
Measurement(timestamp),temperature(temperature)
{
}

float Temperature::getTemperature() const
{
	return this->temperature;
}

std::string Temperature::toString()
{
	std::string result="Temperature:";
	result+=" "+std::to_string(this->temperature)+"°C";
	return result;
}


Temperature::~Temperature()
{
	// TODO Auto-generated destructor stub
}

std::shared_ptr<Temperature> Temperature::fromString(long timestamp,
		std::string value)
{
	value.pop_back();
		//For debugging
		std::cout<<value<<std::endl;
		float measuredvalue = stof(value);
		std::cout<<std::fixed<<std::setprecision(6)<<measuredvalue<<std::endl;
		return std::make_shared<Temperature>(timestamp,measuredvalue);
}

Temperature* Temperature::toType(Measurement *ptr)
{
	Temperature* tptr = dynamic_cast<Temperature*>(ptr);
	if(tptr!=nullptr)
	{
		return tptr;
	}
	else
	{
		return nullptr;
	}
}
