#include <iostream>
#include <iomanip>

int main()
{
	const int arrSize = 10;
	int posY = 0, posZ = 0, posX = 0;
	int arrY[arrSize], arrZ[arrSize], arrX[arrSize];

	for (posY = 0; posY <= arrSize; ++posY)
	arrY[posY] = 
	{
		for (posZ = 0; posZ < arrSize; ++posZ)
		{
			for (posX = 0; posX <= arrSize; ++posX)
			{

			}
		}
	}
}

//for f = 1, floors do
	//grid[f] = {}
		//for c = 1, columns do
		//grid[f][c] = {}
			//for r = 1, rows do
			//local part
			//local call
			//-- Based on y and %Chance, decide a block type chosen
			//part = decide(part, f, chance)
			//--Size, Position, Anchor, and grab name block
			//part.Size = Vector3.new(size, size, size)
			//part.Position = Vector3.new((size * r) - 1, -(size * f) + 4, (size * c) - 1)
			//part.Anchored = true
			//call = tostring(part)
			//--Based on the current stage of generation, assign a part to a specific index to allow navigation to it
			//grid[f][c][r] = part
			//part.Name = "[" ..f .. "][" ..c .. "][" ..r .. "]" ..call
			//part.Parent = miningArea
			//blocksGenned = blocksGenned + 1
			//genPercent = ((blocksGenned / totalBlocks) * 100)
			//if genPercent == math.floor(genPercent) then
			//print(tostring(genPercent) .. " percent of the mine generated.")
			//end
		//end
	//end
	//wait()
//end
