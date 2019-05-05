/* Title	: 5 Card Poker		*/
/* File		: card_shuffle.c	*/  
/* Date		: 2/24/16		*/
/* Author	: Russell Gillespie	*/
/* Course	: CS 344		*/
/* Section	: 04			*/
/* Assignment	: Homework H5 Prob 2	*/
/* Input	: from keyboard		*/
/* Output	: to screen, 5 cards with best match */
/* Method	: funtions 		*/


/* Card shuffling dealing program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototypes */
void shuffle( int wDeck[][ 13 ] );
void deal( int wDeck[][ 13 ], const char *wFace[], 
           const char *wSuit[] );
void match(int wDeck[][13]);

int main( void )
{
	printf("\n");
   /* initialize suit array */
   const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   
   /* initialize face array */
   const char *face[ 13 ] = 
      { "Ace", "Deuce", "Three", "Four", 
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };

   /* initialize deck array */
   int deck[ 4 ][ 13 ] = { 0 };

   srand( time( 0 ) ); /* seed random-number generator */

   shuffle( deck ); /* shuffle the deck */
   deal( deck, face, suit ); /* deal the deck */
   match(deck);
   return 0; /* indicates successful termination */
} /* end main */

/* shuffle cards in deck */
void shuffle( int wDeck[][ 13 ] )
{
   int row; /* row number */
   int column; /* column number */
   int card; /* counter */

   /* for each of the 52 cards, choose slot of deck randomly */
   for ( card = 1; card <= 52; card++ ) {

      /* choose new random location until unoccupied slot found */
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 ); /* end do...while */

      /* place card number in chosen slot of deck */
      wDeck[ row ][ column ] = card;
   } /* end for */

} /* end function shuffle */

/* deal cards in deck */
void deal( int wDeck[][ 13 ], const char *wFace[],
           const char *wSuit[] )
{
   int card; /* card counter */
   int row; /* row counter */
   int column; /* column counter */
   /* deal each of the 52 cards */
   for ( card = 1; card <= 52; card++ ) {

      /* loop through rows of wDeck */
      for ( row = 0; row <= 3; row++ ) {

         /* loop through columns of wDeck for current row */
         for ( column = 0; column <= 12; column++ ) {

            /* if slot contains current card, display card */
            if ( wDeck[ row ][ column ] == card ) {
              /* printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],
                  card % 2 == 0 ?  '\n' :'\t' ); */
		
            } /* end if */
         } /* end for */
      } /* end for */
   } /* end for */
printf("\nHere is your 5 card hand:\n");/*rg - added code*/
   for ( card = 1; card <= 5; card++ ) {

      /* loop through rows of wDeck */
      for ( row = 0; row <= 3; row++ ) {

         /* loop through columns of wDeck for current row */
         for ( column = 0; column <= 12; column++ ) {

            /* if slot contains current card, display card */
            if ( wDeck[ row ][ column ] == card ) {               
		printf( "%5s of %-8s\n", wFace[ column ], wSuit[ row ] );
            } /* end if */
         } /* end for */
      } /* end for */
   } /* end for 'rg' */
printf("\n\n");/*rg*/
} /* end function deal */
void match(int wDeck[][13])
{
  int card; /* card counter */
   int row; /* row counter */
   int column; /* column counter */
	int H,D,C,S,ACE,TWO,THR,FOU,FIV,SIX,SEV,EIG,NIN,TEN,JAC,QUE,KIN,MATCH;
	H=D=C=S=ACE=TWO=THR=FOU=FIV=SIX=SEV=EIG=NIN=TEN=JAC=QUE=KIN=0;
for ( card = 1; card <= 5; card++ ) {

      /* loop through rows of wDeck */
      for ( row = 0; row <= 3; row++ ) {

         /* loop through columns of wDeck for current row */
         for ( column = 0; column <= 12; column++ ) {

            if (wDeck[row][column] == card)
	    {
		switch ( row )
	        {
		case 0: H++;break;
		case 1: D++;break;
		case 2: C++;break;
		default: S++;break;
	        } /*end switch*/
		switch ( column )
	        {
		case 0: ACE++;break;
		case 1: TWO++;break;
		case 2: THR++;break;
		case 3: FOU++;break;
		case 4: FIV++;break;
		case 5: SIX++;break;
		case 6: SEV++;break;
		case 7: EIG++;break;
		case 8: NIN++;break;
		case 9: TEN++;break;
		case 10: JAC++;break;
		case 11: QUE++;break;
		default: KIN++;break;
	        } /*end switch*/
	   }/* end if*/
         } /* end column for */
      } /* end row for */
   } /* end card for */	
	if(ACE==2||TWO==2||THR==2||FOU==2||FIV==2||SIX==2||SEV==2||EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)
	{MATCH=5;/*pair*/
	if(ACE==2&&(TWO==2||THR==2||FOU==2||FIV==2||SIX==2||SEV==2||EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||TWO==2&&(THR==2||FOU==2||FIV==2||SIX==2||SEV==2||EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||THR==2&&(FOU==2||FIV==2||SIX==2||SEV==2||EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||FOU==2&&(FIV==2||SIX==2||SEV==2||EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||FIV==2&&(SIX==2||SEV==2||EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||SIX==2&&(SEV==2||EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||SEV==2&&(EIG==2||NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||EIG==2&&(NIN==2||TEN==2||JAC==2||QUE==2||KIN==2)||NIN==2&&(TEN==2||JAC==2||QUE==2||KIN==2)||TEN==2&&(JAC==2||QUE==2||KIN==2)||JAC==2&&(QUE==2||KIN==2)||QUE==2&&KIN==2)
	{MATCH=4;};/* 2 pair*/
	};
	if(ACE==3||TWO==3||THR==3||FOU==3||FIV==3||SIX==3||SEV==3||EIG==3||NIN==3||TEN==3||JAC==3||QUE==3||KIN==3)
	{MATCH=3;};/* three of a kind */
	if(ACE==4||TWO==4||THR==4||FOU==4||FIV==4||SIX==4||SEV==4||EIG==4||NIN==4||TEN==4||JAC==4||QUE==4||KIN==4)
	{MATCH=2;};/*four of a kind*/
	if (H==5||D==5||C==5||S==5)
	{MATCH=1;};/*flush*/
	if (ACE==1&&TWO==1&&THR==1&&FOU==1&&FIV==1||TWO==1&&THR==1&&FOU==1&&FIV==1&&SIX==1||THR==1&&FOU==1&&FIV==1&&SIX==1&&SEV==1||FOU==1&&FIV==1&&SIX==1&&SEV==1&&EIG==1||FIV==1&&SIX==1&&SEV==1&&EIG==1&&NIN==1||SIX==1&&SEV==1&&EIG==1&&NIN==1&&TEN==1||SEV==1&&EIG==1&&NIN==1&&TEN==1&&JAC==1||EIG==1&&NIN==1&&TEN==1&&JAC==1&&QUE==1||NIN==1&&TEN==1&&JAC==1&&QUE==1&&KIN==1||ACE==1&&TEN==1&&JAC==1&&QUE==1&&KIN==1)
	{ MATCH = 0;};/*straight*/
	switch (MATCH){
	case 0: printf("Your best hand is a straight!\n\n");break;
	case 1: printf("Your best hand is a flush!\n\n");break;
	case 2: printf("Your best hand is four of a kind!\n\n");break;
	case 3: printf("Your best hand is three of a kind!\n\n");break;
	case 4: printf("Your best hand is two pairs!\n\n");break;
	case 5: printf("Your best hand is a pair!\n\n");break;
	default: printf("Your hand is no good.\n\n");break;
	} /*end switch*/
} /* END MATCH FUNCTION*/
