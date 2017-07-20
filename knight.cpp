#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
typedef struct
{
	int xpos;
	int ypos;
}Position;
char col;
int row;
int count;
int chess[8][8];
Position start_pos;
Position end_pos;
int target = 0xfffffff;
void Knight(int chess[8][8], Position start_pos, Position end_pos, int count)
{
	if (start_pos.xpos == end_pos.xpos && start_pos.ypos == end_pos.ypos) 
	{
		target = target > count ? count : target;
	}
	if (chess[start_pos.xpos][start_pos.ypos] != 0)
	{
		if (chess[start_pos.xpos][start_pos.ypos] > count)
			chess[start_pos.xpos][start_pos.ypos] = count;
		else return;
	}
	else chess[start_pos.xpos][start_pos.ypos] = count;

	if (start_pos.xpos >= 1 && start_pos.ypos >= 2) 
	{
		start_pos.xpos -= 1; start_pos.ypos -= 2;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos += 1; start_pos.ypos += 2; count--;
	}
	if (start_pos.xpos >= 2 && start_pos.ypos >= 1) 
	{
		start_pos.xpos -= 2; start_pos.ypos -= 1;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos += 2; start_pos.ypos += 1; count--;
	}
	if (start_pos.xpos >= 2 && start_pos.ypos <= 6) 
	{
		start_pos.xpos -= 2; start_pos.ypos += 1;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos += 2; start_pos.ypos -= 1; count--;
	}
	if (start_pos.xpos >= 1 && start_pos.ypos <= 5) 
	{
		start_pos.xpos -= 1; start_pos.ypos += 2;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos += 1; start_pos.ypos -= 2; count--;
	}
	if (start_pos.xpos <= 6 && start_pos.ypos >= 2) 
	{
		start_pos.xpos += 1; start_pos.ypos -= 2;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos -= 1; start_pos.ypos += 2; count--;
	}
	if (start_pos.xpos <= 5 && start_pos.ypos >= 1) 
	{
		start_pos.xpos += 2; start_pos.ypos -= 1;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos -= 2; start_pos.ypos += 1; count--;
	}
	if (start_pos.xpos <= 5 && start_pos.ypos <= 6) 
	{
		start_pos.xpos += 2; start_pos.ypos += 1;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos -= 2; start_pos.ypos -= 1; count--;
	}
	if (start_pos.xpos <= 6 && start_pos.ypos <= 5) 
	{
		start_pos.xpos += 1; start_pos.ypos += 2;
		Knight(chess, start_pos, end_pos, ++count);
		start_pos.xpos -= 1; start_pos.ypos -= 2; count--;
	}
}

int main(void)
{
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			chess[i][j] = 0;
		}
	}

	fstream filein;
	filein.open("knight.inp.txt");
	filein >> col;
	filein >> row;

	start_pos.ypos = col - 97;
	start_pos.xpos = 8 - row;
	filein >> col;
	filein >> row;


	end_pos.ypos = col - 97;
	end_pos.xpos = 8 - row;

	Knight(chess, start_pos, end_pos, count);
	ofstream fileout;
	fileout.open("knight.out.txt", ios_base::out);
	fileout << target << endl;

	return 0;
}
