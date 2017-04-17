#include "StringCalc.h"
#include <vector>
#include <algorithm>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
	vector<char> k;
	vector<string> a;
	string::iterator i;
	string::iterator j;
	if (numbers[0] == '/' && numbers[1] == '/' )
	{
		
		for (string::iterator z = numbers.begin() + 2; z != numbers.end(); z++)
			if (*z == '\n')
			{
				i = ++z;
				break;

			}
			else
				k.push_back(*z);
	}
	else
	{
		k.push_back(',');
		i = numbers.begin();
	}
	
		while (i != numbers.end())
	{
		i = find_if(i, numbers.end(), [=](char s) {return find(k.begin(), k.end(), s) == k.end(); });
		j = find_if(i, numbers.end(), [=](char s) {return find(k.begin(), k.end(), s) != k.end(); });
		if (i != numbers.end())
		{
			a.push_back(string(i, j));
			i = j;
		}
	}
	int result = 0;
	for (string s : a)
	{
		int x = atoi(s.c_str());
		if (x > 0)
		{
			result += x;
		}
		else
			return -1;
	}
	return result;
}
