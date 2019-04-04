// Workshop 9 - Files

// Name:Nikolai Rubtsov
// Student #: 134471168
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct Box{
   int id;        // the box ID
   double size[3];   // dimensions of the box (Length, Width, Height)
   double weight; // weight of the box
};
int readBox(FILE* fp, struct Box* bp);
void listBoxes(const char filename[]); // lists all boxes in the file
int searchBox( FILE *fp, int id2Find);// search for spesific id
void displayBox(const char filename[],int id2Find);     // display a box, given ID

/*int addBox(const char filename[], const struct Box * b2Add);// add a box to file
int numberBoxes(const char filename[]);      // find the number of boxes in a file
int getRandomInt(int lower, int higher);  // get a random number
void displayBoxN(char filename[], int n); // display a box given its record number
void writeBox(FILE* fp, const struct Box* bp);*/

void printBox(struct Box* b){
	printf("%2d %6.2lf %5.2lf %6.2lf %6.2lf\n", b->id, b->size[0], b->size[1], b->size[2], b->weight);
}
void printBox2(struct Box* b) {
	printf("\nID:     %6d\n"
		"Length: %6.2lf\n"
		"Width:  %6.2lf\n"
		"Height: %6.2lf\n"
		"Weight: %6.2lf\n\n", b->id, b->size[0], b->size[1], b->size[2], b->weight);
}
int menu(void){
   int choice = -1;

   printf("1- List all boxes\n");
   printf("2- Find a box\n");
   printf("3- Add a box\n");
   printf("4- Randomly pick a lucky box!\n");
   printf("0- Exit program\n");

printf("Select an option: ");
do {
	scanf("%d", &choice);
	if (choice < 0 || choice > 4)
		printf("Please enter a number between 0 and 4: ");
} while (choice < 0 || choice > 4);
return choice;
}
int main(void) {

	int choice; // , boxID, r;
	char filename[] = "storage.txt";
	printf("Welcome to My Storage Room\n");
	printf("==========================\n");
	do {
		// get user's choice
		choice = menu();
		switch (choice) {
		case 1:
			// IN_LAB: list items
			printf("List of boxes\n"
				   "=============\n\n"
				   "ID Length Width Height Weight\n"
				   "-----------------------------\n");
			listBoxes(filename);
			break;
		case 2:
			// IN_LAB: find a box given its ID 
			// ask for ID
			printf("Enter box ID: ");
			scanf("%d", &choice);
			displayBox(filename, choice);
			// call displayBox
			break;
		case 3:
			// AT_HOME: add a box
			// get user input for box's ID, size and weight



			// call addBox, print message to show number of boxes added



			break;

		case 4:
			// AT_HOME: randomly pick a lucky box



			// choose a random number between 1 and the number of boxes in storage


			// display the lucky box!



			break;


		};

	} while (choice > 0);

	return 0;
}

void listBoxes(const char filename[]) {
	int i = 0;
	struct Box b[10];
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (fscanf(fp, "%d", &(b + i)->id) != -1) {
			readBox(fp, b + i);
			printBox(b + i);
			i++;
		}
	}
	else {
		printf("Failed to open file!\n");
	}
	printf("\n");
	rewind(fp);
	fclose(fp);
}
void displayBox(const char filename[], int id2Find) {
	int i = 0;
	struct Box b[10];
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (fscanf(fp, "%d", &(b + i)->id) != -1) {
			readBox(fp, b + i);
			i++;
		}
		rewind(fp);
		i = searchBox(fp, id2Find);
	     if (i != -1) {
		printf("Found box %d as record #%d:\n", id2Find, i + 1);
		printBox2(b + i);
	     }
	     else {
		printf("This box is not recorded.\n\n");
	    }
    }
	    else {
		printf("Failed to open file!\n");
	}
	rewind(fp);
	fclose(fp);
}
int searchBox(FILE *fp, int id2Find) {
	int out = -1;
	int i = 0;
	struct Box b[10];
	while (fscanf(fp, "%d", &(b + i)->id) != -1) {
		readBox(fp, b + i);
		if (((b + i)->id) == id2Find) {
			out = i;
		}
		i++;
	}
	return out;
}
int readBox(FILE* fp, struct Box* bp) {
	fscanf(fp, "%lf %lf %lf %lf", &bp->size[0], &bp->size[1], &bp->size[2], &bp->weight);
	return 0;
}

/*int addBox(const char filename[], const struct Box * b2Add) {

}
int numberBoxes(const char filename[]) {

}
int getRandomInt(int lower, int higher) {

} 
void displayBoxN(char filename[], int n) {

}
void writeBox(FILE* fp, const struct Box* bp) {
	return fscanf(fp, "%d%lf%lf%lf%lf", &bp->id, &bp->size[0], &bp->size[1], &bp->size[2], &bp->weight) == 5;
}*/

/*
Welcome to My Storage Room
==========================
1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 1
List of boxes
=============

ID Length Width Height Weight
-----------------------------
10  50.34 61.00  30.00  50.50
11  25.60 12.34   9.23  12.89
55  10.00 20.00  30.00  40.50
56  30.00 40.00  50.00  60.00
57   5.20  6.30   7.40   8.50

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 2
Enter box ID: 55
Found box 55 as record #3:

ID:         55
Length:  10.00
Width:   20.00
Height:  30.00
Weight:  40.50

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 2
Enter box ID: 15
This box is not recorded.

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 0
*/
