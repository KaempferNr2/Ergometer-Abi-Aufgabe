#include "ErgometerKlasse.h"

ErgometerKlasse::ErgometerKlasse(std::string serialPort)
{
	port = new Serial("COM3", 9600, 8, 1, 0);
	open();
}

bool ErgometerKlasse::reset()
{
	port->write(CMD_RESET);
	std::string temp;
	for (int i = 0; (i < 100000) && ((temp = port->readLine()) != ACK); i++) {
		Sleep(10);
	}
	return (temp == ACK);
}


bool ErgometerKlasse::setPower(int destPower)
{
	port->write(CMD_CHANGEMODE);
	Sleep(50);
	port->write(std::string(to_string(destPower)) + "\n");
	std::string temp;
	for (int i = 0; ((i < 100000) && (((temp = port->readLine())) != ACK)); i++) {
		Sleep(1);
	}
	return (temp == ACK);
}

std::string ErgometerKlasse::readStatus()
{
	if (port->dataAvailable())
		port->readLine();
	std::string output;
	port->write(CMD_GET_STATUS);
	while (port->dataAvailable() == 0) {
		Sleep(1000);
		std::cout << "..." << std::endl;
	};
	system("cls");
	do {
		Sleep(10);
		output = port->readLine();
		cout << output << endl;
		Sleep(10);
	} while (output.length()<= 5);
	return output;
}

void ErgometerKlasse::open()
{
	if (!port->open()) {
		std::cout << "Serial Port verbindung hat nicht funktioniert";
		Sleep(3000);
	}
}

void ErgometerKlasse::close()
{
	port->close();
}
