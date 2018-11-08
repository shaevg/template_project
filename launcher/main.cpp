#include "libA/liba.h"
#include "libB/libb.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

int main()
{
	int x = 2;
	int y = 3;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "LibA 2:3 = " << libA::method(x, y) << std::endl;
		std::cout << "LibB 2:3 = " << libB::method(x, y) << std::endl;
#if defined (_REGULAR_)
		std::cout << "Regular project" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
#endif
#if defined(_VARIANT_1_)
		std::cout << "Variant1 project" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
#endif
#if defined(_VARIANT_2_)
		std::cout << "Variant2 project" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
#endif
	}

	return 0;
}
