#include<iostream>
#include<fstream>
#include"list_couse.h"
#include<string>
using namespace std;
void list_couse::hienthidanhsach(){
    cout<<"--------------DANH SACH TEST---------------"<<endl;
    for(int i = 0;i<p.size();i++){
        p[i] ->hienthi();
        cout<<"\n";
    }
}
// bool list_couse::timkiem_ten(string ten_mon){
//     int dem = 0;
//     string ten_mon_upper = ten_mon;
//     ten_mon_upper[0] = toupper(ten_mon_upper[0]);
//     for(int i = 0;i<cnt;i++){
//         if(p[i]->getten_mon_hoc().find(ten_mon_upper) != string::npos||
//         p[i]->getten_mon_hoc().find(ten_mon) != string::npos){
//         p[i] ->hienthi();
//         dem++;
//         }
//     }
//     if(dem == 0){
//         cout<<"ko tim thay ket qua!"<<endl;
//         return false;
//     }else{
//     cout<<"tim thay tat ca "<<dem<<" mon hoc!"<<endl;
//     return true;
//     }
// }
// void list_couse::nhapdanhsach(string file_name){
//     string chose;
//     string line;
//     ofstream f(file_name,ios::app);
//     if(!f.is_open()){
//         cout<<"ko mo dc file!"<<endl;
//         return;
//     }
//     cout<<"Nhap loai lop hoc muon dang ( ON / OFF): ";
//     getline(cin,chose);
//     if(chose == "ON" || chose == "on"){
//         p[cnt] = new online;
//         p[cnt] -> nhap();
//         p[cnt] ->fix_matusinh();
//         p[cnt] ->tusinhma(); /* xử lý hàm tự sinh mã khởi tạo trc khi có tên môn ->mã sai */
//         line = "online|"+ p[cnt]->get_time()+"|"+p[cnt]->getten_mon_hoc()
//         +"|"+p[cnt]->get_gv()+"|"+to_string(p[cnt]->get_tc())+"|"+to_string(p[cnt]->get_cursv())
//         +"|"+to_string(p[cnt]->get_maxsv())+"|"+p[cnt]->get_data();
//         cnt++;
//     }else if(chose == "OFF" || chose == "off"){
//         p[cnt] = new offline;
//         p[cnt] -> nhap();
//          p[cnt] ->fix_matusinh();
//         p[cnt] ->tusinhma();
//         line = "offline|" + p[cnt]->get_time()+"|"+p[cnt]->getten_mon_hoc()
//         +"|"+p[cnt]->get_gv()+"|"+to_string(p[cnt]->get_tc())+"|"+to_string(p[cnt]->get_cursv())
//         +"|"+to_string(p[cnt]->get_maxsv())+"|"+p[cnt]->get_data();
//         cnt++;
//     }else{
//         cout<<"loi nhap lieu, vui long chon dung!"<<endl;
//     }
//     f<<endl;
//     f<<line;
//     f.close();
//     cout<<"them mon hoc thanh cong!";
// } đoạn này ko lỡ xoá vì chức năng tìm kiếm tên gần đúng sau này có thể tham khảo lại
void list_couse::nhap_test(giangvien &gv_func, Time &time_func, subject &sub_func,string file_name) {
    string chose;
    cout << "Nhap loai lop hoc muon dang (ON / OFF): ";
    getline(cin, chose);

    couse* newCourse = nullptr;

    if (chose == "ON" || chose == "on") {
        newCourse = new online;
    }
    else if (chose == "OFF" || chose == "off") {
        newCourse = new offline;
    }
    else {
        cout << "Loi nhap lieu, vui long chon dung!\n";
        return;
    }
    // Gọi hàm nhập dữ liệu lớp học
    newCourse->nhap(gv_func, time_func, sub_func);
    newCourse ->xuat_du_lieu_file(file_name);

    // Đưa vào danh sách
    p.push_back(newCourse);
    cout << "Them mon hoc thanh cong!\n";
}
bool list_couse::nhap_du_lieu_tu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,string file_name){
    vector<string> a;
    string line;   
    string temp = "";
    ifstream f(file_name);
    if(!f.is_open()){  
        cout<<"ko mo dc file!"<<endl;
        return false;
    }else{
        while(getline(f,line)){
         if(line.empty()) continue;
          for(char c : line){ 
            if(c == '|'){
                a.push_back(temp); /* đoạn này tách chuỗi theo dấu '|' */
                temp = "";
            }else{
                temp +=c;
            }
        }
       a.push_back(temp);
       temp = "";
       couse *mon = nullptr;
       if(a[0] == "online"){
        mon = new online;
        mon->nhap_du_lieu_file(ds_gv,ds_time,ds_sub,a);
       }else if(a[0] == "offline"){
        mon = new offline;
        mon->nhap_du_lieu_file(ds_gv,ds_time,ds_sub,a);
       }else{
        cout<<"loai lop hoc khong hop le!"<<endl;
        return false;
       }
       p.push_back(mon);
       a.clear();
    }
}
f.close();
    return true;
}
couse* list_couse::tim_lop_theo_ma(string ma){
    for(int i = 0;i<p.size();i++){
        if(p[i]->get_ma_mon_hoc() == ma){
            return p[i];
        }
    }
    return nullptr;
}

    

    
