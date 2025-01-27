#pragma once
#include "Benutzer.h"
#include "Date.h"
#include "Messung.h"

class Trainingseinheit
{
	Date datum;
	int dauer;
	bool aktiv;
	int maxPuls;
	int minPuls;
	Benutzer* benutzer;
	std::list<Messung*> messungen;
public:
	Trainingseinheit(Benutzer benutzer, int dauer);
	void hinzufuegenMessung(Messung data);
	Messung leseMessung(int index);
	void berechneTrainingwerte();
	void abbrechen();
};

