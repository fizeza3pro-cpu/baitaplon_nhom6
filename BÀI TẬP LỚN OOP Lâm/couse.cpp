#include<iostream>
#include<string>
#include"couse.h"
#include"UI.h"
using namespace std;
int couse::sl = 0;
void couse::tusinhma() {
    ma_lop_hoc = to_string(sl);
    while (ma_lop_hoc.length() < 3) {
        ma_lop_hoc.insert(0, "0");
    }
    ma_lop_hoc = "MTA" + ma_lop_hoc;
}
void couse::hienthi() {
    // cout<<"[+] Ten mon hoc: "<<mon_hoc->get_ten()<<"\t"<<"Ma mon hoc: "<<ma_lop_hoc<<"\t"<<"Giang vien: "<<gv->get_name()<<endl;
    // cout<<"    Thoi gian: ";
    // time.hienthithongtin();
    // cout<<"\t"<<"So tin chi: "<<mon_hoc->get_tin_chi()<<"\t\t";
    // if(cur_sv<max_sv){
    //     doi_mau_full(2);
    // }else UI::doi_mau_full(4);
    // cout<<"So luong :"<<cur_sv<<"/"<<max_sv<<endl;
    // UI::doi_mau_full(7);
   // Thiết kế độ rộng thẻ là 60 ký tự
    int width = 58; 
    int do_lech = getUTF8LenDiff(mon_hoc->get_ten());
    int do_lech2 = getUTF8LenDiff(gv->get_name());
    cout << "  ├──────────────────────────────────────────────────────────┤" << endl;   
    // Dòng 2: Tên môn học (In hoa cho nổi bật)
    cout << "  │ " << left << setw(width + do_lech) << ("Tên môn: " + mon_hoc->get_ten()) << " │" << endl;
    cout << "  │ " << right << setw(width + 2) << " │" << endl;
    // Dòng 3 & 4: Mã môn và Giảng viên
    cout << "  │ " << left << setw(29) << ("Mã lớp học: " + ma_lop_hoc )  << setw(width - 26 + do_lech2) << ("GV: " + gv->get_name()) << " │" << endl;  
     cout<<"  │ "<<right<<setw(width + 2)<<" │"<<endl;  
    cout << "  │ " << left << setw(29) <<("Số tín chỉ: " + to_string(mon_hoc->get_tin_chi()));
    if(cur_sv<max_sv){
        doi_mau_full(2);
    }else doi_mau_full(4);
    string siSoStr = to_string(cur_sv) + "/" + to_string(max_sv);
    cout <<left<<setw(width - 23)<<("Sĩ số: " + siSoStr);
    doi_mau_full(7);
    cout<<" │" << endl;  
     cout<<"  │ "<<right<<setw(width + 2)<<" │"<<endl;
    // Dòng 5: Thời gian
    cout << "  │ " << left << setw(width + 8) << ("Lịch học(hằng tuần): " + time.hienthithongtin_string()) << " │" << endl;

    cout << "  ├──────────────────────────────────────────────────────────┤" << endl;
}

bool couse::tang_sv() {
    if (cur_sv < max_sv) {
        cur_sv++;
        return true;
    }
    else return false;
}
bool couse::giam_sv() {
    if (cur_sv > 0) {
        cur_sv--;
        return true;
    }
    else return false;
}
bool couse::ktra_full() {
    if (cur_sv == max_sv) {
        return true;
    }
    else return false;
}
bool couse::nhap(giangvien* gv_func, subject* sub_func) {
    time.nhap();
    if (!gv_func->kra_trung_lich(time)) {
        cout << "Nhập số lượng sinh viên tối đa: ";
        cin >> max_sv;
        cur_sv = 0;
        gv = gv_func;
        gv->them_couse_da_day_id(ma_lop_hoc);
        gv->them_lich_day(time);
        mon_hoc = sub_func;
        mon_hoc->add_ma_lop_hoc(ma_lop_hoc);
        return true;
<<<<<<< HEAD
    }else{
        doi_mau_full(4);
        cout<<" ❗Giảng viên đã trùng lịch";
        doi_mau_full(7);
=======
    }
    else {
        UI::doi_mau_full(4);
        cout << " ❗Giảng viên đã trùng lịch";
        UI::doi_mau_full(7);
>>>>>>> 73aa9b80af4464efd3f24652abd5453f63bb6cb5
        return false;
    }
}
// bool couse::nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a){
//        gv = ds_gv.tim_giangvien_theo_id(a[2]);
//     //    if(!gv) return false;
//         time = ds_time.tim_kip_hoc_theo_tg(a[3]);
//         // if(!time) return false;
//         mon_hoc = ds_sub.tim_mon_theo_ten(a[1]);
//         // if(!mon_hoc) return false;2
//         max_sv = stoi(a[4]);
//         cur_sv = 0;
//     return true;    
//  }
bool couse::xuat_du_lieu_file(string& line) {
    line = ma_lop_hoc + "|" + mon_hoc->get_ten() + "|" + gv->get_id() + "|" + to_string(time.get_bat_dau()) + "|" + to_string(time.get_ket_thuc()) + "|" + to_string(time.get_thu())
        + "|" + to_string(max_sv);
    return true;
}
void couse::cap_nhat_id(string id) {
    int so = stoi(id.substr(3));
    if (so > sl) {
        sl = so;
    }
}

