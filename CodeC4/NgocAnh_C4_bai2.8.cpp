#include<iostream>
using namespace std;
struct node
{
	int info;
	node *left, *right;
};
// Viet thu tuc duyet cay theo thu tu LRN (dung QUEUE)
void LRN(TREE Root)
{
	if(Root != NULL)
	{
		LRN(Root->Left)
			LRN(Root->Right); // xử lý Root, xử lý tương ứng theo nhu cầu
	}
}
