#include "ui.h"
#include "repo.h"
#include "service.h"
#include <stdio.h>

void display_menu()
{
	printf("1. Add offer\n");
	printf("2. Update offer\n");
	printf("3. Delete offer\n");
	printf("4. Order by price and destination\n");
	printf("5. Filter by criteria\n");
	printf("6. Exit\n");
}

void add_offer_ui(Offers *l)
{
    printf("Type: ");
    char type[20];
    scanf_s("%s", type, 20);
    printf("Destination: ");
    char destination[20];
    scanf_s("%s", destination, 20);
    printf("Year: ");
    int year;
    scanf_s("%d", &year);
    printf("Month: ");
    int month;
    scanf_s("%d", &month);
    printf("Day: ");
    int day;
    scanf_s("%d", &day);
    printf("Price: ");
    float price;
    scanf_s("%f", &price);
    addOffer(l, destination, type, year, month, day, price);

}

void start()
{
    Offers l = createEmpty();
	int option;
	do {
		display_menu();
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			add_offer_ui(&l);
			break;
		case 2:
			// Update offer
			break;
		case 3:
			// Delete offer
			break;
		case 4:
			// Order by price and destination
			break;
		case 5:
			// Filter by criteria
			break;
		case 6:
			break;
		default:
			printf("Invalid option\n");
			break;
		}
	} while (option != 6);
}