#include <boost/test/unit_test.hpp>
#include "libA/liba.h"

BOOST_AUTO_TEST_SUITE(libA_test_suite)

BOOST_AUTO_TEST_CASE(libA_test)
{
	int x = 1;
	int y = 2;
	BOOST_REQUIRE_EQUAL(libA::method(x, y), x + y);
}

BOOST_AUTO_TEST_SUITE_END()
