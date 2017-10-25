class Female;
class Male;
class Person
{
public:
	bool isMale() { return _isMale;}
	char getCode() { return _code;}
	static Person* CreateMale();
	static Person* CreateFemale();
	
private:
	const bool _isMale;
	const char _code;
protected:
	Person(bool isMale,char code) : _isMale(isMale),_code(code) {}
};
/*
class Male : public Person
{
public:
	Male() : Person(true,'M') {}
	//bool isMale() { return true;}
	//char getCode() { return 'M';}
};
*/
/*class Female : public Person
{
public:
	Female() : Person(false,'F') {}
	//bool isMale() { return false;}
	//char getCode() {return 'F';}
};
*/
 Person* Person::CreateFemale()
{
	//return new Female();
	return new Person(false,'F');
}
 Person* Person::CreateMale()
{
	//return new Male();
	return new Person(true,'M');
}