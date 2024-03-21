#include "domain.h"
#include "service.h"
#include "repo.h"
#include <string.h>
#include <assert.h>

// Tests all functionalities.
void testAll() {
    testCreateDestroy();
     testCreateList();
     testIterateList();
     testAddOffer();
}

// Generates a unique ID for a new offer.
// Parameters:
// - l: A pointer to the Offers struct.
// Returns: The generated ID.
int generateId(Offers *l) {
    //take the biggest id from the repo and add 1
    int id = size(l);
    return id+1;
}

// Adds a new offer to the repository.
// Parameters:
// - offers: A pointer to the Offers struct.
// - destination: The destination of the offer.
// - type: The type of the offer.
// - year, month, day: The departure date of the offer.
// - price: The price of the offer.
// Returns: 0 if the offer is added successfully, -1 if the offer is invalid.
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

// Updates an existing offer in the repository.
// Parameters:
// - offers: A pointer to the Offers struct.
// - id: The ID of the offer to be updated.
// - destination: The new destination of the offer.
// - type: The new type of the offer.
// - year, month, day: The new departure date of the offer.
// - price: The new price of the offer.
// Returns: 0 if the offer is updated successfully, -1 if the offer is invalid.
int updateOffer(Offers* offers, int id, char destination[100], char type[100], int year, int month, int day , float price) {
    Date d = createDate(year, month, day);
    Offer o = createOffer(id, destination, type, d, price);
    if (validateOffer(o) == 0)
    {
        destroyOffer(&o);
        return -1;
    }
    update(offers, id, o);

    return 0;
}

// Adds a specified quantity of random offers to the repository.
// Parameters:
// - offers: A pointer to the Offers struct.
// - quantity: The number of random offers to be added.
void add_random_offers(Offers*offers, int quantity) {
for (int i = 0; i < quantity; i++) {
        char type[100],dest[100];
        strcpy(type,"b");
        strcpy(dest,"a");
        addOffer(offers, dest, type, 2020, 10, 10, i);
}
}

// Comparison function used for sorting offers by price and destination.
// Parameters:
// - o1, o2: Pointers to the offers to be compared.
// Returns: 1 if o1 is greater, -1 if o2 is greater, 0 if they are equal.
int function(Offer* o1, Offer* o2) {
    //price and destination
    if (o1->price > o2->price)
        return 1;
    if (o1->price < o2->price)
        return -1;
    if (strcmp(o1->destination, o2->destination) > 0)
        return 1;
    if (strcmp(o1->destination, o2->destination) < 0)
        return -1;
    return 0;
}

// Sorts the offers in the repository based on a specified comparison function.
// Parameters:
// - offers: A pointer to the Offers struct.
// - function: The comparison function used for sorting.
void sort(Offers * offers,int (function(Offer*,Offer* )))
{
    for (int i = 0; i < size(offers) - 1; i++) {
        for (int j = i + 1; j < size(offers); j++) {
            if (function(&offers->elems[i],&offers->elems[j]) > 0) {
                Offer aux = offers->elems[i];
                offers->elems[i] = offers->elems[j];
                offers->elems[j] = aux;
            }
        }
    }
}

//old sorting function
//void orderByPriceAndDestination(Offers* offers) {
//    for (int i = 0; i < size(offers) - 1; i++) {
//        for (int j = i + 1; j < size(offers); j++) {
//            if (offers->elems[i].price > offers->elems[j].price) {
//                Offer aux = offers->elems[i];
//                offers->elems[i] = offers->elems[j];
//                offers->elems[j] = aux;
//            }
//            else if (offers->elems[i].price == offers->elems[j].price) {
//                if (strcmp(offers->elems[i].destination, offers->elems[j].destination) > 0) {
//                    Offer aux = offers->elems[i];
//                    offers->elems[i] = offers->elems[j];
//                    offers->elems[j] = aux;}}}}}

// Deletes an offer from the repository.
// Parameters:
// - offers: A pointer to the Offers struct.
// - id: The ID of the offer to be deleted.
int removeOffer(Offers* offers, int id) {
    delete(offers, id);
    return 0;
}

// Filters the offers in the repository based on specified criteria.
// Parameters:
// - offers: A pointer to the Offers struct.
// - type: The type criteria for filtering.
// - dest: The destination criteria for filtering.
// - min_price: The minimum price criteria for filtering.
// - max_price: The maximum price criteria for filtering.
// Returns: A new Offers struct containing the filtered offers.
Offers filterByCriteria(Offers * offers, char type[], char dest[], float min_price, float max_price){
    //filter the offers
    Offers rez = createEmpty();
    for (int i = 0; i < size(offers); i++) {
        if (strstr(getType(&offers->elems[i]),type) != NULL && strstr(getDestination(&offers->elems[i]), dest) != NULL &&
                getPrice(&offers->elems[i]) >= min_price && getPrice(&offers->elems[i]) <= max_price) {
            Offer o = createOffer(getId(&offers->elems[i]), getDestination(&offers->elems[i]), getType(&offers->elems[i]), getDepartureDate(&offers->elems[i]), getPrice(&offers->elems[i]));
            add(&rez, o);
        }
    }
    return rez;
}

// Tests the service functions.
// Tests the addOffer, updateOffer, filterByCriteria, and sort functions.
void testAddOffer() {
    Offers offers = createEmpty();
    //try to add invalid offers
    char dest[100],type[100];
    strcpy(dest,"");
    strcpy(type,"");
    int error = addOffer(&offers, dest, type, 2020, 10, 10, 10);
    assert(error != 0);
    assert(size(&offers) == 0);
    strcpy(dest,"a");
    strcpy(type,"b");
    error = addOffer(&offers, dest, type, 2020, 10, 10, -10);
    assert(error != 0);
    error = addOffer(&offers, dest, type, 2020, 10, -1, -1);
    assert(error != 0);
    error = addOffer(&offers, dest, type, 2020, -1, 10, -1);
    assert(error != 0);
    error = addOffer(&offers, dest, type, -1, 10, 10, -1);
    assert(error != 0);
    error = addOffer(&offers, dest, type, 2020, 10, 10, -1);
    assert(error != 0);
    strcpy(type,"");
    error = addOffer(&offers, dest, type, 2020, 10, 10, -1);
    assert(error != 0);
    strcpy(dest,"");
    error = addOffer(&offers, dest, type, 2020, 10, 10, -1);
    assert(error != 0);
    assert(size(&offers) == 0);
    destroy(&offers);
    Offers offers1 = createEmpty();
    //try to add some valid offers
    strcpy(dest,"a");
    strcpy(type,"b");
    addOffer(&offers1, dest, type, 2020, 10, 10, 10);
    strcpy(dest,"a2");
    strcpy(type,"b2");
    addOffer(&offers1, dest, type, 2020, 10, 10, 20);
    assert(size(&offers1) == 2);
    strcpy(dest,"a1");
    strcpy(type,"b1");
    updateOffer(&offers1, 1, dest, type, 2020, 10, 10, 10);
    //try to update with invalid offer
    strcpy(dest,"");
    strcpy(type,"");
    updateOffer(&offers1, 1, dest, type, 2020, 10, 10, 10);
    assert(strcmp(getDestination(&offers1.elems[0]), "a1") == 0);
    removeOffer(&offers1, 1);
    assert(size(&offers1) == 1);
    //display_repo(&offers1);
    destroy(&offers1);
    //test the filter function
    Offers offers2 = createEmpty();
    strcpy(dest,"a");
    strcpy(type,"b");
    addOffer(&offers2, dest, type, 2020, 10, 10, 10);
    strcpy(dest,"a2");
    strcpy(type,"b2");
    addOffer(&offers2, dest, type, 2020, 10, 10, 20);
    strcpy(dest,"a3");
    strcpy(type,"b3");
    addOffer(&offers2, dest, type, 2020, 10, 10, 30);
    strcpy(dest,"a");
    strcpy(type,"b");
    Offers rez = filterByCriteria(&offers2, type, dest, 10, 20);
    //display_repo(&rez);
    assert(size(&rez) == 2);

    destroy(&offers2);
    destroy(&rez);
//    test the order function
    Offers offers3 = createEmpty();
    strcpy(dest,"a");
    strcpy(type,"b");
    addOffer(&offers3, dest, type, 2020, 10, 10, 10);
    strcpy(dest,"a2");
    strcpy(type,"b2");
    addOffer(&offers3, dest, type, 2020, 10, 10, 20);
    strcpy(dest,"a4");
    strcpy(type,"b4");
    addOffer(&offers3, dest, type, 2020, 10, 10, 10);
    strcpy(dest,"a3");
    strcpy(type,"b3");
    addOffer(&offers3, dest, type, 2020, 10, 10, 10);
    strcpy(dest,"a3");
    strcpy(type,"b3");
    addOffer(&offers3, dest, type, 2020, 10, 10, 10);
    sort(&offers3, function);
    assert(getPrice(&offers3.elems[0]) == 10);
    assert(getPrice(&offers3.elems[1]) == 10);
    assert(getPrice(&offers3.elems[2]) == 10);
    assert(getPrice(&offers3.elems[3]) == 10);
    assert(getPrice(&offers3.elems[4]) == 20);
    destroy(&offers3);
    //test add random offers
    Offers offers4 = createEmpty();
    add_random_offers(&offers4, 10);
    assert(size(&offers4) == 10);
    destroy(&offers4);
}
