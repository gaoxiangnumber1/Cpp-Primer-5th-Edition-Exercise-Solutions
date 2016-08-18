#include <cstdio>

int main(int argc, char **argv)
{
	for(int index = 0; index < argc; ++index)
	{
		printf("argv[%d]: %s\n", index, argv[index]);
	}

	return 0;
}
