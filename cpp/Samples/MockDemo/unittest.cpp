#include <gtest/gtest.h>
#include "FakeWin32ApiImpl.h"
#include "WinApiException.h"
#include "file.h"


#undef STRICT 

using testing::_;
using testing::Expectation;
using testing::Throw;
using testing::Return;

HANDLE h = (void*)5;

class TestSuite : public testing::Test
{
protected:

	FakeWin32ApiImpl impl;
	File *file;
	void SetUp()
	{
		ON_CALL(impl,CreateFile("noname.txt",_,_,_,_,_,_)).WillByDefault(Return(INVALID_HANDLE_VALUE));
		ON_CALL(impl,CreateFile("test.txt",_,_,_,_,_,_)).WillByDefault(Return(h));
		ON_CALL(impl,WriteFile(h,"1234",4,_,_)).WillByDefault(Return(true));
		ON_CALL(impl,CloseHandle(_)).WillByDefault(Return(TRUE));
	    file = new File(&impl);
	}
	void TearDown()
	{
		delete file;
	}
};


TEST_F(TestSuite,CreateFileTest)
{

	ASSERT_THROW(file->Open("noname.txt"),WinApiException);
	ASSERT_NO_THROW(file->Open("test.txt"));
	ASSERT_EQ(h,file->hHandle);
	file->Open("test.txt");
}
TEST_F(TestSuite,WriteFileTest)
{
	ASSERT_NO_THROW(file->Open("test.txt"));

	char Buffer[80];
	EXPECT_CALL(impl,WriteFile(h,Buffer,4,_,_)).Times(1).WillRepeatedly(Return(true));
	file->Write(Buffer,4);

}

int main(int argc,char **argv)
{
	::testing::InitGoogleMock(&argc,argv);
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}