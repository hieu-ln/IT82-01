#include <iostream>
using namespace std;

#define max 100
struct node {
	int info;
	node *link;
};
node *first[max];
int n;
//Câu 7.2

void output_list(node *f) 
{
	if (f != NULL)
	{
		node *p = f;
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
	}
}

void output()
{
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			cout << endl << "Danh sach thu " << i + 1 << ": ";
			output_list(first[i]);
		}
	else
		cout << "Rong\n";
}
