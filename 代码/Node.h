#ifndef NODE_H
#define NODE_H
#include <iostream>
#include<cstring>
#include<string>  
#include<map>
#include<stack> 
#include<queue>
#include<vector>
#include <iomanip>
#include "Node.h"
using namespace std;

 
struct node 
{ 
 string no;//车牌号 
 int time;//车辆进入的时间（以小时为单位） 
 int sub;//车辆在停车场的位置 
} nod; 
map<string,int>mp;//用来检测车辆在停车场或者在便道内 
deque<node>q1;//模拟停车场 
deque<node>q2;//模拟便道 
stack<node>sk;//交换媒介 
string str1="park",str2="pavement"; 
void Push(int n)//车辆驶入操作 
{
	cout<<"请输入要进入车辆的车牌号"<<endl; 
	string x; 
	int y;
	cin>>x; 
	cout<<"请输入该车辆进入停车场的时间(例如0210 1530)"<<endl; 
	cin>>y; 
	if(!mp[x])//如果此车不在停车场或者便道内执行以下命令 
	{ 
		 if(q1.size()<n)//如果停车场未满 
		 {
			nod.no=x; 
			nod.time=y; 
			nod.sub=q1.size()+1; 
			q1.push_back(nod); 
			mp[x]=q1.size();
			cout<<"成功停入停车场！"<<endl;
		 }
		 else//停车场满了之后进入便道 
		 {
			 nod.no=x; 
			 nod.time=y; 
			 nod.sub=q2.size()+1; 
			 q2.push_back(nod); 
			 mp[x]=n+q2.size(); 
			 cout<<"您的车辆正位于便道等待"<<endl;
		 } 
	}
	else
	cout<<"错误：该车辆已在停车场内！"<<endl; 
} 
void Pop(int n)//车辆驶出操作 
{
	cout<<"请输入要驶出车辆的车牌号"<<endl; 
	string x; 
	int y,ans,minutes,hours,inhour;
	float payment;
	cin>>x; 
	cout<<"请输入该车辆驶出停车场的时间(例如0210 1530)"<<endl; 
	cin>>y; 
	if(!mp[x])
		cout<<"错误：该辆并不在停车场内！"<<endl; 
	else if(mp[x]<=n)//如果该车在停车场内 
	{
		mp[x]=0; 
		while(q1.back().no!=x)//车出 
		{
			q1.back().sub--; 
			sk.push(q1.back()); 
			q1.pop_back(); 
		}
		 ans=y-q1.back().time;
		 hours=ans/100;
		 minutes=ans-hours*100+hours*60;
		 inhour=minutes/60;
		 minutes=minutes%60;

		 payment=hours*5+minutes*5.0/60;
		 q1.pop_back(); 
		 while(!sk.empty()) 
		 {		 
			 q1.push_back(sk.top()); 
			 sk.pop(); 
			 mp[q1.back().no]=q1.back().sub; 
		 }
		 if(!q2.empty())//如果便道里也有车，那么进入停车场，并且便道后面的车向前移动 
		 { 
			 q2.front().time=y; 
			 q2.front().sub=q1.size()+1; 
			 q1.push_back(q2.front()); 
			 q2.pop_front();
			 while(!q2.empty()) 
			 { 
				 q2.back().sub--; 
				 sk.push(q2.back()); 
				 q2.pop_back(); 
			 }
			 while(!sk.empty())
			 { 
				 q2.push_back(sk.top()); 
				 sk.pop(); 
				 mp[q2.back().no]=q1.back().sub; 
			 }
			 mp[q1.back().no]=q1.size(); 
		 } 
	 cout<<"该车辆一共停了 "<<hours<<" 个小时"<<minutes<<"分钟"<<endl; 
	 cout<<"所以该车辆需要缴纳 "<<setprecision(4)<<payment<<"元"<<endl; 
	}
	else if(mp[x]>n)//如果车在便道里，那么直接离开，后面的车向前移动 
	{ 
		mp[x]=0; 
		while(q2.back().no!=x) 
		{ 
			 q2.back().sub--; 
			 sk.push(q2.back()); 
			 q2.pop_back(); 
		} 
		q2.pop_back(); 
		while(!sk.empty()) 
		{ 
			 q2.push_back(sk.top()); 
			 sk.pop(); 
		}
		cout<<"由于该车辆并未进入停车场，所以不进行收费"<<endl; 
	} 	
} 
void Query1(int n)//查询停车场的停车状态 
{
	cout<<"请输入要查询状态的车牌号"<<endl; 
	cout<<endl; 
	string x; 
	cin>>x; 
	if(!mp[x]) 
		cout<<"该车辆并未在停车场"<<endl; 
	else if(mp[x]<=n) 
		cout<<"该车辆位于停车场"<<mp[x]<<"号位"<<endl; 
	else
		cout<<"该车辆位于"<<mp[x]-n<<"号便道"<<endl; 
} 
void Query2(int n)//查询停车场的空车位 
{ 
	cout<<endl; 
	if(q1.size()==n)
	{
		cout<<"停车场已满"<<endl;
	}
	else
	{ 
		cout<<"停车场的"<<q1.size()+1; 
		for(int i=q1.size()+2; i<=n; i++) 
		cout<<"、"<<i; 
		cout<<"号位车为空"<<endl; 
	} 
} 

#endif