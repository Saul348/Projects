#include<iostream>
#include"Grid.h"
void Solver(Grid NewSudoku) {
	int LastPos = -1, index = 1, buffer[81]{ -1 };
		for (int k = 0; k < 81; k++) {
		
			for (int i = index; i <=10; i++) {
				if (i == 10) {
					NewSudoku.grid[k]=0;
					k -= 2;
					if (k < 80) {
						while (k + 1 == buffer[k + 1])
							k--;
					}
					LastPos = k+1;
					index = NewSudoku.grid[LastPos]+1;
					break;
				}
				 if (NewSudoku.grid[k] == 0 || LastPos == k) {
					if (NewSudoku.IsValid(k % 9,floor(k/9),k,i)) {
						NewSudoku.grid[k] = i;
						index = 1;
						break;
					}
				}
				 else { buffer[k] = k; break; }
			}
		}
		NewSudoku.Print();
	
}


int main() {
	Grid NewSudoku;
	Solver(NewSudoku);
	
}