#include "ErgometerKlasse.h"

ErgometerKlasse::ErgometerKlasse(std::string serialPort)
{
	port = new Serial(serialPort, 9600, 8, 1, 0);
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
	std::string output = port->readLine();
	port->write(CMD_GET_STATUS);
	do {
		output = port->readLine();
		cout << output << endl;
	} while (output.length()<= 4);
	return output;
}

void ErgometerKlasse::close()
{
	port->close();
}
