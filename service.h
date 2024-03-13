#pragma once

#include "repo.h"
/*
Add a pet to the store
*/
int addOffer(Offers* l, Offer p);


/*
  Filter pets in the store
  typeSubstring - cstring
  return all pets where typeSubstring is a substring of the type
*/
Offers getAllOffers(Offers* l);


void testAddOffer();
