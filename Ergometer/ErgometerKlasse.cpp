#include "ErgometerKlasse.h"

ErgometerKlasse::ErgometerKlasse(std::string serialPort)
{
	port->open();
}

bool ErgometerKlasse::open()
{

}

bool ErgometerKlasse::reset()
{
}

bool ErgometerKlasse::setPower(int destPower)
{
}

std::string ErgometerKlasse::readStatus()
{
}

void ErgometerKlasse::close()
{
}
