#include <string>

using std::string;


enum PState {blank, white, black};

class grid {
public:
grid():state(blank){}
void occupy(PState s){state = s;}
void reset() {state = blank;}
bool isOccupied() {return !(state == blank);}
bool isBlack(){return state == black;}
bool isWhite(){return state == white;}
void flip() {
	if (state == blank) return;
	if (state == black) state = white;
	else state = black;
}

private:
PState state;
};

template <int dim>
class GameBoard {
public:
GameBoard(): blackScore(0), whiteScore(0){}
void ResetGame();
bool isValid(int x, int y, PState s);
bool place(int x, int y, PState s);
bool endCheck(PState s);
void flipSection(int x, int y, PState s);
void UpdateScore();
int ShowScore(PState s);

private:
grid board[dim][dim];
int blackScore;
int whiteScore;
};


class player
{
public:
player():color(blank){}
void SetName(string n) {name = n;}
void SetColor(PState s) {color = s;}
string GetName() {return name;}
PState GetColor() {return color;}

private:
string name;
PState color;
};

class Game
{
public:
Game() {players[0].SetColor(white); players[1].SetColor(black); }
GameBoard<10>* GetBoard() {return &gameboard;}
player* GetPlayer() {return players;}

private:
GameBoard<10> gameboard;
player players[2];
};

int main()
{


	return 0;
}
