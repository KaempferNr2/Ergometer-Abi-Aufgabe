#include "Messung.h"

int Messung::get_puls() const
{
	return puls;
}

void Messung::set_puls(int puls)
{
	this->puls = puls;
}

int Messung::get_umdrehungen() const
{
	return umdrehungen;
}

void Messung::set_umdrehungen(int umdrehungen)
{
	this->umdrehungen = umdrehungen;
}

int Messung::get_ziel_leistung() const
{
	return zielLeistung;
}

void Messung::set_ziel_leistung(int ziel_leistung)
{
	zielLeistung = ziel_leistung;
}

int Messung::get_reale_leistung() const
{
	return realeLeistung;
}

void Messung::set_reale_leistung(int reale_leistung)
{
	realeLeistung = reale_leistung;
}

Messung::Messung(std::string dataString)
{
	int i = 0;
	int counter = 0;
	for (char c : dataString) {
		if (c == ';') {
			switch (counter) {
			case 0:
				puls = stoi(dataString.erase(0, i));
			case 1:
				umdrehungen = stoi(dataString.erase(0, i));
			case 2:
				zielLeistung = stoi(dataString.erase(0, i));
			case 3:
				realeLeistung = stoi(dataString.erase(0, i));
			default:
				std::terminate();
			}
		}
		i++;
	}
}

