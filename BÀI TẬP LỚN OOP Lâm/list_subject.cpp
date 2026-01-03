
#include<iostream>
#include"list_subject.h"
#include<fstream>
#include<vector>   
using namespace std;
void list_subject::lay_du_lieu_tu_file(string file_name) {
    ifstream f(file_name);
    if (!f.is_open()) {
        cout << "ko mo dc file!" << endl;
        return;
    }
    else {
        subject mon_temp;
        while (mon_temp.nhap_du_lieu_tu_file(f)) {
            ds_mon.push_back(mon_temp);
        }
    }
    f.close();
}

void list_subject::ghi_du_lieu_vao_file(string file_name) {
    ofstream f(file_name);
    if (!f.is_open()) return;
    for (size_t i = 0; i < ds_mon.size(); i++) {
        f << ds_mon[i].to_file_string();
        if (i < ds_mon.size() - 1) f << endl;
    }
    f.close();
}

subject* list_subject::tim_mon_theo_ma(string ma_mon) {
    for (size_t i = 0; i < ds_mon.size(); i++) {
        if (ds_mon[i].get_ma_mon() == ma_mon) 
            return &ds_mon[i];
    }
    return nullptr;
}

subject* list_subject::tim_mon_theo_ten(string ten_mon) {
    for (size_t i = 0; i < ds_mon.size(); i++) {
        if (ds_mon[i].get_ten() == ten_mon) 
            return &ds_mon[i];
    }
    return nullptr;
}

void list_subject::add_mon_hoc(string file_name) {
    subject temp;
    cin >> temp;
    ds_mon.push_back(temp);
    temp.ghi_du_lieu_vao_file(file_name);
}
void list_subject::hthi_ds_mon_hoc(){
    
    cout << "\t\t  ╭─────────────────────DANH SÁCH MÔN HỌC────────────────────╮" << endl;
    cout << "\t\t  ╰──────────────────────────────────────────────────────────╯" << endl;
    cout<<endl;
   for(int i = 0;i<ds_mon.size();i++){
    cout<<ds_mon[i];
    cout<<'\n';
   } 
}

bool list_subject::xoa_mon_hoc_theo_ma(string ma,string file_name) {
    for (size_t i = 0; i < ds_mon.size(); i++) {
        if (ds_mon[i].get_ma_mon() == ma) {
            ds_mon.erase(ds_mon.begin() + i);
            //xoá xong thì ghi lại vào file để cập nhât
            ghi_du_lieu_vao_file(file_name);
            return true;
        }
    }
    return false;
}
// ostream& operator<<(ostream& os, const list_subject& l) {
//     os << "\n------- DANH SACH MON HOC -------\n"<<endl;
//     for (size_t i = 0; i < l.ds_mon.size(); i++) {
//         os << l.ds_mon[i] << endl;
//     }
//     return os;
// }
// istream& operator>>(istream& is, list_subject& l) {
//     subject temp;
//     is >> temp;
//     l.ds_mon.push_back(temp);
//     return is;
// }

