#pragma once
#include <string>

#include "Trainingseinheit.h"
#include <list>

class Benutzer
{
public:
	const Trainingseinheit& get_einheit() const;
	void set_einheit(const Trainingseinheit& einheit);
	const std::string& get_name() const;
	void set_name(const std::string& name);
	int get_fitness_zustand() const;
	void set_fitness_zustand(const int fitness_zustand);
	int get_ziel_leistung() const;
	void set_ziel_leistung(const int ziel_leistung);

private:
	std::list<Trainingseinheit*> einheiten;
	std::string name;
	int fitnessZustand;
	int zielLeistung;
public:
	Benutzer(std::string Name);
	void hinzufuegenEinheit(Trainingseinheit einheit);
};

