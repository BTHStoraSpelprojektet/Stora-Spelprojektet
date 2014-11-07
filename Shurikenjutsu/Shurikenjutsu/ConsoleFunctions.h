#ifndef CONSOLEFUNCTIONS
#define CONSOLEFUNCTIONS

#include <string>
#include <iostream>

static void ConsolePrintSuccess(std::string p_message)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::cout << "[SUCCESS] : " << p_message << std::endl;

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

static void ConsolePrintError(std::string p_message)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);

	std::cout << "[FAILURE] : " << p_message << std::endl;

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::cout << "[REQUEST] : Press any key to quit." << std::endl;

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	std::cin.get();
	PostQuitMessage(0);
}

static void ConsolePrintText(std::string p_message)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	std::cout << "[CONSOLE] : " << p_message << std::endl;
}

static void ConsolePrintRequest(std::string p_message)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::cout << "[REQUEST] : " << p_message << std::endl;

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

#endif