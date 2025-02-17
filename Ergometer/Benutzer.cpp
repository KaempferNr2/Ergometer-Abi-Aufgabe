#include "Benutzer.h"

const std::string& Benutzer::get_name() const
{
	return name;
}

void Benutzer::set_name(const std::string& name)
{
	this->name = name;
}

int Benutzer::get_fitness_zustand() const
{
	return fitnessZustand;
}

void Benutzer::set_fitness_zustand(const int fitness_zustand)
{
	fitnessZustand = fitness_zustand;
}

int Benutzer::get_ziel_leistung() const
{
	return zielLeistung;
}

void Benutzer::set_ziel_leistung(const int ziel_leistung)
{
	zielLeistung = ziel_leistung;
}

Benutzer::Benutzer(std::string Name)
{

	name = Name;
	fitnessZustand = 0;
	zielLeistung = 10;
}

void Benutzer::hinzufuegenEinheit(Trainingseinheit* training)
{
	einheiten.push_back(training);
}
