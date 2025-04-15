// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Measurement.h"
#include "Temperature.h"
#include "Humidity.h"
#include "MeasurementDb.h"

// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main()
{
	// TODO: Add your program code here
	cout << "MeasurementDB started." << endl << endl;
	//Measurement m1(10);
	//int time = m1.toTimestamp(25,30);
	//cout<<time<<std::endl;
	//std::string time = m1.toTimeOfDay(485);
	//cout<<time<<std::endl;

	/**
	 long timestamp=Measurement::toTimestamp(6,0);
	 Temperature measurement1(timestamp,-3.00f);
	 std::cout<<measurement1;//This line is called as operator<<(std::cout,measurement1);
	 **/
//	Humidity humidity(480,80.00f);
//	cout<<humidity.toString()<<std::endl;
	MeasurementDb db;
	Temperature temperature1(605, 20.00f);
	Temperature temperature2(720, 22.00f);
	Humidity humid(480, 80.00f);
	std::shared_ptr<Measurement> share1 = std::make_shared<Temperature>(
			temperature1);
	std::shared_ptr<Measurement> share2 = std::make_shared<Temperature>(
			temperature2);
	std::shared_ptr<Measurement> humidity = std::make_shared<Humidity>(humid);
//
	db.addMeasurement("Bath", humidity);
	db.addMeasurement("Kitchen", share1);
	db.addMeasurement("Kitchen", share2);
//
//	db.print();
//	ofstream file("data.txt");
//	db.save(file);

	/**
	 long timestamp = 480;
	 //std::string type= " ";
	 //std::string remain = " ";
	 std::shared_ptr<Humidity>humid;
	 humid=Humidity::fromString(timestamp,"80.000000%");
	 std::cout<<"Timestamp is "<<humid->getTimestamp()<<std::endl<<"Humidity is "<<
	 humid->getHumidity()<<std::endl;
	 **/

	/**long timestamp = 480;
	 //std::string type= " ";
	 //std::string remain = " ";
	 std::shared_ptr<Temperature>temp;
	 temp=Temperature::fromString(timestamp,"80.000000%");
	 std::cout<<"Timestamp is "<<temp->getTimestamp()<<std::endl<<"Temperature is "<<
	 temp->getTemperature()<<std::endl;**/

//	MeasurementDb db;
//	ifstream file("data.txt");
//	//std::istream is(file);
//	db.load(file);
//
//	//new data
//	db.print();
	std::string location = " ";
	shared_ptr<Measurement> ptr;
	db.maximumTemperature(location, ptr);
	Temperature *tptr = dynamic_cast<Temperature*>(ptr.get());
	cout << location << " " << tptr->getTemperature() << std::endl;

	return 0;
}
