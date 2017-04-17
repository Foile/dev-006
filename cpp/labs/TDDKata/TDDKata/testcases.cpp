#include "gtest/gtest.h"
#include "StringCalc.h"

using ::testing::TestWithParam;
using ::testing::Values;
using namespace std;

class ParametrizedTest : public TestWithParam < std::tr1::tuple<std::string, int> >
{

};

TEST_P(ParametrizedTest, stringCalcTest)
{
	string expression = std::tr1::get<0>(GetParam());
	int expected = std::tr1::get<1>(GetParam());
	
	StringCalc c;
	int actual = c.Add(expression);
	ASSERT_EQ(actual, expected);
}

INSTANTIATE_TEST_CASE_P(TDDKata, ParametrizedTest, testing::Values(
	make_tuple("1,2", 3),
	make_tuple("1", 1),
	make_tuple("", 0),
	make_tuple("25,2", 27),
	make_tuple("2,3,4,5", 14),
	make_tuple("-2,3", -1),
	make_tuple("-2", -1),
	make_tuple("//;\n2;3",5),
	make_tuple("//*%\n1%2*2",5)
	));