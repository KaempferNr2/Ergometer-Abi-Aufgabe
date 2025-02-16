#pragma once
#include <list>

#include "Date.h"
#include "Messung.h"

class Benutzer;

class Trainingseinheit
{
public:
	Date get_datum() const;
	void set_datum(const Date& datum);
	int get_dauer() const;
	void set_dauer(int dauer);
	bool is_aktiv() const;
	void set_aktiv(bool aktiv);
	int get_max_puls() const;
	void set_max_puls(int max_puls);
	int get_min_puls() const;
	void set_min_puls(int min_puls);
	Benutzer* get_benutzer() const;
	void set_benutzer(Benutzer* benutzer);
	std::list<Messung*> get_messungen() const;
	void set_messungen(const std::list<Messung*>& messungen);

private:
	Date datum;
	int dauer;
	bool aktiv;
	int maxPuls;
	int minPuls;
	Benutzer* benutzer;
	std::list<Messung*> messungen;
public:
	Trainingseinheit(Benutzer benutzer, int dauer);
	Trainingseinheit(Benutzer, int, int, int);
	void hinzufuegenMessung(Messung* data);
	Messung* leseMessung(int index);
	void berechneTrainingwerte();
	void abbrechen();
};

