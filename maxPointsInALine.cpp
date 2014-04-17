#include<iostream>
#include<map>
#include<vector>
#include<limits>
using namespace std;
struct Points{
	int x;
	int y;
	Points():x(0),y(0){}
	Points(int x0,int y0):x(x0),y(y0){}
};

class Solution{
public:
	int f(vector<Points> &p){
		int len=p.size();
		int max,maxP,samePoint;
		maxP=0;
		map<double,int> times;
		for(int i=0;i<len;i++){
			times.clear();
			samePoint=0;
			cout<<"----------------"<<i<<endl;
			for(int j=i+1;j<len;j++){
				if(p[i].x==p[j].x && p[i].y==p[j].y)
					samePoint++;
				else{
					if((p[i].x-p[j].x)==0){
				        times[numeric_limits<double>:: max()]++;
				    }
					else{
					    times[1.0*(((double)p[i].y-p[j].y)/(p[i].x-p[j].x))]++;
						cout<<((double)p[i].y-p[j].y)/(p[i].x-p[j].x)<<endl;    
					}
				}
			}
			int max=1;
			for(const auto &m: times)
				if(max<m.second+1)
					max=m.second+1;
			max+=samePoint;
			if(maxP<max)
				maxP=max;
		}
		return maxP;
	}
};
int main(){
	Solution s;
	vector<Points *> v={new Points(84,250),new Points(0,0),new Points(1,0),new Points(0,-70),new Points(0,-70),new Points(1,-1),new Points(21,10),new Points(42,90),new Points(-42,-230)};
	vector<Points> v0;
	for(int i=0;i<v.size();i++)
		v0.push_back(*v[i]);
	cout<<s.f(v0)<<endl;
	return 1;
}


