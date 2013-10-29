#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct point{int x; int y;};

int sqDist(point a, point b){return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);}


void checkSquare(char* inputName) {
	char* inputName2 = "inputFile.txt";
	FILE * inputFile = fopen(inputName2,"r");
	if(inputFile){
		point a , b , c , d , center;
		while(fscanf(inputFile, "( %d, %d), (%d,%d), (%d,%d), (%d,%d)\n", &a.x , &a.y , &b.x, &b.y , &c.x, &c.y , &d.x , &d.y) == 8){
			int length[6];
			string output = "true";
			length[0] = sqDist(a,b); length[1] = sqDist(a,c); length[2] = sqDist(a,d);
			length[3] = sqDist(b,c); length[4] = sqDist(b,d); length[5] = sqDist(c,d);
			int side = min(length[0], min(length[1], length[2])), diag = max(length[0], max(length[1], length[2]));
			if(diag != 2 * side){output = "false";}
			for(int k = 0; k < 6; k++){if(length[k] != side && length[k] != diag){output = "false";}}
			cout << output << endl;
		}
		fclose(inputFile);
	}
}

int main (int argc, char * const argv[]) {
	checkSquare(argv[1]);
	return 0;
}
