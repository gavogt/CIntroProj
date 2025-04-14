#include "cyborg.h"

const char* GetAge(int age)
{
	if (age < 18)
	{
		return "you are a minor";
	}
	else if (age < 65)
	{
		return "you are an adult";
	}
	else
	{
		return "you are a senior citizen";
	}
}