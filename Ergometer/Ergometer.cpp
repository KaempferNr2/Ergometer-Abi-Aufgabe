
#include <iostream>
#include "Steuerung.h"
#include "Benutzer.h"

int main()
{
    Steuerung steuerung("COM3");
    std::cout << "Serial Port erstellt" << std::endl;
    Sleep(3000); 
    Benutzer benutzer("Jonathan");
    benutzer.set_ziel_leistung(100);
    std::cout << "Benutzer erstellt" << std::endl;
    Sleep(3000);
    steuerung.absolvierePulsTraining(benutzer, 80, 140);
    std::cout << "pulstraining absolviert" << std::endl;
    Sleep(3000);
    steuerung.absolviereTrainingseiheit(benutzer, 20);
    std::cout << "eiheit absolviert" << std::endl;
    Sleep(3000);
    steuerung.berechneFitnessNote();
    std::cout << "fitnessNote berechnet";
}


