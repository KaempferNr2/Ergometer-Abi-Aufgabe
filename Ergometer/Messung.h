#pragma once
#include <string>

class Messung
{
	int puls;
	int umdrehungen;
	int zielLeistung;
	int realeLeistung;
public:
	Messung(std::string dataString);
	Messung();
	std::string toString();
};

