#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>     // EXIT_FAILURE
#include <stdio.h>
#include <unordered_map>
using namespace std;



class PhieuSach {
private:
	string tensach;
	int id;
	string linhvuc;
	string tacgia;
	int sotrang;
	int namxb;

public:
	PhieuSach(string _tensach, int _id, string _linhvuc, string _tacgia, int _sotrang, int _namxb) {
		this->tensach = _tensach;
		this->id = _id;
		this->linhvuc = _linhvuc;
		this->tacgia = _tacgia;
		this->sotrang = _sotrang;
		this->namxb = _namxb;
	}

	PhieuSach() {

	}

	void setTensach(string _tensach) {
		this->tensach = _tensach;
	}

	void setId(int _id) {
		this->id = _id;
	}
	void setTacgia(string _tacgia) {
		this->tacgia = _tacgia;
	}
	void setSotrang(int _sotrang) {
		this->sotrang = _sotrang;
	}
	void setNamxb(int _namxb) {
		this->namxb = _namxb;
	}




	string getTensach() {
		return this->tensach;
	}

	int getId() {
		return this->id;
	}

	string getLinhvuc() {
		return this->linhvuc;
	}
	string getTacgia() {
		return this->tacgia;
	}
	int getSotrang() {
		return this->sotrang;
	}
	int getNamxb() {
		return this->namxb;
	}


};


class QuanLySach {
private:
	PhieuSach phieusach;
	int soluong;
	string vitri;
public:
	QuanLySach(string _tensach, int _id, string _linhvuc, string _tacgia, int _sotrang, int _namxb, int _soluong, string _vitri) {
		this->phieusach = PhieuSach(_tensach, _id, _linhvuc, _tacgia, _sotrang, _namxb);
		this->soluong = _soluong;
		this->vitri = _vitri;
	}

	PhieuSach getPhieuSach() {
		return this->phieusach;
	}
	int getSoluong() {
		return this->soluong;
	}
	string getVitri() {
		return this->vitri;
	}
	void setPhieuSach(PhieuSach _phieusach) {
		this->phieusach = _phieusach;
	}
	void setSoluong(int _soluong) {
		this->soluong = _soluong;
	}
	void setVitri(string _vitri) {
		this->vitri = _vitri;
	}
};

class QuanLyThuVien {
private:
	vector<QuanLySach> list;
	string fileTenSach = "danhsachsach.txt";
	string fileTruycapSach = "danhsachduongdan.txt";
public:
	QuanLyThuVien() {
		ifstream myfile(this->fileTruycapSach);
		if (myfile.is_open()) {
			while (!myfile.eof()) {
				string line;
				getline(myfile, line);
				ifstream fileBook(line);
				if (fileBook.is_open()) {
					int i = 0;
					int id;
					string vitri;
					string tensach;
					string linhvuc;
					string tacgia;
					int sotrang;
					int soluong;
					int namxb;
					while (!fileBook.eof()) {
						string l;
						getline(fileBook,l);
						if (i == 0) {
							id = stoi(l);
						}
						else if (i == 1) {
							tensach = l;
						}
						else if (i == 2) {
							linhvuc = l;
						}
						else if (i == 3) {
							tacgia = l;
						}
						else if (i == 4) {
							sotrang = stoi(l);
						}
						else if (i == 5) {
							namxb = stoi(l);
						}
						else if (i == 6) {
							soluong = stoi(l);
						}
						else if (i == 7) {
							vitri = l;
						}
						i++;


					}
					QuanLySach sach(tensach, id, linhvuc, tacgia, sotrang, namxb, soluong, vitri);
					list.push_back(sach);
				}
				fileBook.close();
			}
			myfile.close();
		}
	}

	void themSachMoi() {
		cout << "\n\n\n";

		string tensach;
		int id;
		string linhvuc;
		string tacgia;
		int sotrang;
		int namxb;
		int soluong;
		string vitri;
		string mystring;
		cout << "Moi ban nhap thong tin cua sach: \n";
		cout << "1. Nhap thong tin cho phieu sach:\n";
		cout << "Nhap ten cua sach :\n";
		getline(cin, tensach);
		cout << "Nhap linh vuc cua sach:\n";
		getline(cin, linhvuc);
		cout << "Nhap ten cua tac gia:\n";
		getline(cin, tacgia);
		cout << "Nhap so trang cua sach:\n";
		getline(cin, mystring);
		stringstream(mystring) >> sotrang;
		cout << "Nhap nam xuat ban sach:\n";
		getline(cin, mystring);
		stringstream(mystring) >> namxb;
		cout << "2. Nhap thong tin quan ly ngoai phieu sach:\n";
		cout << "Nhap so luong sach:\n";
		getline(cin, mystring);
		stringstream(mystring) >> soluong;
		cout << "Nhap vi tri cua sach trong thu vien:\n";
		getline(cin, vitri);


		id = list.size();
		QuanLySach sach(tensach, id, linhvuc, tacgia, sotrang, namxb, soluong, vitri);
		list.push_back(sach);


		string fileName = "./file/";
		fileName.append(std::to_string(id));
		fileName.append(tensach);
		fileName.append(".txt");

		ofstream listBookFile;

		listBookFile.open(this->fileTenSach, std::ios::app);
		listBookFile <<  tensach;
		listBookFile << "\n";
		listBookFile.close();


		ofstream listPathBookfile;
		listPathBookfile.open(this->fileTruycapSach, std::ios::app);
		listPathBookfile << fileName;
		listPathBookfile << "\n";
		listPathBookfile.close();


		ofstream myfile;
		myfile.open(fileName);
		myfile << id;
		myfile << "\n";
		myfile << tensach;
		myfile << "\n";
		myfile << linhvuc;
		myfile << "\n";
		myfile << tacgia;
		myfile << "\n";
		myfile << sotrang;
		myfile << "\n";
		myfile << namxb;
		myfile << "\n";
		myfile << soluong;
		myfile << "\n";
		myfile << vitri;
		myfile << "\n";
		myfile.close();

	}

	void thaydoithongtin() {
		cout << "\n\n\n";

		string mystring;
		cout << "Thay doi thong tin sach:\n";
		cout << "Nhap id cua sach ma ban muon thay doi thong tin:\n";
		int id;
		getline(cin, mystring);
		stringstream(mystring) >> id;
		if (id > list.size()) {
			cout << "Khong co sach voi id la " << id;
			return;
		}

		string tensach = list[id].getPhieuSach().getTensach();
		string linhvuc = list[id].getPhieuSach().getLinhvuc();
		string tacgia = list[id].getPhieuSach().getTacgia();
		int sotrang = list[id].getPhieuSach().getSotrang();
		int namxb = list[id].getPhieuSach().getNamxb();
		int soluong = list[id].getSoluong();
		string vitri = list[id].getVitri();

		string l;

		while (true) {
			cout << "Nhap 1 de thay doi ten sach\n";
			cout << "Nhap 2 de thay doi linh vuc cua sach\n";
			cout << "Nhap 3 de thay doi ten tac gia\n";
			cout << "Nhap 4 de thay doi so trang sach\n";
			cout << "Nhap 5 de thay doi nam xuat ban cua sach\n";
			cout << "Nhap 6 de thay doi so luong cua sach\n";
			cout << "Nhap 7 de thay doi vi tri cua sach trong thu vien\n";
			cout << "Nhap phim khac bat ky de thuc hien thay doi thong tin sach\n";
			cout << "Moi ban thuc hien nhap phim\n";
			int i;
			getline(cin, mystring);
			stringstream(mystring) >> i;
			if (i == 1) {

				cout << "Ten cua sach:\n";
				getline(cin, l);
				tensach = l;
			}
			else if (i == 2) {

				cout << "Linh vuc cua sach:\n";
				getline(cin, l);
				linhvuc = l;
			}
			else if (i == 3) {

				cout << "Ten cua tac gia la:\n";
				getline(cin, l);
				tacgia = l;
			}
			else if (i == 4) {

				cout << "So trang cua sach la:\n";
				getline(cin, mystring);
				stringstream(mystring) >> sotrang;
			}
			else if (i == 5) {

				cout << "Nam xuat ban sach la:\n";
				getline(cin, mystring);
				stringstream(mystring) >> namxb;
			}
			else if (i == 6) {

				cout << "So luong cua sach la:\n";
				getline(cin, mystring);
				stringstream(mystring) >> soluong;
			}
			else if (i == 7) {

				cout << "Vi tri moi cua sach la:\n";
				getline(cin, l);
				vitri = l;
			}
			else {
				break;
			}
		}

		PhieuSach phieusach(tensach, id, linhvuc, tacgia, sotrang, namxb);
		list[id].setPhieuSach(phieusach);
		list[id].setSoluong(soluong);
		list[id].setVitri(vitri);

		string fn = "./file/";
		fn.append(std::to_string(id));
		fn.append(list[id].getPhieuSach().getTensach());
		fn.append(".txt");
		remove(fn.c_str());

		fn = "./file/";
		fn.append(std::to_string(id));
		fn.append(tensach);
		fn.append(".txt");

		ofstream myfile;
		myfile.open(fn);
		myfile << id;
		myfile << "\n";
		myfile << tensach;
		myfile << "\n";
		myfile << linhvuc;
		myfile << "\n";
		myfile << tacgia;
		myfile << "\n";
		myfile << sotrang;
		myfile << "\n";
		myfile << namxb;
		myfile << "\n";
		myfile << soluong;
		myfile << "\n";
		myfile << vitri;
		myfile << "\n";
		myfile.close();


		fstream listBookFile(this->fileTenSach);


		fstream listPathBookfile(this->fileTruycapSach);

		for (int i = 0; i < list.size(); i++) {
			listBookFile << list[i].getPhieuSach().getTensach();
			listBookFile << "\n";



			string filename = "./file/";
			filename.append(std::to_string(i));
			filename.append(list[i].getPhieuSach().getTensach());
			filename.append(".txt");
			listPathBookfile << filename;
			listPathBookfile << "\n";
		}


		listPathBookfile.close();
		listBookFile.close();
	}





	void xemdanhsachsach() {
		cout << "\n\n\n";

		cout << "Danh sach sach hien tai dang co trong thu vien la:\n";
		for (int i = 0; i < list.size(); i++) {
			cout << i << ".  " << list[i].getPhieuSach().getTensach() << "\n";
		}
	}
	void xemthongtinchitietcuasach() {
		cout << "\n\n\n";

		cout << "Moi ban nhap id cua sach ban muon xem:\n";
		string mystring;
		int id;
		getline(cin, mystring);
		stringstream(mystring) >> id;
		if (mystring != to_string(id) || id > list.size()) {
			cout << "Khong ton tai sach co id la " << mystring;
			return;
		}
		else {
			cout << "\n";
			cout << "Thong tin chi tiet la:\n";
			cout << "Ten sach:     " << list[id].getPhieuSach().getTensach() << "\n";
			cout << "Tac gia:      " << list[id].getPhieuSach().getTacgia() << "\n";
			cout << "Linh vuc:     " << list[id].getPhieuSach().getLinhvuc() << "\n";
			cout << "So trang:     " << list[id].getPhieuSach().getSotrang() << "\n";
			cout << "So luong:     " << list[id].getSoluong() << "\n";
			cout << "Vi tri:       " << list[id].getVitri() << "\n";
			cout << "Nam xuat ban: " << list[id].getPhieuSach().getNamxb() << "\n";
			
		}
	}

	void timkiemsachtheotentacgia() {
		cout << "\n\n\n";

		string tacgia;
		cout << "Nhap ten cua tac gia ma ban muon tim kiem:\n";
		getline(cin, tacgia);
		int stt = 0;
		for (int i = 0; i < list.size(); i++) {
			
			if (list[i].getPhieuSach().getTacgia() == tacgia) {
				if (stt == 0) {
					cout << "Danh sach sach cua tac gia " << tacgia << "trong thu vien:\n";
				}
				stt++;
				cout << stt << ".  " << list[i].getPhieuSach().getTacgia()<<"\n";
			}
		}
		if (stt == 0) {
			cout << "Khong co sach cua tac gia " << tacgia;
		}
	}

	void timkiemtheolinhvuc() {
		cout << "\n\n\n";

		string linhvuc;
		cout << "Nhap ten cua linh vuc ma ban muon tim kiem:\n";
		getline(cin, linhvuc);
		int stt = 0;

		for (int i = 0; i < list.size(); i++) {

			if (list[i].getPhieuSach().getLinhvuc() == linhvuc) {
				if (stt == 0) {
					cout << "Danh sach sach trong linh vuc  " << linhvuc << "trong thu vien :\n";
				}
				stt++;
				cout << stt << ".  " << list[i].getPhieuSach().getLinhvuc() << "\n";
			}
		}
		if (stt == 0) {
			cout << "Khong co sach trong linh vuc " << linhvuc;
		}
	}

	void thongke() {
		unordered_multimap<string,int> hashMap;

		typedef unordered_multimap<string, int>::iterator umit;
		for (int i = 0; i < list.size(); i++) {
			auto itr = hashMap.find(list[i].getPhieuSach().getTacgia());
			if (itr == hashMap.cend()) {
				hashMap.insert({ list[i].getPhieuSach().getTacgia(),1 });
			}
			else {
				itr->second += 1;
			}
		}
		cout << "\n\n\n";
		cout << "Danh sach cac sach theo ten tac gia trong thu vien:\n";
		

		umit it = hashMap.begin();
		for (; it != hashMap.end(); it++) {
			cout << it->first << ":   " << it->second << "\n";
		}
		hashMap.clear();


		for (int i = 0; i < list.size(); i++) {
			auto itr = hashMap.find(list[i].getPhieuSach().getLinhvuc());
			if (itr == hashMap.cend()) {
				hashMap.insert({ list[i].getPhieuSach().getLinhvuc(),1 });
			}
			else {
				itr->second += 1;
			}
		}
		cout << "Danh sach cac sach theo ten linh vuc trong thu vien:\n";


		it = hashMap.begin();
		for (; it != hashMap.end(); it++) {
			cout << it->first << ":   " << it->second << "\n";
		}
		hashMap.clear();





	}
};


int main() {
	QuanLyThuVien quanLyThuVien;
	cout << "Chao mung ban den voi chuong trinh quan ly thu vien:\n";
	
	cout << "Nhap 1 de them phieu sach cho thu vien va cac thong tin ve so luon, vi tri cua sach\n";
	cout << "Nhap 2 de xem danh sach dang co trong thu vien\n";
	cout << "Nhap 3 de xem chi tiet thong tin ve sach va phieu sach trong thu vien\n";
	cout << "Nhap 4 de sua doi thong tin sach\n";
	cout << "Nhap 5 de tim kiem dau sach theo tac gia\n";
	cout << "Nhap 6 de tim kiem dau sach theo linh vuc\n";
	cout << "Nhap 7 de xem thong ke sach cua thu vien\n";
	cout << "Nhap phim khac de ket thuc chuong trinh\n";
	while (true) {
		cout << "Moi ban thuc hien nhap cac phim duoi day tuong ung voi cac hanh dong:\n";
		string mystring;
		int id;
		getline(cin, mystring);
		stringstream(mystring) >> id;
		if (id == 1) {
			quanLyThuVien.themSachMoi();
		}
		else if (id == 2) {
			quanLyThuVien.xemdanhsachsach();
		}
		else if (id == 3) {
			quanLyThuVien.xemthongtinchitietcuasach();
		}
		else if (id == 4) {
			quanLyThuVien.thaydoithongtin();
		}
		else if (id == 5) {
			quanLyThuVien.timkiemsachtheotentacgia();
		}
		else if (id == 6) {
			quanLyThuVien.timkiemtheolinhvuc();
		}
		else if (id == 7) {
			quanLyThuVien.thongke();
		}
		else {
			break;
		}

	}

}