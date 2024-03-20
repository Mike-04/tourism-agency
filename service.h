#pragma once

#include "repo.h"
#include <stdbool.h>

int addOffer(Offers* offers, char destination[100], char type[100], int year, int month, int day, float price);

int updateOffer(Offers* offers, int id, Offer o);

int removeOffer(Offers* offers, int id);

void orderByPriceAndDestination(Offers* offers);

void add_random_offers(Offers* offers, int quantity);

void display(Offers* offers, bool reversed);

Offers filterByCriteria(Offers * offers, char type[], char dest[], float min_price, float max_price);

void testAll();

void testAddOffer();
