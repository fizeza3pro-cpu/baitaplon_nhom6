#include<iostream>
#include<fstream>
#include"list_couse.h"
#include"UI.h"
#include<string>
using namespace std;
void list_couse::hienthidanhsach(){
    doi_mau_full(14);
    cout<<"                ─────────────── ✦ ───────────────DANH SÁCH LỚP HỌC─────────────── ✦ ───────────────"<<endl;
    doi_mau_full(7);
    for(int i = 0;i<p.size();i++){
        p[i] ->hienthi();
        cout<<"\n";
    }
}
void list_couse::timkiem_ten(string ten_mon){
    if(ten_mon == ""){
        cout<<"Không tìm thấy kết quả!"<<endl;
        return;
    }
    int dem = 0;
    string ten_mon_upper = ten_mon;
    ten_mon_upper[0] = toupper(ten_mon_upper[0]);

    for(int i = 0;i<p.size();i++){
        if(p[i]->get_mon_hoc()->get_ten().find(ten_mon_upper) != string::npos||
        p[i]->get_mon_hoc()->get_ten().find(ten_mon) != string::npos){
        p[i] ->hienthi();
        dem++;
        }
    }
    if(dem == 0){
        cout<<"Không tìm thấy kết quả!!"<<endl;
        return;
    }else{
    cout<<"Tìm thấy tất cả "<<dem<<" môn học!"<<endl;
    }
}

void list_couse::hien_thi_lop_theo_tc(int tc){
    int dem = 0;
    for(int i = 0;i<p.size();i++){
        if(p[i]->get_tin_chi() == tc){
            p[i] ->hienthi();
            ++dem;
        }
    }
    cout<<endl;
    if(dem == 0){
        cout<<"Không có kết quả!";
    }else{
        cout<<"Tìm kiếm tổng cộng "<<dem<<" lớp học";
    }
}

void list_couse::nhap_test(giangvien *gv_func, subject *sub_func,string file_name) {
    string chose;
    cout << "Nhập loại lớp học muốn tạo (ON / OFF): ";
    getline(cin, chose);

    couse* newCourse = nullptr;

    if (chose == "ON" || chose == "on") {
        newCourse = new online;
    }
    else if (chose == "OFF" || chose == "off") {
        newCourse = new offline;
    }
    else {
        doi_mau_full(4);
        cout << "Lỗi nhập liệu, vui lòng chọn đúng (ON/OFF)!\n";
        doi_mau_full(7);
        return;
    }
    // Gọi hàm nhập dữ liệu lớp học
    if(newCourse->nhap(gv_func, sub_func)){
        doi_mau_full(2);
        cout<<"Tạo lớp mới thành công!";
        doi_mau_full(7);
        
        newCourse ->xuat_du_lieu_file(file_name);
    // Đưa vào danh sách
        p.push_back(newCourse);
    }else{
        delete newCourse;
        newCourse = nullptr;
        doi_mau_full(4);
        cout<<"Tạo lớp mới thất bại!";
        doi_mau_full(7);
    }
}
bool list_couse::nhap_du_lieu_tu_file(list_giangvien &ds_gv,list_subject &ds_sub,string file_name){
    vector<string> a;
    string line;   
    string temp = "";
    int dem = 0;
    ifstream f(file_name);
    if(!f.is_open()){  
        cout<<"Không mở được file!"<<endl;
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
       if(!check_id_hop_le(a[1])){
        cout<<"mã môn học không hợp lệ, bỏ qua lớp học thứ "<<dem+1<<"!"<<endl;
        a.clear();
        continue;
       }
       couse *mon = nullptr;
       giangvien *gv_temp = ds_gv.tim_giangvien_theo_id(a[3]);
       subject *sub_temp = ds_sub.tim_mon_theo_ma(a[2]);
       if(a[0] == "online" && a.size() == 10){
        mon = new online(a[1],sub_temp,gv_temp,stof(a[4]),stof(a[5]),stoi(a[6]),stoi(a[7]),a[8],a[9]);
       }else if(a[0] == "offline" && a.size() == 10){
        mon = new offline(a[1],sub_temp,gv_temp,stof(a[4]),stof(a[5]),stoi(a[6]),stoi(a[7]),a[8],a[9]);
       }else{
        cout<<"Loại lớp học không hợp lệ, bỏ qua dòng nhập!"<<endl;
        continue;
       }
       if(!gv_temp->kiemtra_trung_lich(mon->get_time())){
            gv_temp->them_couse_da_day_id(mon->get_ma_lop_hoc());
            sub_temp->add_ma_lop_hoc(mon->get_ma_lop_hoc());
            couse::cap_nhat_id(a[1]);
            p.push_back(mon);
            dem++;
             a.clear();
       }else{
        cout<<"dữ liệu trong file có trùng lịch, bỏ qua dòng nhập"<<endl;
        a.clear();
        continue;
       }
    }
}
doi_mau_full(2);
cout<<"Đã nhập thành công "<<dem+1<<" lớp học!"<<endl;
doi_mau_full(7);
f.close();
    return true;
}

couse* list_couse::tim_lop_theo_ma(string ma){
    //Tìm kiếm nhị phân cho tối ưu
    // int l = 0;
    // int r = p.size() - 1;
    // int m;
    // while(l<=r){
    //     m = (l + r) /2;
    //     if(p[m]->get_ma_lop_hoc() == ma){
    //         return p[m];
    //     }else if(p[m]->get_ma_lop_hoc() < ma ){
    //         l = m+1;
    //     }else{
    //         r = m-1;
    //     }
    // }
    // couse* temp = nullptr;
    // return temp;
    for(int i = 0;i<p.size();i++){
         if(p[i]->get_ma_lop_hoc() == ma){
           return p[i];
         }
    }
     couse* temp = nullptr;
     return temp;
}

bool list_couse::check_id_hop_le(string id){
    if(id.length() != 6) return false;
    if(id.substr(0,3) != "MTA") return false;
    for(int i =3;i<6;i++){
        if(id[i]<'0' || id[i]>'9'){
            return false;
        }
    }
    return true;
}

// void list_couse::xuat_du_lieu_ra_file(string file_name){
//     ofstream f(file_name);
//         if(!f.is_open()){
//             cout<<"ko mo dc file"<<endl;
//         }else{
//             for(int j = 0;j<p.size();j++){
//                 p[j]->xuat_du_lieu_file(file_name);
//             }
//         }
//     f.close();
// }
void list_couse::xuat_du_lieu_ra_file_full(string file_name){
    ofstream f(file_name);
    if (!f.is_open()) {
        cout << "Không mở được file!";
        return;
    }
    string line;
    for(int i = 0;i<p.size();i++){
        p[i]->string_file(line);
        f<<line<<endl;
    }
    doi_mau_full(2);
    cout<<"Lưu dữ liệu vào file "<<file_name<<" thành công!"<<endl;
    doi_mau_full(7);
    f.close();
}

bool list_couse::delete_lop_hoc(string ma_lop,string file_name){
    for(int i = 0;i<p.size();i++){
        if(p[i]->get_ma_lop_hoc() == ma_lop){
            if (p[i]->get_cur_sv() != 0) {
                cout << "Không thể xóa lớp học vì đã có sinh viên đăng ký!\n";
                return false;
            }   

            subject* y = p[i]->get_mon_hoc();
            giangvien* x = p[i]->get_gv();

            if (!y || !x) return false;

// check trước
            if (!y->check_ma_lop_hoc(ma_lop)) {
                cout << "Môn học "<<y->get_ten()<<"  không chứa lớp này!\n";
                return false;
            }

            if (!x->check_lop_dang_day(ma_lop)) {
                cout << "Giảng viên "<<x->get_name()<<" chưa dạy lớp này!\n";
                return false;
            }
            y->xoa_ma_lop_hoc(ma_lop);
        x->xoa_couse_da_day_id(ma_lop);
        x->xoa_lich_day(p[i]->get_time());
        
        delete p[i];
        p.erase(p.begin() + i);
        
        xuat_du_lieu_ra_file_full(file_name);
        cout << "\nXoá lớp học thành công!\n";
        return true;
        }
    }
    cout << "\nXoá lớp học không thành công!\n";
    return false;
}

void list_couse::sap_xep_couse(string file_name){
       system("cls");
        cout<<"╭──────────────────────DANH SÁCH SẮP XẾP────────────────────╮"<<endl;
       cout<<"│"<<""<<setw(59)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"1.Xếp theo số sinh viên đã đăng ký (giảm dần)"<<setw(8)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"2.Xếp theo số tín chỉ (giảm dần)"<<setw(21)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"3.Xếp theo thời gian học"<<setw(29)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"Nhập lựa chọn của bạn: "<<setw(30)<<""<<"│"<<endl;
       cout<<"╰───────────────────────────────────────────────────────────╯"<<endl;
       gotoxy(30,5);
       int chose;
       cin>>chose;
       if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        return;
        }
        switch (chose)
        {
        case 1:
        {
           bbsort(so_sanh_sv);
            cout<<"\nĐã sắp xếp theo sinh viên ";
          
            break;
        }
        case 2:
        {
           bbsort(so_sanh_tc);
            cout<<"\nĐã sắp xếp theo tín chỉ";
          
            break;
        }
        case 3:
        {
           bbsort(so_sanh_time);
            cout<<"\nĐã sắp xếp theo thời gian tăng dần";
          
            break;
        }
        
        default:
        doi_mau_full(4);
        cout<<"Lựa chọn không hợp lệ";
        doi_mau_full(7);
            break;
        }
        xuat_du_lieu_ra_file_full(file_name);
    
}
//phương thức sắp xếp 
void list_couse::bbsort(bool (*ham_so_sanh)(couse *a, couse *b)){
    int n = p.size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(ham_so_sanh(p[j],p[j+1])){
                swap(p[j],p[j+1]);
            }
        }
    }
}


    

    
