#pragma once

#include "repo.h"
#include <stdbool.h>

int addOffer(Offers* offers, char destination[100], char type[100], int year, int month, int day, float price);

int updateOffer(Offers* offers, int id, char destination[100], char type[100], int year, int month, int day, float price);

int removeOffer(Offers* offers, int id);

int function(Offer* o1, Offer* o2);

void sort(Offers* offers, int (function(Offer*, Offer*)));

void orderByPriceAndDestination(Offers* offers);

void add_random_offers(Offers* offers, int quantity);

void display(Offers* offers, bool reversed);

Offers filterByCriteria(Offers * offers, char type[], char dest[], float min_price, float max_price);

void testAll();

void testAddOffer();
