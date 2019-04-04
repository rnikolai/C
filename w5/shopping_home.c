#include <stdio.h>

struct item{
	int sku; //sku code
	int quantity; //quantity of item in shop
	float price; //price of item 
};
int main() {
	int i;//array index
	int j = 0;//loop exit
	int p;//input flag
	int option;//option selection
	int tempid;//temp val to get index array out if the check loop
	int tempsku;//temporary sku
	int addval;//add this val to the quantity
	const int maxitems = 10;//cap
	struct item id[10];//data
	int size = 0;//current size
	printf("Welcome to the Shop\n===================\n");
	while (j != -1) {
		p = 0;
		i = 0;
		printf("Please select from the following options:\n");
		printf("1) Display the inventory.\n2) Add to shop.\n3) Price check.\n0) Exit.\nSelect:");
		scanf("%d", &option);
	   if (option == 0){
		   j = -1;   
	   }
	   else if (option == 1){
		   printf("\n\nInventory\n=========================================\nSku         Price       Quanity\n");
		   while (i != size) {
			   printf("%d        %.2f       %d         \n", id[i].sku , id[i].price, id[i].quantity);
			   i += 1;
		   }
		   printf("=========================================\n");
	   }
	    else if (option == 2){
			printf("Please input a SKU number:");
			scanf("%d", &tempsku);
			while (i != size) {
				if (id[i].sku == tempsku) {
					tempid = i;
					p = 1;
				}
				i += 1;
			}
			if (p == 1) {
				printf("Quantity:");
				scanf("%d", &addval);
				id[tempid].quantity += addval;
				printf("The item exists in the repository, quanity is updated.\n");
			}
			else {
				if(size == maxitems){
					printf("Inventory is full\n");
				}
				else {
					id[size].sku = tempsku;
					printf("Quantity:");
					scanf("%d", &id[size].quantity);
					printf("Price:");
					scanf("%f", &id[size].price);
					printf("The item is successfully added to the inventory.\n");
					size += 1;
				}
			}
	   }
	   else if (option==3) {
		   printf("Please input the sku number of the item:\n");
		   scanf("%d",&tempsku);
		   while (i != size) {
			   if (id[i].sku == tempsku) {
				   tempid = i;
				   p = 1;
			   }
			   i += 1;
		   }
		   if (p == 1) {
				   printf("Item %d costs $%.2f\n", id[tempid].sku, id[tempid].price);
	   }
		   else {
		      printf("Item does not exist in the shop! Please try again.\n");
		   }
		 }
	   else {
		   printf("Invalid input, try again: ");
	   }
	}
	printf("Good bye!\n");
	return 0;
	
}
