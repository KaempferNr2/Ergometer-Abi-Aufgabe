#include "Steuerung.h"

bool Steuerung::trainingGestartet()
{
}

Steuerung::Steuerung(std::string serialPort)
{
}

void Steuerung::absolviereTrainingseiheit()
{
}

void Steuerung::absolvierePulsTraining(Benutzer benutzer, int minPuls, int maxPuls)
{
	benutzer.hinzufuegenEinheit(benutzer, minPuls, maxPuls);
	if (benutzer.get_ziel_leistung() == 0) benutzer.set_ziel_leistung(25);

}

int Steuerung::berechneFitnessNote()
{
	if(einheit->leseMessung(40) == 0) // einige sachen sind nur temp btw
	
}

void Steuerung::delay(long millis)
{
	Sleep(millis);
}

long Steuerung::currentTime()
{
}
