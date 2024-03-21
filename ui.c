#include "ui.h"
#include "repo.h"
#include "service.h"
#include "domain.h"
#include <stdio.h>
#include <stdbool.h>

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
    printf("Type:");
    char type[20];
    scanf("%s", type);
    printf("Destination:");
    char destination[20];
    scanf("%s", destination);
    printf("Year:");
    int year;
    scanf("%d", &year);
    printf("Month:");
    int month;
    scanf("%d", &month);
    printf("Day:");
    int day;
    scanf("%d", &day);
    printf("Price:");
    float price;
    scanf("%f", &price);
    addOffer(l, destination, type, year, month, day, price);

}

void update_offer_ui(Offers *l)
{
    printf("Id:");
    int id;
    scanf("%d", &id);
    printf("Type:");
    char type[20];
    scanf("%s", type);
    printf("Destination:");
    char destination[20];
    scanf("%s", destination);
    printf("Year:");
    int year;
    scanf("%d", &year);
    printf("Month:");
    int month;
    scanf("%d", &month);
    printf("Day:");
    int day;
    scanf("%d", &day);
    printf("Price:");
    float price;
    scanf("%f", &price);
    updateOffer(l, id, destination, type, year, month, day, price);
}

void delete_offer_ui(Offers *l)
{
    printf("Id:");
    int id;
    scanf("%d", &id);
    removeOffer(l, id);
}

void display(Offers* offers, bool reversed) {
    //display all offers
    if (reversed == false) {
        for (int i = 0; i < size(offers); i++) {
            printf("Id:%d Destination:%s Type:%s Departure date:%d-%d-%d Price:%.2f\n", offers->elems[i].id, offers->elems[i].destination, getType(&offers->elems[i]), offers->elems[i].departure_date.year, offers->elems[i].departure_date.month, offers->elems[i].departure_date.day, offers->elems[i].price);
        }
    }
    else {
        for (int i = size(offers) - 1; i >= 0; i--) {
            printf("Id:%d Destination:%s Type:%s Departure date:%d-%d-%d Price:%.2f\n", offers->elems[i].id, offers->elems[i].destination, getType(&offers->elems[i]), offers->elems[i].departure_date.year, offers->elems[i].departure_date.month, offers->elems[i].departure_date.day, offers->elems[i].price);
        }
    }


}

void filter(Offers* offers){
    //read criteria
    //type
    printf("Type:");
    char type[20];
    scanf("%s", type);
    //destination
    printf("Destination:");
    char destination[20];
    scanf("%s", destination);
    //price interval
    //min price
    printf("Min price:");
    float min_price;
    scanf("%f", &min_price);
    //max price
    printf("Max price:");
    float max_price;
    scanf("%f", &max_price);

    Offers rez;
    //call service function
    rez = filterByCriteria(offers, type, destination, min_price, max_price);
    display(&rez, false);
    printf("ok");
    destroy(&rez);
}


void start()
{
    Offers offers = createEmpty();
    add_random_offers(&offers, 10);
	int option;
	do {
		display_menu();
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			add_offer_ui(&offers);
			break;
		case 2:
			update_offer_ui(&offers);
			break;
		case 3:
            delete_offer_ui(&offers);
			break;
		case 4:
            sort(&offers, function);
                printf("Reversed list?\nY/N:");
                getchar();
                char c;
                scanf("%c", &c);
                if (c == 'N' || c=='n') display(&offers, false);
                else display(&offers, true);
			break;
		case 5:
            filter(&offers);
            break;
    	case 6:
			break;
        case 7:
            display(&offers, false);
		    break;

        default:
			printf("Invalid option\n");
			break;
		}
	} while (option != 6);
    destroy(&offers);
}