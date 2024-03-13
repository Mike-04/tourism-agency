#pragma once
#include "domain.h"
typedef Offer ElemType;
typedef struct {
    ElemType elems[50];
    int lg;
} Thingys;

/*
  Create an empty list
*/
Thingys summon();

/*
  Destroy list
*/
void voidify(Thingys* offers);

/*
  Get an element from the list
  poz - position of the element, need to be valid
  return element on the given position
*/
ElemType yank(Thingys* offers, int id);

/*
  return number of elements in the list
*/
int girth(Thingys* offers);

/*
  Add element into the list
  post: element is added to the end of the list
*/
void inject(Thingys* offers, ElemType el);

/*
  Make a shallow copy of the list
  return Mylist containing the same elements as offers
*/
Thingys yank_all_stuff(Thingys* offers);

void desuommon(Thingys* offers, int id);

void incredify(Thingys* offers, int id, ElemType el);

void sum_test();
void sum_other_test();
void another_test();