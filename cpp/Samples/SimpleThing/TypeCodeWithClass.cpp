
class BloodGroup
{
public:
	enum _BloodGroup { BloodGroup_I,BloodGroup_II, BloodGroup_III, BloodGroup_IV};
private:
	_BloodGroup _code;
	static BloodGroup _values[4];
public:
	BloodGroup(_BloodGroup Code) : _code(Code) {}
	_BloodGroup GetCode()
	{
		return _code;
	}
	static BloodGroup Code(_BloodGroup group)
	{
		return _values[group];
	}
};

BloodGroup BloodGroup::_values[4] = {BloodGroup(BloodGroup::BloodGroup_I),BloodGroup(BloodGroup::BloodGroup_II),
	BloodGroup(BloodGroup::BloodGroup_III),BloodGroup(BloodGroup::BloodGroup_IV)};

class Person
{
public:
    enum _BloodGroup { BloodGroup_I,BloodGroup_II, BloodGroup_III, BloodGroup_IV};
private:
	_BloodGroup BloodGroup;
public:


 Person()
	{
	}
	void SetBloodGroup(_BloodGroup BG)
	{
		BloodGroup = BG;
	}
	_BloodGroup GetBloodGroup()
	{
		return BloodGroup;
	}
};


void mainTypeCodeWithClass()
{
	Person p;
	p.SetBloodGroup(Person::BloodGroup_I);
}

