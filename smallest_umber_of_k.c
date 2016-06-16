/*
description：
寻找最小的k个数
有n个数，请找出最小的k个数要求时间复杂度尽可能低。

方法1：全排序  时间复杂度O(n*logn)
方法2：部分排序 维护一个容量为k的堆  O(n*logk)
方法3：线性选择算法  时间复杂度 O(n)  本算法
<<编程之法>>
参考：https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/02.01.md
author: JasonZhou
date：  2016-03-13
*/ 

#include<iostream>
using namespace std;



//选择前k小的数
void QuickSelect(int s[],int k,int left,int right)
{

	int i,j,pivot;
	if (left<=right)
	{
		pivot=s[left];

		i=left;
		j=right;
		//类似快排部分
		while (i<j)
		{
			while(i<j && s[j]>pivot){j--;};
			if(i<j) 
			{
				s[i]=s[j];
				i++;
			}

			while(i<j && s[i]<pivot){i++;};
			if(i<j) 
			{
				s[j]=s[i];
				j--;
			}
		}
		s[i]=pivot;
	}		

	if (k<(i+1))
	{
		QuickSelect(s,k,left,i-1);
	} 
	else if(k==(i+1))
	{
		return;
	}
	else
	{//k>i-1
		QuickSelect(s,k,i+1,right);
	} 


}


int main()
{

	int s[]={99,22,6,7,88,34,2,12,435,9,34,23,1,97};//14个元素，取最小的k个数
	for (int i=0;i<sizeof(s)/sizeof(int);i++)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
	int k=5;//最小的5个数
	QuickSelect(s,k,0,sizeof(s)/sizeof(int)-1);
	cout<<"----result:----"<<endl;
	for (int m=0;m<k;m++)
	{

		cout<<s[m]<<" ";
	}
	cout<<endl;
	return 0;
}
