#include "ErgometerKlasse.h"

ErgometerKlasse::ErgometerKlasse(std::string serialPort)
{
	this->open();
}

bool ErgometerKlasse::open()
{
	port->open();
}

bool ErgometerKlasse::reset()
{
}

bool ErgometerKlasse::setPower(int destPower)
{
}

std::string ErgometerKlasse::readStatus()
{
	port->write();
}

void ErgometerKlasse::close()
{
	port->close();
}
