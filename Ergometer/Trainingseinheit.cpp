#include "Trainingseinheit.h"

#include "Benutzer.h"

Date Trainingseinheit::get_datum() const
{
	return datum;
}

void Trainingseinheit::set_datum(const Date& datum)
{
	this->datum = datum;
}

int Trainingseinheit::get_dauer() const
{
	return dauer;
}

void Trainingseinheit::set_dauer(int dauer)
{
	this->dauer = dauer;
}

bool Trainingseinheit::is_aktiv() const
{
	return aktiv;
}

void Trainingseinheit::set_aktiv(bool aktiv)
{
	this->aktiv = aktiv;
}

int Trainingseinheit::get_max_puls() const
{
	return maxPuls;
}

void Trainingseinheit::set_max_puls(int max_puls)
{
	maxPuls = max_puls;
}

int Trainingseinheit::get_min_puls() const
{
	return minPuls;
}

void Trainingseinheit::set_min_puls(int min_puls)
{
	minPuls = min_puls;
}

Benutzer* Trainingseinheit::get_benutzer() const
{
	return benutzer;
}

void Trainingseinheit::set_benutzer(Benutzer* benutzer)
{
	this->benutzer = benutzer;
}

std::list<Messung*> Trainingseinheit::get_messungen() const
{
	return messungen;
}

void Trainingseinheit::set_messungen(const std::list<Messung*>& messungen)
{
	this->messungen = messungen;
}

Trainingseinheit::Trainingseinheit(Benutzer benutzer, int dauer)
{
	this->benutzer = &benutzer;
	this->dauer = dauer;
	aktiv = true;
	datum = Date(1, 01, 1111);
	maxPuls = INT_MIN; 
	minPuls = INT_MAX;
}
Trainingseinheit::Trainingseinheit(Benutzer benutzer, int minPuls, int maxPuls, int dauer)
{
	this->benutzer = &benutzer;

}

void Trainingseinheit::hinzufuegenMessung(Messung* data)
{
	messungen.push_back(data);
}

Messung* Trainingseinheit::leseMessung(int index)
{
	return nullptr;
}

void Trainingseinheit::berechneTrainingwerte()
{
	for (auto messung : messungen)
	{
		if (messung->get_puls() < minPuls)minPuls = messung->get_puls();
		if (messung->get_puls() > maxPuls)maxPuls = messung->get_puls();
	}
}

void Trainingseinheit::abbrechen()
{
}
