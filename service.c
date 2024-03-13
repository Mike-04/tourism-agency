
#include "service.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*
Add a pet to the store
*/
int addOffer(Offers* l, Offer o) {
    if (validateOffer(o) == 0) return -1;

    add(l, o);
    return 0; // all ok
}



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

int updateOffer(Offers* l, int poz, Offer o) {
    if (validateOffer(o) == 0) return -1;
    update(l, poz, o);
    return 0;
}

Offers getAllOffers(Offers* l) {
    Offers rez = createEmpty();
    for (int i = 0; i < size(l); i++) {
        Offer o = get(l, i);
            add(&rez, o);
        }
    return rez;
}


void testAddOffer() {
    Offers l = createEmpty();
    //try to add invalid offers
    int error = addOffer(&l, createOffer("", "b", createDate(2020, 10, 10), 10));
    assert(error != 0);
    assert(size(&l) == 0);

    error = addOffer(&l, createOffer("a", "b", createDate(2020, 10, 10), -10));
    assert(error != 0);
    assert(size(&l) == 0);

    //try to add some valid offers
    addOffer(&l, createOffer("a", "b", createDate(2020, 10, 10), 10));
    addOffer(&l, createOffer("a2", "b2", createDate(2020, 10, 10), 20));
    Offers filtered = getAllOffers(&l);
    assert(size(&filtered) == 2);
}