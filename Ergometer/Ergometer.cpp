
#include <iostream>
#include "Steuerung.h"
#include "Benutzer.h"

int main()
{
    Steuerung steuerung("COM3");
    Benutzer benutzer("Jonathan");
    steuerung.absolvierePulsTraining(benutzer, 100, 180);
    steuerung.absolviereTrainingseiheit(benutzer, 20);
    steuerung.berechneFitnessNote();
}


