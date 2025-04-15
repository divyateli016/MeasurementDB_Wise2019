/*
 * MeasurementDb.h
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#ifndef MEASUREMENTDB_H_
#define MEASUREMENTDB_H_
#include "Measurement.h"
#include <memory>
#include <map>
#include <vector>
#include <set>

/**
 * @class MeasurementDb
 * @brief Manages a collection of measurements grouped by location.
 *
 * Each location is mapped to a list of measurements. This class allows
 * adding, saving, loading, printing, and analyzing measurement data.
 */
class MeasurementDb
{
private:
	/**
	 * @brief The main data container.
	 *
	 * Maps location names to a vector of shared pointers to Measurement objects.
	 */
	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;
public:
	/**
	 * @brief Default constructor.
	 */
	MeasurementDb();

	/**
	 * @brief Adds a new measurement for a given location.
	 * @param location The name of the location.
	 * @param measurement A shared pointer to the Measurement object.
	 */
	void addMeasurement(const std::string &location,
			std::shared_ptr<Measurement> measurement);
	/**
	 * @brief Prints all measurements to standard output.
	 */
	void print();
	/**
	 * @brief Saves the database to an output stream.
	 * @param to The output stream to write to.
	 */
	void save(std::ostream &to);
	/**
	 * @brief Loads the database from an input stream.
	 * @param from The input stream to read from.
	 */
	void load(std::istream &from);
	/**
	 * @brief Finds the maximum temperature measurement in the database.
	 *
	 * If a temperature measurement exists, returns true and sets the parameters
	 * with the corresponding measurement and location. Otherwise, returns false.
	 *
	 * @param location Reference to store the location of the maximum temperature.
	 * @param measurement Reference to store the shared pointer to the measurement.
	 * @return true if a temperature measurement was found, false otherwise.
	 */
	bool maximumTemperature(std::string &location,
			std::shared_ptr<Measurement> &measurement);
	/**
	 * @brief Virtual destructor.
	 */
	virtual ~MeasurementDb();
};

#endif /* MEASUREMENTDB_H_ */
