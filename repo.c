#include "repo.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Offers createEmpty() {
    //dynamic allocation
    Offers offers;
    offers.size = 0;
    offers.max_size = 100;
    offers.elems = malloc(100 * sizeof(Offer));
    return offers;
}

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


int size(Offers* offers) {
    return offers->size;
}



void add(Offers *offers, Offer el) {
    if (offers->size == offers->max_size) {
        resize(offers);
    }
    offers->elems[offers->size] = el;
    offers->size++;
}

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

void update(Offers* offers, int id, Offer el) {
    for (int i = 0; i < offers->size; i++) {
        if (offers->elems[i].id == id) {
            offers->elems[i] = el;
            return;
        }
    }
}

Offer get(Offers* offers, int poz) {
    return offers->elems[poz];
}



void display_repo(Offers* offers) {
    for (int i = 0; i < offers->size; i++) {
        printf("Id:%d Destination:%s Type:%s Departure date:%d-%d-%d Price:%.2f\n", offers->elems[i].id, offers->elems[i].destination, offers->elems[i].type, offers->elems[i].departure_date.year, offers->elems[i].departure_date.month, offers->elems[i].departure_date.day, offers->elems[i].price);
    }
}

void testCreateList() {
    Offers offers = createEmpty();
    resize(&offers);
    assert(size(&offers) == 0);
    destroy(&offers);
}

void testIterateList() {
    Offers offers = createEmpty();
    add(&offers, createOffer(1, "a", "b", createDate(2020, 10, 10), 10));
    add(&offers, createOffer(2, "c", "d", createDate(2020, 10, 10), 10));
    assert(size(&offers) == 2);
    delete(&offers, 1);
    assert(size(&offers) == 1);
    destroy(&offers);
}
