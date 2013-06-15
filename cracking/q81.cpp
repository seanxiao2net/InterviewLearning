#include <iostream>
#include <list>

using std::list;

class cards {
public:
cards(int cv, int co):cardVal(cv),colors(co){}
virtual ~cards(){}
//cards(cards &rhs);//make copy constructor
//cards& operator(const cards &rhs);//overload assignment operator
virtual int GetVal() {return cardVal;}
int GetColor() {return colors;}
bool isAvaliable() {return avaliable;}
void setAvaliable() {avaliable = true;}
void setUnavaliable() {avaliable = false;}

protected:
int cardVal;
int colors;
bool avaliable;
};

template <class T>
class deck {
public:
deck(list<T> newlist);

void shuffle();
int remainCards(){return cardlist.size()-cardptr;}
cards assignCards();

private:
list<T> cardlist;
int cardptr;
};

template <class T>
class hands{
//friend class bjHands;
public:
hands(){};
virtual ~hands(){}
void addCard(T card){holding.push_front(card);}

protected:
list<T> holding;
};

class blackjack: public cards {
public:
blackjack(int cv, int co): cards(cv, co){}
virtual ~blackjack(){}
int GetVal() {
	if (cardVal >= 10)	return 10;
	else return cardVal;
}
};

class bjHands: public hands<blackjack>{
public:
	bjHands():maxScore(0), minScore(0){}
	virtual ~bjHands(){}
	int getScore()
	{
		typename list<blackjack>::iterator it;
		for (it = hands<blackjack>::holding.begin(); it!=hands<blackjack>::holding.end();++it)
		{
			if ((*it).GetVal() == 1	) {
				maxScore += 10;
				minScore += 1;
			}
			else {
				maxScore += (*it).GetVal();
				minScore += (*it).GetVal();
			}
		}

		return minScore;
	}
	bool isOut() {return getScore() > 21;}
	bool isBlackJack();
private:
	int maxScore;
	int minScore;
};

int main()
{
	bjHands myBJ;

	return 0;
}
