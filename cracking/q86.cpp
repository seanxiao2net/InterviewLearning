#include <vector>

using std::vector;

enum EdgeType { inner, outer, flat};

class Piece;

class Edge {
public:
bool fitsWidth(Edge edge);
private:
Piece* parent;
Edge* connect_to;
enum EdgeType Type;
int ID;
};



class Piece {
public:
Piece();
~Piece();
bool isCorner();

private:
Edge edges[4];
};

template <int dimx, int dimy>
class Puzzle {
public:
void solve();
void removeFromList(Edge* edge);
void addToList(Piece* pieces);
private:
Piece* Solution[dimx][dimy];
vector<Piece*> remainings;
vector<Edge*> inners;
vector<Edge*> outers;
vector<Edge*> flats;
};

int main()
{



	return 0;
}
