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
    char *destination;
    char *type;
    Date departure_date;
    float price;
}Offer;

Offer createOffer(int id, char destination[100], char type[100], Date departure_date, float price);
void destroyOffer(Offer* o);

Date createDate(int year, int month, int day);
void destroyDate(Date * d);

//getters and setters for offer

int getId(Offer * o);
int setId(Offer * o, int id);

char * getDestination(Offer * o);
int setDestination(Offer * o, char * destination);

char * getType(Offer * o);
int setType(Offer * o, char * type);

Date getDepartureDate(Offer * o);
int setDepartureDate(Offer * o, Date departure_date);

float getPrice(Offer * o);
int setPrice(Offer * o, float price);

//validate offer
int validateOffer(Offer o);

void testCreateDestroy();



