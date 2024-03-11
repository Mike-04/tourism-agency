void display_menu()
{
	printf("1. Add offer\n");
	printf("2. Update offer\n");
	printf("3. Delete offer\n");
	printf("4. Order by price and destination\n");
	printf("5. Filter by criteria\n");
	printf("6. Exit\n");
}

void start()
{
	int option;
	do {
		display_menu();
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			// Add offer
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
	return 0;
}