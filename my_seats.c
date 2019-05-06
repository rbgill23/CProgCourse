/* Title	: Seat Assignment	*/
/* File		: my_seats.c		*/  
/* Date		: 3/30/16		*/
/* Author	: Russell Gillespie	*/
/* Course	: CS 344		*/
/* Section	: 04			*/
/* Assignment	: Homework H8 Prob 1	*/
/* Input	: from keyboard		*/
/* Output	: to screen, reservations */
/* Method	: arithmetic functions struct */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct seat {
	int id;
	char avail[2];	
	char name[20];
};
typedef struct seat Seat;
int reservation(Seat seats[]);
int available(Seat seats[]);
int assignments(Seat seats[]);	

int main()
{
Seat seats[30];
int menu = 1;
int i,entid,num;
for (i=0;i<30;i++)
{
	seats[i].id = i+1;
	strcpy(seats[i].avail, "A");
	strcpy(seats[i].name, " ");
}
while (menu != 4)
{
printf("Enter the corresponding number from the menu.\n"
	"1 Enter a seat reservation\n"
	"2 Display number of seats available\n"
	"3 Display current seat assignments\n"
	"4 Exit\n"
	"Menu Number: ");
	scanf("%d", &menu);
	if (menu == 1|menu == 2|menu == 3|menu == 4)
	{

	switch(menu) {
		case 1:
		entid = reservation(seats);
		printf("\nSeat %d has been reserved for %s\n\n",
				seats[entid-1].id,seats[entid-1].name);
	
		break;
		case 2:
		printf("\nThere are %d seats available.\n\n", available(seats));
		break;
		case 3:
		num = assignments(seats);
		
		break;
		case 4:
		printf("Goodbye!\n");
		break;
		
		}
	}
}
return 0;
}
int reservation(Seat seats[]){
	int entid;
	int w = 1;
while (w == 1)
{
	printf("Choose an available seat number between 1-30 to reserve: ");
	scanf("%d",&entid);
	
	if (entid > 30 | entid < 1)
	{printf("Number not within parameters. Try again.\n");}
	if (entid > 0 && entid < 31)
	{
		
		if (strcmp(seats[entid-1].avail, "R")==0)
		{
			printf("Seat is not available. Choose another seat.\n");
		}
		if (strcmp(seats[entid-1].avail, "A")==0)
		{
			printf("Enter name for reservation: ");
			scanf("%s", seats[entid-1].name);
			strcpy(seats[entid-1].avail, "R");
			w=0;
		}
	}	
}/*end while*/
return entid;
}
int available(Seat seats[]){
int i,count;
for (i=0;i<30;i++){
	if (strcmp(seats[i].avail, "A")==0){count++;}
}
return count;
}
int assignments(Seat seats[]){
int i;
for (i = 0; i < 30; i++)
{
	printf("%s%d\t%s%s\t%s%s\n","Seat ID: ", seats[i].id,
		"Availability: ", seats[i].avail,"Name: ", seats[i].name);
}	
return 0;
}
