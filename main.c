#include "service.h"
#include "domain.h"
#include "ui.h"

/*
9. Agentie de turism

Creati o aplicatie care permite gestiunea ofertelor de la o agentie de turism.
Fiecare oferta are: tip (munte,mare, citiy break), destinatie, data plecare, pret
Aplicatia permite:
 a) Adaugarea de noi oferte.
 b) Actualizare oferte
 c) Stergere oferta
 d) Vizualizare oferete ordonat dupa pret, destinatie (crescator/descrescator)
 e) Vizualizare oferta filtrate dupa un criteriu (destinatie, tip, pret)
*/


int main()
{
    testAll();
	start();
    return 0;
} // where test and layered arhitecture