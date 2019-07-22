//Bai1, chương 3: Xep thu tu , tim kiem
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

#define MAX 5000
//cau 1.1
int a[MAX];
int n;

//1.0:KHOI TAO NGAU NHIEN NHAP TU DONG
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach:";
	cin >> n;
	for(int i =0;i <n; i++)
	{
		a[i]= rand() % 10000 + 1; // tao ngau nhien
	}
	cout<<"Danh sach da duoc nhap ngau nhien nhu sau:"<< endl;
	for(int i = 0; i<n ; i++)
	{
		cout << a[i] <<"   ";
	}
	cout << endl;
}

//cau 1.2 : Thủ tục nhập DS
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach";
	cin >> n;
	cout<< "Nhap vao cac phan tu cua danh sach:" << endl;
	for(int i =0 ; i< n ; i++)
	{
		cout <<"a[" <<i <<"]";
		cin >> a[i];
	}
}

//cau1.3: XUAT DANH SACH
void output(int a[], int &n)
{
	for(int i =0 ; i< n; i++)
	{
		cout<< a[i]<<"  ";
	}
	cout << endl;
}

void CopyArray (int a[], int b[], int n)
{
	for (int i=0; i < n;i++)
	{
		b[i]=a[i]; // gán gtri b cho a
	}
}

//cau 1.4: Insertion Sort
void Insertion(int a[], int n)
{
	int i , key, j;
	for(i = 1 ;i < n ; i++)
	{
		key = a[i];
		j=i-1;
		// Di chuyển các ptu có gtri lớn hơn giá trị key về sau 1 vị trí so với vị trí ban đầu của nó//
		while (j >=0 && a[j] > key)
		{
			a[j+1] =a [j] ;// về sau 1 vi trí
			j=j-1;
		}
		a[j+1] = key;
	}
}

//ham doi cho 2 so nguyen
void swap(int &a,int &b)
{
	int t = a; // gán t để trung gian hoán đổi a vs b
	a=b;
	b=t;
}

//cau5 :  Selection sort
void selectionSort(int a[],int n)
{
	int i,j,min_idx;
	//di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for(i=0; i< n ; i++)
	{
		// Tìm phân tử nhỏ nhất trong mảng chưa sắp xếp
		min_idx = i;//phân tử nhỏ nhất trong mảng chưa sắp xếp
		for(j = i+1; j < n;j++)
			if(a[j] < a[min_idx])
				min_idx = j;
		// Đổi chỗ ptu nho nhat vs ptu đầu tiên
		swap (a[min_idx], a[i]);
	}
}

//cau1.6
void interchangesort(int a[], int n)
{
	for(int i =0 ; i<n; i++)
		for(int j = i + 1 ; j < n;  j++)
			if(a[i]>a[j])
				swap (a[i],a[j]);

}

//Cau1.7: Hàm sắp xếp Bubble Sort  ????!!!
void bubbleSort(int a[], int n) // lập để xét thứ tự
{
	for(int i=0; i<n-1;i++)
		for(int j = n-1 ; j>i; j-- )
			if(a[j-1]>a[j])// dk ptu sau nho hon ptu truoc
				swap(a[j],a[j-1]);
}

// cau 1.8 : quicksort
// sếp thứ tự tăng dần
int partition(int a[], int low , int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot) left ++;
		while (right >= left && a[right] > pivot ) right --;
		if (left >= right ) break; // k đúng (j >i)
		swap (a[left],a[right]);
		left ++ ;
		right --;
		
	}
	swap (a[left],a[high]);
	return left;
}
// Hàm thực hiện giải thuật quicksort
void quickSort(int a[], int low, int high)
{
	if(low < high)
	{
		//pi la chỉ số nơi vi tri  này đứng đúng và chia thành 2 mảng con trái phải
		int pi = partition(a, low,high);

		//Gọi đệ quy sắp xếp 2 mảng con trái vs phải
		quickSort(a,low,pi - 1);
		quickSort(a,pi + 1,high);
	}
}



//1.9: Tăng dần HeapSort - xét 4 trường hợp
void heapify(int a[], int n , int i)
{
	int largest = i; // initialize largest as root
	int l = 2*i+1;
	int r= 2*i+2;

	// Nếu trái dài hơn root (cha)
	if(l < n && a[l] > a[largest])
		largest = 1;

	// Nếu phai dài hơn root (cha)
	if(r < n && a[r] > a[largest])
		largest =r;

	// Nếu largest k phải là cha
	if(largest !=i)
	{
		swap(a[i],a[largest]);
		
		heapify(a,n,largest);
	}
}

//main function to do heap sort
void heapSort(int a[], int n)
{
	//Build heap (rearrange array)
	for(int i = n/2 -1;i>=0;i--)
		heapify (a,n,i);

	// one by one extract an element from heap
	for(int i =n-1; i >=0 ;i--)
	{
		// Move current root to end
		swap(a[0],a[i]);
		//call max heapify 
		heapify(a,i,0);
	}
}

//cau 1.10 : Viết tìm 1 ptu trong ds có thứ tự(tìm kiếm tuần tự) .Đánh giá độ phức tạp của bài toán
void searchSequence(int a[],int n , int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if(i==n)
	{
		cout << "Khong tim thay";
	}
	else 
	{
		cout << "Tìm thấy tai vi tri i = "<<i; // vì lúc đó i++
	}
}

//cau 1.11: Viết tìm 1 ptu trong ds có thứ tự(tìm kiếm nhị phân) .Đánh giá độ phức tạp của bài toán
int searchBinary(int a[], int l, int r , int x)
{
	if(r >= l)
	{
		int mid = l+(r-l)/2;//ưu đỉm tránh tràn số khi l, r lớn
		// nếu a[mid] = x, trả về chỉ số và kết thúc
		if (a[mid] ==x)
			return mid;

		// nếu a[mid]>x, thực hiện tìm kiếm nửa trái của bàng
		if (a[mid] > x)
			return searchBinary(a,l,mid - 1 ,x);

		//nếu a[mid] < x , thực hiện tìm kiếm nửa phải của bảng
		if (a[mid] < x)
			return searchBinary(a,mid +1,r ,x); 

	}
	// Nếu k tìm thấy
	return -1;
}


int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice , x, i;
	system("cls");
	cout <<"----------BAI TAP 1 CHUONG 3, XẾP THỨ TỰ - TÌM KIẾM-----" << endl;
	cout <<"0. Khoi tao danh sach ngau nhien" << endl;
	cout <<"1.Nhap ds"<< endl;
	cout <<"2.Xuat ds"<< endl;
	cout <<"3.Xep thu tu ds = SELECTION SORT"<< endl;
	cout <<"4.Xep thu tu ds = INSERTION SORT"<< endl;
	cout <<"5.Xep thu tu ds = BUBBLE SORT"<< endl;
	cout <<"6.Xep thu tu ds = INTERCHANGE SORT"<< endl;
	cout <<"7.Xep thu tu ds = QUICK SORT"<< endl;
	cout <<"8.Xep thu tu ds = HEAP SORT"<< endl;
	cout <<"9.Tim kiem ptu x bang TIM KIEM TUAN TU"<< endl;
	cout <<"10.Tim kiem ptu x bang TIM KIEM NHI PHAN"<< endl;
	cout << "11.Thoat" << endl;


	do
	{
		cout<<"\n Vui long chon so de thuc hien:";
		cin>> choice;
		switch(choice)
		{
		case 0:
			init(a, n);
			break;
		case 1 :
			input(a,n);
			break;
		case 2:
			cout << "Danh sach la:"<< endl;
			output(a,n);
			break;
		case 3:
			CopyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout <<"DS sau khi xep thu tu voi SELECTION SORT la :"<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout<<"Thoi gian SELECTION SORT:" << duration * 1000000<< " Microseconds"<< endl;
			break;
		case 4:
			CopyArray(a,b,n);
			start= clock();
			Insertion(b,n);
			duration = (clock()- start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout <<"DS sau khi xep thu tu voi Insertion SORT la :"<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout<<"Thoi gian Insertion SORT:" << duration * 1000000<< " Microseconds"<< endl;
			break;
		case 5 :
			CopyArray(a,b,n);
			start= clock();
			bubbleSort(b,n);
			duration = (clock()- start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout <<"DS sau khi xep thu tu voi bubbleSort SORT la :"<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout<<"Thoi gian bubbleSort SORT:" << duration * 1000000<< " Microseconds"<< endl;
			break;
		case 6 :
			CopyArray(a,b,n);
			start= clock();
			interchangesort(b,n);
			duration = (clock()- start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout <<"DS sau khi xep thu tu voi interchangesort SORT la :"<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout<<"Thoi gian interchangesort SORT:" << duration * 1000000<< " Microseconds"<< endl;
			break;
		case 7:
			CopyArray(a,b,n);
			start= clock();
			quickSort(b,0,n-1);
			duration = (clock()- start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout <<"DS sau khi xep thu tu voi interchangsort SORT la :"<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout<<"Thoi gian quickSort SORT:" << duration * 1000000<< " Microseconds"<< endl;
			break;
		case 8:
			CopyArray(a,b,n);
			start= clock();
			heapSort(b,n);
			duration = (clock()- start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout <<"DS sau khi xep thu tu voi heapSort SORT la :"<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout<<"Thoi gian heapSort SORT:" << duration * 1000000<< " Microseconds"<< endl;
			break;
		case 9:
			cout<< "Vui long nhap gia tri x= ";
			cin >> x;
			start = clock();
			searchSequence(a,n,x);
			duration= (clock()- start) / (double) CLOCKS_PER_SEC;
			if(duration > 0)
				cout << "\n Thoi gian tim kiem TUAN TU là " <<  duration * 1000000 << " Microseconds"<< endl;
			break;
		case 10:
			cout<< "Vui long nhap gia tri x= ";
			cin >> x;
			start = clock();
			i= searchBinary(b,0,n,x);// xét bảng b 
			duration= (clock()- start) / (double) CLOCKS_PER_SEC;
			if(i ==-1)
				cout <<"khong tim thay x ="<<x<<"trong day! "<< endl;
			else
				cout <<"tim thay x =" <<x<<"tai vi tri i=" <<i<< endl;
			if(duration > 0)
				cout << "\n Thoi gian tim kiem NHI PHAN là " <<  duration * 1000000 << " Microseconds"<< endl;
			break;
		case 11:
			cout<<" Good bye ! " << endl;
			break;
		default:
			break;

		}

	}
	while(choice !=11);
	system("pause");
	return 0;
}