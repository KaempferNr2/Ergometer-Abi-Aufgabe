#include "ErgometerKlasse.h"

ErgometerKlasse::ErgometerKlasse(std::string serialPort)
{
	this->open();
}

bool ErgometerKlasse::open()
{
	return port->open();
}

bool ErgometerKlasse::reset()
{
	port->write(CMD_RESET);
	std::string temp;
	for (int i = 0; !((i < 100000) || (((temp = port->readLine())) == ACK)); i++) {
		Sleep(1);
	}
	return (temp == ACK);
}

bool ErgometerKlasse::setPower(int destPower)
{
	port->write(CMD_CHANGEMODE);
	port->write(std::string(to_string(destPower)) + "\n");
	std::string temp;
	for (int i = 0; !((i < 100000) || (((temp = port->readLine())) == ACK)); i++) {
		Sleep(1);
	}
	return (temp == ACK);
}

std::string ErgometerKlasse::readStatus()
{
	port->write(CMD_GET_STATUS);
	return port->readLine();
}

void ErgometerKlasse::close()
{
	port->close();
}
