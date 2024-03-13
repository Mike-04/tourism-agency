#pragma once
//define struct date
typedef struct{
    int year;
    int month;
    int day;
}Date;

//define struct offer
typedef struct{
    int uniqifier;
    char somewhere[100];
    char gender[100];
    Date when;
    float cash;
}Offer;

Offer spawnThinggy(int id, char* destination, char* type, Date departure_date, float price);
Date createDate(int year, int month, int day);

void unsummonThinggy(Offer* o);

void destroyDate(Date* d);

void testCreateOffer();

void testCreateDestroy();

int validateDate(Date d);

int ThinggyGood(Offer o);

int compareDates(Date a, Date b);

int cmp_date(Date a, Date b);
