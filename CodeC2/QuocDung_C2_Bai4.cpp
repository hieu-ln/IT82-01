//#include<iostream>
//using namespace std;
//
//struct node
//{
//	int info;
//	node *link;
//};
//
//node *first;
//
//void init()
//{
//	first = NULL;
//}
//
//bool check_t()
//{
//	bool kq = false;
//	node *p, *q;
//	if (first != NULL)
//	{
//		p = first;
//		q = first;
//		while (p ->link!= NULL)
//		{
//			q = p;
//			p = p->link;
//			if (q->info < p->info)
//				kq = true;
//			else
//			{
//				return kq;
//			}
//		}	
//	}
//
//	return kq;
//}
//
//bool check_g()
//{
//	bool kq = false;
//	node *p, *q;
//	if (first != NULL)
//	{
//		p = first;
//		q = first;
//		while (p ->link!= NULL)
//		{
//			q = p;
//			p = p->link;
//			if (q->info > p->info)
//				kq = true;
//			else
//			{
//				return kq;
//			}
//		}
//	}
//
//	return kq;
//}
//
//int add(int x)
//{
//	bool tang, giam;
//	node *p,*q;
//	tang = check_t();
//	giam = check_g();
//	p = new node;
//	p->info = x;
//	q = first;
//	if (first != NULL)
//	{
//		if (tang == true)
//		{
//			cout << "tang:" <<tang << endl;
//			while (q->link != NULL && q->info > x)
//			{
//				q = q->link;
//			}
//			p->link = q->link;
//			q->link = p;
//		}
//		else
//			if(giam == true)
//		{
//				cout <<"giam: "<< giam << endl;
//				while (q->link != NULL && q->info < x)
//				{
//					q = q->link;
//				}
//				p->link = q->link;
//				q->link = p;
//		}
//			else
//			{
//				//Thêm vào đầu danh sách
//				p->link = first;
//				first = p;
//			}
//	}
//	else {
//		//trường hợp first = NULL
//		p->link = first;
//		first = p;
//	}
//	
//	return 1;
//}
//
//void list()
//{
//	node *p;
//	p = first;
//	while (p != NULL)
//	{
//		cout << p->info << " ";
//		p = p->link;
//	}
//	cout << endl;
//}
//node *search(int x)
//{
//	node *p;
//	p = first;
//	while (p != NULL && p->info != x )
//		p = p->link;
//	return p;
//}
//
//int search_delete(int x)
//{
//	//Kiểm tra rỗng
//	if (first == NULL)
//		return 0;
//	else
//	{
//		node *p, *q;
//		p = first;
//		q = first;
//		while (q!=NULL && q->info != x)
//		{
//			p = q;
//			q = q->link;
//		}
//		//Kiểm tra tìm thấy hay không
//		if (q == NULL)
//		{
//			return -1;
//		}
//		else
//		{
//			//Kiễm tra đầu
//			if (q == first)
//			{
//				first = q->link;
//				delete q;
//				return 1;
//			}
//			else
//				//Kiễm tra cuối
//				if (q->link == NULL)
//				{
//					p->link = q->link;
//					delete q;
//					return 1;
//				}
//				else
//				{
//					p->link = q->link;
//					return 1;
//				}
//		}
//
//	}
//}
//
//int main()
//{
//	int temp,x,i;
//	node *p;
//	do
//	{
//		cout << "==========Menu============\n";
//		cout << " 1.Khoi tao danh sach\n";
//		cout << " 2.Them mot phan tu vao danh sach \n";
//		cout << " 3.Xuat danh sach\n";
//		cout << " 4.Tim mot phan tu trong danh sach\n";
//		cout << " 5. Tim va xoa mot phan tu trong danh sach \n";
//		cout << " 6. Thoat\n";
//
//		do {
//			cout << "Nhap vao lua chon: ";
//			cin >> temp;
//		} while (temp < 1 || temp >6);
//
//		switch (temp)
//		{
//		case 1:
//		{
//			init();
//			cout << "Khoi tao danh sach thanh cong\n";
//			break;
//		}
//		case 2:
//		{
//			cout << "Nhap vao phan tu muon them\n";
//			cin >> x;
//			i = add(x);
//			if (i == 1)
//				cout << "Them thanh cong\n";
//			cout << "Danh sach sau khi them\n";
//			list();
//			break;
//		}
//		case 3:
//		{
//			cout << "Danh sach\n";
//			list();
//			break;
//		}
//		case 4:
//		{
//			cout << "Nhap vao gia tri can tim\n";
//			cin >> x;
//			p = search(x);
//			if (p != NULL)
//			{
//				cout << "Tim thay x\n";
//			}
//			else
//				cout << "Khong tim thay x\n";
//			break;
//		}
//		case 5:
//		{
//			cout << "Nhap vao gia can tim va xoa\n";
//			cin >> x;
//			i = search_delete(x);
//			if (i == 0)
//				cout << "Danh sach rong, khong the tim va xoa gia tri\n";
//			else
//				if (i == -1)
//					cout << "Khong tim thay x\n";
//				else
//				{
//					cout << "Tim thay x va xoa thanh cong x\n";
//					cout << "Danh sach sau khi xoa x\n";
//					list();
//				}
//			break;
//		}
//		}
//	} while (temp != 6);
//	system("pause");
//	return 0;
//}