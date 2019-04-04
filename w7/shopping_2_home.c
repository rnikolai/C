//Nikolai Rubtcov 134471168 rnikolai
#include <stdio.h>
const int maxitems = 10;//cap
struct item{
	int sku; //sku code
	int quantity; //quantity of item in shop
	float price; //price of item 
};
void displayInventory(const struct item items[], const int size);
void clear(void);
int validate(const int low, const int high);
int searchInventory(const struct item items[], const int sku_item, const int size);
void addItem(struct item items[], int *size);
void menu(void);
void checkPrice(const struct item items[], const int size);
int main(void) {
   int size = 0;
	int option=0;//option selection
	struct item id[10];//data
   clear();
	printf("Welcome to the Shop\n===================\n");
	while (option != -1) {
		menu();
		option = validate(0,4);
		if (option == 0){
			option = -1;
		}
		else if (option == 1){
			displayInventory(id,size);
		}
      else if (option == 2) {
	 addItem(id, &size);
      }
      else if (option == 3) {
	 checkPrice(id,size);
      }
      else if (option == 4) {
	 clear();
    clear();
      }
	}
	printf("Goodbye!\n");
	return 0;
}
void menu(void) {
   printf("Please select from the following options:\n1) Display the inventory.\n2) Add to the inventory.\n3) Check price.\n4) Clear Screen.\n0) Exit.\n");
}
int validate(const int low, const int high) {
   int opt;
   printf("Select: ");
   scanf("%d", &opt);
   while (opt<low || opt >high) {
      printf("Invalid input, try again: ");
      scanf("%d", &opt);
   }
   return opt;
}
void displayInventory(const struct item items[], const int size) {
   int i = 0; //loop counter
   printf("\n\nInventory\n=========================================\nSku         Price       Quantity\n");
   while (i != size) {
      printf("%d        %.2f        %d        \n", items[i].sku, items[i].price, items[i].quantity);
      i += 1;
   }
   printf("=========================================\n");
}
int searchInventory(const struct item items[], const int sku_item, const int size) {
   int tempi = -1;//snap of array index
   int i=0;//loop counter
   while (i <=size) {
      if (items[i].sku == sku_item) {
	 tempi = i;
      }
      i += 1;
   }
   return tempi;
}  
void addItem(struct item items[], int* size) {
   int p = -1; //flag of if statment /array index
   int tempsku;//temporary sku
   int addval;//value to add to quantity 
   printf("Please input a SKU number: ");
   scanf("%d", &tempsku);
   if (size != 0) {
      p = searchInventory(items, tempsku, *size);
   }
   if (*size == 10) {
      printf("Inventory is full\n");
   }
   else if (p == -1) {
      items += *size;
      items->sku = tempsku;
      printf("Quantity: ");
      scanf("%d", &items->quantity);
      printf("Price: ");
      scanf("%f", &items->price);
      printf("The item is successfully added to the inventory.\n");
      *size +=1;
   }
   else {
	 printf("Quantity: ");
	 scanf("%d", &addval);
	 items[p].quantity += addval;
	 printf("The item exists in the repository, quantity is updated.\n");
      }
   }
void checkPrice(const struct item items[], const int size) {
   int p = -1;//fnction return
   int tempsku;//temporary sku
   printf("Please input the sku number of the item : ");
   scanf("%d", &tempsku);
   p = searchInventory(items, tempsku, size);
   if (p == -1){
      printf("Item does not exist in the shop! Please try again.\n");
   }
   else {
      printf("Item %d costs $%.2f", items[p].sku , items[p].price);
   }
}
void clear(void) {
   //call 2 times when 40 lines needed
   int i;
   for (i = 0; i != 20; i++) {
      printf("\n");
   }
}
