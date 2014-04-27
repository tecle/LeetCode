#include"myhead.h"

bool isError=false;
int rightMerge(int *A,int size){
	isError=false;
	if(A==NULL || size <= 0){
		isError=true;
		return 0;
	}
	int last=size;
	bool haveMerged=false;
	for(int i=size-1;i>=0;i--){
		if(A[i]!=0 && last == size){
			std::swap(A[i],A[--last]);
		}else if(A[i]!=0 && A[last] == A[i]){
			if(!haveMerged){
				A[last]*=2;
				A[i]=0;
				haveMerged=true;
			}else{
				A[--last]=A[i];
				A[i]=0;
				haveMerged=false;
			}
		}else if(A[i]!=0){
			std::swap(A[i],A[--last]);
			haveMerged=false;
		}
	}
	return last;
}
int leftMerge(int *A,int size){
	isError=false;
	if(A==NULL || size <=0){
		isError=true;
		return 0;
	}
	int last=-1;
	bool haveMerged=false;
	for(int i=0;i<size;i++){
		if(A[i]!=0 && last == -1){//初始情况
			std::swap(A[i],A[++last]);
		}else if(A[i]!=0 && A[last]==A[i]){//相等情况
			if(!haveMerged){//相等且前面的数没有被合并
				A[last]*=2;
				A[i]=0;
				haveMerged=true;
			}else{//相等但是是合并后的结果
				A[++last]=A[i];
				A[i]=0;
				haveMerged=false;
			}
		}else if(A[i]!=0){//不相等
			std::swap(A[i],A[++last]);
			haveMerged=false;
		}

	}
	return size-last-1;
}
int upMerge(int *A,int row,int col){
	int last=-1;
	bool haveMerged=false;
	for(int i=0;i<row;i++){
		int &a=*(A+i*row);//cout<<"a:"<<a<<endl;
		if( a != 0 && last == -1){	
			last++;
			std::swap(*A,a); 
		}else if( a != 0 && *(A+last)==a){
			if(!haveMerged){
				(*(A+last)) *= 2;
				a=0;
				haveMerged=true;
			}else{
				last+=col;
				std::swap(*(A+last),a);
				
				haveMerged=false;
			}
		}else if(a!=0){
			last+=col;
			std::swap(*(A+last),a);
			haveMerged=false;
		}
	}
	return 0;
}
int downMerge(int *A,int row,int col){
	int last=row*col;
	bool haveMerged=false;
	for(int i=row-1;i>=0;i--){
		int &a=*(A+i*row);//cout<<"a:"<<a<<endl;
		if( a != 0 && last == -1){	
			last -= col;
			std::swap(*(A+last),a); 
		}else if( a != 0 && *(A+last)==a){
			if(!haveMerged){
				(*(A+last)) *= 2;
				a=0;
				haveMerged=true;
			}else{
				last -= col;
				std::swap(*(A+last),a);
				haveMerged=false;
			}
		}else if(a!=0){
			last -= col;
			std::swap(*(A+last),a);
			haveMerged=false;
		}
	}
	return 0;
}
#define ROW 4
#define COL 4
void coutArray(int *a){
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++)
			printf("%4d ",*(a+i*COL+j));
		cout<<endl;
	}
}
void move(int *A,int dir){
	if(dir==1)
		for(int i=0;i<ROW;i++)
			leftMerge(A+i*COL,COL);
	else if(dir==2)
		for(int i=0;i<ROW;i++)
			rightMerge(A+i*COL,COL);
	else if(dir == 3)
		for(int i=0;i<COL;i++)
			upMerge(A+i,ROW,COL);
	else if(dir == 4)
		for(int i=0;i<COL;i++)
			downMerge(A+i,ROW,COL);
}
void fillNumber(int *A){
	bool haveZero=false;
	for(int i=0;i<ROW*COL;i++)
		if(*(A+i)==0){
			haveZero=true;
			break;
		}
	if(!haveZero)
		return;
	
	int total=ROW*COL;
	int num=2;//生成的数的大小
	//生成随机的数
	while(true){
		srand((unsigned)time(0));
		int offset=rand()%total;
		if(*(A+offset)==0){
			*(A+offset)=num;
			return;
		}else{
			//横向查找为空的位置
			for(int i=0;i<total;i++)
				if(*(A+(offset+i)%total)==0){
					*(A+(offset+i)%total)=num;
					return;
				}
		}
	}
}
int main(){
	int row=ROW;
	int A[ROW][COL]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int tmp;
	fillNumber(&A[0][0]);
	
	coutArray(&A[0][0]);
	//cout<<"zero:"<<rightMerge(&A[0][0],ROW)<<endl;
	cout<<endl<<"使用W,A,S,D来选择上,左,下,右:";
	char dir;
	while(cin>>dir){
		switch(dir){
			case 'A':case'a':tmp=1;break;
			case 'D':case'd':tmp=2;break;
			case 'W':case'w':tmp=3;break;
			case 'S':case's':tmp=4;break;
			default:tmp=5;cout<<"错误的操作！"<<endl;continue;
		}
	//	cout<<tmp<<endl;
		move(&A[0][0],tmp);
		fillNumber(&A[0][0]);
		cout<<endl;	
		coutArray(&A[0][0]);
		//cout<<endl;
		cout<<endl<<"使用W,A,S,D来选择上,左,下,右:";
	}
}
