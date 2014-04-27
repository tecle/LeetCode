#include "myhead.h"
/*
找到第k大的数
目前看来
最好的解法是利用容量为k的极小堆来实现
*/

class findKth{
public:
	findKth(){}
	~findKth(){}
	void find(vector<int > &v, int k){
		way1(v,k,0,v.size()-1);
	}
private:
	void way1(vector<int> &v,int k,int first,int last){
		cout<<"~1:"<<k<<","<<last<<endl;
		//观察者必须选择随机选择一个数据模式，否则会出现退化，导致找不到答案
		//这里需要完善
		int watcher=v[last];
		cout<<"~2"<<endl;
		int i=first,end=-1;
		//完成后，大于watcher的在[first,end]之间
		while(i<=last){
			if(v[i]>=watcher){
				end++;
				std::swap(v[end],v[i]);
			}
			i++;
		}
		//没有出现交换现象，也就是说这是一个退化现象，需要重新来一次
		if(end==-1){
			way1(v,k,first,last);
		}
		else if(end+1==k){
			//找到结果，输出
			for(int ii=first;ii<=end;ii++)
				cout<<v[ii]<<endl;
		}
		else if(end+1<k){
			for(int ii=first;ii<=end;ii++)
				cout<<v[ii]<<endl;
			//找到了前end+1个结果，还差前k-end-1个结果
			way1(v,k-end-1,end+1,last);
		}else{
			way1(v,k,first,end);
		}
		
	}
};
int parent(int i){
	return (i-1)/2;
}
int left(int i){
	return 2*i+1;
}
int right(int i){
	return 2*i+2;
}
//极小堆
void heap(vector<int> &v,int i){
	int min=i;
	int l=left(i),r=right(i);
	//左子树小于父节点，记录它
	if(l<v.size() && v[l] < v[min]){
		min = l;
		}
	//右子树小于最小节点，记录它
	if(r<v.size() && v[right(i)] < v[min]){
		min = r;
	}
	//已经是极小堆
	if(min==i)
		return;
	std::swap(v[min],v[i]);
	//沿着最小节点下降
	heap(v,min);
}
void buildHeap(vector<int> &v){
	int len=v.size();
	for(int i=len/2-1;i>=0;i--)
		heap(v,i);
}
void insert(vector<int > &v,int n){
	if(n<=v[0])
		return;
	v[0]=n;
	heap(v,0);

}
void findMaxK(vector<int>&v, int k){
	vector<int> ans(k);
	for(int i=0;i<k;i++)
		ans[i]=v[i];
	buildHeap(ans);
	//开始插入
	for(int i=k;i<v.size();i++){
		insert(ans,v[i]);
	}
	for(auto &ele:ans)
		cout<<ele<<" ";
	cout<<endl;
}

int main(){
	vector<int> v={10,5,4,6,2,1,7,3,8,9};
	findMaxK(v,9);
	findKth f;
	f.find(v,9);
}



