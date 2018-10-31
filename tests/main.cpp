#include <iostream>

#define UNUSED(x) (void)(x)

int main(int argc, char **argv)
{
	std::cout << "Running test program..." << std::endl;
	UNUSED(argc);
	UNUSED(argv);
	return 0;
}

