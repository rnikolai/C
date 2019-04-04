#include <stdio.h>

int main() {
	int n_marks , GradeIn; //inputs
	int i = 0 , n_Fail = 0, n_Pass = 0 ; //counters
	double tot = 0 , totp = 0 , totf = 0, TotalMean, MeanPass, MeanFail ; //floats
	int min = 100, max = 0;
	printf("       ---=== IPC mark Analyser ===---\n");
	printf("Please enter the number of marks(between 3 and 40): ");
	scanf("%d", &n_marks);
	while ( (n_marks < 3) || (n_marks > 40)){
			printf("Invalid number, enter a number between 3 and 40 inclusive: ");
			scanf("%d", &n_marks);
		}
	while (i != n_marks) {
		printf("%d> ", i+1);
		scanf("%d", &GradeIn);
		if ((GradeIn <= 0) || (GradeIn >= 100)) {
			printf("Error: Enter values between 0 and 100 inclusive.\n");
		}
		else if (GradeIn < 50) {
			n_Fail += 1; // not pass
			tot += GradeIn;
			totf += GradeIn;
			i += 1;
			if (min > GradeIn) {
				min = GradeIn;
			}
			else if (max < GradeIn) {
				max = GradeIn;
			}
		}
		else {
			n_Pass += 1; //pass
			tot += GradeIn;
			totp += GradeIn;
			i += 1;
			if (min > GradeIn) {
				min = GradeIn;
			}
			else if (max < GradeIn) {
				max = GradeIn;
			}
		}
	}
	if (n_Pass != 0) {
		MeanPass = totp / n_Pass;
	    printf("Total of %d students passed with an average of %.1f.\n", n_Pass, MeanPass);
	}
	if (n_Fail != 0) {
		MeanFail = totf / n_Fail;
		printf("Total of %d students failed with an average of %.1f.\n", n_Fail, MeanFail);
	}
	TotalMean = tot / i;
	printf("Highest mark in group: %d\n", max);
	printf("Lowest mark in group: %d\n", min);
	printf("The average of all marks in this group is %.1f.\n", TotalMean);
	printf("Program Ended.\n");
	scanf("%d", &GradeIn);
	return 0;
}
