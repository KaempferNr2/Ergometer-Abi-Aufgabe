#pragma once
#include <string>
#include "Windows.h"
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
	void absolviereTrainingseiheit(Benutzer, int);
	void absolvierePulsTraining(Benutzer, int, int);
	int berechneFitnessNote();
	static void delay(long millis);
	static long currentTime();
};

