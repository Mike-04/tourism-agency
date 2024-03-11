#pragma once
typedef struct date
{
	int day;
	int month;
	int year;
}date;

typedef struct offer
{
	char tip[256];
	char destinatie[256]; // why the variable in romanian?
	date data;
	float pret;
}offer;