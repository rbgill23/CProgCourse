/* Title	: Bin File		*/
/* File		: my_file.c		*/  
/* Date		: 4/1/16		*/
/* Author	: Russell Gillespie	*/
/* Course	: CS 344		*/
/* Section	: 04			*/
/* Assignment	: Homework H8 Prob 3	*/
/* Input	: from keyboard		*/
/* Output	: to screen,		*/
/* Method	: struct FILE		*/

#include <stdio.h>
struct hardwareData {
int record;
char tool[20];
int quant;
double cost;
};

int main()
{

struct hardwareData hardware = { 0, "", 0, 0.00};
FILE *cfptr;

int w=4;
int i=1;
int choice,yes;
if (( cfptr = fopen("hardware.dat","wb")) == NULL){
	printf("File could not be opened.\n");
for (i=1;i<=100;i++){
	fwrite( &hardware, sizeof( struct hardwareData), 1, cfptr);
	}
fclose(cfptr);
}

while (w==4){
	printf("%s%s","Menu\n1 Input a record\n2 List all records\n3 Delete a record\n",
		"4 Update a record\n5 Quit\n");
	printf("Enter a corresponding number: ");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		fopen("hardware.dat","rb+");
		printf("Enter record number between 1-100: ");
		scanf("%d", &hardware.record);
		printf("Enter tool name: ");
		fscanf(stdin,"%s", hardware.tool);
		printf("Enter quantity: ");
		fscanf(stdin,"%d", &hardware.quant);
		printf("Enter cost: ");
		fscanf(stdin,"%lf", &hardware.cost);
		fseek( cfptr, (hardware.record) * sizeof( struct hardwareData), SEEK_SET);
		fwrite( &hardware, sizeof( struct hardwareData ), 1, cfptr);
		fclose(cfptr);
	break;
	case 2:
		
		fopen("hardware.dat", "rb");
		printf("Record\tTool\tQuantity\tCost\n");
		while(!feof(cfptr)){
		
		
		fread( &hardware, sizeof( struct hardwareData), 1, cfptr );
		if (hardware.record != 0){
			printf("%d\t%s\t%d\t\t%.2f\n", hardware.record, hardware.tool, hardware.quant,
				hardware.cost);
		}
		}
		fclose(cfptr);	




	break;
	case 3:
	printf("Enter record number to delete: ");
	scanf("%d", &hardware.record);
	fopen("hardware.dat", "rb");
	fseek( cfptr, (hardware.record) * sizeof( struct hardwareData), SEEK_SET);
	struct hardwareData hardware = { 0, "", 0, 0.00};
	fwrite( &hardware, sizeof( struct hardwareData ), 1, cfptr);
	fclose(cfptr);
	break;
	case 4:
	printf("Enter record number to update: ");
	scanf("%d", &hardware.record);
	printf("Do you want to update the tool name (Enter 1 for yes, 2 for no)? ");
	scanf("%d", &yes);
	if (yes == 1) {
	printf("Enter the new tool name: ");
	fscanf(stdin,"%s", hardware.tool);
	}
	printf("Do you want to update the quantity (Enter 1 for yes, 2 for no)? ");
	scanf("%d", &yes);
	if (yes == 1) {
		printf("Enter the new quantity: ");
		fscanf(stdin,"%d", &hardware.quant);
	}
	printf("Do you want to update the cost (Enter 1 for yes, 2 for no)? ");
	scanf("%d", &yes);
	if (yes == 1) {
		printf("Enter new cost: ");
		fscanf(stdin,"%lf", &hardware.cost);
	}
	fopen("hardware.dat", "rb+");
	fseek( cfptr, (hardware.record) * sizeof( struct hardwareData), SEEK_SET);
	fwrite( &hardware, sizeof( struct hardwareData ), 1, cfptr);
	fclose(cfptr);
	break;
	case 5:
	
	printf("Goodbye!\n");
	w=5;
	break;
	
	}
}




return 0;
}




