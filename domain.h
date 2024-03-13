#pragma once
//define struct date
typedef struct{
    int year;
    int month;
    int day;
}Date;

//define struct offer
typedef struct{
    int id;
    char destination[100];
    char type[100];
    Date departure_date;
    float price;
}Offer;

Offer createOffer(int id,char* destination, char* type, Date departure_date, float price);
Date createDate(int year, int month, int day);

void destroyOffer(Offer* o);

void destroyDate(Date* d);

void testCreateOffer();

void testCreateDestroy();

int validateDate(Date d);

int validateOffer(Offer o);

int compareDates(Date a, Date b);

int cmp_date(Date a, Date b);
