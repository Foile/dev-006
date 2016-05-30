#include <gtest/gtest.h>
#include "Movie.h"
TEST(SampleTestCase, FirstTest)
{
	Movie *movie = new Movie("Rio2", Movie::NEW_RELEASE);
	EXPECT_STREQ("Rio2", movie->getTitle()) << "Bad film name";
	EXPECT_EQ(Movie::NEW_RELEASE, movie->getPriceCode());
}
