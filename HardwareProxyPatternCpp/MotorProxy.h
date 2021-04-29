#ifndef MotorProxy_H
#define MotorProxy_H

#include "HWProxyExample.h"
#include "MotorData.h"

//-----------------------------------------------------------------------------

/* Class MotorProxy */
class MotorProxy {
public:
	MotorProxy() {
		motorAddr = nullptr;
	}

	~MotorProxy() {
		
	}

	void configure(std::uint32_t length, uint32_t* location);
	void initialize();

	DirectionType getMotorDirection();
	std::uint32_t getMotorSpeed();
	std::uint32_t getMotorState();

	void setMotorSpeed(const DirectionType direction, std::uint32_t speed);

	void clearErrorStatus();
	void disable();
	void enable();

private:
	std::uint32_t marshal(const MotorData& mData);
	MotorData unmarshal(std::uint32_t encodedMData);

	std::uint32_t* motorAddr;
	std::uint32_t rotaryArmLength;
};

//-----------------------------------------------------------------------------

#endif