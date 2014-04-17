#include"myhead.h"
#define A_NUM 100
#define B_NUM 10
int A[A_NUM],B[B_NUM];
#define fmax(a,b) (((a-b)>>31)&1==1?b:a)
int *f(int *x, int y){
 	return x+=y;
}
int f(char * a,char *b[]){
	a=new char[15];
	*b=new char[10];
}
void printNum(int num){
	int i=31;
	char a[32];
	while(i>=0){
		a[i]=(num&1)+'0';
		num=num>>1;
		i--;
	}
	for(i=0;i<32;i++)
		cout<<a[i];
	cout<<endl;
}
int editDis(string &s1,string &s2,int i,int j){
        if(i==0)
            return j;
        if(j==0)
            return i;
        int dis1=editDis(s1,s2,i-1,j)+1;
        int dis2=editDis(s1,s2,i,j-1)+1;
        dis1=min(dis1,dis2);
        
        dis2=editDis(s1,s2,i-1,j-1);
        if(s1[i-1]!=s2[j-1])
            dis2+=1;
        return min(dis1,dis2);
    }
int main(){

	string s1,s2;
	while(cin>>s1){
		cin>>s2;
		cout<<editDis(s1,s2,s1.size(),s2.size())<<endl;
	}
	//cout<<a<<endl;
}


