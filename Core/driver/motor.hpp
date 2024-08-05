#pragma once

#include "PID.hpp"

class Motor
{
public:
	Motor() : pid_(PID(1, true)) {};
private;
	PID pid_;
	int encoder
};

