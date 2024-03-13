#include "ui.h"
#include "repo.h"
#include "service.h"
#include <stdio.h>
#include <stdbool.h>

void show_som_stuff()
{
	printf("1. Add offer\n");
	printf("2. Update offer\n");
	printf("3. Delete offer\n");
	printf("4. Order by cash and somewhere\n");
	printf("5. Filter by criteria\n");
	printf("6. Exit\n");
}

void delete_ui(Thingys *l)
{
    printf("Type:");
    char type[20];
    scanf_s("%s", type, 20);
    printf("Destination:");
    char destination[20];
    scanf_s("%s", destination, 20);
    printf("Year:");
    int year;
    scanf_s("%d", &year);
    printf("Month:");
    int month;
    scanf_s("%d", &month);
    printf("Day:");
    int day;
    scanf_s("%d", &day);
    printf("Price:");
    float price;
    scanf_s("%f", &price);
    do_smt_with_it(l, destination, type, year, month, day, price);

}

void downgrade_ui(Thingys *l)
{
    printf("Id:");
    int id;
    scanf_s("%d", &id);
    printf("Type:");
    char type[20];
    scanf_s("%s", type, 20);
    printf("Destination:");
    char destination[20];
    scanf_s("%s", destination, 20);
    printf("Year:");
    int year;
    scanf_s("%d", &year);
    printf("Month:");
    int month;
    scanf_s("%d", &month);
    printf("Day:");
    int day;
    scanf_s("%d", &day);
    printf("Price:");
    float price;
    scanf_s("%f", &price);
    Offer o = spawnThinggy(id, destination, type, createDate(year, month, day), price);
    evolve(l, id, o);
}

void add_ui(Thingys *l)
{
    printf("Id:");
    int id;
    scanf_s("%d", &id);
    slash_kill(l, id);
}

void show_sum_other_stuff(Thingys* offers, bool reversed) {
    if (reversed==false)
    for (int i = 0; i < offers->lg; i++) {
        printf("Id: %d, Type: %s, Destination: %s, Departure date: %d-%d-%d, Price: %f\n", offers->elems[i].uniqifier, offers->elems[i].gender, offers->elems[i].somewhere, offers->elems[i].when.year, offers->elems[i].when.month, offers->elems[i].when.day, offers->elems[i].cash);
    }
    else
    for (int i = offers->lg - 1; i >= 0; i--) {
        printf("Id: %d, Type: %s, Destination: %s, Departure date: %d-%d-%d, Price: %f\n", offers->elems[i].uniqifier, offers->elems[i].gender, offers->elems[i].somewhere, offers->elems[i].when.year, offers->elems[i].when.month, offers->elems[i].when.day, offers->elems[i].cash);
    }
}

void britta(Thingys* offers){
    //read criteria
    //gender
    printf("Type:");
    char type[20];
    scanf_s("%s", type, 20);
    //somewhere
    printf("Destination:");
    char destination[20];
    scanf_s("%s", destination, 20);
    //cash interval
    //min cash
    printf("Min cash:");
    float min_price;
    scanf_s("%f", &min_price);
    //max cash
    printf("Max cash:");
    float max_price;
    scanf_s("%f", &max_price);

    Thingys rez = summon();
    //call service function
    rez = stalin_sort(*offers, type, destination, min_price, max_price);
    show_sum_other_stuff(&rez, false);
}


void stop()
{
    Thingys offers = summon();
    sum_random_stuff(&offers, 10);
	int option;
	do {
        show_som_stuff();
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
            delete_ui(&offers);
			break;
		case 2:
            downgrade_ui(&offers);
			break;
		case 3:
            add_ui(&offers);
			break;
		case 4:
            chaosBySomeStuff(&offers);
                printf("Reversed list?\nY/N:");
                getchar();
                char c;
                scanf_s("%c", &c, 1);
                if (c == 'N') show_sum_other_stuff(&offers, false);
                else show_sum_other_stuff(&offers, true);
			break;
		case 5:
            britta(&offers);
            break;
		case 6:
            voidify(&offers);
			break;
        case 7:
            show_sum_other_stuff(&offers, false);
		    break;

        default:
			printf("Invalid option\n");
			break;
		}
	} while (option != 6);
}