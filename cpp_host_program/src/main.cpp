#include <Windows.h>
#include <iostream>
#include <csignal>
#include <cstdlib>

#define DLLNAME "MyRustDLL.dll"
#define PRELOAD

int test()
{
	HMODULE dll = LoadLibraryA(DLLNAME);
	if (!dll)
		return -1;

	//Attempt to load get_number() from the DLL
	using pfn_get_number = int (*)();
	auto get_number = reinterpret_cast<pfn_get_number>(GetProcAddress(dll, "get_number"));

	if (!get_number)
		return -2;

	const int result = get_number();

	FreeLibrary(dll);
	return result;
}


int main(int, char**)
{
#ifdef PRELOAD
	HMODULE preload = LoadLibraryA(DLLNAME);
#endif

	signal(SIGTERM, [](int) { std::exit(0); });
	while (true)
	{
		std::cout << "Will attempt to load DLL, call get_number from it. Try to debug me!\n";
		std::cin.get();

		switch(const auto result = test())
		{
		case -1:
			std::cout << "Failed to load the DLL\n";
			break;
		case -2:
			std::cout << "Failed to get fucntion from dll\n";
			break;
		case 42:
			std::cout << "Got 42, the only answer we needed.\n";
			break;
		default:
			std::cout << "We got a value we did not expect : " << result << "\n";
		}
	}

	return 0;
}