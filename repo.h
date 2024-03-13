#pragma once
#include "domain.h"
typedef Offer ElemType;
typedef struct {
    ElemType elems[50];
    int lg;
} Offers;

/*
  Create an empty list
*/
Offers createEmpty();

/*
  Destroy list
*/
void destroy(Offers* l);

/*
  Get an element from the list
  poz - position of the element, need to be valid
  return element on the given position
*/
ElemType get(Offers* l, int poz);

/*
  return number of elements in the list
*/
int size(Offers* l);

/*
  Add element into the list
  post: element is added to the end of the list
*/
void add(Offers* l, ElemType el);

/*
  Make a shallow copy of the list
  return Mylist containing the same elements as l
*/
Offers copyList(Offers* l);

void remove(Offers* l, int poz);

void update(Offers* l, int poz, ElemType el);

void testCreateList();
void testIterateList();
void testCopyList();