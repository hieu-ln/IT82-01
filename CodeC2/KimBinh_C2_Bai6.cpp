#include <iostream>
using namespace std;

#define max 100
int a[max], sp;

void init()
{
	sp = -1;
}
void push(int a[], int &sp, int x)
{
	if (sp < max - 1)
	{
		a[sp] = x;
		sp++;
	}
}
int pop(int a[], int &sp)
{
	int x = 0;
	if (sp > -1)
	{
		x = a[sp-1];
		sp = sp - 1;
	}

	return x;
}

int main()
{
	int temp,x,sodu,i;
	cout << "Nhap vao so thap phan: ";
	cin >> x;
	temp = x;
	init();
	//gắn số 1 và 0 vào trong stack
	while (temp > 0)
	{
		sodu = temp % 2;
		push(a, sp, sodu);
		temp = temp / 2;
	}
	//lấy số 1 và 0 ra khỏi stack (ghép thành số nhị phân)

	cout << "So nhi phan cua so " << x << " la: ";
	while (sp > -1)
	{
		i = pop(a, sp);
		cout << i;
	}
	cout << endl;
	system("pause");
	return 0;
}