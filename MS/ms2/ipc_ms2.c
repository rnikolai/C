#include <stdio.h>
void clrKyb(void);
void pause(void);
int getInt(void);
int yes(void);  // ms2
int getIntLimited(int lowerLimit, int upperLimit);
void welcome(void);
void GrocInvSys(void);  // ms2
int menu(void);  // ms2

int main(void) {
	GrocInvSys();
	return 0;
}
// implmement MS2 fucntions here
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
	int menucall=0;
	welcome();printf("\n");
	while (menucall != 1) {
		switch (menu()){
		case 0:
			printf("Exit the program? (Y)es/(N)o): ");
			menucall = yes();
			break;
		case 1:
			printf("List Items!\n");
			break;
		case 2:
			printf("Search Items!\n");
			break;
		case 3:
			printf("Checkout Item!\n");
			break;
		case 4:
			printf("Stock Item!\n");
			break;
		case 5:
			printf("Add/Update Item!\n");
			break;
		case 6:
			printf("Delete Item!\n");
			break;
		case 7:
			printf("Search by name!\n");
			break;
		}
	}
}
int menu(void) {
	printf("1- List all items\n"
		"2 - Search by SKU\n"
		"3 - Checkout an item\n"
		"4 - Stock an item\n"
		"5 - Add new item or update item\n"
		"6 - delete item\n"
		"7 - Search by name\n"
		"0 - Exit program\n"
		">");
	return getIntLimited(0, 7);
}
// copy MS1 functions here
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
		printf("Invalid number, please try again: ");
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
			printf("Invalid value, %d< value < %d: ", lowerLimit, upperLimit);
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
			printf("Invalid value, %f< value < %f: ", lowerLimit, upperLimit);
		}
		else {
			i++;
		}
	} while (i == 0);
	return value;
}


/*
---=== Grocery Inventory System ===---

1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 8
Invalid value, 0 < value < 7: 1
List Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 2
Search Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 3
Checkout Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 4
Stock Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 5
Add/Update Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 6
Delete Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 7
Search by name!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : x
Only (Y)es or (N)o are acceptable: n
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : y
*/