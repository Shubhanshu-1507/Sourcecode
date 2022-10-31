#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& arr,int m)
{
	int area=0,i=1,h=0,p=0;
    stack<int> startpos,height;
	startpos.push(0);
	for(i=0;i<m;i++)
	{
		if(height.empty()||arr[i]>height.top())
		{
			startpos.push(i);
			height.push(arr[i]);
		}
		else if(arr[i]<height.top())
		{
			while(!height.empty()&&height.top()>arr[i])
			{
				h=height.top();
				p=startpos.top();
				height.pop();
				startpos.pop();
				area=max(area,h*(i-p));
			}
			startpos.push(p);
			height.push(arr[i]);
		}
	}
	while(!height.empty())
	{
		h=height.top();
		p=startpos.top();
		height.pop();
		startpos.pop();
		area=max(area,h*(i-p));
	}
	return area;
}
int maxRectangle(vector<vector<int> >& mat,int n,int m)
{
	int res=0;
	vector<int> arr(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]==1)
			arr[j]=mat[i][j]+arr[j];
			else 
			arr[j]=0;
		}
		res=max(res,maxArea(arr,m));
     }
	return res;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > mat;
	for(int i=0;i<n;i++)
	{
		vector<int> t;
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			t.push_back(x);
		}
		mat.push_back(t);
	}
	int ans=maxRectangle(mat,n,m);
	cout<<ans<<" ";
	return 0;
}
