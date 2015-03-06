#ifndef CONSOLEFUNCTIONS
#define CONSOLEFUNCTIONS

#include <string>
#include <iostream>
#include "Flags.h"

const static void ConsolePrintSuccess(std::string p_message)
{
	if (FLAG_DEBUG == 1)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		std::cout << "[SUCCESS] : " << p_message << std::endl;

		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

const static void ConsolePrintErrorAndQuit(std::string p_message)
{
	if (FLAG_DEBUG == 1)
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
}

const static void ConsolePrintError(std::string p_message)
{
	if (FLAG_DEBUG == 1)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);

		std::cout << "[FAILURE] : " << p_message << std::endl;

		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

const static void ConsolePrintText(std::string p_message)
{
	if (FLAG_DEBUG == 1)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		std::cout << "[CONSOLE] : " << p_message << std::endl;
	}
}

const static void ConsolePrintRequest(std::string p_message)
{
	if (FLAG_DEBUG == 1)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		std::cout << "[REQUEST] : " << p_message << std::endl;

		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

const static void ConsoleSkipLines(int p_numberOfLines)
{
	if (FLAG_DEBUG == 1)
	{
		for (int i = 0; i < p_numberOfLines; i++)
		{
			std::cout << std::endl;
		}
	}
}
#endif