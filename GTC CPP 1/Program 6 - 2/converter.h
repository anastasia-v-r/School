#pragma once

void convert(float &height, char type)
{
	if (type == 'c')
	{

	}
	else if (type == 'i')
	{
		height *= 2.54;
	}
	else if (type == 'f')
	{
		height *= (2.54 * 12);
	}
	else if (type == 'y')
	{
		height *= (2.54 * 36);
	}
	else if (type == 'm')
	{
		height *= 100;
	}
}

/*1 inch = 2.54 cm
1 yard = 3 ft
1 foot = 12 inches
1 meter = 100 cm*/