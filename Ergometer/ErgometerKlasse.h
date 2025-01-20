#pragma once
#include <iostream>

#include "Serial.h"

class ErgometerKlasse
{
		Serial* port;
		static std::string CMD_CHANGEMODE;
		static std::string CMD_RESET;
		static std::string CMD_GET_STATUS;
		static std::string CMD_SET_POWER;
		static std::string ACK;
		static std::string Error;
	public:
		ErgometerKlasse(std::string serialPort);
		bool open();
		bool reset();
		bool setPower(int destPower);
		std::string readStatus();
		void close();



};

