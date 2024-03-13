#include "domain.h"
#include "service.h"
#include "repo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void testAll() {
    testCreateDestroy();
    testCreateList();
    testIterateList();
    testCopyList();
    testAddOffer();
}


int generateId(Offers *l) {
    //take the biggest id from the repo and add 1
    int id= size(l);
    return id+1;
}

int addOffer(Offers* l,char *destination, char *type, int year,int month, int day , float price) {
    //create an offer
    Date departure_date = createDate(year, month, day);
    Offer o = createOffer(generateId(l), destination, type, departure_date, price);
    if (validateOffer(o) == 0) return -1;
    add(l, o);
    return 0; // all ok
}

int updateOffer(Offers* l, int id, Offer o) {
    if (validateOffer(o) == 0) return -1;
    update(l, id, o);
    return 0;
}

int removeOffer(Offers* l, int id) {
    delete(l, id);
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
    int error = addOffer(&l, "", "", 2020, 10, 10, 10);
    assert(error != 0);
    assert(size(&l) == 0);
    error = addOffer(&l, "a", "b", 2020, 10, 10, -10);
    assert(error != 0);
    assert(size(&l) == 0);

    //try to add some valid offers
    addOffer(&l, "a", "b", 2020, 10, 10, 10);
    addOffer(&l,"a2", "b2", 2020, 10, 10, 20);
    Offers filtered = getAllOffers(&l);
    assert(size(&filtered) == 2);
}