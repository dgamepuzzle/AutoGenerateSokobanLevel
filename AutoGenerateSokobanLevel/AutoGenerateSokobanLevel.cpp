// AutoGenerateSokobanLevel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "State.h"
#include "Map.h"
#include "Solver.h"
int main()
{
	TileType tilesample[49] = {
		Wall, Wall, Wall, Wall, Wall, Wall, Wall,
			Wall, Aid, Floor, Aid, Floor, Aid, Wall,
			Wall, Floor, Box, Box, Box, Floor, Wall,
			Wall, Aid, Box, Character, Box, Aid, Wall,
			Wall, Floor, Box, Box, Box, Floor, Wall,
			Wall, Aid, Floor, Aid, Floor, Aid, Wall,
			Wall, Wall, Wall, Wall, Wall, Wall, Wall,
	};
	TileType * tiles = new TileType[49];
	for (int i = 0; i < 49; i++) {
		tiles[i] = tilesample[i];
	}
	State * state = new State(7,7);
	state->setLevel((TileType *)tiles);
	Map * map = new Map();
	Solver solver(state);
	map->drawMap(state);
	int res = solver.run();
	if (res == -1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		std::wcout << L"无解！！！\n";
	}
	else if(res == 1) {
		solver.drawStep();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		std::wcout << L"恭喜胜利！！！\n";
	}
	/*
	while (!state->ifWin()) {
		map->drawMap(state);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		std::wcout << L"请输入操作：w向上，s向下，a向左，d向右\n";
		char c=getchar();
		getchar();
		if (c == 'w') {
			state->up();
		}
		if (c == 's') {
			state->down();
		}
		if (c == 'a') {
			state->left();
		}
		if (c == 'd') {
			state->right();
		}
	}
	map->drawMap(state);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	std::wcout << L"恭喜胜利！！！\n";
	*/
	delete state;
	delete map;
}