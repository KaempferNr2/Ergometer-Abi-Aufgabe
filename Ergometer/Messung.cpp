#include "Messung.h"

#include <iostream>

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
    std::cout << dataString;
    int counter = 0;
    size_t pos = 0;
    std::string temp;
    while ((pos = dataString.find(';')) != std::string::npos) {
        temp = dataString.substr(0, pos);
        switch (counter) {
        case 0:
            puls = std::stoi(temp);
            break;
        case 1:
            umdrehungen = std::stoi(temp);
            break;
        case 2:
            zielLeistung = std::stoi(temp);
            break;
        case 3:
            realeLeistung = std::stoi(temp);
            break;
        default:
            return;
        }
        dataString.erase(0, pos + 1);
        counter++;
    }
}
