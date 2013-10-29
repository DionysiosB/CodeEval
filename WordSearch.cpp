#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> point;

const int nrows=3,ncols=4;
char data[nrows][ncols]={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

bool findWord(string input,vector<point> visited){
    int length=input.size();
    if(length==0){return 1;}
    if(visited.empty()){
        for(int row=0;row<nrows;row++){for(int col=0;col<ncols;col++){if(input[0]==data[row][col]){
                    visited.clear();visited.push_back(make_pair(row,col));
                    if(findWord(input.substr(1,length),visited)){return 1;}
		}}}
    }
    else{
        point previousPos=visited.back();
        int x=previousPos.first,y=previousPos.second;
		vector<point> nextVec;
		if(x>0 && data[x-1][y]==input[0] && find(visited.begin(),visited.end(),make_pair(x-1,y))==visited.end()){
            nextVec=visited;nextVec.push_back(make_pair(x-1,y));
            if(findWord(input.substr(1,length),nextVec)){return 1;}
        }
        if(x<ncols-1 && data[x+1][y]==input[0]&& find(visited.begin(),visited.end(),make_pair(x+1,y))==visited.end()){
             nextVec=visited;nextVec.push_back(make_pair(x+1,y));
             if(findWord(input.substr(1,length),nextVec)){return 1;}
        }   
        if(y>0 && data[x][y-1]==input[0]&& find(visited.begin(),visited.end(),make_pair(x,y-1))==visited.end()){
			nextVec=visited;nextVec.push_back(make_pair(x,y-1));
            if(findWord(input.substr(1,length),nextVec)){return 1;}
        }
        if(y<ncols-1 && data[x][y+1]==input[0]&& find(visited.begin(),visited.end(),make_pair(x,y+1))==visited.end()){
             nextVec=visited;nextVec.push_back(make_pair(x,y+1));
             if(findWord(input.substr(1,length),nextVec)){return 1;}
        }
    }
    return 0;
}

void wordSearch(char * inputName) {
		string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){while(getline(inputFile,line)){
            vector<point> visitedSet;
			if(findWord(line,visitedSet)){cout <<"True"<<endl;}
			else{cout << "False"<<endl;}
		}
		inputFile.close();
	}
}	

int main (int argc, char * const argv[]) {
	wordSearch(argv[1]);
	return 0;
}
