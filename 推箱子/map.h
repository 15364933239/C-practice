#pragma once
typedef int Status;
typedef int ElemType;
class map
{
public:
	Status RandomMaze(int n, int m);
	Status PrintMaze(int n);
public:
	int mazemap[20][20];
};
