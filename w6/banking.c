#include <stdio.h>
const int nosClients = 5; // Number of accounts
struct account {
   int accNumber;//account numbers
   double balance;//balance of the account
};
double balanceUp(double balance, double amount) {
   double i=0;
   if (amount >= 0) {
      i = balance + amount;
   }
   return i;
}
double balanceDown(double balance, double amount) {
   double i = 0;
 if (amount >= 0) {
      i = balance - amount;
   }
   return i;
}
double interestCalc(double balance , double rate) {
   double out = 0;
   out = (balance * (rate / 100));
   return out;
}
   int main(void) {
   struct account acct[] = { { 11111111,123.45 },{ 22222222,12365.50 },{ 33333333,0 },{ 44444444,1475 },{ 55555555,25000.65 } };// inital val for data
   int arrayind=0;
   int opt;//option selected by user
   int tempaccnum; // temporary account number
   double tempadd; // value to add to balance
   double calcInterest;//first arrayindex that match search
   int i; //array index
   int p; // true or false array search result
   double k;//no money flag
   printf("***** Welcome to Savings Account Banking *****\n");
   do {
      p = i = 0;
      printf("\n1.) Deposit \n"
	 "2.) Withdraw\n"
	 "3.) Apply monthly interest earnings to all accounts\n"
	 "4.) Apply service charges to all accounts\n"
	 "5.) Account Summary\n"
	 "0.) Log out\n\n"
	 "Please enter an option to continue: ");
      scanf("%d", &opt);
      if (opt == 0) {
      }
      else if (opt == 1) {
	 printf("\n-- Make a deposit --\n\n");
	 printf("Enter account number: ");
	 scanf("%d", &tempaccnum);
	 while (i <= nosClients) {
	    if (tempaccnum == acct[i].accNumber) {
	  arrayind = i;
	       p = 1;
	    }
	    i += 1;
	 }
	 if (p == 0) {
	    printf("ERROR: Account number does not exist.\n");
	 }
	 else {
	    printf("Enter amount to deposit (CAD): ");
	    scanf("%lf", &tempadd);
	    acct[arrayind].balance = balanceUp(acct[arrayind].balance, tempadd);
	    printf("Current balance is : %.2f\n", acct[arrayind].balance);
	 }
      }
      else if (opt == 2) {
	 printf("\n-- Withdraw funds --\n\n");
	 printf("Enter account number: ");
	 scanf("%d", &tempaccnum);
	 while (i <= nosClients) {
	    if (tempaccnum == acct[i].accNumber) {
	  arrayind = i;
	       p = 1;
	    }
	    i += 1;
	 }
	 if (p == 0) {
	    printf("ERROR: Account number does not exist.\n");
	 }
	 else {
	    printf("Enter amount to withdraw (CAD): ");
	    scanf("%lf", &tempadd);
	    k = balanceDown(acct[arrayind].balance, tempadd);
	    if (k<0){
	    printf("Withdrawal failed. You only have : %.2f in your account\n",acct[arrayind].balance);
	    }
	    else{
	    acct[arrayind].balance = k;
	    printf("Current balance is : %.2f\n", acct[arrayind].balance);
	    }
	 }
      }
      else if (opt == 3) {
	 printf("\n-- Add monthly interest earnings to all accounts --\n\n");
	 printf("Account# New Balance Interest Earnings (M)\n-------- ----------- ---------------------\n");
	 while (i < nosClients) {
	    if (acct[i].balance <= 500) {
	       calcInterest = interestCalc(acct[i].balance, 0.99);
	       acct[i].balance = balanceUp(acct[i].balance, calcInterest);
	       printf("%8d %11.2lf %21.2lf\n" ,acct[i].accNumber,acct[i].balance, calcInterest);
	    }
	    else if(acct[i].balance > 500 && acct[i].balance <= 1500){
	       calcInterest = interestCalc(acct[i].balance, 1.66);
	       acct[i].balance = balanceUp(acct[i].balance, calcInterest);
	       printf("%8d %11.2lf %21.2lf\n",acct[i].accNumber, acct[i].balance, calcInterest);
	    }
	    else if (acct[i].balance > 1500){
	       calcInterest = interestCalc(acct[i].balance, 2.49);
	       acct[i].balance = balanceUp(acct[i].balance, calcInterest);
	       printf("%8d %11.2lf %21.2lf\n",acct[i].accNumber, acct[i].balance, calcInterest);
	    }
	    i += 1;
	 }
      }
      else if (opt == 4) {
	 printf("\n-- Apply service charges to all accounts --\n\n");
	 printf("Account# New Balance Service charges (M)\n-------- ----------- -------------------\n");
	 while (i < nosClients) {
	    if (acct[i].balance > 1500) {
	       acct[i].balance = balanceDown(acct[i].balance, 2.5);
	       printf("%8d %11.2lf %19.2lf\n", acct[i].accNumber, acct[i].balance, 2.50);
	    }
	    else {
	       acct[i].balance = balanceDown(acct[i].balance, 7.50);
	       printf("%8d %11.2lf %19.2lf\n", acct[i].accNumber, acct[i].balance, 7.50);
	    }
	    i += 1;
     }
      }
      else if (opt == 5) {
	 printf("\n-- Account information --\n\n");
	 printf("Account# Balance   \n-------- ----------\n");
	 while (i < nosClients) {
	    printf("%8d %10.2lf\n", acct[i].accNumber, acct[i].balance);
	    i += 1;
	 }
      }
      else {
	 printf("Error: Please enter a valid option to continue\n\n");
      }
   } while (opt != 0);
   return 0;
}
