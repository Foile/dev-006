#include <map>

using namespace ::std;

class SuperHero
{
private:
  string Name;
  bool CanFly;
  int Age;
public:
	SuperHero(string Name,bool CanFly,int Age):
		Name(Name),CanFly(CanFly),Age(Age)
	{
	}
};


class SomeClass
{
private:

SuperHero *Hero;
public:
	SomeClass(SuperHero *Hero): Hero(Hero)
	{
	}
};
int main()
{
	return 0;
}