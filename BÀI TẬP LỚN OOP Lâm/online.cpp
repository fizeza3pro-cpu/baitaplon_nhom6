#include<iostream>
#include<string>
#include"online.h"
#include"UI.h"
using namespace std;
void online::hienthi(){
    int width = 58;
    cout << "  ╭──────────────────────────────────────────────────────────╮" << endl;
    UI::doi_mau_full(14);
    // cout << "  │"<<left<< setw(width - 2)<<"ONLINE" << "│" << endl;
    cout << "  │" << setw(26) << "" << "ONLINE" << setw(26) << "" << "│" << endl;
    UI::doi_mau_full(7);
    couse::hienthi();
    cout << "  |"<<left<< setw(width +5)<<(" Nền tảng học: "+nen_tang)<< " │" << endl;
    cout << "  ╰──────────────────────────────────────────────────────────╯" << endl;
}
bool online::nhap(giangvien* gv_func,subject* sub_func){
    if(couse::nhap(gv_func, sub_func)){
    cout<<"nhap nan tang hoc truc tuyen: ";
    cin.ignore();
    getline(cin,nen_tang);
    return true;
    }
    return false;
}
  bool online::xuat_du_lieu_file(string &file_name){
    ofstream f(file_name,ios::app);
    if(!f.is_open()){
        cout<<"ko mo dc file!";
        return false;
    }else{
        string line;
        couse::xuat_du_lieu_file(line);
        line.insert(0,"online|");
        f<<line+"|"+nen_tang<<"\n";
        f.close();
    }
    return true;

 }