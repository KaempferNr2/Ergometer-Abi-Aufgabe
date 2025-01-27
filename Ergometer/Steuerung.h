#pragma once
#include <string>

#include "Benutzer.h"
#include "ErgometerKlasse.h"
class Steuerung
{
	std::list<Benutzer*> benutzer;
	Trainingseinheit* einheit;
	ErgometerKlasse* ergometer;
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

