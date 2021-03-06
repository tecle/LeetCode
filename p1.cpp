#include<iostream>
#include<string>
#include<map>
using namespace std;


void deal(string &str){
	int slen=str.size();
	int store[256]={0};
	map<char,int> st;
	int i=0;
	for(i=0;i<slen;i++){
		if(str[i]<'0' || (str[i]>'9' && str[i]<'a') || str[i]>'z'){
			cout<<"<invalid input string>"<<endl;
			return;
		}
		store[str[i]]++;
		st[str[i]]++;
	}
	bool stop=false;
	string ans="";
	while(!stop){
		stop = true;
		//travel once
		for(i=0;i<10;i++){
			if( st[i+'0'] >0 ){
				ans.append(1,i+'0');
				st[i+'0']--;
				stop=false;
			}
		}
		for(i=0;i<26;i++){
			if( st[i+'a'] >0 ){
				ans.append(1,i+'a');
				st[i+'a']--;
				stop=false;
			}
		}
	}
	cout<<ans<<endl;

}
/*for(i=0;i<256;i++){
			if(store[i]>0){
				cout<<i<<endl;
				ans.append(1,(char)i);
				store[i]--;
				stop =false;
			}
		}*/

int main(){
	string str;
	while(getline(cin,str)){
		deal(str);
	}
	return 0;
}
