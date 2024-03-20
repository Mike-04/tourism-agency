#include "domain.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
//int leap_year(int year)
//{
//    //a simple function that checks for leap years
//    if ((year % 4 == 0) && (year % 100 != 0))
//        return 1;
//    if (year % 400 == 0)
//        return 1;
//    return 0;
//}


//int validateDate(Date d) // kinda overengineered instead of just using linux time but cool
//{
//    // a function that validates a date structure
//    // check if the month is between 1 and 12
//    if (d.month > 12 || d.month < 1)
//        return 0;
//    //check for months with 31 days
//    if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12)
//        return (d.day > 0 && d.day <= 31);
//    //check in what kind of year we are and analyze febraury
//    if (d.month == 2)
//        if (leap_year(d.year))
//            return (d.day > 0 && d.day <= 29);
//        else
//            return (d.day > 0 && d.day <= 28);
//    //check for months with 30 days
//    if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
//        return (d.day > 0 && d.day <= 30);
//}

Offer * createOffer(int id, char *destination, char *type, Date * departure_date, float price)
{
    //a simple function that creates an offer
    Offer * o = (Offer *)malloc(sizeof(Offer));
    o->id = id;
    o->destination = (char *)malloc(sizeof(char) * (strlen(destination) + 1));
    strcpy_s(o->destination,sizeof(o->destination), destination);
    o->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
    strcpy_s(o->type,sizeof(o->type), type);
    o->departure_date = departure_date;
    o->price = price;
    return o;
}

Date * createDate(int year, int month, int day)
{
    //a simple function that creates a date
    Date * d = (Date *)malloc(sizeof(Date));
    d->year = year;
    d->month = month;
    d->day = day;
    return d;
}

void destroyOffer(Offer *o)
{
    //dealocate offer
    printf("destroying date\n");
    destroyDate(o->departure_date);
    printf("destroying offer\n");
    free(o->destination);
    free(o->type);
    printf("destroying strings\n");
    free(o);
    printf("destroyed\n");
}

void destroyDate(Date *d)
{
    //dealocate date
    free(d);
}

//getters and setters for offer

int getId(Offer *o)
{
    return o->id;
}
int setId(Offer *o, int id)
{
    o->id = id;
    return 0;
}

char *getDestination(Offer *o)
{
    return o->destination;
}
int setDestination(Offer *o, char *destination)
{
    strcpy_s(o->destination,sizeof(o->destination), destination);
    return 0;
}

char *getType(Offer *o)
{
    return o->type;
}
int setType(Offer *o, char *type)
{
    strcpy_s(o->type,sizeof(o->type), type);
    return 0;
}

Date *getDepartureDate(Offer *o)
{
    return o->departure_date;
}
int setDepartureDate(Offer *o, Date *departure_date)
{
    o->departure_date = departure_date;
    return 0;
}

float getPrice(Offer *o)
{
    return o->price;
}
int setPrice(Offer *o, float price)
{
    o->price = price;
    return 0;
}

//validate offer
int validateOffer(Offer *o)
{
    //a simple function that validates an offer
    if (o->id < 0)
        return 0;
    if (strlen(o->destination) == 0)
        return 0;
    if (strlen(o->type) == 0)
        return 0;
    if (o->departure_date->year < 0)
        return 0;
    if (o->departure_date->month < 0)
        return 0;
    if (o->departure_date->day < 0)
        return 0;
    if (o->price < 0)
        return 0;
    return 1;
}


void testCreateDestroy() {
    Date * d = createDate(2020, 10, 10);
    assert(d->year == 2020);
    assert(d->month == 10);
    assert(d->day == 10);
    destroyDate(d);
    Offer * o = createOffer(1, "a", "b", createDate(2020, 10, 10), 10);
    assert(getId(o) == 1);
    assert(strcmp(getDestination(o), "a") == 0);
    assert(strcmp(getType(o), "b") == 0);
    assert(getDepartureDate(o)->year == 2020);
    assert(getDepartureDate(o)->month == 10);
    assert(getDepartureDate(o)->day == 10);
    assert(getPrice(o) == 10);
    destroyOffer(o);

}
