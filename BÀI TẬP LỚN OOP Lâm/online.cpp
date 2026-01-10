#include<iostream>
#include<string>
#include"online.h"
#include"UI.h"
using namespace std;
void online::hienthi() {
    int width = 58;
    cout<<space() << "  ╭──────────────────────────────────────────────────────────╮" << endl;
    // cout << "  │"<<left<< setw(width - 2)<<"ONLINE" << "│" << endl;
    cout<<space() << "  │" ;
    doi_mau_full(14);
    cout << left << setw(26) << "" << "ONLINE" << setw(26) << "" ;
    doi_mau_full(15);
    cout << "│" << endl;
    doi_mau_full(15);
    couse::hienthi();
    cout<<space() << "  │" << left << setw(width + 5) << (" Nền tảng học: " + nen_tang) << " │" << endl;
    cout<<space() << "  │ Link: " ;
    doi_mau_full(1);
    cout << left << setw(width -8  + getUTF8LenDiff(link))<< link ;
    doi_mau_full(15);
    cout << " │" << endl;

    cout<<space() << "  ╰──────────────────────────────────────────────────────────╯" << endl;
}
bool online::nhap(giangvien* gv_func, subject* sub_func) {
    if (couse::nhap(gv_func, sub_func)) {
        cout << "Nhập nền tảng học trực tuyến: ";
        cin.ignore();
        getline(cin, nen_tang);
        cout<<"Nhập link phòng học (0) hay sử dụng link tự sinh (1)?"<<endl;
        int temp;
        cin>>temp;
        if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
         pause();
         return false;
    }else if(temp == 0){
        cout<<"Nhập link phòng học: ";
        getline(cin,link);
        return true;
    }else if(temp == 1){
        link = "http://" + nen_tang +".com" +tao_random(10);
        cout<<"Tạo link thành công";
        return true;
    }else{
        cout<<"Vui lòng nhập 0 hoặc 1!";
        return false;
    }
    }
    return false;
}
bool online::xuat_du_lieu_file(string& file_name) {
    ofstream f(file_name, ios::app);
    if (!f.is_open()) {
        cout << "Không mở được file!";
        return false;
    }
    else {
        string line;
        couse::xuat_du_lieu_file(line);
        line.insert(0, "online|");
        f << line + "|" + nen_tang + "|" + link<<endl;
        f.close();
    }
    return true;

}
string online::tao_random(int do_dai) {
    string kq = "";
    string tap_ky_tu = "abcdefghijklmnopqrstuvwxyz0123456789";

    for (int i = 0; i < do_dai; i++) {
        int vi_tri_ngau_nhien = rand() % tap_ky_tu.length();
        kq += tap_ky_tu[vi_tri_ngau_nhien];
    }

    return kq;
}
void online::string_file(string &line){
    couse::string_file(line);
    line.insert(0,"online|");
    line += "|" + nen_tang + "|" + link;
}