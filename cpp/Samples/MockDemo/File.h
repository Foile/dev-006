#pragma once
#include <Windows.h>
#include "IDiskApi.h"
#include <gtest/gtest_prod.h>
class File
{
private:
	HANDLE hHandle;
	IDiskApi *api;
	friend class TestSuite;
	FRIEND_TEST(TestSuite,CreateFileTest);
public:
	File(IDiskApi *aApi);
	~File(void);
	virtual void Open(char* FileName);
	virtual void Write(char* Buffer, int size);
	virtual void Read(char* Buffer, int size);
};

