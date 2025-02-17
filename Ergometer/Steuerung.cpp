#include "list"
#include "Steuerung.h"


bool Steuerung::trainingGestartet()
{
	return 0;
}

Steuerung::Steuerung(std::string serialPort)
{
	ergometer = new ErgometerKlasse((serialPort));
}

void Steuerung::absolviereTrainingseiheit(Benutzer benutzer, int dauer)
{
	einheit = new Trainingseinheit(benutzer, dauer);
	benutzer.hinzufuegenEinheit(einheit);
	if (benutzer.get_ziel_leistung() == 0) benutzer.set_ziel_leistung(25);
	ergometer->reset(); // todo: ELIAS
	ergometer->setPower(benutzer.get_ziel_leistung());
	
	while (Messung(ergometer->readStatus()).get_umdrehungen() <= 0)
	{
		Sleep(1);
	}
	for (int i = 0; i < dauer * 3; i++)
	{
		delay(20);
		Messung* AktuelleMessung = new Messung(ergometer->readStatus());
		einheit->hinzufuegenMessung(AktuelleMessung);
	}
	einheit->berechneTrainingwerte();
	

}



void Steuerung::absolvierePulsTraining(Benutzer benutzer, int minPuls, int maxPuls)
{
	einheit = new Trainingseinheit(benutzer, minPuls, maxPuls, 40);
	benutzer.hinzufuegenEinheit(einheit);
	if (benutzer.get_ziel_leistung() == 0) benutzer.set_ziel_leistung(25);
	ergometer->reset(); 
	int leistung = benutzer.get_ziel_leistung();
	ergometer->setPower(leistung); 
	while(Messung(ergometer->readStatus()).get_umdrehungen() <= 0)
	{
		Sleep(1);
		cout << Messung(ergometer->readStatus()).get_umdrehungen(); 

	}
	cout << endl;
	delay(60);
	{
		Messung* AktuelleMessung = new Messung(ergometer->readStatus());
		einheit->hinzufuegenMessung(AktuelleMessung);
		if (AktuelleMessung->get_puls() > einheit->get_max_puls())
		{
			leistung -= 5;
			ergometer->setPower(leistung);
			cout << "Power -5" << endl;
			cout << AktuelleMessung->get_puls() << endl;
		} 
		if (AktuelleMessung->get_puls() < einheit->get_min_puls())
		{
			leistung += 5;
			ergometer->setPower(leistung);
			cout << "Power +5" << endl;
			cout << AktuelleMessung->get_puls() << endl;
		} 
	}
	for(int i = 0; i < 39*3; i++)
	{
		delay(20);
		Messung* AktuelleMessung = new Messung(ergometer->readStatus());
		einheit->hinzufuegenMessung(AktuelleMessung);
		if (AktuelleMessung->get_puls() > einheit->get_max_puls())
		{
			if (leistung >= 5)leistung -= 5;
			ergometer->setPower(leistung);
			cout << "Power -5" << endl;
		}
		if (AktuelleMessung->get_puls() < einheit->get_min_puls())
		{
			leistung += 5;
			ergometer->setPower(leistung);
			cout << "Power +5" << endl;
		}
	}
	einheit->berechneTrainingwerte();
	benutzer.set_ziel_leistung(leistung);
	cout << "Zielleistung auf " << leistung << "gesetzt";

}

int Steuerung::berechneFitnessNote()
{
	int p1 = Messung(ergometer->readStatus()).get_puls();
	if (p1 <= 0) return -1;
	delay(60);
	int p2 = Messung(ergometer->readStatus()).get_puls();
	if (p2 > p1) return -1;
	return 0;
	
}

void Steuerung::delay(long millis)
{
	Sleep(millis);
}

long Steuerung::currentTime()
{
	return time(nullptr);
}
