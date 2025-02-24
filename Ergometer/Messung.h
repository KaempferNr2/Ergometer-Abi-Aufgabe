#pragma once
#include <string>

class Messung
{
public:
	int get_puls() const;
	void set_puls(int puls);
	int get_umdrehungen() const;
	void set_umdrehungen(int umdrehungen);
	int get_ziel_leistung() const;
	void set_ziel_leistung(int ziel_leistung);
	int get_reale_leistung() const;
	void set_reale_leistung(int reale_leistung);

private:
	int puls;
	int umdrehungen;
	int zielLeistung;
	int realeLeistung;
public:
	Messung(std::string dataString);
	std::string toString();
};

