#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool isOrder(vector<int> &vi,vector<int> &vo){
	int leni=vi.size(),leno=vo.size();
	int i=0,j=0;
	bool ans=false;
	if(leni==0&&leno==0)
		return false;
	stack<int> data;
	while(j<leno){
		//cout<<i<<","<<j<<endl;
		while(data.size()==0 || data.top()!=vo[j]){
			if(i>=leni)
				break;
			//cout<<"push->"<<vi[i]<<endl;
			data.push(vi[i]);
			i++;
		}
		//cout<<"top:"<<data.top()<<",now:"<<vo[j]<<endl;
		//if top element in stack is not equal to vo[j]
		if(data.top()!=vo[j])
			break;
		
		data.pop();
		j++;
	}
	if(data.size()==0 && i==leni)
		ans= true;

	return ans;
}
int main(){
	vector<int> vin;
	vector<int> vout;
	int nums,i,tmp;
	while(cin>>nums){
		vin.clear();
		vout.clear();
		for(i=0;i<nums;i++){
			cin>>tmp;
			vin.push_back(tmp);
		}
		for(i=0;i<nums;i++){
			cin>>tmp;
			vout.push_back(tmp);
		}		
		if(isOrder(vin,vout))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
