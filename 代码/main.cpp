#include  <cctype>
#include "Node.h"
using namespace std;
int main() 
{ 
 int n; 
 cout<<"  **************ͣ��������ϵͳ**************"<<endl; 
cout<<endl; 
cout<<"ͣ��������ϵͳ˵��:"<<endl; 
cout<<"1.��ͣ������λ����֮�󣬳�����ͣ�ڱ��"<<endl; 
cout<<"2.ͣ��������ÿСʱ��Ԫ�ı�׼�շѣ�����һСʱ����һСʱ���㣩"<<endl; 
cout<<"3.ͣ�ڱ���ĳ������շѡ�"<<endl; 
cout<<endl; 
Start:cout<<"������ͣ�������ܹ��ĳ�λ��:"<<endl; 
cin>>n;
if (cin.good()!=1||n<=0) 
	{
		cout <<"������������������!" << endl;	
		cin.clear();  	
		cin.sync();   
		goto Start;
	}
 
 cout<<endl; 
 cout<<"****************��λ������ϣ����濪ʼͣ��������ϵͳģ��***************"<<endl; 
 cout<<endl; 
 cout<<"*******************************����˵��********************************"<<endl; 
 cout<<endl; 
 cout<<"����ʻ��Ǽǣ��밴1                 ����ʻ���Ǽǣ��밴2      "<<endl; 
 cout<<endl; 
 cout<<"��ѯͣ������ͣ��״̬���밴3         ��ѯͣ�������г�λ���밴4"<<endl; 
 cout<<endl; 
 cout<<"                 �˳�ͣ��������ϵͳ���밴0"<<endl; 
 cout<<endl; 
 cout<<"***********************************************************************"<<endl; 
 cout<<endl; 
 while(1) 
 { 
	cout<<"           ��ʾ��:";
	Query2(n); 
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"********��ѡ�����1~4,�������˳��밴0********"<<endl; 
	cout<<endl; 
	cin.clear();  	
	cin.sync();  
	int t; 
	cin>>t; 
	 if(t==1) 
		Push(n); 
	 else if(t==2) 
		Pop(n); 
	 else if(t==3) 
		Query1(n); 
	 else if(t==4) 
		Query2(n); 
	 else if(t==0)
		break; 
	 else 
		 cout<<"������������������!"<<endl;
 cout<<endl; 
 cout<<"**********************�d(������)Bye~**********************"<<endl; 
 cout<<"**********************�d(������)Bye~**********************"<<endl; 
 cout<<endl; 
 } 
 cout<<"��ӭʹ��ͣ��������ϵͳ���ڴ������´�ʹ��^_^"<<endl; 
 return 0;
}
