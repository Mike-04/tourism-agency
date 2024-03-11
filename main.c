#include <stdio.h>
#include <stdlib.h>
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
#define max_size 1000





int leap_year(int year)
{
	//a simple function that checks for leap years
	if ((year % 4 == 0) && (year % 100 != 0))
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

int validate_date(struct date d) // kinda overengineered instead of just using linux time but cool
{
	// a function that validates a date structure
	// check if the month is between 1 and 12
	if (d.month > 12 || d.month < 1)
		return 0;
	//check for months with 31 days
	if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12)
		return (d.day > 0 && d.day <= 31);
	//check in what kind of year we are and analyze febraury
	if (d.month == 2)
		if (leap_year(d.year))
			return (d.day > 0 && d.day <= 29);
		else
			return (d.day > 0 && d.day <= 28);
	//check for months with 30 days
	if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
		return (d.day > 0 && d.day <= 30);
}

int cmp_date(struct date a, struct date b)
{
	//simple function that compares 2 date structs
	// return -1 if a<b
	// return 1 if a>b
	// returns 0 if a==b
	if (a.year < b.year)
		return -1;
	if (a.year > b.year)
		return 1;
	if (a.month < b.month)
		return -1;
	if (a.month > b.month)
		return 1;
	if (a.day < b.day)
		return -1;
	if (a.day > b.day)
		return 1;
	return 0;
}

int main()
{
	start();
} // where test and layered arhitecture