#pragma once
#include <iostream>

#include "Serial.h"

class ErgometerKlasse
{
		Serial* port;
		inline constexpr static const char* CMD_CHANGEMODE = "CMD_CHANGEMODE";
		inline constexpr static const char* CMD_RESET = "CMD_RESET";
		inline constexpr static const char* CMD_GET_STATUS = "CMD_GET_STATUS";
		inline constexpr static const char* CMD_SET_POWER = "CMD_SET_POWER";
		inline constexpr static const char* ACK = "ACK";
		inline constexpr static const char* Error = "ERROR";
	public:
		ErgometerKlasse(std::string serialPort);
		bool open();
		bool reset();
		bool setPower(int destPower);
		std::string readStatus();
		void close();



};

