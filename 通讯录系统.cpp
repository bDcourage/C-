#include<iostream>
#include<string>
#define MAX 1000  //宏定义 
using namespace std;


void showMenu()
{
	cout<<"*************************"<<endl;
	cout<<"***** 1. 添加联系人 *****"<<endl;
	cout<<"***** 2. 显示联系人 *****"<<endl;
	cout<<"***** 3. 删除联系人 *****"<<endl;
	cout<<"***** 4. 查找联系人 *****"<<endl;
	cout<<"***** 5. 修改联系人 *****"<<endl;
	cout<<"***** 6. 清空联系人 *****"<<endl;
	cout<<"***** 0. 退出通讯录 *****"<<endl;
	cout<<"*************************"<<endl;
	cout<<"请输入对应的指令：";
}
struct r
{
	string Name;
	string Xy;
	int Age;
	string Num;
	string Home;
	}x;
struct addressbooks
{
	struct r personArray[MAX];
	int size; 
};
void addPerson(addressbooks * abs)  //指针接收地址 
{
	if(abs->size==MAX)
	{
	cout<<"通讯录已满，无法添加"<<endl;
	return;
}
	else 
	cout<<"请输入姓名："<<endl;
	string name;
	cin>>name; 
	abs->personArray[abs->size].Name=name; 
	cout<<"请输入性别："<<endl;
	while(true)
	{
	string xy;
	cin>>xy;
	if(xy=="男"||xy=="女")
	{
	abs->personArray[abs->size].Xy=xy; 
	break;
}
	else
	cout<<"输入错误，请重新输入："<<endl;
}
	cout<<"请输入年龄："<<endl;
	while(true)
	{
	int age;
	cin>>age;
	if(age>0)
	{
	abs->personArray[abs->size].Age=age; 
	break;
}
	else
	cout<<"输入错误，请重新输入："<<endl;
}
	cout<<"请输入联系电话："<<endl;
	while(true)
	{
	string num;
	cin>>num;
	if(num.length()==11)
	{
	abs->personArray[abs->size].Num=num;
	break; 
}
	else
	cout<<"格式不对请重新输入"<<endl;
}
	cout<<"请输入家庭住址："<<endl;
	string home;
	cin>>home; 
	abs->personArray[abs->size].Home=home; 
	abs->size++;
	cout<<"添加成功！"<<endl;
	system("pause");
	system("cls");
}
void showPerson(addressbooks * abs)
{
	if(abs->size==0)
	cout<<"当前记录为空"<<endl;
	else
	{
	for(int i=0;i<abs->size;i++)
	{
	cout<<"姓名："<<abs->personArray[i].Name<<'\t'
	<<"性别："<<abs->personArray[i].Xy<<'\t'
	<<"年龄："<<abs->personArray[i].Age<<'\t'
	<<"电话："<<abs->personArray[i].Num<<'\t'
	<<"住址："<<abs->personArray[i].Home<<'\t'<<endl;
	}
}
	system("pause");
	system("cls");
}
int isExist(addressbooks * abs,string name)
{
	for(int i=0;i<abs->size;i++)
	{
	if(abs->personArray[i].Name==name)
	{
		return i;
	} 
	}
	return -1;
}
void deletePerson(addressbooks * abs)
{
	cout<<"请输入您要删除的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
	for(int i=ret;i<abs->size;i++)
	{
	abs->personArray[i]=abs->personArray[i+1];
	} 
	abs->size--;
	cout<<"删除成功！"<<endl;
	}
	else
	cout<<"查无此人"<<endl;
	system("pause");
	system("cls"); 
} 
void findPerson(addressbooks * abs)
{
	cout<<"请输入您需要查找的联系人：";
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
	cout<<"姓名："<<abs->personArray[ret].Name<<'\t'
	<<"性别："<<abs->personArray[ret].Xy<<'\t'
	<<"年龄："<<abs->personArray[ret].Age<<'\t'
	<<"电话："<<abs->personArray[ret].Num<<'\t'
	<<"住址："<<abs->personArray[ret].Home<<'\t'<<endl;
}
	else
	cout<<"查无此人"<<endl;
	system("pause");
	system("cls"); 
}
void modifyPerson(addressbooks * abs)
{
	cout<<"请输入需要修改的联系人:";
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
	cout<<"请输入姓名："<<endl;
	string name;
	cin>>name; 
	abs->personArray[ret].Name=name; 
	cout<<"请输入性别："<<endl;
	while(true)
	{
	string xy;
	cin>>xy;
	if(xy=="男"||xy=="女")
	{
	abs->personArray[ret].Xy=xy; 
	break;
}
	else
	cout<<"输入错误，请重新输入："<<endl;
}
	cout<<"请输入年龄："<<endl;
	while(true)
	{
	int age;
	cin>>age;
	if(age>0)
	{
	abs->personArray[ret].Age=age; 
	break;
}
	else
	cout<<"输入错误，请重新输入："<<endl;
}
	cout<<"请输入联系电话："<<endl;
	while(true)
	{
	string num;
	cin>>num;
	if(num.length()==11)
	{
	abs->personArray[ret].Num=num;
	break; 
}
	else
	cout<<"格式不对请重新输入"<<endl;
}
	cout<<"请输入家庭住址："<<endl;
	string home;
	cin>>home; 
	abs->personArray[ret].Home=home; 
	abs->size++;
	cout<<"修改成功！"<<endl;
	system("pause");
	system("cls");
}
	else
	cout<<"查无此人"<<endl;
}
void clearPerson(addressbooks * abs)
{
	abs->size=0;  //逻辑清空：将联系人数量重置为0 
	cout<<"通讯录已清空"<<endl;
	system("pause");
	system("cls");
} 
int main()
{
	addressbooks abs;
	abs.size=0;
	while(true)
	{
	showMenu(); 
	int num;
	cin>>num; 
	switch(num)
	{
	case 0:cout<<"欢迎下次使用！"<<endl;
	return 0;
	break;
	case 1:addPerson(&abs);
	break;
	case 2:showPerson(&abs);
	break;
	case 3:deletePerson(&abs);
	break;
	case 4:findPerson(&abs);
	break;
	case 5:modifyPerson(&abs); 
	break;
	case 6:clearPerson(&abs); 
	break;
	}
}
	return 0;
}
