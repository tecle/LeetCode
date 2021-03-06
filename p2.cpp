#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int cnt;
		int pos;
		void solution(char* str,int length,int k,int n,int m){
			cnt=0;
			pos=k;
			if(f(n,m) < pos || pos<0){
				cout<<"Impossible"<<endl;
				return;
			}
				
			permutation(str,length);
		}
		long long f(int n,int m){
			int mid=max(n,m);
			int i=0;
			long long sum1=1;
			for(i=n+m;i>mid;i--)
				sum1*=i;

			mid=min(n,m);
			for(i=2;i<=mid;i++){
				sum1 /= i;
			}

			return sum1;
		}
		void permutation(char* str,int length)  
		{  
		    sort(str,str+length);  
		    do  
		    {  

	            cnt++;
	            if(cnt==pos){
	            	cout<<str<<endl;
	            }
		    }while(next_permutation(str,str+length));  
		  
		}

};
      
//m : 1
int main(){
	int n,m,k;
	cin>>k;
	int pos;
    int i;  

    Solution s;
	while(k--){
		cin >> n;
		cin >> m;
		cin >> pos;
		char str[m+n+1];  
		for(i=0;i<n;i++)
			str[i]='0';
		for(i=n;i<m+n;i++)
			str[i]='1';
		str[m+n]='\0';
		s.solution(str,m+n,pos,n,m);
	}
}
