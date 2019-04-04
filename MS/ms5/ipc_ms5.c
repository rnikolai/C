//Rubtsov Nikolai
#include <stdio.h>
#include <string.h>

struct Item {
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
};

/********************************************************************
Milestones 1 to 4  prototypes, definitions and etc...*/

#define MAX_QTY 		999
#define SKU_MAX 		999
#define SKU_MIN 		100
#define TAX             0.13
#define LINEAR          1
#define FORM            0
#define STOCK           1
#define CHECKOUT        0
//4
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQty(struct Item item[], int NoOfRecs, int stock);
//3
double totalAfterTax(struct Item item);
int isLowQty(struct Item item);
struct Item itemEntry(int sku);
void dspItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);
//2
int yes(void);
void GrocInvSys(void);
int menu(void);
//1
void welcome(void);
void prnTitle(void);
void prnFooter(double gTotal);
void clrKyb(void);
void pause(void);
int getInt(void);
double getDbl(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDblLimited(double lowerLimit, double upperLimit);

/*End of milestone 1 to 4 stuff
*********************************************************************/


/********************************************************************
Milestone 5 prototypes*/


#define MAX_ITEM_NO 500   
#define DATAFILE "ipc_ms5_long.txt" 

void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(struct Item* item, char fileName[], int NoOfRecs);
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr);

/*End of milestone 5 prototypes
*********************************************************************/

int main(void) {
GrocInvSys();
return 0;
}

/* End Main function
********************************************************************/

/********************************************************************
Milestone 5 functions*/
void saveItem(struct Item item, FILE* dataFile) {
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n",item.sku,item.quantity,item.minQuantity,item.price,item.isTaxed,item.name);
}
int loadItem(struct Item* item, FILE* dataFile) {
	return fscanf(dataFile, "%d,%d,%d,%lf,%d,%20[^\n]s", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name) == 6;
}
int saveItems(struct Item* item, char fileName[], int NoOfRecs) {
	int i = 0;
	FILE * fp = NULL;
	fp = fopen(fileName, "w");
	if (fp != NULL) {
	   while (i != NoOfRecs) {
		   saveItem(item[i], fp);
		   i++;
	   }
	   fclose(fp);
	}
	return fp != 0;
}
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr) {
	FILE * fp = NULL;
	fp = fopen(fileName, "r");
	if (fp != NULL) {
		while(loadItem(&item[*NoOfRecsPtr], fp) ) {
			*NoOfRecsPtr+=1;
		}
		fclose(fp);
	}
	return fp != 0;
}
/*End of milestone 5 functions
*********************************************************************/

/********************************************************************
Milestones 1  to 4 functions*/
//4
void search(const struct Item item[], int NoOfRecs) {
	int searchindex;//arrayindex to be found 
	printf("Please enter the SKU: ");
	if (locateItem(item, NoOfRecs, getIntLimited(SKU_MIN, SKU_MAX), &searchindex)) {
		dspItem(item[searchindex], FORM);
	}
	else {
		printf("Item not found!\n");
	}
}
void updateItem(struct Item* itemptr) {
	struct Item newitem;//temp stuct to recive data
	printf("Enter new data:\n");
	printf("        SKU: %3d\n", itemptr->sku);
	newitem = itemEntry(itemptr->sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	if (yes()) {
		*itemptr = newitem;
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}
}
void addItem(struct Item item[], int *NoOfRecs, int sku) {
	struct Item newitem;//temp stuct to recive data
	if (*NoOfRecs == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full\n");
	}
	else {
		newitem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		if (yes()) {
			item[*NoOfRecs] = newitem;
			*NoOfRecs += 1;
			printf("--== Added! ==--\n");
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
}
void addOrUpdateItem(struct Item item[], int* NoOfRecs) {
	int tempsku;//saves the result of getintlimited
	int searchindex;//arrayindex to be found                       
	printf("Please enter the SKU: ");
	tempsku = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, *NoOfRecs, tempsku, &searchindex)) {
		dspItem(item[searchindex], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		if (yes()) {
			updateItem(&item[searchindex]);
		}
	}
	else {
		printf("        SKU: %3d\n",tempsku);
		addItem(&*item, &*NoOfRecs, tempsku);
	}

}
void adjustQty(struct Item item[], int NoOfRecs, int stock) {
	int tempquan;//saves the result of getintlimited for quantity
	int searchindex;//arrayindex to be found , or not 
	printf("Please enter the SKU: ");
	if (locateItem(item, NoOfRecs, getIntLimited(SKU_MIN, SKU_MAX), &searchindex)) {
		dspItem(item[searchindex], FORM);
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stock ? "to stock" : "to checkout", stock ? MAX_QTY - item[searchindex].quantity : item[searchindex].quantity);
		if (stock) {
			tempquan = getIntLimited(0, MAX_QTY - item[searchindex].quantity);
			if (tempquan) {
				item[searchindex].quantity += tempquan;
				printf("--== Stocked! ==--\n");
			}
			else {
				printf("--== Aborted! ==--\n");
			}
		}
		else {
			tempquan = getIntLimited(0, item[searchindex].quantity);
			if (tempquan) {
				item[searchindex].quantity -= tempquan;
				printf("--== Checked out! ==--\n");
			}
			else {
				printf("--== Aborted! ==--\n");
			}
		}
		if (isLowQty(item[searchindex])) {
			printf("Quantity is low, please reorder ASAP!!!\n");
		}
	}
	else {
		printf("SKU not found in storage!\n");
	}
}
//3
double totalAfterTax(struct Item item) {
	double out;
	out = item.price * item.quantity;
	if (item.isTaxed) {
		out += out * TAX;
	}
	return out;
}
int isLowQty(struct Item item) {
	return (item.quantity <= item.minQuantity);
}
struct Item itemEntry(int sku) {
	struct Item new;
	new.sku = sku;
	printf("       Name: ");
	scanf("%20[^\n]", new.name);
	clrKyb();
	printf("      Price: ");
	new.price = getDblLimited(0.01, 1000.00);
	printf("   Quantity: ");
	new.quantity = getIntLimited(1 , MAX_QTY);
	printf("Minimum Qty: ");
	new.minQuantity = getIntLimited(0, 100);
	printf("   Is Taxed: ");
	new.isTaxed = yes();
	return new;
}
void dspItem(struct Item item, int linear) {
	if (linear) {
		printf("|%3d|%-20s|%8.2lf|%5s| %3d | %3d |%12.2lf|%s", item.sku, item.name, item.price, item.isTaxed? "Yes": "No", item.quantity, item.minQuantity, totalAfterTax(item),isLowQty(item)? "***\n":"\n");
		}
	else {
		printf("        SKU: %3d\n"
			   "       Name: %s\n"
			   "      Price: %.2lf\n"
			   "   Quantity: %d\n"
			   "Minimum Qty: %d\n"
			   "   Is Taxed: %s\n", item.sku, item.name, item.price, item.quantity, item.minQuantity, item.isTaxed ? "Yes" : "No");
		if (isLowQty(item)) {
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}

	}
void listItems(const struct Item item[], int NoOfItems) {
	int i = 0;
	double gTotal = 0;
	prnTitle();
	while (i != NoOfItems) {
		printf("%-4d", i + 1);
		dspItem(item[i], LINEAR);
		gTotal += totalAfterTax(item[i]);
		i++;
	}
	prnFooter(gTotal);
}
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
	int i = 0;
	int out = 0;
	while (i != NoOfRecs) {
		if (sku == item[i].sku) {
			*index = i;
			out = 1;
		}
		i++;
	}
	return out;
}
//2
int yes(void) {
	char ans = 0;
	int ret = 0;
	while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {
		scanf("%c", &ans);
		clrKyb();
		if (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {
			printf("Only (Y)es or (N)o are acceptable: ");
		}
	}
	if (ans == 'y' || ans == 'Y') {
		ret = 1;
	}
	return ret;
}
void GrocInvSys(void) {
	struct Item GI[MAX_ITEM_NO];
	int GNoOfRecs = 0;
	int menucall = 0;
	welcome();printf("\n");
	if (!loadItems(GI, DATAFILE, &GNoOfRecs)) {
		printf("Could not read from %s.\n", DATAFILE);
		menucall = 1;
	}
	while (menucall != 1) {
		switch (menu()) {
		case 0:
			printf("Exit the program? (Y)es/(N)o): ");
			menucall = yes();
			break;
		case 1:
			listItems(GI , GNoOfRecs);
			pause();
			break;
		case 2:
			search(GI , GNoOfRecs);
			pause();
			break;
		case 3:
			adjustQty(GI,GNoOfRecs,CHECKOUT);
			if (!saveItems(GI, DATAFILE, GNoOfRecs)) {
				printf("Could not update data file %s\n",DATAFILE);
			}
			pause();
			break;
		case 4:
			adjustQty(GI, GNoOfRecs,STOCK);
			if (!saveItems(GI, DATAFILE, GNoOfRecs)) {
				printf("Could not update data file %s\n", DATAFILE);
			}
			pause();
			break;
		case 5:
			addOrUpdateItem(GI, &GNoOfRecs);
			if (!saveItems(GI, DATAFILE, GNoOfRecs)) {
				printf("Could not update data file %s\n", DATAFILE);
			}
			pause();
			break;
		case 6:
			printf("Not implemented!\n");
			pause();
			break;
		case 7:
			printf("Not implemented!\n");
			pause();
			break;
		}
	}
}
int menu(void) {
	printf("1- List all items\n"
		"2- Search by SKU\n"
		"3- Checkout an item\n"
		"4- Stock an item\n"
		"5- Add new item or update item\n"
		"0- Exit program\n"
		"> ");
	return getIntLimited(0, 5);
}
//1
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n");
}
void prnTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n"
		"----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void prnFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0) {
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
	}
}
void clrKyb(void) {
	while (getchar() != '\n');
}
void pause(void) {
	printf("Press <ENTER> to continue...");
	clrKyb();
}
int getInt(void) {
	int input;
	char NL = 'x';
	while (scanf("%d%c", &input, &NL) != 2 || NL != '\n') {
		printf("Invalid integer, please try again: ");
		clrKyb();
	}
	return input;
}
double getDbl(void) {
	double input;
	char NL = 'x';
	while (scanf("%lf%c", &input, &NL) != 2 || NL != '\n') {
		printf("Invalid number, please try again: ");
		clrKyb();
	}
	return input;
}
int getIntLimited(int lowerLimit, int upperLimit) {
	int value;
	int i = 0;
	do {
		value = getInt();
		if (value < lowerLimit || value > upperLimit) {
			printf("Invalid value, %d <= value <= %d: ", lowerLimit, upperLimit);
		}
		else {
			i++;
		}
	} while (i == 0);
	return value;
}
double getDblLimited(double lowerLimit, double upperLimit) {
	double value;
	int i = 0;
	do {
		value = getDbl();
		if (value < lowerLimit || value > upperLimit) {
			printf("Invalid value, %f <= value <= %f: ", lowerLimit, upperLimit);
		}
		else {
			i++;
		}
	} while (i == 0);
	return value;
}

/*End of milestone 1 to 4 functions
*********************************************************************/
