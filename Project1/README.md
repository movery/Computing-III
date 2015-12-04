README for Poker Program

Programmer: Michael Overy
Date: 11/26/2014

Files:

Deck.h
Deck.cpp
Card.h
Card.cpp
main.cpp
Makefile


Description:
	
Utilizes Deck and Card class implementation of a standard 52 deck of playing cards to play one game of poker per run of the program.

main.cpp has 4 helper functions, three of which are explained in the program. Here I will give a brief description of the Dealer heuristic:

dealerReEvaluate is a simple function which takes the hand to be improved and its current evaluation as arguements. Based on the eval arguement, it will do one of a few things:

	1 (High Card) - Throw away the 3 lowest face value cards
	2 (One Pair) - Throw away the 3 cards not part of the pair
	3 (Two Pair) - Throw away the 1 card not part of the 2-pair
	4 (Three of a kind) - Throw away the 2 cards not part of the Three of a Kind
	5+ (Straight through Royal Flush) - Do nothing

Based on these conditions, the evaluation of a hand will never decrease (based on the combination of cards, not necessarily whether or not it has better kickers or not). 

Originally I made a very basic algorithm that threw away cards based on a value they were given based on their evaluation and their high-cards, but after I did some testing I found that the dealer would often ruin its hand bt throwing away cards that gave them a combination of strong cards, probably due to a bug that I was unable to find. Therefore, during the first 20 game test I won far more often than the dealer (14-6 in favor of me).

Afterwards I altered the algorithm to do what is listed above so make sure the Dealer doesn't ruin its hand. I feel the way I wrote the dealer it plays like an average player would -- thinking to retain their good cards instead of taking chances to greatly improve their hand, and this shows when I played the dealer again. The results were (11 - 9) in favor of the dealer, which is essentially even.

Overall this program was really fun to work on, although I feel like doing a Texas Hold'em version where instead of tossing cards you make bets until one side wins or loses would have been way cooler. 

If you have any questions or need any clarification on this assignment, please contact me at mike.overy13@gmail.com
