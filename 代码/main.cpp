#include  <cctype>
#include "Node.h"
using namespace std;
int main() 
{ 
 int n; 
 cout<<"  **************停车场管理系统**************"<<endl; 
cout<<endl; 
cout<<"停车场管理系统说明:"<<endl; 
cout<<"1.当停车场车位已满之后，车将会停在便道"<<endl; 
cout<<"2.停车场按照每小时五元的标准收费（不足一小时按照一小时计算）"<<endl; 
cout<<"3.停在便道的车辆不收费。"<<endl; 
cout<<endl; 
Start:cout<<"请设置停车场的总共的车位数:"<<endl; 
cin>>n;
if (cin.good()!=1||n<=0) 
	{
		cout <<"输入有误请重新输入!" << endl;	
		cin.clear();  	
		cin.sync();   
		goto Start;
	}
 
 cout<<endl; 
 cout<<"****************车位设置完毕！下面开始停车场管理系统模拟***************"<<endl; 
 cout<<endl; 
 cout<<"*******************************操作说明********************************"<<endl; 
 cout<<endl; 
 cout<<"车辆驶入登记：请按1                 车辆驶出登记：请按2      "<<endl; 
 cout<<endl; 
 cout<<"查询停车场的停车状态：请按3         查询停车场空闲车位：请按4"<<endl; 
 cout<<endl; 
 cout<<"                 退出停车场管理系统：请按0"<<endl; 
 cout<<endl; 
 cout<<"***********************************************************************"<<endl; 
 cout<<endl; 
 while(1) 
 { 
	cout<<"           告示牌:";
	Query2(n); 
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"********请选择操作1~4,若您想退出请按0********"<<endl; 
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
		 cout<<"输入有误，请重新输入!"<<endl;
 cout<<endl; 
 cout<<"**********************ヾ(￣▽￣)Bye~**********************"<<endl; 
 cout<<"**********************ヾ(￣▽￣)Bye~**********************"<<endl; 
 cout<<endl; 
 } 
 cout<<"欢迎使用停车场管理系统，期待您的下次使用^_^"<<endl; 
 return 0;
}
