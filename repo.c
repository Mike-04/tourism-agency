#include "repo.h"

#include <assert.h>
#include <string.h>

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
void destroy(Offers* l) {
    //nothing to dealocate for now
    l->lg = 0;
}

/*
Get an element from the list
poz - position of the element, need to be valid
return element on the given position
*/
ElemType get(Offers* l, int id) {
    for (int i = 0; i < l->lg; i++) {
        if (l->elems[i].id == id) {
            return l->elems[i];
        }
    }
    return createOffer(-1, " ", " ", createDate(0, 0, 0), 0);
}

/*
return number of elements in the list
*/
int size(Offers* l) {
    return l->lg;
}

/*
Add element into the list
post: element is added to the end of the list
*/
void add(Offers* l, ElemType el) {
    l->elems[l->lg] = el;
    l->lg++;
}

void delete(Offers* l, int poz) {
    for (int i = poz; i < l->lg - 1; i++) {
        l->elems[i] = l->elems[i + 1];
    }
    l->lg--;
}

void update(Offers* l, int id, ElemType el) {
    for (int i = 0; i < l->lg; i++) {
        if (l->elems[i].id == id) {
            l->elems[i] = el;
            return;
        }
    }
}

/*
Make a shallow copy of the list
return Mylist containing the same elements as l
*/
Offers copyList(Offers* l) {
    Offers rez = createEmpty();
    for (int i = 0; i < l->lg; i++) {
        add(&rez, l->elems[i]);
    }
    return rez;
}

void testCreateList() {
    Offers l = createEmpty();
    assert(size(&l) == 0);
}
void testIterateList() {
    Offers l = createEmpty();
    add(&l, createOffer(1,"a", "b", createDate(2020, 10, 10), 10));
    add(&l, createOffer(2,"a2", "b2", createDate(2020, 10, 10), 20));
    assert(size(&l) == 2);
    Offer p = get(&l,1);

    assert(strcmp(p.destination, "a") == 0);
    assert(strcmp(p.type, "b") == 0);

    destroy(&l);
    assert(size(&l) == 0);
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