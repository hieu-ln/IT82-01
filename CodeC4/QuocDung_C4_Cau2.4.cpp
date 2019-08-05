#include<iostream>
using namespace std;
struct node {
	int info;
	node *left, *right;
};
//Câu 2.4: tìm kiếm trong cây nhị phân tìm kiếm không dùng đệ quy
node *search(node *p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info < x)
				p = p->right;
			else
				p = p->right;
	}
}
