#include<iostream>
using namespace std;

void deal(int num[],int size){
	int max=0,maxP=-1;
	int cnt;
	for(int i=0;i<size;i++){
		cnt=0;
		
		for(int j=i+1;j<size;j++)
			if(num[i]>num[j])
				cnt++;
	
	}

}
