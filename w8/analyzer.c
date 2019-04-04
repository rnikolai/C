//Nikolai Rubtsov 134471168 rnikolai
#include <stdio.h>

#define MAX 100
struct studentMarks {
   int   id;
   float marks;
};

void welcome(void);
int get_data( struct studentMarks * ptr );
void show( struct studentMarks list[], int num );
float analyze(float* min, float* max, struct studentMarks ls[], int num);
void printSummary(float p, float min, float max);

int main(void){
   struct studentMarks studentMark[MAX];
   int i = 0;//loop counter
   int p = 0;//function output flag
   int cpi= 0;//copy of i 
   float k;//avarage receiver
   float min = 100; //min
   float max = 0; //max
   // declarations of a constant, an array and variables
      welcome();
   // call a function to display a welcome message
      do{
	p = get_data(studentMark+i);
	i++;
	cpi++;
	if (p == -1) {
	   cpi = i;
	   i = MAX;
	}
      } while (i != MAX);

   // 1. use a do-while loop to get student ids and student marks
      show(studentMark, cpi);
   // 2. print out all the student marks
	  k = analyze(&min,&max,studentMark,cpi);
	  printSummary(k,min,max);
   // 3. Call analyze to calculate 
    return 0;
}
void welcome(void) {
   printf("####### Marks Analyzer V3.0 #######\n");
}
int get_data(struct studentMarks* ptr) { //same as (struct studentMarks ptr[])
   int p=0;//return val
   printf("Enter student id and marks (e.g. 12345 89.5): ");
   scanf("%d  %f", &ptr->id, &ptr->marks);
   if (ptr->id == -1 || ptr->marks == -1) {
      p = -1;
   }
   return p;
}
void show(struct studentMarks list[], int num) {
   int i = 0; //loop counter
   while (i != num-1) {
      printf("%d. %d, %.2f\n",i+1, list[i].id, list[i].marks);
      i += 1;
   }
   if (i == MAX) {
      printf("%d. %d, %.2f\n", i + 1, list[i].id, list[i].marks);
   }
}
float analyze(float* min,float* max, struct studentMarks ls[],int num) {
	float avr;
	float total=0;
	int i=0;
	while (i != num-1) {
		if (ls[i].marks > *max) {
			*max = ls[i].marks;
}
		if (ls[i].marks < *min) {
			*min = ls[i].marks;
		}
		total += ls[i].marks;
		i++;
}
	avr = total / (num - 1);
		return avr;
}
void printSummary(float p,float min,float max) {
	printf("### result of marks analysis ###\n");
	printf("average: %.2f, highest marks: %.2f, lowest marks: %.2f\n",p, max, min);
}
