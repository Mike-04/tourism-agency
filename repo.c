#include "repo.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Creates an empty list of offers.
// Returns: An empty Offers struct.
Offers createEmpty()
{
    //alocate memory
    Offers offers;
    offers.size = 0;
    offers.max_size = 100;
    offers.elems = malloc(100 * sizeof(Offer));
    return offers;
}

// Destroys all elements in the list and frees memory.
// Parameters:
// - offers: A pointer to the Offers struct.
void destroy(Offers * offers) {
    //dealocate memory for every element
    int i;
    for (i = 0; i < offers->size; i++)
    {
        destroyOffer(&(offers->elems[i]));
    }
    offers->size = 0;
    offers->max_size = 0;
    free(offers->elems);
}

// Resizes the list by doubling its capacity.
// Parameters:
// - offers: A pointer to the Offers struct.
void resize(Offers* offers) {
    int new_size = offers->max_size * 2;
    Offer* new_elems = malloc(new_size * sizeof(Offer));
    for (int i = 0; i < offers->size; i++) {
        new_elems[i] = offers->elems[i];
    }
    free(offers->elems);
    offers->elems = new_elems;
    offers->max_size = new_size;
}

// Returns the number of elements in the list.
// Parameters:
// - offers: A pointer to the Offers struct.
// Returns: The number of elements in the list.
int size(Offers* offers) {
    return offers->size;
}


// Adds an element to the end of the list.
// Parameters:
// - offers: A pointer to the Offers struct.
// - el: The Offer element to be added.
void add(Offers *offers, Offer el) {
    if (offers->size == offers->max_size) {
        resize(offers);
    }
    offers->elems[offers->size] = el;
    offers->size++;
}

// Deletes the element with the given ID from the list.
// Parameters:
// - offers: A pointer to the Offers struct.
// - id: The ID of the element to be deleted.
void delete(Offers* offers, int id) {
    if (id < 0)
        return;
    int i;
    for (i = 0; i < offers->size; i++) {
        if (offers->elems[i].id == id) {
            destroyOffer(&offers->elems[i]);
            for (int j = i; j < offers->size - 1; j++) {
                offers->elems[j] = offers->elems[j + 1];
            }
            offers->size--;
            return;
        }
    }

}

// Updates the element with the given ID in the list.
// Parameters:
// - offers: A pointer to the Offers struct.
// - id: The ID of the element to be updated.
// - el: The new Offer element.
void update(Offers* offers, int id, Offer el) {
    for (int i = 0; i < offers->size; i++) {
        if (offers->elems[i].id == id) {
            destroyOffer(&offers->elems[i]);
            offers->elems[i] = el;
            return;
        }
    }
}


// Retrieves the element at the given position in the list.
// Parameters:
// - offers: A pointer to the Offers struct.
// - poz: The position of the element to retrieve.
// Returns: The Offer element at the specified position.
Offer get(Offers* offers, int poz) {
    return offers->elems[poz];
}


//for debug
//void display_repo(Offers* offers) {
//    for (int i = 0; i < offers->size; i++) {
//        printf("Id:%d Destination:%s Type:%s Departure date:%d-%d-%d Price:%.2f\n", offers->elems[i].id, offers->elems[i].destination, offers->elems[i].type, offers->elems[i].departure_date.year, offers->elems[i].departure_date.month, offers->elems[i].departure_date.day, offers->elems[i].price);
//    }
//}

// Tests the creation of an empty list and resizing.
void testCreateList() {
    Offers offers = createEmpty();
    resize(&offers);
    assert(size(&offers) == 0);
    destroy(&offers);
}

// Tests adding, deleting, and retrieving elements from the list.
void testIterateList() {
    Offers offers = createEmpty();
    char dest[100],type[100];
    strcpy(dest,"a");
    strcpy(type,"b");
    add(&offers, createOffer(1, dest, type, createDate(2020, 10, 10), 10));
    strcpy(dest,"c");
    strcpy(type,"d");
    add(&offers, createOffer(2, dest, type, createDate(2020, 10, 10), 10));
    assert(size(&offers) == 2);
    delete(&offers, 1);
    delete(&offers, -1);
    Offer offer;
    offer = get(&offers, 0);
    assert(offer.id == 2);
    assert(size(&offers) == 1);
    for(int i = 0; i < 102; i++) {
        strcpy(dest,"a");
        strcpy(type,"b");
        add(&offers, createOffer(i, dest, type, createDate(2020, 10, 10), 10));
    }
    destroy(&offers);
}
