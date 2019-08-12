//#include<iostream>
//#include<fstream>
// using namespace std;
//#define max 100
//
// int a[max][max];
// int n;
// char vertex[max];
// struct node
// {
//	 int info;
//	 node *link;
// };
//
// node *sp;
// node *front,*rear;
// void init()
// {
//	 n= 0;
// }
//
// void Nhap()
// {
//	 cout <<"Nhap vao so dinh cua do thi: ";
//	 cin >> n;
//	 
//	 for(int i=0;i<n;i++)
//	 {
//		 cout<<"Nhap vao dong thu "<<i+1<<": ";
//		 for(int j=0; j<n;j++)
//			 cin >> a[i][j];
//	 }
// }
//
// void NhapTuFile()
// {
//	 string line;
//	 ifstream myfile ("matranke1.txt");
//	 if(myfile.is_open())
//	 {
//		 myfile>>n;
//		 for(int i=0; i<n; i++)
//		 {
//			 myfile>>vertex[i];
//		 }
//		 for(int i=0;i<n; i++)
//			for(int j=0;j<n; j++)
//				myfile>>a[i][j];
//	 }
// }
// 
// void xuat()
// {
//	 for(int i=0; i<n; i++)
//	 {
//		 for(int j=0; j<n; j++)
//			 cout << a[i][j] << " "; 
//		 cout << endl;
//	 }
// }
//
// void initQ()
// {
//	 front = NULL;
//	 rear = NULL;
// }
// int isEmptyQ()
// {
//	 if(front == NULL)
//		 return 1;
//	 return 0;
// }
// void pushQ(int x)
// {
//	 node *p;
//	 p = new node;
//	 p->info = x;
//	 p->link = NULL;
//	 if(rear == NULL)
//		 front = p;
//	 else
//		 rear->link = p;
//	 rear = p;
// }
// int popQ(int &x)
// {
//	 if(front != NULL)
//	 {
//		 node *p = front;
//		 x = p->info;
//		 front = front->link;
//		 if(front == NULL)
//			 rear = NULL;
//		 delete p;
//		 return 1;
//	 }
//	 return 0;
// }
// 
// void initS()
// {
//	 sp = NULL;
// }
// int isEmptyS()
// {
//	 if(sp == NULL)
//		 return 1;
//	 return 0;
// }
//
// void pushS(int &x)
// {
//	 node *p;
//	 p = new node;
//	 p->info = x;
//	 p->link = sp;
//	 sp = p;
// }
//
// int popS(int &x)
// {
//	 if(sp!= NULL)
//	 {
//		 node *p = sp;
//		 x = p->info;
//		 sp = p->link;
//		 delete p;
//		 return 1;
//	 }
//	 return 0;
// }
//
// int c[100], bfs[100];
// int nbfs = 0;
// void initC()
// {
//	 for(int i=0; i<n; i++)
//		 c[i] = 1;
// }
//
// void BFS(int v) //V la dinh
// {
//	 int p;
//	 pushQ(v);
//	 c[v] =0;
//	 while(front != NULL)
//	 {
//		 popQ(p);
//		 bfs[nbfs] = p;
//		 nbfs ++;
//		 for(int w=0; w<n; w++)
//			 if(c[w] != 0 && a[p][w] == 1)
//			 {
//				 pushQ(w);
//				 c[w] =0;
//			 }
//	 }
// }
//
// int dfs[100];
// int ndfs = 0;
//
// void DFS(int s)
// {
//	 pushS(s);
//	 dfs[ndfs] = s;
//	 ndfs++;
//	 c[s] = 0;
//	 int v = -1, u = s;
//	 while(isEmptyS()==0)
//	 {
//		 if(v==n)
//			 popS(u);
//		 for(v = 0; v<n; v++)
//		 {
//			 if(a[u][v] !=0 && c[v]==1)
//			 {
//				 pushS(u);
//				 pushS(v);
//				 dfs[ndfs] = v;
//				 ndfs++;
//				 c[v] = 0;
//				 u=v;
//				 break;
//			 }
//		 }
//	 }
// }
//
// void output(int a[], int n)
// {
//	 for(int i=0; i<n; i++)
//		 cout << vertex[a[i]] << " ";
// }
// /*void outputBFS()
// {
//	 for(int i=0; i<nbfs; i++)
//		 cout << vertex[bfs[i]] << " "; 
// }*/
//
// /*void outputDFS()
// {
//	 for(int i=0; i<ndfs; i++)
//		 cout << vertex[dfs[i]] << " ";
// }*/
//
// void search_BFS(int x, int v)
// {
//	 int p;
//	 pushQ(v);
//	 c[v] = 0;
//	 while(front != NULL)
//	 {
//		 popQ(p);
//		 if(x == p)
//		 {
//			 cout <<"Tim thay x\n";
//			 return ;
//		 }
//		 for(int w=0; w<n; w++)
//			 if(c[w] !=0 && a[p][w] == 1)
//			 {
//				 pushQ(w);
//				 c[w] = 0;
//			 }
//	 }
//	 cout <<"Khong ton tai\n";
// }
//
// int main()
//
// {
//	 int a[max], b[max];
//	 int choice, x;
//	 cout <<"===============Menu===============\n";
//	 cout <<"1.Khoi tao ma tran ke\n";
//	 cout <<"2.Nhap ma tran tu file\n";
//	 cout <<"3.Nhap ma tran\n";
//	 cout <<"4.Xuat ma tran\n";
//	 cout <<"5.Duyet do thi theo chieu rong\n";
//	 cout <<"6.Duyet do thi theo chieu sau\n";
//	 cout <<"7.Tim dinh co gia tri x theo bfs\n";
//	 cout <<"8.Thoat\n";
//	 do {
//		 do{
//				 cout <<"nhap vao lua chon: ";
//				 cin >> choice;
//				 if(choice <1 || choice >8)
//				 {
//					 cout <<"Nhap sai, nhap lai\n";
//				 }
//			 }while(choice<1 || choice >8);
//		 switch(choice)
//		 {
//		 case 1:
//			 {
//				 init();
//				 cout <<"Khoi tao ma tran ke thanh cong\n";
//				 break;
//			 }
//		 case 2:
//			 {
//				 NhapTuFile();
//				 cout <<"Ma tran sau khi nhap tu file: \n";
//				 xuat();
//				 break;
//			 }
//		 case 3:
//			 {
//				 Nhap();
//				 cout <<"Ma tran sau khi nhap: \n";
//				 xuat();
//				 break;
//			 }
//		 case 4:
//			 {
//				 cout<<"Ma tran: \n";
//				 xuat();
//				 break;
//			 }
//		 case 5:
//			{
//				initQ();
//				initC();
//				cout <<"Nhap vao dinh xuat phat: ";
//				cin >> x;
//				nbfs = 0;
//				BFS(x);
//				cout <<"Thu tu sau khi duyet bfs:\n";
//				output(bfs,n);
//				break;
//			}
//		 case 6:
//			 {
//				 initS();
//				 initC();
//				 cout <<"Nhap vao dinh xuat phat: ";
//				 cin >> x;
//				 ndfs = 0;
//				 DFS(x);
//				 cout <<"Thu tu sau khi duyet dfs: \n";
//				 output(dfs,n);
//				 break;
//			 }
//		 case 7:
//			 {
//				 cout <<"Vui long nhap gia tri x can tim: ";
//				 cin >> x;
//				 search_BFS(x,0);
//				 break;
//			 }
//		 case 8:
//			 {
//				 cout <<"Goodbye.\n";
//				 break;
//			 }
//		 }
//	 } while(choice != 8);
// }