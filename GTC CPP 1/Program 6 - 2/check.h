#pragma once
#include <iostream>
#include <string>

std::string check(float b, float d)
{
	if (b * 0.25 >= d)
	{
		return "Blocked";
	}
	else if (b * 0.40 >= d > b * 0.25)
	{
		return "Limbo";
	}
	else if (b * 0.65 >= d > b * 0.40)
	{
		return "Crawl";
	}
	else if (b * 1.05 >= d > b * 0.65)
	{
		return "Duck";
	}
	else if (b * 1.25 >= d > b *1.05)
	{
		return "Walk";
	}
	else if (d > b * 1.25)
	{
		return "Stilts";
	}
	else
	{
		return "Error";
	}
}