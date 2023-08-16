#include<conio.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<fstream>
//total hours: 192
using namespace std;
class thuoc{ //lop cha
private:
	int ID_thuoc;
	string name;
	int soluong;
	float price;
public://dong goi
	void set_ID_thuoc(int x)
	{
		ID_thuoc=x;
	}
	void set_name(string y)
	{
		name=y;
	}
	void set_soluong(int z)
	{
		soluong=z;
	}
	void set_price(float t)
	{
		price=t;
	}
	//dong goi
	int get_ID_thuoc()
	{
		return ID_thuoc;
	};
	string get_name()
	{
		return name;
	};
	int get_soluong()
	{
		return soluong;
	};
	float get_price()
	{
		return price;
	};

	virtual float tinh_gia_tien() //da hinh
	{
        return soluong * price;
    }
};
class thuoc_gia_moi : public thuoc //ke thua
{//lop con
public:
    float tinh_gia_tien() override //da hinh
	{
		int x=get_soluong();
		float y=get_price();
		return float(x*y* 1.2); //tang them 20%
    }
};
void nhap_data(thuoc a[])
{
	ifstream doc;
	//string duong_dan;
	//cout<<"\n\t Nhap duong dan: ";
	//cin>>duong_dan;
	/*"C:\\Users\\hient\\OneDrive\\Desktop\\data\\data_oop.txt"*/
	doc.open("C:\\Users\\hient\\OneDrive\\Desktop\\data\\data_oop.txt");
	for(int i=0;i<100;i++)
	{
		int x=0,z=0;
		string y;
		float t=0;
		doc>>x>>y>>z>>t;
		a[i].set_ID_thuoc(x);
		a[i].set_name(y);
		a[i].set_soluong(z);
		a[i].set_price(t);
	}
	doc.close();
}
void ghi_file(thuoc a[])
{
	ofstream ghi;
	//string duong_dan;
	//cout<<"\n\t Nhap duong dan: ";
	//cin>>duong_dan;
	////"C:\\Users\\hient\\OneDrive\\Desktop\\data\\oop_out.txt"
	ghi.open("C:\\Users\\hient\\OneDrive\\Desktop\\data\\oop_out.txt");
	int n = 0;
    while (a[n].get_ID_thuoc() != 0) n++;
	for(int i=0;i<n;i++)
	{
		ghi<<a[i].get_ID_thuoc()<<" "<<a[i].get_name()<<" "<<a[i].get_soluong()<<" "<<a[i].get_price()<<endl;

	}
	ghi.close();
}
void xuat_data(thuoc a[]) 
{
	if(a!=NULL)
	{
		cout << setw(10) << left <<"|MA THUOC"<< setw(20) << left <<"|TEN"<< setw(15) << left <<"|SO LUONG"<< setw(10) << left <<"|GIA (NGHIN DONG)"<< endl;
		cout << setw(10) << left <<"|________"<< setw(20) << left <<"|___"<< setw(15) << left <<"|________"<< setw(10) << left <<"|________________"<< endl;
		for (int i = 0; i < 100; i++) 
		{
			if (a[i].get_ID_thuoc() != 0) 
			{
				cout << setw(10) << left << a[i].get_ID_thuoc()<< setw(20) << left << a[i].get_name()<< setw(15) << left << a[i].get_soluong()<< setw(10) << left << a[i].get_price() << endl;
			}
		}
	}
	else cout<<"Chua co danh sach nao!"<<endl;
}
void timkiem(thuoc a[])
{
	int id;
	cout<<"\n\t\t Nhap ma thuoc muon tim kiem: ";
	cin>>id;
	int dem=0;
	int n = 0;
    while (a[n].get_ID_thuoc() != 0) n++;
	for(int i=0;i<n;i++)
	{
		if(id==a[i].get_ID_thuoc())
		{
			cout << setw(10) << left <<"|MA THUOC"<< setw(20) << left <<"|TEN"<< setw(15) << left <<"|SO LUONG"<< setw(10) << left <<"|GIA (NGHIN DONG)"<< endl;
			cout << setw(10) << left <<"|________"<< setw(20) << left <<"|___"<< setw(15) << left <<"|________"<< setw(10) << left <<"|________________"<< endl;
			cout << setw(10) << left << a[i].get_ID_thuoc()<< setw(20) << left << a[i].get_name()<< setw(15) << left << a[i].get_soluong()<< setw(10) << left << a[i].get_price() << endl;
			dem++;
		}
	}
	if(dem==0) cout<<"\n\n\t KHONG TIM THAY LOAI THUOC NAY!!!"<<endl;
}
void them(thuoc a[])
{
    int index = 0;
    // tìm vị trí cuối cùng trong danh sách
    while (a[index].get_ID_thuoc() != 0)
    {
        index++;
    }

    // nhập thông tin cho thuốc mới
    int id, sl;
    float price;
    string name;
    cout << "\nNhap ma thuoc: ";
    cin >> id;
    cout << "Nhap ten thuoc: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap so luong: ";
    cin >> sl;
    cout << "Nhap gia: ";
    cin >> price;

    // dịch chuyển các phần tử của danh sách để tạo vị trí mới cho thuốc mới
    for (int i = index; i >= 1; i--)
    {
        a[i] = a[i-1];
    }

    // gán thông tin cho thuốc mới vào vị trí mới của danh sách
    a[0].set_ID_thuoc(id);
    a[0].set_name(name);
    a[0].set_soluong(sl);
    a[0].set_price(price);

    cout << "\n\nThem thanh cong! Nhan phim bat ki de quay lai Menu";
    getch();
}
void sua_thuoc(thuoc a[], int id)
{
    int index = -1;
	int n = 0;
    while (a[n].get_ID_thuoc() != 0) n++;
    for (int i = 0; i < n; i++)
    {
        if (a[i].get_ID_thuoc() == id)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Khong tim thay loai thuoc co ma so " << id << endl;
    }
    else
    {
        cout << "Nhap ten thuoc moi: ";
        string name;
        cin >> name;
        a[index].set_name(name);

        cout << "Nhap so luong thuoc moi: ";
        int soluong;
        cin >> soluong;
        a[index].set_soluong(soluong);

        cout << "Nhap gia thuoc moi: ";
        float price;
        cin >> price;
        a[index].set_price(price);

        cout << "Da sua doi thanh cong loai thuoc co ma so " << id << endl;
    }
}
void sapxep_data_name(thuoc a[])
{
    int n = 0;
    while (a[n].get_ID_thuoc() != 0) n++; // đếm số lượng phần tử trong danh sách

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (a[j].get_name() > a[j + 1].get_name()) // so sánh theo tên (dùng phương thức get_name)
            {
                // hoán đổi vị trí 2 phần tử
                thuoc tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void sapxep_data_id(thuoc a[])
{
    int n = 0;
    while (a[n].get_ID_thuoc() != 0) n++; // đếm số lượng phần tử trong danh sách

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (a[j].get_ID_thuoc() > a[j + 1].get_ID_thuoc()) // so sánh theo ID_thuoc (dùng phương thức get_ID_thuoc)
            {
                // hoán đổi vị trí 2 phần tử
                thuoc tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void tinhtong(thuoc a[])
{
	int n = 0;
    while (a[n].get_ID_thuoc() != 0) n++;
	float tong=0,tong_goc=0;
	for (int i=0;i<n;i++)
	{
		thuoc_gia_moi b;
		b.set_soluong(a[i].get_soluong());
		b.set_price(a[i].get_price());
		tong=tong+b.tinh_gia_tien();
		tong_goc=tong_goc+a[i].tinh_gia_tien();
	}
	cout<<"\n\t\t Tong tien ban dau cua danh sach la: "<<tong_goc<< "\tdon vi (nghin dong)"<<endl;
	cout<<"\n\t\t Tong tien sau thue cua danh sach la: "<<tong<< "\tdon vi (nghin dong)"<<endl;
}
void menu(thuoc a[])
{
	int choice = 1;
	do {
		system("cls");
		cout << "\n1. Nhap danh sach tu file" << endl;
		cout << "2. In danh sach ra man hinh" << endl;
		cout << "3. Tim kiem theo Ma Thuoc" << endl;
		cout << "4. Them vao danh sach" << endl;
		cout<<"5. Sua thong tin thuoc"<<endl;
		cout<<"6. Sap xep lai danh sach theo TEN THUOC"<<endl;
		cout<<"7. Sap xep lai danh sach theo MA SO THUOC"<<endl;
		cout<<"8. Xuat file"<<endl;
		cout<<"9. Tinh tong tien san pham"<<endl;
		char x;
		cout << "\n\t Vui long chon hanh dong: ";
		cin >> x; 
		if (x == '1')
		{
			nhap_data(a);
			cout << "\n\nHanh dong 1 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '2')
		{
			xuat_data(a);
			cout << "\n\nHanh dong 2 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '3')
		{
			timkiem(a);
			cout << "\n\nHanh dong 3 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '4')
		{	
			them(a);
			cout << "\n\nHanh dong 4 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '5')
		{
			int id_cantim;
			cout<<"Nhap vao ma so can tim: ";
			cin>>id_cantim;
			sua_thuoc(a,id_cantim);
			cout << "\n\nHanh dong 5 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '6')
		{	
			sapxep_data_name(a);
			cout << "\n\nHanh dong 6 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '7')
		{	
			sapxep_data_id(a);
			cout << "\n\nHanh dong 7 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '8')
		{	
			ghi_file(a);
			cout << "\n\nHanh dong 8 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else if (x == '9')
		{	
			tinhtong(a);
			cout << "\n\nHanh dong 9 da duoc thuc thi! Nhan phim bat ki de quay lai Menu";
			getch();
		}
		else
		{
			cout << "\n\nKhong co hanh dong nay. Vui long chon lai!";
			getch();
		}
	} while (choice != 0);
}
int main()
{
	thuoc a[100];
	menu(a);
	getch();
	return 0;
}