/*
 * Humidity.h
 *
 *  Created on: Apr 14, 2025
 *      Author: divya
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_
#include "Measurement.h"
#include <memory>
#include <iomanip>

/**
 * @class Humidity
 * @brief Represents a humidity measurement.
 *
 * The Humidity class encapsulates a humidity measurement, providing access to
 * the humidity value and functionality to create an instance from a string.
 * It also supports converting an object pointer of type Measurement to a
 * Humidity pointer.
 */
class Humidity: public Measurement
{
private:
	float humidity;
public:
	/**
	 * @brief Constructs a Humidity object.
	 *
	 * @param timestamp The timestamp of the measurement.
	 * @param humidity The humidity value.
	 */
	Humidity(long timestamp, float humidity);
	/**
	 * @brief Returns the humidity value.
	 *
	 * @return The humidity as a float.
	 */
	float getHumidity() const;
	/**
	 * @brief Converts the Humidity measurement to a string.
	 *
	 * Overrides the base class's toString() to provide a string representation
	 * specific to a humidity measurement.
	 *
	 * @return A string representation of the humidity measurement.
	 */
	std::string toString() override;
	/**
	 * @brief Creates a Humidity object from a string.
	 *
	 * Converts a string representation of a humidity measurement and creates a
	 * corresponding Humidity object.
	 *
	 * @param timestamp The timestamp of the measurement.
	 * @param value The string representation of the humidity measurement
	 *  (e.g., "80.000000%").
	 * @return A shared pointer to the newly created Humidity object.
	 */
	static std::shared_ptr<Humidity> fromString(long timestamp,
			std::string value);
	/**
	 * @brief Converts a Measurement pointer to a Humidity pointer.
	 *
	 * Checks if the provided Measurement pointer actually points to a Humidity
	 * object. If it does, returns a pointer to the Humidity object; otherwise,
	 *  returns nullptr.
	 *
	 * @param ptr A pointer to a Measurement object.
	 * @return A pointer to the Humidity object if the conversion is successful,
	 *  or nullptr otherwise.
	 */
	static Humidity* toType(Measurement *ptr);
	/**
	 * @brief Destroys the Humidity object.
	 *
	 * The destructor cleans up any resources used by the Humidity object.
	 */
	virtual ~Humidity();
};

#endif /* HUMIDITY_H_ */
