#pragma once

#include "repo.h"
/*
Add a pet to the store
*/
int addOffer(Offers* l, char *destination, char *type, int year, int month, int day, float price);
/*
  Filter pets in the store
  typeSubstring - cstring
  return all pets where typeSubstring is a substring of the type
*/
Offers getAllOffers(Offers* l);

void testAll();

void testAddOffer();
