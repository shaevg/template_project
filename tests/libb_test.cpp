#include <boost/test/unit_test.hpp>
#include "libB/libb.h"

BOOST_AUTO_TEST_SUITE(libB_test_suite)

BOOST_AUTO_TEST_CASE(libB_test1)
{
	int x = 1;
	int y = 2;
	BOOST_REQUIRE_EQUAL(libB::method(x, y), x - y);
}

BOOST_AUTO_TEST_CASE(libB_test2)
{
	int x = 4;
	int y = 2;
	BOOST_REQUIRE_EQUAL(libB::method(x, y), x - y);
}

BOOST_AUTO_TEST_SUITE_END()
