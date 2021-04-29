#ifndef IO2Sensor_H
#define IO2Sensor_H

/* Class IO2Sensor */
class IO2Sensor {
public:
	virtual int gimmeO2Conc() = 0;
	virtual int gimmeO2Flow() = 0;
};

#endif