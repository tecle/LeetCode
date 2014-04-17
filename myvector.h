#ifndef MYVECTOR
#define MYVECTOR
#include<iostream>
#include<vector>
using namespace std;
void printvi(const std::vector<int> &v){
	for(int i=0;i<v.size()-1;i++){
		std::cout<<v[i]<<",";
	}
	if(v.size()>0)
		std::cout<<v[v.size()-1]<<std::endl;
	else
		std::cout<<"Empty Vector!"<<std::endl;
}
void printvc(const vector<char> &v){
	for(int i=0;i<v.size()-1;i++){
		cout<<v[i]<<",";
	}
	if(v.size()>0)
		cout<<v[v.size()-1]<<endl;
	else
		cout<<"Empty Vector!"<<endl;
}
void printvs(const vector<char> &v){
	for(int i=0;i<v.size()-1;i++){
		cout<<v[i]<<",";
	}
	if(v.size()>0)
		cout<<v[v.size()-1]<<endl;
	else
		cout<<"Empty Vector!"<<endl;
}


#endif
