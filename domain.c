#include "domain.h"
#include <string.h>
#include <assert.h>

Offer createOffer(char *destination, char *type, Date departure_date, int price)
{
    //a simple function that creates an offer
    Offer o;
    strcpy_s(o.destination,sizeof(o.destination), destination);
    strcpy_s(o.type,sizeof(o.type), type);
    o.departure_date = departure_date;
    o.price = price;
    return o;
}

Date createDate(int year, int month, int day)
{
    //a simple function that creates a date
    Date d;
    d.year = year;
    d.month = month;
    d.day = day;
    return d;
}

void destroyOffer(Offer *o)
{
    //no memory is allocated on the heap
    //nothing to dealocate
    //mark that pet is destroyed, avoid accidental use after destroy
    o->departure_date.year = -1;
    o->departure_date.month = -1;
    o->departure_date.day = -1;
    o->price = -1;
    o->destination[0] = '\0';
    o->type[0] = '\0';
}

void destroyDate(Date *d)
{
    //no memory is allocated on the heap
    //nothing to dealocate
    //mark that pet is destroyed, avoid accidental use after destroy
    d->year = -1;
    d->month = -1;
    d->day = -1;
}

int validateOffer(Offer o)
{
    //a simple function that validates an offer
    return (o.price > 0 && validateDate(o.departure_date));
}

int leap_year(int year)
{
    //a simple function that checks for leap years
    if ((year % 4 == 0) && (year % 100 != 0))
        return 1;
    if (year % 400 == 0)
        return 1;
    return 0;
}

int validateDate(Date d) // kinda overengineered instead of just using linux time but cool
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

int cmp_date(Date a, Date b)
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