/* Title	: Passenger Seats	*/
/* File		: air.c		*/  
/* Date		: 2/10/16		*/
/* Author	: Russell Gillespie	*/
/* Course	: CS 344		*/
/* Section	: 04			*/
/* Assignment	: Homework H4 Prob 3	*/
/* Input	: from keyboard		*/
/* Output	: to screen, seats reserved */
/* Method	: function with array */

#include <stdio.h>
int searchSeat(int seat[], int class);
int main()
{
	int class, seatnumber, beta, swt, sst, alpha;
	int seat[10];
	beta = 1;
	
	for (seatnumber = 0; seatnumber <= 10; seatnumber++)
	{
		seat[seatnumber] = 1;
		
	}
	
	while (beta == 1)
	{	seatnumber = 1;
		printf("\nEnter 1 for First Class or enter 2 for Economy Class: ");
		scanf("%i", &class);
		alpha = 1;
		while (alpha == 1)
		{
		  sst = searchSeat(seat, class);
		  switch (sst)
		  {
		  case -1:
			printf("The flight is completely booked\n");
			printf("and is ready to depart\n");
			beta = 0;
			alpha = 0;
			break;
		case 0:
			if (class == 1)
			{
				printf("First Class is completly booked.\n");
			}
			if (class == 2)
			{
				printf("Economy Class is completly booked.\n");
			}
			printf("\nDo you want a seat in the other class?\n");
			printf("Enter 1 to change Classes, 2 to start new reservation for person,\n");
			printf("or 3 to depart flight: ");	
			scanf("%i", &swt);
			if (swt == 1)
			{ 	if (class == 2)
			  	{class = 1;}
			  	class = 2;
			}
			if (swt == 3)
			{
				printf("The flight is ready to depart!\n\n");
				beta = 0;
				alpha = 0;
			}
			if (swt == 2)
			{
				alpha = 0;
			}
			break;
		default:
			if (class == 1)
			{
			printf("You have reserved Seat %d in First Class.\n", sst);	
			}
			if (class == 2)
			{
			printf("You have reserved Seat %d in Economy Class.\n", sst);
			}
			alpha = 0;
			break;
		  } /* end switch */
		}/* end while alpha*/
	}/* end while beta*/	
return 0;
}
int searchSeat(int seat[], int class)
{
	int random, totavail, avail1, availe, seatnumber, seats;
	totavail = 0;
	avail1 = 0;
	availe = 0;
	random = 1;
	seatnumber = 1;
	for (seatnumber = 1; seatnumber <= 10; seatnumber++)
	{
		if (seat[seatnumber] == 1)
		{
		totavail = totavail + 1;
		}
	}
	
	if (totavail > 0)
	{
		if (class == 1) /* first class*/
		{
		for (seatnumber = 1; seatnumber <= 4; seatnumber++) /* 1st avail seats*/
		{
			if (seat[seatnumber] == 1)
			{
			avail1 = avail1 + 1;
			}
		}
		if (avail1 > 0) /* reserve seat*/
		{
			seatnumber = 1;
			while (random <= 4)
			{
				if (seat[seatnumber] == 0)
				{
					random = random + 1;		
					seatnumber = seatnumber + 1;
				}
				if (seat[seatnumber] == 1)
				{
					seat[seatnumber] = 0;
					random = 5;
				}
					
			}
			seats = seatnumber;
		}
		if (avail1 == 0)
		{
			seats = 0;
		}
		}
		if (class == 2) /* eco class*/
		{
		for (seatnumber = 5; seatnumber <= 10; seatnumber++) /* eco avail seats*/
		{
			if (seat[seatnumber] == 1)
			{
				availe = availe + 1;
			}
		}
		if (availe > 0) /* reserve seat*/
		{	
			random = 5;
			seatnumber = 5;
			while (random <= 10)
			{
				if (seat[seatnumber] == 0)
				{
					random = random + 1;		
					seatnumber = seatnumber + 1;
				}
				if (seat[seatnumber] == 1)
				{
					seat[seatnumber] = 0;
					random = 11;
				}
			}
			seats = seatnumber;
		}
		if (availe == 0)
		{
			seats = 0;
		}
	}
	}
	if (totavail == 0)
	{
		seats = -1;
	}
return seats;
}
