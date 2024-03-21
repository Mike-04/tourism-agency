#include "domain.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//helper function for old implementation of validateDate
//int leap_year(int year)
//{
//    //a simple function that checks for leap years
//    if ((year % 4 == 0) && (year % 100 != 0))
//        return 1;
//    if (year % 400 == 0)
//        return 1;
//    return 0;
//}

//not used anymore but kept for future use
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

//create offer function create an offer with the given parameters
//Parameters:
//id - the id of the offer
//destination - the destination of the offer
//type - the type of the offer
//departure_date - the departure date of the offer
//price - the price of the offer
//Returns: the created offer
Offer createOffer(int id, char destination[100], char type[100], Date departure_date, float price)
{
    //a simple function that creates an offer
    Offer o;
    o.id = id;
    o.type = (char *)malloc((strlen(type)+1)*sizeof(char));
    strcpy(o.type, type);
    o.destination = (char *)malloc((strlen(destination)+1)*sizeof(char));
    strcpy(o.destination, destination);
    o.departure_date = departure_date;
    o.price = price;
    return o;
}

//create date function create a date with the given parameters
//Parameters:
//year - the year of the date
//month - the month of the date
//day - the day of the date
//Returns: the created date
Date createDate(int year, int month, int day)
{
    //a simple function that creates a date
    Date d;
    d.year = year;
    d.month = month;
    d.day = day;
    return d;
}

//destroy offer function dealocate the memory of the offer
//Parameters:
//o - the offer to be dealocated
void destroyOffer(Offer *o)
{
    //dealocate offer
    //printf("Id:%d Destination:%s Type:%s Departure date:%d-%d-%d Price:%.2f\n", o->id, o->destination, getType(o), o->departure_date.year, o->departure_date.month, o->departure_date.day, o->price);
    if (o == NULL)
        return;
    o->departure_date.year = -1;
    o->departure_date.month = -1;
    o->departure_date.day = -1;
    o->id = -1;
    o->price = -1;
    strcpy(o->destination, "\0");
    strcpy(o->type, "\0");
    free(o->destination);
    free(o->type);

}

//destroy date function dealocate the memory of the date
//Parameters:
//d - the date to be dealocated
void destroyDate(Date *d)
{
    //dealocate date
}

//getters and setters for offer
//setters not used

int getId(Offer *o)
{
    return o->id;
}
//int setId(Offer *o, int id)
//{
//    o->id = id;
//    return 0;
//}

char *getDestination(Offer *o)
{
    return o->destination;
}
//int setDestination(Offer *o, char *destination)
//{
//    strcpy(o->destination, destination);
//    return 0;
//}

char *getType(Offer *o)
{
    return o->type;
}
//int setType(Offer *o, char *type)
//{
//    strcpy(o->type, type);
//    return 0;
//}

Date getDepartureDate(Offer *o){
    return o->departure_date;
}
//int setDepartureDate(Offer *o, Date departure_date)
//{
//    o->departure_date = departure_date;
//    return 0;
//}

float getPrice(Offer *o)
{
    return o->price;
}
//int setPrice(Offer *o, float price)
//{
//    o->price = price;
//    return 0;
//}

//validate offer
//Parameters:
//o - the offer to be validated
//Returns: 1 if the offer is valid, 0 otherwise
int validateOffer(Offer o)
{
    //a simple function that validates an offer
    if (strlen(o.destination) == 0)
        return 0;
    if (strlen(o.type) == 0)
        return 0;
    if (o.departure_date.year < 0)
        return 0;
    if (o.departure_date.month < 0)
        return 0;
    if (o.departure_date.day < 0)
        return 0;
    if (o.price < 0)
        return 0;
    return 1;
}

//test function for domain
void testCreateDestroy() {
    Date d = createDate(2020, 10, 10);
    assert(d.year == 2020);
    assert(d.month == 10);
    assert(d.day == 10);
    destroyDate(&d);
    //printf("destroyed date\n");
    char destination[100], type[100];
    strcpy(destination, "a");
    strcpy(type, "b");
    Offer o = createOffer(1, destination, type, createDate(2020, 10, 10), 10);
    assert(getId(&o) == 1);
    assert(strcmp(getDestination(&o), "a") == 0);
    assert(strcmp(getType(&o), "b") == 0);
    assert(getDepartureDate(&o).year == 2020);
    assert(getDepartureDate(&o).month == 10);
    assert(getDepartureDate(&o).day == 10);
    assert(getPrice(&o) == 10);
    destroyOffer(&o);
    destroyOffer(NULL);
    //printf("destroyed offer\n");
}
