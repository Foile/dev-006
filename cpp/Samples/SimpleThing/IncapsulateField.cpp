class Foo
{
private: 
	int Secret;
public:
	void SetSecret(int value)
	{
		Secret = value;
	}
	int GetSecret()
	{
		return Secret;
	}
};