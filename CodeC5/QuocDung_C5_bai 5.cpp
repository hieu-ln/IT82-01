#include<iostream>
#include<fstream>
#include<sstream>
 using namespace std;
#define max 100
 
 char vertex[max];
 struct node
 {
	 int info;
	 node *link;
 };
 node *first[max];
 node *sp;
 node *front,*rear;
 int n;
 void Init()
 {
	 for(int i=0; i<n; i++)
		 first[i] = NULL;
 }

 void insert_first(node *&f, int x)
 {
	 node *p;
	 p = new node;
	 p->info = x;
	 p->link = f;
	 f = p;
 }

 void InsertLast(node *&first, node *p)
 {
	 if(first == NULL)
		 first = p;
	 else
	 {
		 node *q = first;
		 while(p->link != NULL)
		 {
			 q = q->link;
		 }
		 q->link = p;
	 }
 }

 void inputGraphFromText()
 {
	 string line;
	 ifstream myfile ("danhsachke1.txt");
	 if(myfile.is_open())
	 {
		 myfile >>n;
		 for(int i=0; i<n; i++)
		 {
			 myfile >> vertex[i];
		 }
		 string str;
		 int i=0;
		 while(getline(myfile, str))
		 {
			 istringstream ss(str);
			 int u;
			 while(ss >> u)
			 {
				 node *p = new node;
				 p->info = u;
				 p->link = NULL;
				 InsertLast(first[i-1],p);
			 }
			 i++;
		 }
	 }
 }
 void inputGraph()
 {
	 cout <<"Nhap vao so dinh do thi n: ";
	 cin >> n;
	 cout <<"Nhap ten dinh: ";
	 for(int i=0;i <n; i++)
		 cin >> vertex[i];

	 for(int i=0; i<n+1; i++)
	 {
		 if(i>0)
			 cout <<"Nhap DSK cua dinh thu: " << i-1 << " (" << vertex[i-1] <<"): ";
		 int u;
		 string str;
		 while(getline(cin,str))
		 {
			 istringstream ss(str);
			 while(ss >> u)
			 {
				 node *p = new node;
				 p->info = u;
				 p->link = NULL;
				 InsertLast(first[i-1],p);
			 }
			 break;
		 }
	 }
 }

 void outputGraph()
 {
	 for(int i=0; i<n; i++)
	 {
		 cout <<"Dinh " << i <<" ("<<vertex[i]<<"): ";
		 node *p = first[i];
		 while(p!=NULL)
		 {
			 cout << p->info <<" ";
			 p=p->link;
		 }
		 cout << endl;
	 }
 }
  
 void output(int a[], int n)
 {
	 for(int i=0; i<n; i++)
		 cout << vertex[a[i]] <<" ";
 }
 
 void InitQ()
 {
	 front = NULL;
	 rear = NULL;
 }
 int isEmptyQ()
 {
	 if(front == NULL)
		 return 1;
	 return 0;
 }
 void pushQ(int x)
 {
	 node *p;
	 p = new node;
	 p->info = x;
	 p->link = NULL;
	 if(rear == NULL)
		 front = p;
	 else
		 rear->link = p;
	 rear = p;
 }
 int popQ(int &x)
 {
	 if(front != NULL)
	 {
		 node *p = front;
		 x = p->info;
		 front = front->link;
		 if(front == NULL)
			 rear = NULL;
		 delete p;
		 return 1;
	 }
	 return 0;
 }
 
 void InitS()
 {
	 sp = NULL;
 }
 int isEmptyS()
 {
	 if(sp == NULL)
		 return 1;
	 return 0;
 }
 void pushS(int x)
 {
	 node *p;
	 p = new node;
	 p->info = x;
	 p->link = sp;
	 sp = p;
 }
 int popS(int &x)
 {
	 if(sp!= NULL)
	 {
		 node *p = sp;
		 x = p->info;
		 sp = p->link;
		 delete p;
		 return 1;
	 }
	 return 0;
 }

 int c[100], bfs[100];
 int nbfs = 0;
 void InitC()
 {
	 for(int i=0; i<n; i++)
		 c[i] = 1;
 }

 void BFS(int v) //V la dinh
 {
	 int p;
	 node *w;
	 pushQ(v);
	 c[v] =0;
	 while(front != NULL)
	 {
		 popQ(p);
		 bfs[nbfs] = p;
		 w = first[p];
		 nbfs ++;
		 while(w!=NULL)
		 {
			 if(c[w->info])
			 {
				 pushQ(w->info);
				 c[w->info] =0;
			 }
			 w = w->link;
		 }
	 }

 }

 int dfs[100];
 int ndfs = 0;

 void DFS(int s)
 {
	 pushS(s);
	 dfs[ndfs] = s;
	 ndfs++;
	 c[s] = 0;
	 int u = s;
	 node *v= NULL;
	 while(isEmptyS()==0)
	 {
		 if(v== NULL)
			 popS(u);
		 v= first[u];
		 while(v!=NULL)
		 {
			 if(c[v->info] == 1)
			 {
				 pushS(u);
				 pushS(v->info);
				 dfs[ndfs] = v->info;
				 ndfs++;
				 c[v->info] = 0;
				 u=v->info;
				 break;
			 }
			 v=v->link;
		 }
	 }
 }

 void Search_by_BFS(int x, int v)
 {
	 int p;
	 node *w;
	 pushQ(v);
	 c[v] = 0;
	 while(front != NULL)
	 {
		 popQ(p);
		 if(x == p)
		 {
			 cout <<"Tim thay x\n";
			 return ;
		 }
		 w = first[p];
		 while(w!=NULL)
		 {
			 if(c[w->info])
			 {
				 pushQ(w->info);
				 c[w->info] = 0;
			 }
			 w=w->link;
		 }
	 }
 }

 int main()
 {
	 int so, x, dinh;
	 cout<<"-----------Menu-----------";
	 cout<<"\nNhap so 1 de khoi tao danh sach ke";
	 cout<<"\nNhap so 2 de nhap danh sach bang text";
	 cout<<"\nNhap so 3 de nhap danh sach bang tay";
	 cout<<"\nNhap so 4 de xuat danh sach";
	 cout<<"\nNhap so 5 de duyet theo chieu rong BFS";
	 cout<<"\nNhap so 6 de duyet theo chieu sau DFS";
	 cout<<"\nNhap so 7 de kiem tim theo chieu rong";
	 cout<<"\nNhap so khac de thoat";
	 do {
		 cout<<"\nNhap so: "; 
		 cin>>so;
		 switch (so)
		 {
		 case 1:
			 {
				 Init();
				 cout<<"Ban da khoi tao danh sach ke";
				 break;
			 }
		case 2:
			{
				inputGraphFromText();
				cout<<"ban vua nhap danh sach ke tu file";
				outputGraph();
				break;
			}
		case 3:
			{
				inputGraph();
				break;
			}
   		case 4:
			{
				outputGraph();
				break;
			}
		case 5:
			{
				InitQ();
				InitC();
				cout<<"\n\tNhap dinh bat dau duyet "; cin>>dinh;
				nbfs=0;
				BFS(dinh);
				cout<<"Thu tu dinh sau khi duyet la BFS la: ";
				output(bfs,n);
				break;
			}
		case 6:
			{
				InitS();
				Init();
				cout<<"\n\tNhap dinh bat dau duyet "; cin>>dinh;
				ndfs=0;
				DFS(dinh);
				cout<<"Thu tu dinh sau khi duyet DFS la: ";
				output(dfs, n);
				break;
			}
		case 7:
			{
				InitQ();
				InitC();
				nbfs=0;
				cout<<"\n\tNhap so can tim: "; cin>>x;
				Search_by_BFS(x, 0);
				break;
			}
		default:
			{
				so=0;
				break;
			}
		 }
	 }while(so!=0);
	 cout<<endl;
	 system("pause");
	 return 1;
 }