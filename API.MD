1. Card

to create a card, simply

card c(ace,spades);

you can compared two cards ie

card c(ace,spades);
card b(ace,spades);
if(c == b)
{
//your code here
}


2. There are two types of hands. 'hand_vector' and 'hand'

hand_vector is used to input a hand into the system. To use this i would reckomend using init_lists as follows


hand_vector v = {card(ace,clubs),card(ace,spades)}; 

and then you can add dynamically 

v.push_back(card(king, clubs) 


'hand' is an evaluated hand, it has a rank and _hand component (which is a hand_vector). To evaluate a hand_vector into a hand simply do 

hand x = evalHand(v); 

then to compare hands you can do 

if(*hand1 > *hand2)
{
//you get the idea
}


3. Deck.

Deck is simple. 

Deck deck; to create deck


deck.shuffle(); to shuffle deck

deck.removeCard(c); to remove card (and add it to the removed pile)

deck.removeCardF(c); to remove card permenently (this function is usefull to reset decks back to a state you pick quickly; for ex doing equity calculating)

deck.reset(); //takes all the discarded cards (ie not including cards removed with removeCardF) and puts them back into the deck.

card c = deck.draw();

4. Parser 

this class only has one function called parseInput. This takes in a string and returns a hand_vector representation of this 

the syntax is 

Parser p;
p.parseInput("ahad");

