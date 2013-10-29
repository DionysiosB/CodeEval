#include <iostream>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef pair<int,int> point;
 
bool isAccessible(point a) {
	int sum=0,x=abs(a.first),y=abs(a.second);
	while(x) {sum+=x%10;x/=10;}
	while(y){sum+=y%10;y/=10;}
	if(sum<=19) return true;
	return false;
} 
 
int main() {
	map <point,bool> mappedPoints;
	int output=0;
	int offsetX[] = {1,0,-1,0};
	int offsetY[] = {0,1,0,-1};
	queue<point> q;q.push(make_pair(0,0));
 
	while(!q.empty()) {
		point p= q.front();q.pop();
		if(mappedPoints[p]) continue;
		mappedPoints[p]=1;
		if(isAccessible(p)){
			output++;
			for(int j=0;j<4;j++) {
				int nextX= p.first+offsetX[j],nextY= p.second+offsetY[j];
				point currentNeighbor = make_pair(nextX,nextY);
				if(mappedPoints[currentNeighbor]) continue;
				q.push(make_pair(nextX,nextY));
			}
		}
	}
	cout<<output;
}