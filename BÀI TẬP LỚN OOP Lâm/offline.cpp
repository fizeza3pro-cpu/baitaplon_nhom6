#include<iostream>
#include<string>
#include<fstream>
#include"UI.h"
#include"offline.h"
using namespace std;
void offline::hienthi() {
    int width = 58;
    cout<<space() << "  ╭──────────────────────────────────────────────────────────╮" << endl;
    cout<<space() << "  │" ;
    doi_mau_full(14);
    cout << left << setw(26) << "" << "OFFLINE" << setw(25) << "" ;
    doi_mau_full(15);
    cout << "│" << endl;
    doi_mau_full(15);
    couse::hienthi();
    cout<<space() << "  │";
    doi_mau_full(6);
    cout << left << setw(width + 5) << (" Địa điểm: " + phong_hoc + "-" + nha);
    doi_mau_full(15);
    cout << " │" << endl;
    cout<<space() << "  ╰──────────────────────────────────────────────────────────╯" << endl;
}
bool offline::nhap(giangvien* gv_func, subject* sub_func) {
    if (couse::nhap(gv_func, sub_func)) {
        cout << "nhap phong hoc: ";
        cin >> phong_hoc;
        cout << "nhap toa nha: ";
        cin >> nha;
        return true;
    }
    return false;
}
bool offline::xuat_du_lieu_file(string& file_name) {
    ofstream f(file_name, ios::app);
    if (!f.is_open()) {
        cout << "ko mo dc file!";
        return false;
    }
    else {
        string line;
        couse::xuat_du_lieu_file(line);
        line.insert(0, "offline|");
        f << line + "|" + phong_hoc + "|" + nha << "\n";
        f.close();
    }
    return true;
}
 void offline::string_file(string &line){
    couse::string_file(line);
    line.insert(0,"offline|");
    line +="|" + phong_hoc + "|" + nha;
 }