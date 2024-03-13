#pragma once

#include "repo.h"
#include <stdbool.h>
/*
Add a pet to the store
*/
int do_smt_with_it(Thingys* offers, char *destination, char *type, int year, int month, int day, float price);
/*
  Filter pets in the store
  typeSubstring - cstring
  return all pets where typeSubstring is a substring of the gender
*/
Thingys steal_sum_stuff(Thingys* offers);

int evolve(Thingys* offers, int id, Offer o);

int slash_kill(Thingys* offers, int id);

void chaosBySomeStuff(Thingys* offers);

void sum_random_stuff(Thingys* offers, int quantity);

void show_sum_other_stuff(Thingys* offers, bool reversed);

Thingys stalin_sort(Thingys offers, char type[], char dest[], float min_price, float max_price);

void maybe();

void some_random_operations();
