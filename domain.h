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
    int price;
}Offer;

Offer createOffer(char* destination, char* type, Date departure_date, int price);
Date createDate(int year, int month, int day);

void destroyOffer(Offer* o);

void destroyDate(Date* d);

void testCreateOffer();

int validateDate(Date d);

int validateOffer(Offer o);

int compareDates(Date a, Date b);

int cmp_date(Date a, Date b);
