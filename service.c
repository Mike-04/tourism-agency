#include "domain.h"
#include "service.h"
#include "repo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

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

int addOffer(Offers* offers, char *destination, char *type, int year, int month, int day , float price) {
    //create an offer
    Date departure_date = createDate(year, month, day);
    Offer o = createOffer(generateId(offers), destination, type, departure_date, price);
    if (validateOffer(o) == 0) return -1;
    add(offers, o);
    return 0; // all ok
}

int updateOffer(Offers* offers, int id, Offer o) {
    if (validateOffer(o) == 0) return -1;
    update(offers, id, o);
    return 0;
}

void add_random_offers(Offers*offers, int quantity) {
    for (int i = 0; i < quantity; i++) {
        float price = i;
        char dest[10], type[10];
        sprintf(dest, "dest%d", i);
        sprintf(type, "type%d", i);
        addOffer(offers, dest, type, 2020, 10, 10, price);
    }
}

void orderByPriceAndDestination(Offers* offers) {
    for (int i = 0; i < size(offers) - 1; i++) {
        for (int j = i + 1; j < size(offers); j++) {
            if (offers->elems[i].price > offers->elems[j].price) {
                Offer aux = offers->elems[i];
                offers->elems[i] = offers->elems[j];
                offers->elems[j] = aux;
            }
            else if (offers->elems[i].price == offers->elems[j].price) {
                if (strcmp(offers->elems[i].destination, offers->elems[j].destination) > 0) {
                    Offer aux = offers->elems[i];
                    offers->elems[i] = offers->elems[j];
                    offers->elems[j] = aux;
                }
            }
        }
    }
}

int removeOffer(Offers* offers, int id) {
    delete(offers, id);
    return 0;
}

Offers getAllOffers(Offers* offers) {
    Offers rez = createEmpty();
    for (int i = 0; i < size(offers); i++) {
        Offer o = get(offers, i);
            add(&rez, o);
        }
    return rez;
}

Offers filterByCriteria(Offers offers,char type[],char dest[],float min_price,float max_price){
    Offers rez = createEmpty();
    for (int i = 0; i < size(&offers); i++) {
        Offer o = get(&offers, i);
        if (strstr(o.type, type) !=NULL && strstr(o.destination, dest) != NULL && o.price >= min_price && o.price <= max_price ) {
            add(&rez, o);
        }
    }
    return rez;

}

void testAddOffer() {
    Offers offers = createEmpty();
    //try to add invalid offers
    int error = addOffer(&offers, "", "", 2020, 10, 10, 10);
    assert(error != 0);
    assert(size(&offers) == 0);
    error = addOffer(&offers, "a", "b", 2020, 10, 10, -10);
    assert(error != 0);
    assert(size(&offers) == 0);

    //try to add some valid offers
    addOffer(&offers, "a", "b", 2020, 10, 10, 10);
    addOffer(&offers, "a2", "b2", 2020, 10, 10, 20);
    Offers filtered = getAllOffers(&offers);
    assert(size(&filtered) == 2);
}