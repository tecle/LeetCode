#include"myhead.h"
class Nixudui{
	public:
		int cnt;
		vector<int> tmp;
		int deal(vector<int> &v){
			cnt=0;
			sort(v,0,v.size()-1);
			return cnt;
		}
		void prtVt(vector<int> &v,string str){
			cout<<str;
			for(int &ele:v)
				cout<<ele<<" ";
			cout<<endl;
		}
		void merge(vector<int> &v,int h1,int t1,int h2,int t2){
			int p1=t1,p2=t2;
			int index=0;
			tmp.clear();
			while(p1>=h1 && p2>=h2){
				//467 235
				while(v[p1] > v[p2]){
					cnt+=(p2-h2+1);
					cout<<"push:"<<v[p1]<<endl;
					tmp.push_back(v[p1]);
					p1--;
					index++;
				}
				//235 467
				while(v[p1] < v[p2]){
					cout<<"push:"<<v[p2]<<endl;
					tmp.push_back(v[p2]);
					p2--;
					index++;
				}
			}
			prtVt(tmp,"tmp:");
			//456 123
			if(p1<h1){
				while(p2>=h2){
					tmp.push_back(v[p2]);
					p2--;
					index++;
				}
			}
			//123 456
			if(p2<h2){
				while(p1>=h1){
					tmp.push_back(v[p1]);
					p1--;
					index++;
				}
			}
			index=0;
			for(int i=t2;i>=h1;i--){
				v[i]=tmp[index];
				index++;
			}
		}
		void sort(vector<int> &v,int head,int tail){
			if(head>=tail)
				return;
			int mid=(head+tail)/2;
			sort(v,head,mid);
			sort(v,mid+1,tail);
			merge(v,head,mid,mid+1,tail);
			for(auto &ele:v)
				cout<<ele<<" ";
			cout<<endl;
		}

};

int main(){
	vector<int> test;
	int num;
	Nixudui nxd;
	test.clear();
	while(cin>>num){
		if(num==-1){
			cout<<nxd.deal(test)<<endl;
			return 0;
		}
		test.push_back(num);
	}
	
	
}
