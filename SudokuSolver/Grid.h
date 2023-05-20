#pragma once
#include<string>
#include<fstream>
#include<math.h>
class Grid {
public:
	int* grid=new int[81];
	Grid() {
		std::ifstream indata("Matriz.txt");
		for (auto i = 0; i < 9; i++) {
			for (auto j = 0; j < 9; j++) 
				indata >> grid[j + i * 9];}
	}
	
	void Print() const;
	//GetElements
	const int* GetColumna(const int& x)const;	
	const int* GetRenglon(const int& y) const;
	const int* GetGrid( int x) const;
	//Find Functions
	bool IsValid(const int x,const int y ,const int realx, int key);
};


void Grid::Print() const {
	for (auto i = 0; i < 9; i++) {
		for (auto j = 0; j < 9; j++)
			std::cout << grid[j+i*9] << " ";
		std::cout << " " << std::endl;
	}
}

const int* Grid::GetColumna(const int& x)const {
	int* columna = new int[9];
	for (auto i = 0; i < 9; i++) {
		columna[i] = grid[x + 9 * i];
	}
	return columna;
}

const int* Grid::GetRenglon(const int& y)const {
	int* renglon = new int[9];
	for (auto i = 0; i < 9; i++)
		renglon[i] = grid[y*9 + i]; 
	return renglon;
}

const int* Grid::GetGrid(int x)const {
	int coord =(int) floor(x/3)*3;
	int* Lgrid = new int[9];
	if (coord % 27 > 6 && coord % 27 < 18)
		coord -= 9;
	else if(coord%27>=18) coord -= 18;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Lgrid[j + i * 3] = grid[coord + (i * 9 + j)];
			
		}
	}
	
	return Lgrid;
}

bool Grid::IsValid(const int x,const int y,const int realx, int key) {
	for (int i = 0; i < 9; i++) {
		if (GetColumna(x)[i] == key) {
			return false;
		}
		if (GetRenglon(y)[i] == key) {
			return false;
		}
		if (GetGrid(realx)[i] == key) {
			return false;
		}
	}	
		return true;
}
