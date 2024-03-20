#pragma once

#include "repo.h"
#include <stdbool.h>
/*
Add a pet to the store
*/
int addOffer(Offers* offers, char *destination, char *type, int year, int month, int day, float price);
/*
  Filter pets in the store
  typeSubstring - cstring
  return all pets where typeSubstring is a substring of the type
*/
//Offers getAllOffers(Offers* offers);

int updateOffer(Offers* offers, int id, Offer *o);

int removeOffer(Offers* offers, int id);

void orderByPriceAndDestination(Offers* offers);

void add_random_offers(Offers* offers, int quantity);

void display(Offers* offers, bool reversed);

Offers * filterByCriteria(Offers * offers, char type[], char dest[], float min_price, float max_price);

void testAll();

void testAddOffer();
