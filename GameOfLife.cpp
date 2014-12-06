#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


std::vector<std::string> simulateIteration(std::vector<std::string> state){

    std::vector<std::string> output(state);
    if(state.size() == 0){return state;}
    int R = state.size();
    int C = state[0].size();
    for(int row = 0; row < R; row++){
        for(int col = 0; col < C; col++){

            int count = 0;
            if(row > 0      && state[row - 1][col] == '*'){++count;}
            if(row < R - 1  && state[row + 1][col] == '*'){++count;}
            if(col > 0      && state[row][col - 1] == '*'){++count;}
            if(col < C - 1  && state[row][col + 1] == '*'){++count;}
            if(row > 0     && col > 0     && state[row - 1][col - 1] == '*'){++count;}
            if(row > 0     && col < C - 1 && state[row - 1][col + 1] == '*'){++count;}
            if(row < R - 1 && col > 0     && state[row + 1][col - 1] == '*'){++count;}
            if(row < R - 1 && col < C - 1 && state[row + 1][col + 1] == '*'){++count;}

            if(count < 2 || count > 3){output[row][col] = '.';}
            else if(count == 3){output[row][col] = '*';}
        }
    }

    return output;
}



void GameOfLife(char * inputName) {

    const int N = 10;
    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
        std::vector<std::string> grid;
		while(getline(inputFile,line)){grid.push_back(line);}
        for(int p = 0; p < N; p++){grid = simulateIteration(grid);}
        for(int p = 0; p < grid.size(); p++){std::cout << grid[p] << std::endl;}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	GameOfLife(argv[1]);
	return 0;
}
