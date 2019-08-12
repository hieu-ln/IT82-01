//#include <iostream>
//#include <fstream>
//using namespace std;
//#define max 20
//int n;
//int a[max][max];
//char vertext[max];
//
///* Nhap tu file */
//void InputGraphFromText()
//{
//	string line;
//	ifstream myfile("mtts1.txt");
//	if (myfile.is_open())
//	{
//		myfile >> n;
//		for (int i = 0; i < n; i++)
//			myfile >> vertext[i];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//				myfile >> a[i][j];
//		}
//	}
//}
///* Prim */
//int E1[max], E2[max], wE[max], nE = 0;
//int T1[max], T2[max], wT[max], nT = 0;
//
//int TonTai(int d, int D[], int nD)
//{
//	for (int i = 0; i < nD; i++)
//		if (D[i] == d)
//			return 1;
//	return 0;
//}
//
//void XoaViTriE(int i)
//{
//	for (int j = i; j < nE; j++)
//	{
//		E1[j] = E1[j + 1];
//		E2[j] = E2[j + 1];
//		wE[j] = wE[j + 1];
//	}
//	nE--;
//}
//
//void XoaCanhE(int u, int v)
//{
//	for (int i = 0; i < nE; i++)
//		if (E1[i] == u && E2[i] == v)
//		{
//			XoaViTriE(i);
//			break;
//		}
//}
//
//void prim(int s)
//{
//	int u = s, min, i, d1, d2;
//	while (nT < n - 1)
//	{
//		for (int v = 0; v < n; v++)
//		{
//			if (a[u][v] != 0)
//				if (TonTai(v, T2, nT) == 0)
//				{
//					E1[nE] = u;
//					E2[nE] = v;
//					wE[nE] = a[u][v];
//					nE++;
//				}
//		}
//		for (i = 0; i < nE; i++)
//		{
//			if (TonTai(E2[i], T2, nT) == 0)
//			{
//				min = wE[i];
//				d1 = E1[i];
//				d2 = E2[i];
//				break;
//			}
//		}
//		for (i = 0; i < nE; i++)
//		{
//			if (TonTai(E2[i], T2, nT) == 0)
//				if (min > wE[i])
//				{
//					min = wE[i];
//					d1 = E1[i];
//					d2 = E2[i];
//				}
//		}
//		T1[nT] = d1;
//		T2[nT] = d2;
//		wT[nT] = a[d1][d2];
//		a[d1][d2] = 0;
//		a[d2][d1] = 0;
//		nT++;
//		XoaCanhE(d1, d2);
//		u = d2;
//	}
//}