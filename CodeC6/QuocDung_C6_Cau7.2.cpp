
//#include<iostream>
//#include<stdio.h>
//#include <fstream>
//#include<iomanip>
//using namespace std;
//#define max 20
//int a[max][max];
//int n;
//char vertex[max];
//
//void inputGraphFromText()
//{
//	string line;
//	ifstream myfile ("mtts1.txt");
//	if (myfile.is_open())
//	{
//		myfile>>n;
//		for(int i=0; i<n; i++)
//			myfile>>vertex[i];
//		for(int i=0; i<n; i++)
//		{
//			for(int j=0; j<n; j++)
//				myfile>>a[i][j];
//		}
//	}
//}
//
//int e1[max];
//int e2[max];
//int wE[max];
//int nE=0;
//
//int t1[max];
//int t2[max];
//int wT[max]; 
//
//int nT=0;
//int tonTai(int d, int D[], int nD)
//{
//	for(int i=0; i<nD; i++)
//		if(D[i]==d)
//			return 1;
//	return 0;
//}
//
//void xoaVTE(int i)
//{
//	for(int j=i; j<nE; j++)
//	{
//		e1[j]=e1[j+1];
//		e2[j]=e2[j+1];
//		wE[j]=wE[j+1];
//	}
//	nE--;
//}
//
//void sapxep() 
//{
//	for (int i = 0; i < nE - 1; i++)
//	{
//		for (int j = 0; j < nE; j++)
//		{
//			if (wE[i] > wE[j])
//			{
//				swap(wE[i], wE[j]);
//				swap(e1[i], e1[j]);
//				swap(e2[i], e2[j]);
//			}
//		}
//	}
//}
//void kruskal() 
//{
//	for (int i = 0; i < nE; i++)
//	{
//		if (tonTai(e1[i], t1, nT) == 1 && tonTai(e2[i], t2, nT) == 1)
//			continue;
//		if (tonTai(e1[i], t2, nT) == 1 && tonTai(e2[i], t1, nT) == 1)
//			continue;
//		t1[nT] = e1[i];
//		t2[nT] = e2[i];
//		wT[nT] = wE[i];
//		nT++;
//		if (nT == n - 1)
//			break;
//	}
//}
