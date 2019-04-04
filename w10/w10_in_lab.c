#include <stdio.h>
#include <string.h>
#define size 101
#define small 9

int main(void){
	char inputstring[size];
	char name [small] = "default";
	printf("default name is: %s\n", name);

	printf("Enter a name 100 characters or less: ");
	scanf("%[^\n]s", inputstring);
	if (strlen(inputstring)<=8){
		strcpy(name, inputstring);
	}

	if ( ! (strcmp ( name , inputstring))){
		printf("name was successfully changed!\n");
	}else{
		printf("could not copy name, was too long!!\n");
	}
	
	printf("%s\n",inputstring);

	printf("%s\n", name);
	return 0;
}