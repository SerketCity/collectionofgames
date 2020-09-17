/****************************************************************
****************************************************************
*   FILE NAME: GAME/MENU
*
*    AUTHOR: JOHN RICE/DR.DOMAN
*
*   DESCRIPTION: MENU AND WAR GAME
*
****************************************************************
****************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "deck.h"
#include "card.h"
#include "marble.h"
#include "monte.h"
#include "tool.h"
#include "rock.h"
#include "paper.h"
#include "scissors.h"
#include "node.h"
#include "list.h"
#include "playinghand.h"
#include "discardpile.h"

using namespace std;
// Function Prototypes
void showMenu();  // menu
void invalidInputReset();  // resets console after invalid input
// GAMES
void doWar(); // War game
void doMonte(); // monte game
void doBlackjack(); // blackjack game
void doRPS(); // rock paper scissors game
void doCrazy8(); // crazy 8s game
//*****************************************************
// Start of main routine
//*****************************************************

int main()
{
  srand(time(0));
  int choice=0; // init to ensure while executes once

  while (choice!=99)
  {
	   showMenu();
	   cin >> choice;
	   if (cin.fail())  // Input validation error
	   {
       choice = 0; // reset choice to indicate invalid choice
			 invalidInputReset(); // reset cin to valid state
	   }
	   switch (choice)
     {
		     case 1 : // Play War
		    	 doWar();
		     	break;
		     case 2 :
		     	doMonte();
		     	break;	
		     case 3 :
			doBlackjack();
			break;
		     case 4 :
			doRPS();
			break;	
		     case 5 :
			doCrazy8();
			break;
		     case 99 :  // end game
			   cout << "Thanks for playing " << endl << endl;
			   break;

		     default :  // not a valid choice
			   cout << "Error: not a valid selection " << endl;
			   break;

		 } // end of switch statement

   } // end of while loop

return 0;
}

//***************************************
// Function : doWar
// Input: none
// output: none
// Description: plays war game
//*****************************************
void doWar()
{
	int p1score = 0, p2score = 0;
	string p1name, p2name;
	Deck deck;
	deck.shuffle();
	cout<<"Input Player One's name: ";
	cin.ignore();
	getline(cin, p1name);
	cout<<endl<<"Input Player Two's name: ";
	getline(cin, p2name);
	cout<<endl<<"Hello, "<<p1name<<" and "<<p2name<<"!"<<endl;
	cout<<endl<<"Press enter to begin!"<<endl<<endl;
	cin.ignore();

	for(int i = 0; i < 10; i++)
	{
		Card p1card, p2card;
		cout<<"ROUND "<<i+1<<":"<<endl;
		p1card = deck.deal();
		p2card = deck.deal();
		cout<<p1name<<" has pulled: "<<p1card.toString()<<endl;
		cout<<p2name<<" has pulled: "<<p2card.toString()<<endl;
		if(p1card.getRank() > p2card.getRank())
		{
			cout<<endl<<p1name<<" wins round "<<i+1<<"!"<<endl<<endl;
			p1score++;
		}
		else if(p2card.getRank() > p1card.getRank())
		{
			cout<<endl<<p2name<<" wins round "<<i+1<<"!"<<endl<<endl;
			p2score++;
		}
		else
		{
			cout<<"Round "<<i+1<<" is a tie!"<<endl<<endl;
		}
		
	}

	
	cout<<endl<<"FINAL SCORE: "<<endl;
	cout<<p1name<<": "<<p1score<<" POINTS"<<endl;
	cout<<p2name<<": "<<p2score<<" POINTS"<<endl<<endl;
	if(p1score > p2score)
	{
		cout<<p1name<<" wins the game!"<<endl;
	}
	else if(p2score > p1score)
	{
		cout<<p2name<<" wins the game!"<<endl;
	}
	else
	{
		cout<<"The game has ended in a tie!"<<endl;
	}
	
	cout<<endl<<"Thank you for playing!"<<endl;
}

//***************************************
// Function : doMonte
// Input: none
// output: none
// Description: Plays monte game
// 
//*****************************************

void doMonte()
{
	int choice, playerscore = 0, housescore = 0;
	
	do
	{
		cout<<endl<<"Would you like to play Monte with MARBLES or CARDS?"<<endl;
		cout<<"1.MARBLES"<<endl;
		cout<<"2.CARDS"<<endl;
		cin>>choice;
		if(choice > 2)
		{
			cout<<endl<<"INVALID INPUT!"<<endl;
		}
	}while(choice > 2);
	
	if(choice == 1)
	{
		Marble playermarble, homemarble;
	        Marble mar1("RED"), mar2("YELLOW"), mar3("BLUE");
		Monte<Marble> montegame(mar1);
        	montegame.setThing1(mar1);
               	montegame.setThing2(mar2);
               	montegame.setThing3(mar3);
		homemarble = montegame.pick((rand() % 3) + 1);
		cout<<endl<<"Find the "<<homemarble.getColor()<<" marble."<<endl;
		montegame.shuffle();
		do
		{
			cout<<endl<<"Type a number 1 through 3 to pick a marble!"<<endl;
			cin >> choice;
			if(choice > 3)
			{
				cout<<endl<<"INVALID INPUT!"<<endl;
			}
		}while(choice > 3);
		playermarble = montegame.pick(choice);
		cout<<endl<<"You chose the "<<playermarble.getColor()<<" marble!"<<endl;
		if(playermarble.getColor() == homemarble.getColor())
		{
			playerscore = 1;
		}
		else if(playermarble.getColor() != homemarble.getColor())
		{
			housescore = 1;
		}
	} 
	else if(choice == 2)
	{
		Card playercard, homecard, tempcard;
		Monte<Card> montegame(tempcard);
		Deck gamedeck;
		gamedeck.shuffle();
		gamedeck.shuffle();
		gamedeck.shuffle();
		montegame.setThing1(gamedeck.deal());
		montegame.setThing2(gamedeck.deal());
		montegame.setThing3(gamedeck.deal());
		homecard = montegame.pick((rand() % 3) + 1);
		cout<<endl<<"Find the "<<homecard.toString()<<endl;
		montegame.shuffle();
		do
                {
                        cout<<endl<<"Type a number 1 through 3 to pick a card!"<<endl;
                        cin >> choice;
                        if(choice > 3)
                        {
                                cout<<endl<<"INVALID INPUT!"<<endl;
                        }
                }while(choice > 3);
		playercard = montegame.pick(choice);
		cout<<endl<<"You chose the "<<playercard.toString()<<endl;
		
		if(playercard.getRank() == homecard.getRank())
		{
			if(playercard.getSuit() == homecard.getSuit())
			{
				playerscore = 1;
			}
		}
		else if(playercard.getRank() != homecard.getRank())
		{
			housescore = 1;
		}
	}
	
	if(playerscore > housescore)
	{
		cout<<endl<<"YOU WIN!"<<endl;
	}
	else if(housescore > playerscore)
	{
		cout<<endl<<"COMPUTER WINS!"<<endl;
	}

	cout<<endl<<"Thank you for playing!"<<endl;

}

//***************************************
// Function : doBlackjack
// Input: none
// output: none
// Description: Plays blackjack
//
//*****************************************

void doBlackjack()
{
	int house, player;
	char choice;
	Deck carddeck;
	Card dealtcard;
	
	cin.ignore();
	cout<<endl<<"Press enter to begin playing Blackjack."<<endl;
	cin.ignore();
	carddeck.shuffle();

	dealtcard = carddeck.deal();
	if(dealtcard.getRank() > 10)
	{
		house = 10;
	}
	else
	{
		house = dealtcard.getRank();
	}
	cout<<"HOUSE CARDS:"<<endl;
	cout<<dealtcard.toString()<<endl;
	dealtcard = carddeck.deal();
	if(dealtcard.getRank() > 10)
        {
                house += 10;
        }
        else
        {
                house += dealtcard.getRank();
        }
	cout<<dealtcard.toString()<<endl;
	cout<<"TOTAL HOUSE SCORE: "<<house<<endl;

	dealtcard = carddeck.deal();
	if(dealtcard.getRank() > 10)
	{
		player = 10;
	}
	else
	{
		player = dealtcard.getRank();
	}
	cout<<endl<<"PLAYER CARDS:"<<endl;
	cout<<dealtcard.toString()<<endl;
	dealtcard = carddeck.deal();
	if(dealtcard.getRank() > 10)
	{
		player += 10;
	}
	else
	{
		player += dealtcard.getRank();
	}
	cout<<dealtcard.toString()<<endl;
	cout<<"TOTAL PLAYER SCORE: "<<player<<endl;

	do
	{
		cout<<endl<<"Would you like another card? Enter 'Y' for Yes, or 'N' for no."<<endl;
		cin>>choice;
		
		if(choice == 'y' || choice == 'Y')
		{
			dealtcard = carddeck.deal();
			if(dealtcard.getRank() > 10)
			{
				player += 10;
			}
			else
			{
				player += dealtcard.getRank();
			}
			cout<<dealtcard.toString()<<endl;
			cout<<"TOTAL PLAYER SCORE: "<<player<<endl;
		}else if(choice != 'n' && choice != 'N')
                {
                        cout<<"INVALID INPUT!"<<endl;
                        choice = 'y';
                }

	}while((choice == 'y' || choice == 'Y') && player < 21);

	if(player < 21)
	{
		do
		{
			dealtcard = carddeck.deal();
			if(dealtcard.getRank() > 10)
			{
				house += 10;
			}
			else
			{
				house += dealtcard.getRank();
			}
			cout<<dealtcard.toString()<<endl;
			cout<<"TOTAL HOUSE SCORE: "<<house<<endl;
		}while(house < 22 && house < player);
	}

	cout<<endl<<"FINAL PLAYER SCORE: "<<player<<endl;
	cout<<"FINAL HOUSE SCORE: "<<house<<endl;

	if(house > player)
	{
		cout<<endl<<"HOUSE WINS!"<<endl;
	}
	else
	{
		cout<<endl<<"PLAYER WINS!"<<endl;
	}
}

//***************************************
// Function : doRPS
// Input: none
// output: none
// Description: Plays rock paper scissors
//
//*****************************************

void doRPS()
{
	Tool* ComputerToolPtr;
	Tool* PlayerToolPtr;
	int choice, compChoice, score, compScore, fightInt;
	cin.ignore();
        cout<<endl<<"Press enter to begin playing Rock, Paper, Scissors.."<<endl;
        cin.ignore();

	for(int i = 0; i < 3; i++) // loop for 3 rounds 
	{
		cout<<endl<<"Please select an option by typing the corresponding number."<<endl;
		do // loop to ensure correct choices
		{
			cout<<"1.ROCK"<<endl;
			cout<<"2.PAPER"<<endl;
			cout<<"3.SCISSORS"<<endl;
			cout<<endl;
			cin>>choice;
			if(choice != 1 && choice != 2 && choice != 3)
			{
				cout<<endl<<"INVALID INPUT"<<endl;
			}
		}while(choice != 1 && choice != 2 && choice != 3);
		
		if(choice == 1) //creates player object choice and assigns pointer
		{
			PlayerToolPtr = new Rock;
		} else
		if(choice == 2)
		{
			PlayerToolPtr = new Paper;
		} else
		if(choice == 3)
		{
			PlayerToolPtr = new Scissors;
		}

		compChoice = rand() % 3 + 1; 

		if(compChoice == 1) //creates computer object choice and assigns pointer
                {
			ComputerToolPtr = new Rock;
                } else
                if(compChoice == 2)
                {
			ComputerToolPtr = new Paper;
                } else
                if(compChoice == 3)
                {
			ComputerToolPtr = new Scissors;
                }

		fightInt = PlayerToolPtr->fight(ComputerToolPtr); //fights the two tools

		if(fightInt == 0) //announces round winner and assigns points
		{
			cout<<endl<<PlayerToolPtr->getType()<<" meets a stalemate against "<<ComputerToolPtr->getType()<<endl;
		} else
		if(fightInt == 1)
		{
			cout<<endl<<PlayerToolPtr->getType()<<" beats "<<ComputerToolPtr->getType()<<endl;
			++score;
		} else
		if(fightInt == 2)
		{
			cout<<endl<<PlayerToolPtr->getType()<<" is beat by "<<ComputerToolPtr->getType()<<endl;
			++compScore;
		}
		
		//rids the world of these two objects

		delete PlayerToolPtr;
		delete ComputerToolPtr;
	}

	if(score == compScore)
	{
		cout<<endl<<"Game tied!"<<endl;
	} else
	if(score > compScore)
	{
		cout<<endl<<"Player wins!"<<endl;
	} else
	if(score < compScore)
	{
		cout<<endl<<"Computer wins!"<<endl;
	}
}

//***************************************
// Function : doCrazy8
// Input: none
// output: none
// Description: Plays crazy 8s game
//   
//*****************************************
void doCrazy8()
{
	PlayingHand p1Hand;
	PlayingHand p2Hand;
	Deck pickPile;
	DiscardPile discPile;
	Card draw, pick;
	int turn = 1;
	bool valid;
	int p1penalty = 0, p2penalty = 0; 
	int choice;
	pickPile.shuffle();

	//deals each player 7 cards
	for(int i = 0; i < 7; i++)
	{
		draw = pickPile.pop();
		p1Hand.pushFront(draw);
		draw = pickPile.pop();
		p2Hand.pushFront(draw);
	}
	
	//places start card
	draw = pickPile.pop();
	discPile.push(draw);
	
	//keeps game going as long as both players have cards and deck has cards
	while(p1Hand.getSize() > 0 && p2Hand.getSize() > 0 && !(pickPile.isEmpty()))
	{
		Card topCard = discPile.peek();
		if(turn == 1)
		{
			cout<<endl<<"PLAYER'S TURN:"<<endl;
			cout<<endl<<"TOP CARD: "<<topCard.toString()<<endl;
			do
			{
				//validates choice of card
				do
				{
					cout<<endl<<"PICK A CARD TO PLAY"<<endl;
					p1Hand.printList();
					cout<<p1Hand.getSize() + 1<<". DRAW A CARD"<<endl;
					cin>>choice;
					if(choice > p1Hand.getSize() + 1 || choice < 1)
					{
						cout<<endl<<"INVALID INPUT!"<<endl;
						valid = 0;
					}
					else
					{
						valid = 1;
					}
				}while(valid == 0);
				//draws card
				if(choice == p1Hand.getSize() + 1)
				{
					draw = pickPile.pop();
					p1Hand.pushBack(draw);
					valid = 1;
				}
				//validates if chosen card can be placed, if not, placed back in hand and asked to pick another card
				else
				{
					pick = p1Hand.popAPos(choice - 1);
					if(pick.getSuit() == topCard.getSuit() || pick.getRank() == topCard.getRank())
					{
						discPile.pileInput(pick);
						valid = 1;
					}
					else if(pick.getRank() == 8)
					{
						discPile.pileInput(pick);
						valid = 1;
					}
					else
					{
						cout<<endl<<"INVALID CARD! PICK ANOTHER."<<endl;
						p1Hand.pushBack(pick);
						valid = 0;
					}
				
				}
			}while(valid == 0);
		}
		//does computer's turn, similar to players except it cycles through options and doesnt input anything to screen
		if(turn == 2)
                {
			cout<<endl<<"COMPUTER'S TURN:"<<endl;
			cout<<"COMPUTER PLAYING TURN..."<<endl;
			choice = 1;
                        do
                        {
                                do
                                {
                                        if(choice > p2Hand.getSize() + 1 || choice < 1)
                                        {
                                                valid = 0;
                                        }
                                        else
                                        {
                                                valid = 1;
                                        }
                                }while(valid == 0);
                                if(choice == p2Hand.getSize() + 1)
                                {
                                        draw = pickPile.pop();
                                        p2Hand.pushBack(draw);
                                        valid = 1;
                                }
                                else
                                {
                                        pick = p2Hand.popAPos(choice - 1);
                                        if(pick.getSuit() == topCard.getSuit() || pick.getRank() == topCard.getRank())
                                        {
                                                discPile.pileInput(pick);
                                                valid = 1;
                                        }
                                        else if(pick.getRank() == 8)
                                        {
                                                discPile.pileInput(pick);
                                                valid = 1;
                                        }
                                        else
                                        {
                                                p2Hand.pushBack(pick);
						++choice;
                                                valid = 0;
                                        }

                             	}
                        }while(valid == 0);
                }
		//changes turns
		if(turn == 1)
		{
			turn = 2;
		} 
		else if(turn == 2)
		{
			turn = 1;
		}
	}
	//finds winner
	if(p1Hand.getSize() == 0)
	{
		cout<<endl<<"PLAYER WINS!"<<endl;
	} 
	if(p2Hand.getSize() == 0)
	{
		cout<<endl<<"COMPUTER WINS!"<<endl;
	}
	if(pickPile.isEmpty())
	{
		//tallies penalty points in hands
		while(p1Hand.getSize() != 0)
		{
			pick = p1Hand.popFront();
			if(pick.getRank() > 9)
			{
				p1penalty += 10;
			}
			else
			{
				p1penalty += pick.getRank();
			}
		}
		while(p2Hand.getSize() != 0);
		{
			pick = p2Hand.popFront();
			if(pick.getRank() > 9)
			{
				p2penalty += 10;
			}
			else
			{
				p2penalty += pick.getRank();
			}
		}
		cout<<endl<<"PLAYER PENALTY POINTS: "<<p1penalty<<endl;
		cout<<"COMPUTER PENALTY POINTS: "<<p2penalty<<endl;

		if(p1penalty < p2penalty)
		{
			cout<<endl<<"PLAYER WINS!"<<endl;
		}
		if(p2penalty < p1penalty)
		{
			cout<<endl<<"COMPUTER WINS!"<<endl;
		}
		if(p1penalty == p2penalty)
		{
			cout<<endl<<"GAME TIED!"<<endl;
		}
	}

}

//***************************************
// Function : showMenu
// Input: none
// output: none
// Description: This function presents the menu
//    options on the screen.
//*****************************************
void showMenu()
{	//system("clear");  // clear the screen
    // cout<<endl << endl << endl << endl;
    cout<< "                         " << endl;
    cout<< "           _~            " << endl;
	  cout<< "        _~)_)_~          " << endl;
	  cout<< "       )_))_))_)         " << endl;
	  cout<< "       _!__!__!_         " << endl;
	  cout<< "       \\------t/         " << endl;
	  cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	  cout << "****  GAME MENU   ******" << endl << endl;
	  cout<<" Please type a choice:"<<endl;
    cout<<"  1  First game: Game of War"<<endl;
    cout<<"  2  Second game: Monte Game"<<endl;
    cout<<"  3  Third game: Blackjack"<<endl;
    cout<<"  4  Fourth game: Rock Paper Scissors"<<endl;
    cout<<"  5  Fifth game: Crazy 8s"<<endl;
    cout<<"  99  Exit the program"<<endl;
    }

//***************************************
// Function : invalidInputReset
// Input: none
// output: none
// Description: This function resets the cin stream object
//      after in invalid input is detected. It clears the error flags
//      and reads any other 'garbage' on the input line past the last '\n'
//*****************************************
void invalidInputReset()
{
	cin.clear(); // clear the error flags
	cin.ignore(); // skip anything else on the line
}
