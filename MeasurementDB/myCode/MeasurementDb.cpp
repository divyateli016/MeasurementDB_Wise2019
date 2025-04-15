/*
 * MeasurementDb.cpp
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#include "MeasurementDb.h"
#include "Humidity.h"
#include "Temperature.h"

MeasurementDb::MeasurementDb()
{
	// TODO Auto-generated constructor stub

}

void MeasurementDb::addMeasurement(const std::string &location,
		std::shared_ptr<Measurement> measurement)
{
	auto find = this->data.find(location);
	if (find != data.end())
	{
		find->second.push_back(measurement);
	}
	else
	{
		std::vector<std::shared_ptr<Measurement>> toadd;
		toadd.push_back(measurement);
		this->data.insert(make_pair(location, toadd));
	}
	//Debugging
	std::cout << "Size after adding the measurement " << data.size()
			<< std::endl;
}

void MeasurementDb::print()
{
	std::cout << "Content of database:" << std::endl;
	for (const auto &pair : data)
	{
		for (const auto &location : pair.second)
		{
			//std::cout<<location->getTimestamp()<<std::endl;
			std::string time = location->toTimeOfDay(location->getTimestamp());
			std::cout << pair.first << ":" << time << " "
					<< location->toString() << std::endl;
		}

	}
}

void MeasurementDb::save(std::ostream &to)
{
	for (const auto &pair : data)
	{
		to << "[" << pair.first << "]" << std::endl;
		for (const auto &measurement : pair.second)
		{
			to << measurement->getTimestamp() << ";" << measurement->toString()
					<< std::endl;

		}
	}
}

void MeasurementDb::load(std::istream &from)
{

	/*
	 * Clearing the data base
	 */
	this->data.clear();

	std::cout << "After removing the data from file" << data.size()
			<< std::endl;
	std::string data;
	std::string time;
	std::string type;
	std::string remainder;
	std::string location;
	long timestamp;
	while (std::getline(from, data)) //return type of getline is reference to istream
	{
		auto pos = data.find('[');
		if (pos != std::string::npos)
		{
			location = data.substr(1, data.size() - 2);
			std::cout << location << std::endl; //To debug
		}
		else
		{
			//Line will be measurement
			if (data.find('[') == std::string::npos)
			{
				auto hash = data.find(';');
				if (hash != std::string::npos)
				{
					time = data.substr(0, hash);
				}
				auto colon = data.find(':');
				if (colon != std::string::npos)
				{
					type = data.substr(hash + 1, colon - 4);
				}
				timestamp = stol(time);
				remainder = data.substr(colon + 2, (data.size() - colon + 1));
				Measurement::parseLine(data, timestamp, type, remainder);

				//To check if the read values are
				std::cout << "Timestamp is " << timestamp << std::endl;
				std::cout << "type is " << type << std::endl;
				std::cout << "Remainder is " << remainder << std::endl;

				if (type == "Humidity")
				{
					std::shared_ptr<Humidity> humid = Humidity::fromString(
							timestamp, remainder);
					addMeasurement(location, humid);
				}
				else if (type == "Temperature")
				{
					std::shared_ptr<Temperature> temp = Temperature::fromString(
							timestamp, remainder);
					addMeasurement(location, temp);
				}

			}
		}

	}

}

bool MeasurementDb::maximumTemperature(std::string &location,
		std::shared_ptr<Measurement> &measurement)
{
	float maxtemp;
	std::set<float> Temperatures;
	for (const auto &loc : data)
	{
		for (const auto &measure : loc.second)
		{
			Temperature *tptr = dynamic_cast<Temperature*>(measure.get());
			{
				if (tptr != nullptr)
				{
					Temperatures.insert(tptr->getTemperature());
				}
			}
		}
	}

	if (Temperatures.empty())
	{
		return false;
	}
	maxtemp = *Temperatures.rbegin();
	for (const auto &loc : data)
	{
		for (const auto &measure : loc.second)
		{
			Temperature *tptr = dynamic_cast<Temperature*>(measure.get());
			if (tptr != nullptr && tptr->getTemperature() == maxtemp)
			{
				location = loc.first;
				measurement = measure;
				return true;
			}
		}
	}
	return false;

}

MeasurementDb::~MeasurementDb()
{
	// TODO Auto-generated destructor stub
}

