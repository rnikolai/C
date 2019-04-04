#include <stdio.h>

int main() {
	int T, L, Q, D, N, P;
	int B1, B2 ,B3 ,B4 ;
	double A;
	printf("Please enter the number of coins in your piggy bank:\n");
	printf("Toonies: ");
	scanf("%d", &T);
	printf("Loonies: ");
	scanf("%d", &L);
	printf("Quarters: ");
	scanf("%d", &Q);
	printf("Dimes: ");
	scanf("%d", &D);
	printf("Nickels: ");
	scanf("%d", &N);
	printf("Pennies: ");
	scanf("%d", &P);
	A = (T * 2)+(L)+(Q*0.25)+(D*0.10)+(N*0.05)+(P*0.01);
	printf("You have $%.2f in your piggy bank!\n", A);
	B1 = A/50 ;
	A = A - (B1 * 50);
	printf("$50 bill: %d\n", B1);
	B2 = A / 20;
	A = A - (B2 * 20);
	printf("$20 bill: %d\n", B2);
	B3 = A / 10;
	A = A - (B3 * 10);
	printf("$10 bill: %d\n", B3);
	B4 = A / 5;
	A = A - (B4 * 5);
	printf("$5 bill: %d\n", B4);
	printf("Change: $%.2f", A);
	scanf("%d", &P);
	return 0;
}
