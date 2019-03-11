#pragma once

bool BinarySearch(int array[], int searchVal, int arrSize, int& position)
{
	int first = 0,
		last = arrSize - 1,
		middle;

	while (true)
	{
		middle = (first + last) / 2;
		if (array[middle] == searchVal)
		{
			position = middle + 1;
			return true;
		}
		else if (last != first)
		{
			if (array[middle] > searchVal)
			{
				last = middle - 1;
			}
			else
				first = middle + 1;
		}
		else
		{
			return false;
		}
	}
}
