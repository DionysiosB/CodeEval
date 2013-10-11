#include <iostream>
using namespace std;

void printMultTable(int n){
	for(int row=1;row<=n;++row){
		for(int col=1;col<=n;++col){
			cout.width(4);cout<<std::right << row*col;
			if(col==n) cout <<endl;
			}
	}
}

int main (int argc, char * const argv[]) {
	printMultTable(12);
	return 0;
}
