#pragma once
#include <string>

class Messung
{
public:
	[[nodiscard]] int get_puls() const;
	void set_puls(int puls);
	[[nodiscard]] int get_umdrehungen() const;
	void set_umdrehungen(int umdrehungen);
	[[nodiscard]] int get_ziel_leistung() const;
	void set_ziel_leistung(int ziel_leistung);
	[[nodiscard]] int get_reale_leistung() const;
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

