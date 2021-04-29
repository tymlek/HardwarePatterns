#include "MotorProxy.h"

//-----------------------------------------------------------------------------

DirectionType MotorProxy::getMotorDirection() {
	MotorData mData;

	if (motorAddr == nullptr) {
		return NO_DIRECTION;
	}

	mData = unmarshal(*this->motorAddr);

	return mData.direction;
}

//-----------------------------------------------------------------------------

std::uint32_t MotorProxy::getMotorSpeed() {
	MotorData mData;

	if (this->motorAddr == nullptr) {
		return 0;
	}

	mData = unmarshal(*this->motorAddr);

	return mData.speed;
}

//-----------------------------------------------------------------------------

std::uint32_t MotorProxy::getMotorState() {
	MotorData mData;

	if (this->motorAddr == nullptr) {
		return 0;
	}

	mData = unmarshal(*this->motorAddr);

	return mData.errorStatus;
}

//-----------------------------------------------------------------------------

void MotorProxy::clearErrorStatus() {
	if (this->motorAddr == nullptr) {
		return;
	}

	*this->motorAddr &= 0xFF;
}

//-----------------------------------------------------------------------------

void MotorProxy::configure(std::uint32_t length,
	std::uint32_t* location) {
	this->rotaryArmLength = length;
	this->motorAddr = location;
}

//-----------------------------------------------------------------------------

void MotorProxy::disable() {
	if (this->motorAddr == nullptr) {
		return;
	}

	*this->motorAddr &= 0xFFFE;
}

//-----------------------------------------------------------------------------

void MotorProxy::enable() {
	if (this->motorAddr == nullptr) {
		return;
	}

	*this->motorAddr |= 1;
}

//-----------------------------------------------------------------------------

void MotorProxy::initialize() {
	MotorData mData;

	if (this->motorAddr == nullptr) {
		return;
	}

	mData.on_off = 1;
	mData.direction = NO_DIRECTION;
	mData.speed = 0;
	mData.errorStatus = 0;
	mData.noPowerError = 0;
	mData.noTorqueError = 0;
	mData.BITError = 0;
	mData.overTemperatureError = 0;
	mData.reservedError1 = 0;
	mData.reservedError2 = 0;
	mData.unknownError = 0;

	*this->motorAddr = marshal(mData);
}

//-----------------------------------------------------------------------------

void MotorProxy::setMotorSpeed(const DirectionType direction,
	std::uint32_t speed) {
	MotorData mData;

	double dPi;
	double dArmLength;
	double dSpeed;
	double dAdjSpeed;

	if (this->motorAddr == nullptr) {
		return;
	}

	mData = unmarshal(*this->motorAddr);
	mData.direction = direction;

	if (this->rotaryArmLength > 0) {
		dSpeed = speed;
		dArmLength = this->rotaryArmLength;
		dAdjSpeed = dSpeed / 2.0 / 3.14159 / dArmLength * 10.0;
		mData.speed = (int)dAdjSpeed;
	}
	else {
		mData.speed = speed;
	}

	*this->motorAddr = marshal(mData);
}

//-----------------------------------------------------------------------------

std::uint32_t MotorProxy::marshal(const MotorData& mData) {
	std::uint32_t deviceCmd;

	deviceCmd = 0;
	if (mData.on_off) {
		deviceCmd |= 1;
	}

	if (mData.direction == FORWARD) {
		deviceCmd |= (1 << 2);
	}
	else if (mData.direction == REVERSE) {
		deviceCmd |= (1 << 1);
	}

	if (mData.speed < 32 && mData.speed >= 0) {
		deviceCmd |= (mData.speed << 3);
	}

	if (mData.errorStatus) {
		deviceCmd |= (1 << 8);
	}

	if (mData.noPowerError) {
		deviceCmd |= (1 << 9);
	}

	if (mData.noTorqueError) {
		deviceCmd |= (1 << 10);
	}

	if (mData.BITError) {
		deviceCmd |= (1 << 11);
	}

	if (mData.overTemperatureError) {
		deviceCmd |= (1 << 12);
	}

	if (mData.reservedError1) {
		deviceCmd |= (1 << 13);
	}

	if (mData.reservedError2) {
		deviceCmd |= (1 << 14);
	}

	if (mData.unknownError) {
		deviceCmd |= (1 << 15);
	}

	return deviceCmd;
}

//-----------------------------------------------------------------------------

MotorData MotorProxy::unmarshal(std::uint32_t encodedMData) {
	MotorData mData;
	int temp;

	mData.on_off = encodedMData & 1;
	temp = (encodedMData & (3 << 1)) >> 1;

	if (temp == 1) {
		mData.direction = REVERSE;
	}
	else if (temp == 2) {
		mData.direction = FORWARD;
	}
	else {
		mData.direction = NO_DIRECTION;
	}

	mData.speed = (encodedMData & (31 << 3)) >> 3;
	mData.errorStatus = (encodedMData & (1 << 8));
	mData.noPowerError = (encodedMData & (1 << 9));
	mData.noTorqueError = (encodedMData & (1 << 10));
	mData.BITError = (encodedMData & (1 << 11));
	mData.overTemperatureError = (encodedMData & (1 << 12));
	mData.reservedError1 = (encodedMData & (1 << 13));
	mData.reservedError2 = (encodedMData & (1 << 14));
	mData.unknownError = (encodedMData & (1 << 15));

	return mData;
}

//-----------------------------------------------------------------------------