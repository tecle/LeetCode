#include<iostream>
#include<stdlib.h>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<limits.h>
#include<math.h>
using namespace std;

int main(){
	int i,j=0;
	float k;
	cin>>i;
	int ans;
	string str1,str2,str3;
	float offset=INT_MAX;
	while(i--){
		cin>>str1;
		cin>>str2;
		cin>>str3;
		float result;
		if(str2=="+"){
			result=atoi(str1.c_str())+atoi(str3.c_str());
		}else if(str2=="-"){
			result=atoi(str1.c_str())-atoi(str3.c_str());
		}else if(str2=="*"){
			result=atoi(str1.c_str())*atoi(str3.c_str());
		}else{
			result=((float)atoi(str1.c_str()))/atoi(str3.c_str());
		}
		k=result-9;
		if(k<0) k=-k;
		if( k < offset){
			ans=j;
			offset=k;
		}
		j++;
	}
	cout<<ans+1<<endl;

	return 0;
}
