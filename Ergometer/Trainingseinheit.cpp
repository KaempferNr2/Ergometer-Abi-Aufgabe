#include "Trainingseinheit.h"

Trainingseinheit::Trainingseinheit(Benutzer benutzer, int dauer)
{
	this->benutzer = &benutzer;
	this->dauer = dauer;
	aktiv = true;
	datum = Date(1, 01, 1111);
	maxPuls = 0;
	minPuls = 0;
}
Trainingseinheit::Trainingseinheit(Benutzer benutzer, int minPuls, int maxPuls)
{
	this->benutzer = &benutzer;

}

void Trainingseinheit::hinzufuegenMessung(Messung data)
{

}

Messung Trainingseinheit::leseMessung(int index)
{
	return {};
}

void Trainingseinheit::berechneTrainingwerte()
{
}

void Trainingseinheit::abbrechen()
{
}
