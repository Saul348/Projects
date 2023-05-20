#include<iostream>
#include<fstream>
template<int cols, int reng>
class Grid {
private:
	int grid[reng][cols];
	std::ifstream indata;
public:
	Grid() {
		OpenFile();
		for (auto i = 0; i < reng; i++) {
			for (auto j = 0; j < cols; j++)
				indata >> grid[i][j];
		}
	}
	//Open the File
	void OpenFile();
	void Print() const;
	//GetElements
	const int* GetColumna(const int& x)const;
	const int* GetRenglon(const int& y) const;
	int* GetRec(const int& x,const int &y);
	//Auxiliar Funtions
	int* GetCoord( int x,  int y);
	//Find Functions
	bool IsValid(int x, int y, int key);

};
template<int cols, int reng>
 void Grid<cols, reng>::OpenFile() {
	indata.open("Matriz.txt");
	if (!indata)
		std::cout << "No se pudo abrir el archivo" << std::endl;
	else std::cout << "Se abrio el archivo" << std::endl;
}
template<int cols, int reng>
 void Grid<cols, reng>::Print() const{
	for (auto i = 0; i < reng; i++) {
		for (auto j = 0; j < cols; j++)
			std::cout<<grid[i][j]<<" ";
		std::cout<<" "<<std::endl;
	}
}
template<int cols, int reng>
 const int*Grid<cols, reng>::GetColumna(const int& x)const {
	int* columna= new int[reng];
	for (auto i = 0; i < reng; i++) columna[i] = grid[i][x];
	return columna;}
template<int cols, int reng>
 const int* Grid<cols, reng>::GetRenglon(const int& y)const {
	 int* renglon=new int[cols];
	 for (auto i = 0; i < cols; i++) renglon[i] = grid[y][i];
	 return renglon;
 } 
 template<int cols, int reng>
	 int* Grid<cols, reng>::GetCoord(int x,  int y) {
		 int* coords=new int[2];
		 for (auto i = 0; i < 3; i++) {
			 x % 3 != 0 ? x--:coords[0] = x;
			 y % 3 != 0 ? y-- : coords[1] = y;
		 }
		return coords;
	 }
 template<int cols, int reng>
 int* Grid<cols, reng>::GetRec(const int& x, const int& y){
	 int* rect = GetCoord(x, y);
	 int* LittleGrid=new int[9];
	  for (int i = 0; i < 3; i++) {
		  for (int j = 0; j < 3; j++) {
			  LittleGrid[j + (i * 3)] = grid[i+rect[1]][j+rect[0]];
		  }
	  }
	  delete[] rect;
	  return LittleGrid;
 }
 template<int cols, int reng>
 bool Grid<cols, reng>::IsValid(const int x, const int y, int key){
	 for (int i = 0; i < reng; i++) {
		 if (GetColumna(x)[i] == key) {
			 std::cout << "Invalido";
			 return false;
		 }
		 if (GetRenglon(y)[i] == key) {
			 std::cout << "Invalido";
			 return false;
		 }
	 }
	 for (int i = 0; i < 9; i++) {
		 if (GetRec(x, y)[i] == key) {
			 std::cout << "Invalido";
			 return false;
		 }
	 }
	 std::cout << "Es valido";
	 return true;
}



int main() {
	Grid<9, 9> NewGrid;	
	NewGrid.IsValid(8, 3, 6);
}