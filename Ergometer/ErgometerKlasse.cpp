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
}

bool ErgometerKlasse::setPower(int destPower)
{
}

std::string ErgometerKlasse::readStatus()
{
	port->write(CMD_GET_STATUS);
	for (int i = 0; !((i < 100000) || (port->readLine() == ACK)); i++) {
		Sleep(1);
	}
}

void ErgometerKlasse::close()
{
	port->close();
}
