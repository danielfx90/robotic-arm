#ifndef MyServo_h
#define MyServo_h

#include <Servo.h>
#include "Motor.h"
#include "AnalogInput.h"

class MyServo : public Motor {

	int pin;
	float minRotation;
	float maxRotation;
	float initialPosition;

	int movementInterval;
	int countedCycles;
	Servo servo;

	void writePositionWithinRange(float value);

protected:
	virtual void doWriteWithAnalog(AnalogInput& input, int direction);
	virtual void doWriteWithPosition(int position);
	virtual void doWriteWithRelativePosition(int position, int direction);

public:
	MyServo(int pin, float minRotation, float maxRotation, float initialPosition, int movementInterval);
	virtual void setup();
	virtual void update();
	void move(float relativePosition, int direction);
	virtual int getPosition();
	virtual bool hasHitLimit();
};

#endif
