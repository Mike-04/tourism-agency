#include "repo.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
/*
Create an empty list
*/
Offers createEmpty() {
    Offers rez;
    rez.lg = 0;
    return rez;
}

/*
Destroy list
*/
void destroy(Offers* offers) {
    //nothing to dealocate for now
    offers->lg = 0;
}

/*
Get an element from the list
poz - position of the element, need to be valid
return element on the given position
*/
ElemType get(Offers* offers, int id) {
    for (int i = 0; i < offers->lg; i++) {
        if (offers->elems[i].id == id) {
            return offers->elems[i];
        }
    }
    return createOffer(-1, " ", " ", createDate(0, 0, 0), 0);
}

/*
return number of elements in the list
*/
int size(Offers* offers) {
    return offers->lg;
}




/*
Add element into the list
post: element is added to the end of the list
*/
void add(Offers* offers, ElemType el) {
    offers->elems[offers->lg] = el;
    offers->lg++;
}

void delete(Offers* offers, int id) {
    for (int i = 0; i < offers->lg; i++) {
        if (offers->elems[i].id == id) {
            for (int j = i; j < offers->lg - 1; j++) {
                offers->elems[j] = offers->elems[j + 1];
            }
            offers->lg--;
            return;
        }
    }
}

void update(Offers* offers, int id, ElemType el) {
    for (int i = 0; i < offers->lg; i++) {
        if (offers->elems[i].id == id) {
            offers->elems[i] = el;
            return;
        }
    }
}


/*
Make a shallow copy of the list
return Mylist containing the same elements as offers
*/
Offers copyList(Offers* offers) {
    Offers rez = createEmpty();
    for (int i = 0; i < offers->lg; i++) {
        add(&rez, offers->elems[i]);
    }
    return rez;
}


void testCreateList() {
    Offers offers = createEmpty();
    assert(size(&offers) == 0);
}
void testIterateList() {
    Offers offers = createEmpty();
    add(&offers, createOffer(1, "a", "b", createDate(2020, 10, 10), 10));
    add(&offers, createOffer(2, "a2", "b2", createDate(2020, 10, 10), 20));
    assert(size(&offers) == 2);
    Offer p = get(&offers, 1);

    assert(strcmp(p.destination, "a") == 0);
    assert(strcmp(p.type, "b") == 0);

    destroy(&offers);
    assert(size(&offers) == 0);
}

void testCopyList() {
    Offers l = createEmpty();
    add(&l, createOffer(1,"a", "b", createDate(2020, 10, 10), 10));
    add(&l, createOffer(2,"a2", "b2", createDate(2020, 10, 10), 20));
    Offers l2 = copyList(&l);
    assert(size(&l2) == 2);
    Offer o = get(&l2, 1);
    assert(strcmp(o.type, "b") == 0);
}