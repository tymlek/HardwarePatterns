#ifndef MotorData_H
#define MotorData_H

#include "HWProxyExample.h"

//-----------------------------------------------------------------------------

struct MotorData {
	std::uint8_t on_off;
	DirectionType direction;
	std::uint32_t speed;
	std::uint_fast8_t errorStatus;
	std::uint_fast8_t noPowerError;
	std::uint_fast8_t noTorqueError;
	std::uint_fast8_t BITError;
	std::uint_fast8_t overTemperatureError;
	std::uint_fast8_t reservedError1;
	std::uint_fast8_t reservedError2;
	std::uint_fast8_t unknownError;
};

//-----------------------------------------------------------------------------

#endif