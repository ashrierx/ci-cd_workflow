/*
Ashley Judah
test file
adds test for filled out functions
*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}

}

TEST_CASE("splitting a string", "[Split]")
{
	REQUIRE( Split("This is a string", ' ') == std::vector<std::string>{"This", "is", "a", "string"});
}

TEST_CASE("remove string2 from string1", "[RemoveAllSubstrings]")
{
	REQUIRE( RemoveAllSubstrings("Why hello there, stranger", "Oh hey there, sir") == std::string("Why hello stranger"));
};

TEST_CASE("Match the vectors", "[MatchVectors]")
{
	REQUIRE( MatchVectors(std::vector<int>{1, 2, 3, 4}, std::vector<int>{3, 4, 5, 6}) == std::vector<int>{1, 2});
}

TEST_CASE("return 1 or -1", "[Sign]")
{
	REQUIRE( Sign(2.0) == 1.0);
	REQUIRE( Sign(-2.0) == -1.0);
	CHECK( Sign(0.0) == 0.0);
}

TEST_CASE("sum all nums in a vector", "[Sum]")
{
	REQUIRE( Sum(std::vector<int>{1, 2, 3}) == 6);
}
