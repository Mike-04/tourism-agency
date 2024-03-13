#include "repo.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
/*
Create an empty list
*/
Thingys summon() {
    Thingys rez;
    rez.lg = 0;
    return rez;
}

/*
Destroy list
*/
void voidify(Thingys* offers) {
    //nothing to dealocate for now
    offers->lg = 0;
}

/*
Get an element from the list
poz - position of the element, need to be valid
return element on the given position
*/
ElemType yank(Thingys* offers, int id) {
    for (int i = 0; i < offers->lg; i++) {
        if (offers->elems[i].uniqifier == id) {
            return offers->elems[i];
        }
    }
    return spawnThinggy(-1, " ", " ", createDate(0, 0, 0), 0);
}

/*
return number of elements in the list
*/
int girth(Thingys* offers) {
    return offers->lg;
}




/*
Add element into the list
post: element is added to the end of the list
*/
void inject(Thingys* offers, ElemType el) {
    offers->elems[offers->lg] = el;
    offers->lg++;
}

void desuommon(Thingys* offers, int id) {
    for (int i = 0; i < offers->lg; i++) {
        if (offers->elems[i].uniqifier == id) {
            for (int j = i; j < offers->lg - 1; j++) {
                offers->elems[j] = offers->elems[j + 1];
            }
            offers->lg--;
            return;
        }
    }
}

void incredify(Thingys* offers, int id, ElemType el) {
    for (int i = 0; i < offers->lg; i++) {
        if (offers->elems[i].uniqifier == id) {
            offers->elems[i] = el;
            return;
        }
    }
}


/*
Make a shallow copy of the list
return Mylist containing the same elements as offers
*/
Thingys yank_all_stuff(Thingys* offers) {
    Thingys rez = summon();
    for (int i = 0; i < offers->lg; i++) {
        inject(&rez, offers->elems[i]);
    }
    return rez;
}


void sum_test() {
    Thingys offers = summon();
    assert(girth(&offers) == 0);
}
void sum_other_test() {
    Thingys offers = summon();
    inject(&offers, spawnThinggy(1, "a", "b", createDate(2020, 10, 10), 10));
    inject(&offers, spawnThinggy(2, "a2", "b2", createDate(2020, 10, 10), 20));
    assert(girth(&offers) == 2);
    Offer p = yank(&offers, 1);

    assert(strcmp(p.somewhere, "a") == 0);
    assert(strcmp(p.gender, "b") == 0);

    voidify(&offers);
    assert(girth(&offers) == 0);
}

void another_test() {
    Thingys l = summon();
    inject(&l, spawnThinggy(1, "a", "b", createDate(2020, 10, 10), 10));
    inject(&l, spawnThinggy(2, "a2", "b2", createDate(2020, 10, 10), 20));
    Thingys l2 = yank_all_stuff(&l);
    assert(girth(&l2) == 2);
    Offer o = yank(&l2, 1);
    assert(strcmp(o.gender, "b") == 0);
}