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
void destroy(Offers* offers);

/*
  Get an element from the list
  poz - position of the element, need to be valid
  return element on the given position
*/
ElemType get(Offers* offers, int poz);

/*
  return number of elements in the list
*/
int size(Offers* offers);

/*
  Add element into the list
  post: element is added to the end of the list
*/
void add(Offers* offers, ElemType el);

/*
  Make a shallow copy of the list
  return Mylist containing the same elements as offers
*/
Offers copyList(Offers* offers);

void delete(Offers* offers, int poz);

void update(Offers* offers, int poz, ElemType el);

void testCreateList();
void testIterateList();
void testCopyList();