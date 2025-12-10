#include<iostream>
#include<string>
#include"sinhvien.h"
using namespace std;
bool sinhvien::dadangky(couse * mon){
    if(ds_mon_dky.size() == 0){
        return false;
    }else{
        for(int i = 0;i<ds_mon_dky.size();i++){
            if(ds_mon_dky[i] == mon){
                return true;
            }
        }
        return false;
    }
}
bool sinhvien::add_couse(couse * mon){
    if(dadangky(mon)){
        cout<<"mon hoc da dc dang ki!"<<endl;
        return false;
    }else if(cur_tc + mon->get_tin_chi() > max_tc){
        cout<<"vuot qua so luong tin chi, ko the them"<<endl;
        return false;
    }else{
        ds_mon_dky.push_back(mon);
        cur_tc += mon->get_tin_chi();
        return true;
    }
    return false;
}
bool sinhvien::delete_couse(couse * mon){
    if(!dadangky(mon)){
        cout<<"ko co mon hoc, ko the xoa!"<<endl;
        return false;
    }else{
        for(int i = 0;i<ds_mon_dky.size();i++){
            if(ds_mon_dky[i] == mon){
                ds_mon_dky.erase(ds_mon_dky.begin() + i);   // XÓA GỌN
                cur_tc -= mon->get_tin_chi();               // trừ tín chỉ đúng
                return true;
            }
        }
    }
    return false;
}
void sinhvien::hienthithongtin(){
    cout<<"Ma sinh vien: "<<id<<endl;
    cout<<"Ho va ten: "<<name<<"\t\t"<<"Ngay sinh: "<<birth[0]<<"/"<<birth[1]<<"/"<<birth[2]<<"\t\t"<<endl;
    cout<<"Gioi tinh: "<<gioi_tinh<<"\t\t\t\t"<<"So dien thoai: "<<sdt<<endl;
    cout<<"Chuyen nganh: "<<chuyen_nganh<<"\t\t\t"<<"Khoa : K"<<khoa<<endl;
    cout<<"So tin chi toi da: "<<max_tc<<"\t\t\t"<<"So tin chi da dang ky: "<<cur_tc<<endl;
    cout << "So mon da dang ky: " << ds_mon_dky.size() << "\n" << endl;
}
void sinhvien::nhap()
{
    cout << "Nhap ma sinh vien: ";
    getline(cin, id);
    cout << "Nhap ho va ten: "; 
    cin.ignore();
    getline(cin, name);
    cout << "Nhap ngay thang nam sinh: \n";
    cout << "  Ngay: ";
    cin >> birth[0];
    cout << "  Thang: ";
    cin >> birth[1];
    cout << "  Nam: ";
    cin >> birth[2];
    cin.ignore();
    cout << "Nhap gioi tinh: ";
    getline(cin, gioi_tinh);
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap chuyen nganh: ";
    getline(cin, chuyen_nganh);
    cout << "Nhap khoa: ";
    cin >> khoa;
    cout << "Nhap so tin chi toi da: ";
    cin >> max_tc;
}
bool sinhvien::nhap_du_lieu_tu_file(ifstream &f){
    vector<string> a;
    string line;
    string temp = "";
    if(!getline(f,line)){
        return false;
    }
    if(line.empty()) return false;
    for(char c : line){
            if(c == '|'){
                a.push_back(temp);
                temp = "";
            }else{
                temp +=c;
            }
        }
       a.push_back(temp);
       temp = "";
        if(a.size() != 11) return false;
        id = a[0];
        name = a[1];
        gioi_tinh = a[2];
        chuyen_nganh = a[3];
        sdt = a[4];
        birth[0] = stoi(a[5]);
        birth[1] = stoi(a[6]);
        birth[2] = stoi(a[7]);
        khoa = stoi(a[8]);
        cur_tc = stoi(a[9]);
        max_tc = stoi(a[10]);   
    return true;
}


