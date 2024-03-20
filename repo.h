#pragma once
#include "domain.h"

typedef struct {
    Offer* elems;
    int size;
    int max_size;
} Offers;

/*
  Create an empty list
*/
Offers* createEmpty();

void destroy(Offers* offers);


void add(Offers* offers, Offer * el);

int size(Offers* offers);

void delete(Offers* offers, int poz);

void update(Offers* offers, int poz, Offer * el);

void display_repo(Offers* offers);

void testCreateList();
void testIterateList();
void testCopyList();