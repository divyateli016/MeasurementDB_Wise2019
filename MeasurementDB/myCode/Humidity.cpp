/*
 * Humidity.cpp
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#include "Humidity.h"

Humidity::Humidity(long timestamp, float humidity) :
		Measurement(timestamp), humidity(humidity)
{
}

float Humidity::getHumidity() const
{
	return this->humidity;
}

std::string Humidity::toString()
{
	std::string result = "Humidity: ";
	result += std::to_string(this->humidity) + "%";
	return result;
}

std::shared_ptr<Humidity> Humidity::fromString(long timestamp,
		std::string value)
{
	value.pop_back();
	//For debugging
	std::cout << value << std::endl;
	float measuredvalue = stof(value);
	std::cout << std::fixed << std::setprecision(6) << measuredvalue
			<< std::endl;
	return std::make_shared<Humidity>(timestamp, measuredvalue);
}

Humidity* Humidity::toType(Measurement *ptr)
{
	if (ptr != nullptr)
	{
		Humidity *hptr = dynamic_cast<Humidity*>(ptr);
		if (hptr != nullptr)
		{
			return hptr;
		}
	}

	return nullptr;

}

Humidity::~Humidity()
{
	// TODO Auto-generated destructor stub
}

