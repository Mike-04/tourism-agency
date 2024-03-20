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
     testAddOffer();
}


int generateId(Offers *l) {
    //take the biggest id from the repo and add 1
    int id = size(l);
    return id+1;
}

int addOffer(Offers* offers, char destination[100], char type[100], int year, int month, int day , float price) {
    Date d = createDate(year, month, day);
    Offer o = createOffer(generateId(offers), destination, type, d, price);
    if (validateOffer(o) == 0)
    {
        destroyOffer(&o);
        return -1;
    }
    add(offers, o);
    return 0;
}

int updateOffer(Offers* offers, int id, Offer o) {
    if (validateOffer(o) == 0)
        return -1;
    update(offers, id, o);
    return 0;
}

void add_random_offers(Offers*offers, int quantity) {
for (int i = 0; i < quantity; i++) {
        addOffer(offers, "a", "b", 2020, 10, 10, i);
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

Offers filterByCriteria(Offers * offers, char type[], char dest[], float min_price, float max_price){
    //filter the offers
    Offers rez = createEmpty();
    for (int i = 0; i < size(offers); i++) {
        if (strstr(getType(&offers->elems[i]),type) != NULL && strstr(getDestination(&offers->elems[i]), dest) != NULL &&
                getPrice(&offers->elems[i]) >= min_price && getPrice(&offers->elems[i]) <= max_price) {
            add(&rez, offers->elems[i]);
        }
    }
    return rez;
}
//
void testAddOffer() {
    Offers offers = createEmpty();
    //try to add invalid offers
    int error = addOffer(&offers, "", "", 2020, 10, 10, 10);
    assert(error != 0);
    assert(size(&offers) == 0);
    error = addOffer(&offers, "a", "b", 2020, 10, 10, -10);
    assert(error != 0);
    assert(size(&offers) == 0);
    destroy(&offers);
    Offers offers1 = createEmpty();
    //try to add some valid offers
    addOffer(&offers1, "a", "b", 2020, 10, 10, 10);
    addOffer(&offers1, "a2", "b2", 2020, 10, 10, 20);
    assert(size(&offers1) == 2);
    updateOffer(&offers1, 1, createOffer(1, "a1", "b1", createDate(2020, 10, 10), 10));
    assert(strcmp(getDestination(&offers1.elems[0]), "a1") == 0);
    removeOffer(&offers1, 1);
    assert(size(&offers1) == 1);
    display_repo(&offers1);
    destroy(&offers1);

}