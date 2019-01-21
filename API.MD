Make sure to include Master.h, it contains needed includes and tells the compiler to include the .lib files that are in the DIR that you
have chosen for your lib include dir.

1. Card

to create a card, simply

Card c(ace,spades);

card has build in operators, >, <, ==, !=,<=,>=,<<


2. Hands

Build up a hand_vector with Cards (shown how to create above)

hand_vector hand = {Card(ace,spades)} ect or pushback after draw ect.

Hand is the type for evaulated hands (and straightFlush, singlePair, ect extend from it). This has a > operator built in for comparing hands.

to evaulate the hand, call evalHand passing it a hand_vector, which returns a hand_ptr (unique_ptr<Hand>). You can then use > operator to compare,
or access the hand_ (std::vector<Card>) property to see what cards are in the final 5 cards that make up the hand.



3. Deck.

Deck is simple. 

Deck deck; to create deck


deck.shuffle(); to shuffle deck

deck.removeCard(c); to remove card (and add it to the removed pile)

deck.removeCardF(c); to remove card permenently (this function is usefull to reset decks back to a state you pick quickly; for ex doing equity calculating)

deck.reset(); //takes all the discarded cards (ie not including cards removed with removeCardF) and puts them back into the deck.

Cardc = deck.draw();