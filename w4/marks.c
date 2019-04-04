#include <stdio.h>

int main() {
	int size, mrk[37], std[37]; //inputs
	int i = 0, j = 1, p = 0, f = 0 , lm=0,hm=0;//counters
	double tot = 0,totp=0,totf=0, MN ,MNP,MNF ; //floats
	int min = 100, max = 0;
	printf("       ---=== IPC mark Analyser V2.0 ===---\n");
	printf("Please enter the number of students(between 3 and 40): ");
	scanf("%d", &size);
	while ((size < 3) || (size > 40)){
		printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		scanf("%d", &size);
	}
	printf("Row   Std No  Mrk\n--- --------- ---\n");
	while (i != size){
		printf("    _________ ___\r");
		printf("  %d ", j);
		scanf("%d %d", &std[j] , &mrk[j]);
		if ((std[j] < 10000000) || (std[j] > 999999999)) {
			printf("Error: Enter student number values between 10000000 and 999999999 inclusive.\n");
		}
		else if ((mrk[j] < 0) || (mrk[j] > 100)) {
			printf("Error: Enter mark values between 0 and 100 inclusive.\n");
		}
		else if (mrk[j] < 50) {
			tot += mrk[j];
			totf += mrk[j];
			if (mrk[j] < min) {
				min = mrk[j];
				lm = j;
			}
			if (mrk[j] > max){
				max = mrk[j];
				hm = j;
			}
			f += 1;
			j += 1;
			i += 1;
		}
		else{
			tot += mrk[j];
			totp += mrk[j];
			if (mrk[j] > max) {
				max = mrk[j];
				hm = j;
			}
			if (mrk[j] < min) {
				min = mrk[j];
				lm = j;
			}
			p += 1;
			j += 1;
			i += 1;
		}
	}
	printf("=================\n");
	printf("Marks Entered, printing results:\n");
	printf("Row   Std No  Mrk\n--- --------- ---\n");
	j = 1;
	while (j - 1 != size) {
		printf("%03d %09d %3d", j , std[j], mrk[j]);
		if (lm == j)  {
			printf(" ***Lowest mark***\n");
		}
		else if (hm == j ){
			printf(" ***Highest mark***\n");
		}
		else{
			printf("\n");
		}
		j += 1;
	}
	printf("=================\n");
	if (p) {
		MNP = totp / p;
			printf("Total of %d students passed with an average of %.1f.\n", p , MNP);
	}
	if (f) {
		MNF = totf / f;
		printf("Total of %d students failed with an average of %.1f.\n",f ,MNF);
	}
	printf("Highest mark in group: %d\n",max);
	printf("Lowest mark in group: %d\n",min);
	MN = tot / i;
	printf("The average of all marks in this group is %.1f.\n", MN);
	printf("Program Ended.\n");
	return 0;
}
