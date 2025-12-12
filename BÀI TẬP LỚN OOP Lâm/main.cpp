#include<iostream>
#include<string>
#include"list_time.h"
#include"list_giangvien.h"
#include"list_sinhvien.h"
#include"list_subject.h"
#include"list_time.h"
#include<fstream>
#include"nghiepvu.h"
#include<stdlib.h>
using namespace std;
int couse::sl = 0;
int main() {
    list_sinhvien ds;
   // ds.xuatds();
    list_time a;
    list_sinhvien e;
    list_giangvien b;
    list_subject c;

    a.lay_du_lieu_tu_file("D:/dulieuthoigianhoc.txt"); /* file này gửi zl nhé */
    b.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
    c.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
    e.lay_du_lieu_tu_file("D:/dulieusinhvien.txt");

    list_couse d;
   /* if (d.nhap_du_lieu_tu_file(b, a, c, "D:/dulieulophoc.txt")) {
        cout << "Nhap du lieu file thanh cong!" << endl;
    }
    nghiepvu nv(d, e, a, b, c);
    nv.them_mon_hoc(b.get_giangvien(0), a.get_time(1), c.get_subject(3), "D:/dulieulophoc.txt");
    d.hienthidanhsach();*/


    
    int chon;

    do {
        cout << "\n===== MENU SINH VIEN =====\n";
        cout << "1. Xuat danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
            cout << "\n=== DANH SACH SINH VIEN ===\n";
            ds.xuatds();       // <-- GỌI HÀM ĐỌC FILE Ở ĐÂY
            break;

        case 0:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;

}



