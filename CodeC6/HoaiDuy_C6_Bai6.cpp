#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
const int MAX=1000;
struct point{
	int x,y,z;
};
int a[MAX][MAX],n,res=0,ans=0,k=0,lk=1;
point b[MAX];
bool kt[MAX],ktt[MAX];
bool KT=false;
void inputhand(){
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>a[i][j];
}
void inputtext(){
	ifstream fi("map.txt");
	fi>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			fi>>a[i][j];
	fi.close();
}
void change(){
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++){
			if (a[i][j]!=0){
				b[k].x=i;
				b[k].y=j;
				b[k].z=a[i][j];
				k++;
			}
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			a[i][j]=0;
}
void sortt()
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (b[i].z>b[j].z)
			{
				point tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
			}
}
void init(){
	for (int i=0;i<n;i++){
		ktt[i]=true;
		kt[i]=true;
	}
}
void dfs(int x,int y){
	if (x==y) {
		KT=true;
		return;
	}
	for (int i=0;i<n;i++)
		if (a[i][x]!=0 && ktt[i]){
			ktt[i]=false;
			dfs(i,y);
			if (KT) return;
		}
}
void dfstest(int x){
	for (int i=0;i<n;i++)
		if (a[i][x]!=0 && ktt[i]){
			lk++;
			ktt[i]=false;
			dfstest(i);	
		}
}
void kruskal(){
	while(lk!=n){
		int tmp=0;
		int Min=1<<30;
		for (int i=0;i<k;i++){
			KT=false;	
			for (int j=0;j<n;j++) ktt[j]=true;
			dfs(b[i].x,b[i].y);
			if  (((kt[b[i].y] || kt[b[i].x]) || !KT) && b[i].z!=-1) 
				if (b[i].z<Min){
					Min=b[i].z;
					tmp=i;
				}
		}
		res+=b[tmp].z;
		a[b[tmp].x][b[tmp].y]=b[tmp].z;
		a[b[tmp].y][b[tmp].x]=b[tmp].z;
		kt[b[tmp].x]=false;
		kt[b[tmp].y]=false;
		b[tmp].z=-1;
		ans=0;
		lk=1;
		for (int i=0;i<n;i++)
			ktt[i]=true;
		ktt[0]=false;
		dfstest(0);
	}
}
int main()
{
	int c=0;
	cout<<"Menu BT CHUONG 6 Bai6"<<endl;
	cout<<"1, nhap tay"<<endl;
	cout<<"2, nhap may"<<endl;
	cout<<"3, khoi tao"<<endl;
	cout<<"4 chay Krusal"<<endl;
	while (c!=5){
		cout<<"Chon lenh :";cin>>c;
		switch (c){
		case 1:{
				inputhand();
				cout<<"Nhap thanh cong"<<endl;
				break;
			 }
		case 2:{
				inputtext();
				cout<<"Nhap thanh cong"<<endl;
				break;
			 }
		case 3:{
				init();
				cout<<"Khoi tao thanh cong"<<endl;
				break;
			 }
		case 4:{
			    change();
				sortt();
				kruskal();
				cout<<"Tong trong so = "<<res<<endl;
				break;
			 }
		case 5:{
				cout<<"Ket thuc"<<endl;
				system("pause");
				break;
			 }
		default:{
				cout<<"Loi lenh"<<endl;
				break;
			 }
		}
	}
	return 0;
}