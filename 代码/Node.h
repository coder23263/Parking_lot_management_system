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
 string no;//���ƺ� 
 int time;//���������ʱ�䣨��СʱΪ��λ�� 
 int sub;//������ͣ������λ�� 
} nod; 
map<string,int>mp;//������⳵����ͣ���������ڱ���� 
deque<node>q1;//ģ��ͣ���� 
deque<node>q2;//ģ���� 
stack<node>sk;//����ý�� 
string str1="park",str2="pavement"; 
void Push(int n)//����ʻ����� 
{
	cout<<"������Ҫ���복���ĳ��ƺ�"<<endl; 
	string x; 
	int y;
	cin>>x; 
	cout<<"������ó�������ͣ������ʱ��(����0210 1530)"<<endl; 
	cin>>y; 
	if(!mp[x])//����˳�����ͣ�������߱����ִ���������� 
	{ 
		 if(q1.size()<n)//���ͣ����δ�� 
		 {
			nod.no=x; 
			nod.time=y; 
			nod.sub=q1.size()+1; 
			q1.push_back(nod); 
			mp[x]=q1.size();
			cout<<"�ɹ�ͣ��ͣ������"<<endl;
		 }
		 else//ͣ��������֮������� 
		 {
			 nod.no=x; 
			 nod.time=y; 
			 nod.sub=q2.size()+1; 
			 q2.push_back(nod); 
			 mp[x]=n+q2.size(); 
			 cout<<"���ĳ�����λ�ڱ���ȴ�"<<endl;
		 } 
	}
	else
	cout<<"���󣺸ó�������ͣ�����ڣ�"<<endl; 
} 
void Pop(int n)//����ʻ������ 
{
	cout<<"������Ҫʻ�������ĳ��ƺ�"<<endl; 
	string x; 
	int y,ans,minutes,hours,inhour;
	float payment;
	cin>>x; 
	cout<<"������ó���ʻ��ͣ������ʱ��(����0210 1530)"<<endl; 
	cin>>y; 
	if(!mp[x])
		cout<<"���󣺸���������ͣ�����ڣ�"<<endl; 
	else if(mp[x]<=n)//����ó���ͣ������ 
	{
		mp[x]=0; 
		while(q1.back().no!=x)//���� 
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
		 if(!q2.empty())//��������Ҳ�г�����ô����ͣ���������ұ������ĳ���ǰ�ƶ� 
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
	 cout<<"�ó���һ��ͣ�� "<<hours<<" ��Сʱ"<<minutes<<"����"<<endl; 
	 cout<<"���Ըó�����Ҫ���� "<<setprecision(4)<<payment<<"Ԫ"<<endl; 
	}
	else if(mp[x]>n)//������ڱ�����ôֱ���뿪������ĳ���ǰ�ƶ� 
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
		cout<<"���ڸó�����δ����ͣ���������Բ������շ�"<<endl; 
	} 	
} 
void Query1(int n)//��ѯͣ������ͣ��״̬ 
{
	cout<<"������Ҫ��ѯ״̬�ĳ��ƺ�"<<endl; 
	cout<<endl; 
	string x; 
	cin>>x; 
	if(!mp[x]) 
		cout<<"�ó�����δ��ͣ����"<<endl; 
	else if(mp[x]<=n) 
		cout<<"�ó���λ��ͣ����"<<mp[x]<<"��λ"<<endl; 
	else
		cout<<"�ó���λ��"<<mp[x]-n<<"�ű��"<<endl; 
} 
void Query2(int n)//��ѯͣ�����Ŀճ�λ 
{ 
	cout<<endl; 
	if(q1.size()==n)
	{
		cout<<"ͣ��������"<<endl;
	}
	else
	{ 
		cout<<"ͣ������"<<q1.size()+1; 
		for(int i=q1.size()+2; i<=n; i++) 
		cout<<"��"<<i; 
		cout<<"��λ��Ϊ��"<<endl; 
	} 
} 

#endif