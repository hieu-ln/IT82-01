//#include <iostream>
//using namespace std;
//
//struct node 
//{
//	int info;
//	node *link; //đây chỉ khai báo danh sách liên kết đơn
//};
//
////đỉnh kiểu node
//node *sp;
//
//
//void init()
//{
//	sp = NULL;
//}
//
//int isEmpty()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//
//void list()
//{
//	node *p = sp;
//	while (sp != NULL)
//	{
//		cout << p->info << " ";
//		p = p->link;
//	}
//	cout << endl;
//}
//
//int pop()
//{
//	if (sp == NULL)
//		return 0;
//	else
//	{
//		int x;
//		node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//}
//
//void push(int x)
//{
//	node *p;
//	p = new node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//
//void Dec_Bin(int &x)
//{
//	int sodu,temp;
//	temp = x;
//	cout << "So nhi phan cua " << x << "la: ";
//	while (temp > 0)
//	{
//		//chia cho 2 rồi gán số dư vào stack
//		sodu = temp % 2;
//		push(sodu);
//		temp = temp / 2;
//	}
//
//	//Xuất ra kết quả của số dư trong stack
//	while (sp != NULL)
//	{
//		int x;
//		node *p;
//		x = sp->info;
//		p = sp;
//		sp = sp->link;
//		delete p;
//		cout << x;
//	}
//}
//
//int main()
//{	
//	int temp,x,i;
//	do
//	{
//		cout << "==============Menu==============\n";
//		cout << " 1.Khoi tao stack rong\n";
//		cout << " 2.Kiem tra stack rong\n";
//		cout << " 3. Them mot phan tu vao stack\n";
//		cout << " 4. Xoa mot phan tu trong stack\n";
//		cout << " 5. Doi so thap phan thanh nhi phan\n";
//		cout << " 7. thoat\n";	
//		cout << "Nhap vao lua chon cua ban: ";
//		cin >> temp;
//	
//		switch(temp)
//		{
//			case 1:
//			{
//				init();
//				cout << "Khoi tao stack thanh cong\n";
//				break;
//			}
//			case 2:
//			{
//				i = isEmpty();
//				if (i > 0)
//					cout << "Danh stack rong\n";
//				else
//					cout << "Danh sach khong rong\n";
//			}
//			case 3:
//			{
//				cout << "Nhap vao so can them: ";
//				cin >> x;
//				push(x);
//				cout << "Them thanh cong\n";
//				list();
//
//			}
//			case 4:
//			{
//				int i = pop();
//				if (i > 0)
//				{
//					cout << "Xoa thanh cong\n";
//					cout << "Danh sach sau khi xoa: ";
//					list();
//				}
//				else
//					cout << "Danh sach rong, khong the xoa\n";
//			}
//			case 5:
//			{
//				cout << "Nhap vao so can doi sang nhi phan: ";
//				cin >> x;
//				Dec_Bin(x);
//				cout << endl;
//			}
//		}
//	} while (temp != 7);
//	
//
//
//	system("pause");
//	return 0;
//}