/*
 * Temperature.h
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
#include "Measurement.h"
#include <memory>

/**
 * @class Temperature
 * @brief Represents a temperature measurement.
 *
 * Inherits from Measurement and stores a floating-point temperature value.
 * Includes utility functions for construction, conversion, and type-checking.
 */
class Temperature: public Measurement
{
private:
	/// The temperature value in degrees Celsius.
	float temperature;
public:
	/**
	 * @brief Constructs a Temperature object.
	 * @param timestamp The time the measurement was taken.
	 * @param temperature The temperature value.
	 */
	Temperature(long timestamp, float temperature);
	/**
	 * @brief Gets the temperature value.
	 * @return The temperature as a float.
	 */
	float getTemperature() const;
	/**
	 * @brief Converts the temperature measurement to a string.
	 * @return A string representation of the temperature.
	 */
	std::string toString() override;
	/**
	 * @brief Creates a shared Temperature object from string input.
	 * @param timestamp The timestamp associated with the measurement.
	 * @param value The string containing the temperature value.
	 * @return A shared pointer to the Temperature object.
	 */
	static std::shared_ptr<Temperature> fromString(long timestamp,
			std::string value);
	/**
	 * @brief Converts a generic Measurement pointer to a Temperature pointer.
	 * @param ptr A pointer to a Measurement object.
	 * @return A Temperature pointer if successful, or nullptr if the cast fails.
	 */
	static Temperature* toType(Measurement *ptr);
	/**
	 * @brief Virtual destructor.
	 */
	virtual ~Temperature();
};

#endif /* TEMPERATURE_H_ */
