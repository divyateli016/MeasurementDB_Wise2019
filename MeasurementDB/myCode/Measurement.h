/*
 * Measurement.h
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_
#include <iostream>
#include <string>
#include <iomanip>

/**
 * @class Measurement
 * @brief Abstract base class representing a generic measurement.
 *
 * Provides a base interface for timestamped measurements. Derived classes
 * should implement the toString method to provide specific string representations.
 */
class Measurement
{
private:
	long timestamp;
public:
	/**
	 * @brief Constructor initializing the measurement timestamp.
	 * @param timestamp The timestamp of the measurement.
	 */
	Measurement(long timestamp);
	/**
	 * @brief Converts hour and minute into a timestamp.
	 * @param hour The hour component.
	 * @param minute The minute component.
	 * @return Total minutes since.
	 */

	static int toTimestamp(int hour, int minute);
	/**
	 * @brief Converts a timestamp to a formatted time string.
	 * @param timestamp Minutes since 00:00.
	 * @return A string in the format "HH:MM".
	 */

	static std::string toTimeOfDay(int timestamp);
	/**
	 * @brief Gets the timestamp of the measurement.
	 * @return Timestamp in minutes.
	 */
	long getTimestamp() const;
	/**
	 * @brief Returns a string representation of the measurement.
	 * This is a pure virtual function to be overridden by derived classes.
	 * @return String representation of the measurement.
	 */
	virtual std::string toString()=0;
	/**
	 * @brief Parses a measurement line into its components.
	 *
	 * Parses a line in the format "<timestamp>;<type>: <value>" and extracts
	 * the parts.
	 *
	 * @param line The input string to parse.
	 * @param timestamp Reference to store the extracted timestamp.
	 * @param type Reference to store the measurement type (e.g., "Temperature").
	 * @param remainder Reference to store the remaining value string.
	 */
	static void parseLine(const std::string &line, long &timestamp,
			std::string &type, std::string &remainder);
	/**
	 * @brief Virtual destructor for proper cleanup in derived classes.
	 */
	virtual ~Measurement();
};
/**
 * @brief Overloads the stream insertion operator for Measurement objects.
 * @param lhs The output stream.
 * @param rhs The Measurement object to insert into the stream.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream &lhs, Measurement &rhs);

#endif /* MEASUREMENT_H_ */
