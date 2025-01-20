#pragma once
#include <string>

#include "Benutzer.h"

class Steuerung
{
	Benutzer benutzer;
	Trainingseinheit einheit;
	bool trainingGestartet();
public:
	Steuerung(std::string serialPort);
	Benutzer sucheBenutzer(std::string name);
	void absolviereTrainingseiheit();
	void absolvierePulsTraining();
	int berechneFitnessNote();
	void delay(long millis);
	long currentTime();
};

