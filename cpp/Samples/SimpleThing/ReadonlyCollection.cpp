#include <string.h>
#include <vector>
#include <iostream>
class StorageInt
{
private:
	std::vector<int> Storage;
public:
	void Add(int value)
	{
		Storage.push_back(value);
	}
	std::vector<int>::const_iterator GetVector()
	{
		return Storage.cbegin();
	}

};

int mainReadOnlyCollection()
{
	StorageInt st;
	st.Add(1);
	st.Add(2);

	std::vector<int>::const_iterator i = st.GetVector();
	return 0;
}