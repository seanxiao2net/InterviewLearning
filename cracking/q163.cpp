
class Fork {
public:
Fork();
bool PickUP() {
	return lock.trylock();
}
void PutDown() {
	lock.unlock();
}

private:
lock lock;
}

class ppl {
public:
ppl(Fork *f1, Fork *f2): fl(f1), fr(f2){}
void Eat() {
	if (!fl->PickUP())
		return;
	if (!fr->PickUp()) {
		fl.PutDown();
		return;
	}

	//chow here

	fl->PutDown();
	fr->PutDown();
}

private:
Fork *fl, *fr;

}
