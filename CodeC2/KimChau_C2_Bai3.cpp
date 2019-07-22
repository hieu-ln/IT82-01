//Bai 3, chuong 2: Danh sach lien ket don
#include <stdio.h>
#include <iostream>
using namespace std;

//3.1: Khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};
Node *first;

//3.2 : Khoi tao danh sach rong
void Init()
{
	first = NULL;
}

//3.3: Xuat cac ptu trong DS
void Process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

//Cau 3.4: Tim 1 ptu trong DS
Node *Search(int x)
{
	Node *p = first;
	while (p != NULL & p->info != x)
	{
		p = p->link;
	}
	return p;
}

//Cau 3.5: Them ptu vao dau DS

void insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

// 3.6: Xoa ptu dau DS
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//3.7 : them phan tu cuoi danh sach
void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else {
		Node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

//3.8: Xoa phan tu cuoi danh sach
int Delete_last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else first = NULL;
		delete p; // tại vì gán q = p r và trỏ về link

		return 1;
	}
	return 0;
}

// 3.9 : Tim ptu trong ds r xoa ptu neu co
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link == NULL)
		{
			//phan tu giua ds
			if (p->link != NULL)
			{
				q->link = p->link;
			}
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if (p == first)
		{
			// phantu dau ds
			first = p->link;
			delete p;
			return 1;
		}
		else if (p->link == NULL && p->info == x)
		{
			//phantu cuoi ds
			q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
// ham doi cho gia tri cua 2 phantu
void swap(Node *a,Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

//3.10: Sap xep ds co thu tu tang dan (NHO DEN LON)
//sdung selection-sort
void Sort()
{
	Node *p, *q, *min;
	//Di chuyen ranh gioi cua mang da sap xếp và chưa sắp xếp
	p = first;
	while (p != NULL)
	{
		// tìm ohan tử nhỏ nhất trong mảng chưa sắp xếp
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}
		//Đổi chỗ ptu nho nhat vs ptu dau tiên
		swap(min, p);
		p = p->link;
	}
}

// 3.10: Sắp xếp ds co thứ tự giam dan (LỚN ĐẾN BÉ)
void SortDec()
{
	Node *p, *q, *max;
	//Di chuyen ranh gioi cua mang da sap xếp và chưa sắp xếp
	p = first;
	while (p != NULL)
	{
		// tìm ohan tử lớn nhất trong mảng chưa sắp xếp
		max = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info > max->info)
				max = q;
			q = q->link;
		}
		//Đổi chỗ ptu lớn nhat vs ptu dau tiên
		swap(max, p);
		p = p->link;
	}
}


int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "---------BAI TAP 3 , CHUONG 2 , DANH SACH LIEN KET DON ----";
	cout << "1. Khoi tao dslk don" << endl;
	cout << "2. Them ptu vao dau ds" << endl;
	cout << "3. Them ptu vao cuoi ds" << endl;
	cout << "4. Xoa ptu vao dau ds" << endl;
	cout << "5. Xoa ptu vao cuoi ds" << endl;
	cout << "6. Xuat dslk don" << endl;
	cout << "7.Tim 1 ptu co gia tri x trong DSLK DON" << endl;
	cout << "8.Tim 1 ptu co gia tri x và xóa nếu có" << endl;
	cout << "9.Sap xep dslk don tang dan" << endl;
	cout << "10.Sap xep dslk don giam dan" << endl;
	cout << "11. Thoat" << endl;

	do
	{
		cout << "\n Vui long chon so de thuc hien";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao DSLK don thanh cong";
			break;
		case 2:
			cout << "Vui long nhap gia tri x= ";
			cin >> x;
			insert_first(x);
			cout << "Danh sach sau khi them la";
			Process_list();
			break;

		case 3:
			cout << "Vui long nhap gia tri x= ";
			cin >> x;
			Insert_last(x);
			cout << "Danh sach sau khi them la";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if (i = 0)
				cout << "Danh sach rong , khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong ptu dau ds" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if (i = 0)
				cout << "Danh sach rong , khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong ptu cuoi ds" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la: " << endl;
			break;
		case 7:
			cout << "Vui long nhap gia tri can tim x= ";
			cin >> x;
			p = Search(x);
			if (p != NULL)
			{
				cout << "Tim thay x=" << x << endl;
			}
			else
				cout << "Khong tim thay phan tu co gia tri" << x << "!!" << endl;
			break;
		case 8:
			cout << "Vui long nhap gia tri can tim x= ";
			cin >> x;
			i = SearchAndDelete(x);
			if (i = 1)
			{
				cout << "Tim thay x=" << x << "Va da xoa thanh cong  " << endl;
				cout << "Ds sau khi xoa la : ";
				Process_list();
			}
			else
				cout << "Khong tim thay phan tu co gia tri" << x << "!!" << endl;
			break;
		case 9:
			SortDec();
			cout << "Danh sach sau khi sap xep tang dan la: " << endl;
			Process_list();
			break;
		case 10:
			SortDec();
			cout << "Danh sach sau khi sap xep giam dan la: " << endl;
			Process_list();
			break;
		case 11:
			cout << "Goodbye ...!" << endl;

			break;
		default:
			break;
		}

	} while (choice != 11);
	system("pause");
	return 0;
}