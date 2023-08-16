#include<conio.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<fstream>
//total hours: 169
//Nguyễn Hoàng Tùng	19200559
//Nguyễn Trung Hiếu	20200199
//Bùi Quốc Hưng	20200211
//fetel hcmus
//OOP thầy LÊ ĐỨC TRỊ
using namespace std;
class date {
private:
	int ngay;
	int thang;
	int nam;
public:
	int get_ngay(){ 
		return ngay; 
	}
	void set_ngay(int NGAY) { 
		ngay = NGAY; 
	}
	int get_thang() {
		return thang; 
	}
	void set_thang(int THANG) {
		thang=THANG; 
	}
	int get_nam() { 
		return nam; 
	}
	void set_nam(int NAM) {
		nam = NAM; 
	}
};
class thuoc
{
protected:
	string Mathuoc;
	string ten_thuoc;
	date ngay_hethan;
	float gia; 
	int soluong;
public:
	//da hinh 
	// phuong thuc ao
	virtual void Doc_file(ifstream&);
	//da hinh
	virtual void xuat();
	//dong doi
	date get_hethan() {
		return ngay_hethan;
	}
	string get_Mathuoc() {
		return Mathuoc;
	}  //dong goi
	string get_tenthuoc() {
		return ten_thuoc;
	}
	float get_gia()
	{
		return gia;
	}
	int get_soluong() {
		return soluong;
	}
	void set_sl(int x) {
		soluong = x;
	}
	void set_gia(float y)
	{
		y = gia;
	}
	void set_Mathuoc(string z)
	{
		z = Mathuoc;
	}
	void set_tenthuoc(string t)
	{
		t = ten_thuoc;
	}
};
void thuoc::Doc_file(ifstream& filein) {
	getline(filein, Mathuoc, ',');
	filein.seekg(1, 1);
	getline(filein, ten_thuoc, ',');
	int ngay;
	filein >> ngay;
	ngay_hethan.set_ngay(ngay); filein.seekg(1, 1);
	int thang;
	filein >> thang;
	ngay_hethan.set_thang(thang); filein.seekg(1, 1);
	int nam;
	filein >>nam;
	ngay_hethan.set_nam(nam); filein.seekg(1, 1);
	filein >> gia; filein.seekg(1, 1);
	filein >> soluong; filein.seekg(1, 1);
}
void thuoc::xuat() {
	std::cout<<"|===================================================================================================|"<<endl;
	std::cout <<'|' << setw(7) << Mathuoc << setw(4) << "|" << setw(20) << ten_thuoc << setw(2) << "|" << setw(7) << ngay_hethan.get_ngay() << '/' << setw(2) << ngay_hethan.get_thang() << '/' << ngay_hethan.get_nam() << setw(3) << "|";
	std::cout << setw(12) << gia<<setw(4)<< "VND"<<'|' << setw(10) << soluong<<setw(3)<<"|";
}
class thuoc_bo :public thuoc 
{
private:
	float tro_gia;
public:
	void Doc_file(ifstream&);
	void xuat();
};
void thuoc_bo::Doc_file(ifstream &filein) {
	thuoc::Doc_file(filein);
	filein >> tro_gia;
}
void thuoc_bo::xuat() {
	thuoc::xuat();
	std::cout <<setw(8)<<tro_gia<<"(tro gia)" << setw(2) << "|" << endl;
}
//lop con
//tinh da hinh tu lop cha "thuoc"
class thuoc_dieu_tri :public thuoc {
private: 
	float phi_tu_van;
public:
	void Doc_file(ifstream&);
	void xuat();
};
void thuoc_dieu_tri::Doc_file(ifstream& filein) {
	thuoc::Doc_file(filein);
	filein >> phi_tu_van;
}
void thuoc_dieu_tri::xuat() {
	thuoc::xuat();
	std::cout << setw(8) << phi_tu_van<<"(tu van)"<<setw(3)<<"|"<<endl;
}
class customer {
private:
	int so_hd,sl_thuoc;
	string ten_kh;
	date ngay_tao;
	float total;
public:
	
	void khach_hang() {
		int ngay, thang, nam;
		std::cin.ignore();
		std::cout << "\nNhap Ten khach hang: "; getline(std::cin,ten_kh);
		std::cout << "\nNhap ngay: "; std::cin >> ngay; ngay_tao.set_ngay(ngay);
		std::cout << "thang: "; std::cin >> thang; ngay_tao.set_thang(thang);
		std::cout << "nam: "; std::cin >> nam; ngay_tao.set_nam(nam);
	}
	void xuat_ngay() {
		std::cout <<ngay_tao.get_ngay() << '/' << ngay_tao.get_thang() << '/' << ngay_tao.get_nam();
	}
	void xuat_tt_kh() {
		std::cout << "SO HD: " << so_hd<< endl;
		std::cout << "KHACH HANG: " << ten_kh << endl;
	}
	void set_tenKH(string ten) {
		ten_kh == ten;
	}
	void set_soHD(int x) {
		so_hd = x;
	}
	string get_tenKH() {
		return ten_kh;
	}
	int get_soHD() {
		return so_hd;
	}
	void set_sl_thuoc(int x) {
		sl_thuoc = x;
	}
	int get_sl_thuoc() {
		return sl_thuoc;
	}
	void set_total(float y) {
		total = y;
	}
	float get_total() {
		return total;
	}
};
class order {
private:
	float gia;
	int sl_mua;
	string ten_thuoc, ma_thuoc;
public:
	void set_gia(float g) {
		gia = g;
	}
	float get_gia() {
		return gia;
	}
	int get_sl_mua() {
		return sl_mua;
	}
	void set_sl_mua(int x) {
		sl_mua = x;
	}
	void set_tenthuoc(string ten) {
		ten_thuoc = ten;
	}
	void set_mathuoc(string ma) {
		ma_thuoc = ma;
	}
	string getma() {
		return ma_thuoc;
	}
	string getten() {
		return ten_thuoc;
	}
};
void xuat_dsthuoc(thuoc *ds[], int n) {
	std::cout << "+==========+=====================+=================+================+============+==================+";
	std::cout << "\n" << "|" << " Ma thuoc" << setw(2) << "|" << setw(15) << "Ten Thuoc" << setw(7) << "|" << setw(15) << "Ngay het han" << setw(3) << "|" << setw(10) << "GIA" << setw(7) << "|" << setw(10) << "SO LUONG" << setw(3) << "|" << setw(16) << "tro gia/tu van" << setw(3) << "|" << endl;
	for (int i = 0; i < n; i++) {
		ds[i]->xuat();
	}
}
void timkiemMathuoc(thuoc *ds[], int n) {
	string ma;
	int dem=0;
	std::cout << " \n Nhap ma thuoc can tim: "; std::cin >> ma;
	std::cout << "+==========+=====================+=================+================+============+==================+";
	std::cout << "\n" << "|" << " Ma thuoc" << setw(2) << "|" << setw(15) << "Ten Thuoc" << setw(7) << "|" << setw(15) << "Ngay het han" << setw(3) << "|" << setw(10) << "GIA" << setw(7) << "|" << setw(10) << "SO LUONG" << setw(3) << "|" << setw(16) << "tro gia/tu van" << setw(3) << "|" << endl;
	for (int i = 0; i < n; i++) {
		if (ds[i]->get_Mathuoc() == ma) {
			ds[i]->xuat();
			dem++;
		}
	}
	std::cout << "+----------+---------------------+-----------------+----------------+------------+------------------+";
	if (dem == 0) {
		std::cout << " \n Khong tim thay thuoc can tim! ";
		
	}
}
void take_order(thuoc* ds[], int& n, customer*& kh, int& m, order*& od) {
	system("cls");
	xuat_dsthuoc(ds, n);
	std::cout << "+----------+---------------------+-----------------+----------------+------------+------------------+";
	int  ngay, thang, nam, sl_mua, so_hd;
	date ngay_mua;
	int N; float gia, total = 0;
	int choice;
	std::cout << "\nKhoi tao so hd: "; std::cin >> so_hd;
	for (int k = 0; k < m; k++) {
		if (kh[k].get_soHD() == so_hd) {
			std::cout << "So hd da ton tai!";
		}
		else
		{
			kh[k].set_soHD(so_hd);
			kh[k].khach_hang();
			std::cout << "nhap so luong muon mua(toi da 10 loai): "; std::cin >> N; kh[k].set_sl_thuoc(N);
			if (N > 10)std::cout << "So luong thuoc da vuot qua gioi han: ";
			else {
				for (int i = 0; i < N; i++) {
					std::cout << "Nhap lua chon cua ban: "; std::cin >> choice;
					std::cout << "\tMa thuoc: " << ds[choice - 1]->get_Mathuoc() << "\tTen thuoc: " << ds[choice - 1]->get_tenthuoc();
					od[i].set_mathuoc(ds[choice - 1]->get_Mathuoc()); od[i].set_tenthuoc(ds[choice - 1]->get_tenthuoc());
					std::cout << "\nSo luong mua: "; std::cin >> sl_mua; od[i].set_sl_mua(sl_mua); ds[choice - 1]->set_sl(ds[choice - 1]->get_soluong() - sl_mua);
					gia = sl_mua * (ds[choice - 1]->get_gia()); od[i].set_gia(gia);
					std::cout << "\nGia: " << od[i].get_gia() << endl;
					total += od[i].get_gia();
				}
				kh[k].set_total(total);
				std::cout << "===========================================================================" << endl;
				std::cout << "Order Taken Successfully" << endl;
				std::cout << "===========================================================================" << endl;
				std::cout << "Go to Reciept Menu to Pay The Bill" << endl;
				std::cout << "===========================================================================" << endl;
				break;

			}
		}
	}
}
void xuat_hoadon(customer *&kh,int m, order *&od) {
	float total=0,num;
	int so_hd,k;
		k = 0;
		std::cout << "\nNhap so Hoa Don: "; cin >> so_hd;
		if (kh[k].get_soHD() == so_hd) {
			std::cout << "\n";
			std::cout << "=====================================================================" << endl;
			std::cout << "\t\tHere is the Order list\n";
			std::cout << "=====================================================================" << endl;
			kh[k].xuat_tt_kh();
			std::cout << "NGAY TAO HD: "; kh[k].xuat_ngay(); cout << "\n";
			std::cout << "_____________________________________________________________________" << endl;
			std::cout << "=====================================================================" << endl;
			std::cout << "|" << setw(9) << "MA THUOC" << setw(2) << "|" << setw(15) << "TEN THUOC" << setw(6) << "|";
			std::cout << setw(10) << "SO LUONG" << setw(4) << "|" << setw(15) << "TONG GIA" << setw(7) << "|" << endl;
			std::cout << "|==========+====================+=============+=====================|" << endl;
			for (int i = 0; i < kh[k].get_sl_thuoc(); i++) {
				std::cout << "|" << setw(9) << od[i].getma() << setw(2) << "|" << setw(17) << od[i].getten() << setw(4) << "|";
				std::cout << setw(10) << od[i].get_sl_mua() << setw(4) << "|" << setw(15) << od[i].get_gia() << " VND"<< setw(3) << "|" << endl;
				std::cout << "|----------+--------------------+-------------+---------------------|" << endl;
			}
			std::cout << "|___________________________________________________________________|" << endl;
			std::cout << "TOTAL BILL IS: " << kh[k].get_total();
			std::cout << "\n";
			std::cout << "Type the exact amount You need to pay: ";
			cin >> num;
			if (num > kh[k].get_total()) {
				int du; du = num - kh[k].get_total();
				std::cout << "\n";
				std::cout << "\n";
				std::cout << "\nDu: " << du; std::cout << "\n";
				std::cout << "Payment Done\nThank You\n";
				std::cout << "\n_______________________________________________________________________________\n";
			}
			else {
				int conlai;
				conlai = kh[k].get_total() - num;
				std::cout << "\n";
				std::cout << "\n";
				std::cout << "\nCon lai phai tra: " << conlai; cout << "\n";
				std::cout << "Payment Done\nThank You\n";
				std::cout << "\n_______________________________________________________________________________\n";
			}
		}
		else {
			k++;
			std::cout << "So hd ko ton tai!";
		}
}
void xoa_thuoc(thuoc ds[], int& n, string ma) {
	for (int i = 0; i < n; i++) {
		if (ds[i].get_Mathuoc() == ma) {
			for (int j = i; j < n; j++) {
				ds[j] = ds[j + 1];
			}
		}
	}
}
void modify_order(thuoc*ds[], int& n, customer*&kh, int& m, order*& od) {
	int so_hd, choice,sl_mua;
	int N,k,i,j;
	string ma;
	float gia,total=0;
	system("cls");
	xuat_dsthuoc(ds, n);
		k = 0;
		std::cout << "\nNhap so Hoa Don: "; cin >> so_hd;
		if (kh[k].get_soHD() == so_hd) {
			kh[k].xuat_tt_kh();
			std::cout << "NGAY TAO HD: "; kh[k].xuat_ngay(); cout << "\n";
			std::cout << "_____________________________________________________________________" << endl;
			std::cout << "=====================================================================" << endl;
			std::cout << "|" << setw(9) << "MA THUOC" << setw(2) << "|" << setw(15) << "TEN THUOC" << setw(6) << "|";
			std::cout << setw(10) << "SO LUONG" << setw(4) << "|" << setw(15) << "TONG GIA" << setw(7) << "|" << endl;
			std::cout << "|==========+====================+=============+=====================|" << endl;
			for (int i = 0; i < kh[k].get_sl_thuoc(); i++) {
				std::cout << "|" << setw(9) << od[i].getma() << setw(2) << "|" << setw(15) << od[i].getten() << setw(6) << "|";
				std::cout << setw(10) << od[i].get_sl_mua() << setw(4) << "|" << setw(15) << od[i].get_gia() << " VND" << setw(3) << "|" << endl;
				std::cout << "|----------+--------------------+-------------+---------------------|" << endl;
			}
			std::cout << "Nhap so luong thuoc muon thay doi:"; cin >> N;
			for (j = 0; j < N; j++) {
				std::cout << "Nhap lua chon muon thay doi"; cin >> i;
				std::cout << "Nhap thuoc moi: "; cin >> choice;
				std::cout << "\tMa thuoc " << ds[choice - 1]->get_Mathuoc() << "\tTen thuoc " << ds[choice - 1]->get_tenthuoc();
				od[i].set_mathuoc(ds[choice - 1]->get_Mathuoc()); od[i].set_tenthuoc(ds[choice - 1]->get_tenthuoc());
				std::cout << "\nSo luong mua: "; cin >> sl_mua; od[i].set_sl_mua(sl_mua); ds[choice - 1]->set_sl(ds[choice - 1]->get_soluong() - sl_mua);
				gia = sl_mua * (ds[choice - 1]->get_gia()); od[i].set_gia(gia);
				std::cout << "\nGia: " << od[i].get_gia() << endl;
				total += od[i].get_gia();
				for(int k=0;k<n;k++){
					if (ds[k]->get_Mathuoc() == od[i].getma())
						ds[k]->set_sl(ds[k]->get_soluong() + od[i].get_sl_mua());
				}
			}kh[k].set_total(total);
		}
		else {
			k++;
			std::cout << " SO hoa don ko ton tai";
		}
}
void menu(thuoc *ds[], int& n, customer*&kh, int m, order*& od)
{
	int N;
	ifstream filein;
	
	filein.open("input.txt",ios_base::in);
	//fileout.open("output.txt", ios_base::out);
	int choice = 1;
	int a;
	do {
		system("cls");
		std::cout << "\t\t\t Pharmacy Management System \n";
		std::cout << "\t\t==================================================\n\n";
		std::cout << "\t\t--------------------------------------------------\n";
		std::cout << "\t\t||\t1. DOC FILE" << endl;
		std::cout << "\t\t||\t2. XUAT DANH SACH" << endl;
		std::cout << "\t\t||\t3. TIM MA THUOC" << endl;
		std::cout << "\t\t||\t4. GHI FILE" << endl;
		std::cout << "\t\t||\t5. TAKE ORDER" << endl;
		std::cout << "\t\t||\t6. XUAT HOA DON" << endl;
		std::cout << "\t\t||\t7. SUA HOA DON" << endl;
		char x;
		std::cout << "\n\t Vui long chon hanh dong: ";
		cin >> x; 
		if (x == '1')
		{
			filein >> n;
			thuoc* b = NULL;
			for (int i = 0; i < n; i++) {
				char c;
				filein >> c; filein.seekg(-1, 1);
				if (c == 'B') {
					b = new thuoc_bo();
					b->Doc_file(filein);
				}
				else if (c == 'D') {
					b = new thuoc_dieu_tri();
					b->Doc_file(filein);
				}
				ds[i] = b;
			}
			std::cout << "\n\nDONEE!";
			_getch();
		}
		else if (x == '2')
		{
			std::cout << "+==========+=====================+=================+================+============+==================+";
			std::cout << "\n" << "|" << " Ma thuoc" << setw(2) << "|" << setw(15) << "Ten Thuoc" << setw(7) << "|" << setw(15) << "Ngay het han" << setw(3) << "|" << setw(10) << "GIA" << setw(7) << "|" << setw(10) << "SO LUONG" << setw(3) << "|" << setw(16) << "tro gia/tu van" << setw(3) << "|" << endl;
			for (int i = 0; i < n; i++) {
				ds[i]->xuat();
			}
			std::cout << "+----------+---------------------+-----------------+----------------+------------+------------------+";
			_getch();
		}
		else if (x == '3')
		{
			timkiemMathuoc(ds, n);
			_getch();
		}
		else if (x == '4')
		{	
			ofstream fileout;
			fileout.open("output.txt", ios_base::out);
			for (int i = 0; i < n; i++)
			{
				date ngay_hethan = ds[i]->get_hethan();
				fileout << ds[i]->get_Mathuoc() << ", " << ds[i]->get_tenthuoc() << ", " << ngay_hethan.get_ngay() << "/" << ngay_hethan.get_thang() << "/ " << ngay_hethan.get_nam() << ", " << ds[i]->get_gia() << ", " << ds[i]->get_soluong() << endl;

			}
			
			fileout.close();
			std::cout << "\n\nDONEE!";
			_getch();
		}
		else if (x == '5')
		{
			take_order(ds, n, kh, m, od);
			_getch();
		}
		else if (x == '6') {
			xuat_hoadon(kh, m, od);
			_getch();
		}
		else if (x == '7') {
			modify_order(ds, n, kh, m, od);
			_getch();
		}
		else
		{
			cout << "Khong co hanh dong nay. Vui long chon lai!";
			_getch();
		}

	} while (choice != 0);
	filein.close();
}
int main()
{	
	int n=0,m;
	thuoc* ds[100];
	customer* kh = new customer[10]; m = 10;
	order* od = new order[10];
	menu(ds, n, kh, m, od);
	_getch();
	return 0;
}