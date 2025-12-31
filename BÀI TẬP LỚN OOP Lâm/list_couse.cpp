#include<iostream>
#include<fstream>
#include"list_couse.h"
#include"UI.h"
#include<string>
using namespace std;
void list_couse::hienthidanhsach() {
    cout << " ✦ ✧ ✦ ✧ ✦ ✧ ✦ ✧ ✦ DANH SÁCH TEST ✦ ✧ ✦ ✧ ✦ ✧ ✦ ✧ ✦" << endl;
    for (int i = 0; i < p.size(); i++) {
        p[i]->hienthi();
        cout << "\n";
    }
}
<<<<<<< HEAD
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
=======
bool list_couse::timkiem_ten(string ten_mon) {
    int dem = 0;
    string ten_mon_upper = ten_mon;
    ten_mon_upper[0] = toupper(ten_mon_upper[0]);
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->get_mon_hoc()->get_ten().find(ten_mon_upper) != string::npos ||
            p[i]->get_mon_hoc()->get_ten().find(ten_mon) != string::npos) {
            p[i]->hienthi();
            dem++;
        }
    }
    if (dem == 0) {
        cout << "ko tim thay ket qua!" << endl;
        return false;
    }
    else {
        cout << "tim thay tat ca " << dem << " mon hoc!" << endl;
        return true;
    }
}
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
void list_couse::nhap_test(giangvien* gv_func, subject* sub_func, string file_name) {
>>>>>>> 73aa9b80af4464efd3f24652abd5453f63bb6cb5
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
        doi_mau_full(4);
        cout << "Loi nhap lieu, vui long chon dung!\n";
        doi_mau_full(7);
        return;
    }
    // Gọi hàm nhập dữ liệu lớp học
<<<<<<< HEAD
    if(newCourse->nhap(gv_func, sub_func)){
        doi_mau_full(2);
        cout<<"tao lop moi thanh cong!";
        doi_mau_full(7);
        
        newCourse ->xuat_du_lieu_file(file_name);
    // Đưa vào danh sách
=======
    if (newCourse->nhap(gv_func, sub_func)) {
        UI::doi_mau_full(2);
        cout << "tao lop moi thanh cong!";
        UI::doi_mau_full(7);

        newCourse->xuat_du_lieu_file(file_name);
        // Đưa vào danh sách
>>>>>>> 73aa9b80af4464efd3f24652abd5453f63bb6cb5
        p.push_back(newCourse);
    }
    else {
        newCourse = nullptr;
        delete newCourse;
<<<<<<< HEAD
        doi_mau_full(4);
        cout<<"tao lop moi that bai!";
        doi_mau_full(7);
=======
        UI::doi_mau_full(4);
        cout << "tao lop moi that bai!";
        UI::doi_mau_full(7);
>>>>>>> 73aa9b80af4464efd3f24652abd5453f63bb6cb5
    }
}
bool list_couse::nhap_du_lieu_tu_file(list_giangvien& ds_gv, list_subject& ds_sub, string file_name) {
    vector<string> a;
    string line;
    string temp = "";
    int dem = 0;
    ifstream f(file_name);
    if (!f.is_open()) {
        cout << "ko mo dc file!" << endl;
        return false;
    }
    else {
        while (getline(f, line)) {
            if (line.empty()) continue;
            for (char c : line) {
                if (c == '|') {
                    a.push_back(temp); /* đoạn này tách chuỗi theo dấu '|' */
                    temp = "";
                }
                else {
                    temp += c;
                }
            }
            a.push_back(temp);
            temp = "";
            if (!check_id_hop_le(a[1])) {
                cout << "ma lop hoc khong hop le, bo qua lop hoc thu  " << dem + 1 << "!" << endl;
                a.clear();
                continue;
            }
            couse* mon = nullptr;
            giangvien* gv_temp = ds_gv.tim_giangvien_theo_id(a[3]);
            subject* sub_temp = ds_sub.tim_mon_theo_ten(a[2]);
            if (a[0] == "online" && a.size() == 9) {
                mon = new online(a[1], sub_temp, gv_temp, stoi(a[4]), stoi(a[5]), stoi(a[6]), stoi(a[7]), a[8]);
            }
            else if (a[0] == "offline" && a.size() == 10) {
                mon = new offline(a[1], sub_temp, gv_temp, stoi(a[4]), stoi(a[5]), stoi(a[6]), stoi(a[7]), a[8], a[9]);
            }
            else {
                cout << "loai lop hoc khong hop le!" << endl;
                continue;
            }
            if (!gv_temp->kra_trung_lich(mon->get_time())) {
                gv_temp->them_couse_da_day_id(mon->get_ma_lop_hoc());
                sub_temp->add_ma_lop_hoc(mon->get_ma_lop_hoc());
                couse::cap_nhat_id(a[1]);
                p.push_back(mon);
                dem++;
                a.clear();
            }
            else {
                cout << "du lieu trong file co trung lich, bo qua lop hoc" << endl;
                a.clear();
                continue;
            }
        }
    }
}
doi_mau_full(2);
cout<<"da nhap thanh cong "<<dem+1<<" lop hoc!"<<endl;
doi_mau_full(7);
f.close();
    return true;
}

couse* list_couse::tim_lop_theo_ma(string ma){
    //Tìm kiếm nhị phân cho tối ưu
    int l = 0;
    int r = p.size() - 1;
    int m;
    while(l<=r){
        m = (l + r) /2;
        if(p[m]->get_ma_lop_hoc() == ma){
            return p[m];
        }else if(p[m]->get_ma_lop_hoc() < ma ){
            l = m+1;
        }else{
            r = m-1;
        }
    }
    couse* temp = nullptr;
    return temp;
}

bool list_couse::check_id_hop_le(string id) {
    if (id.length() != 6) return false;
    if (id.substr(0, 3) != "MTA") return false;
    for (int i = 3; i < 6; i++) {
        if (id[i] < '0' || id[i]>'9') {
            return false;
        }
    }
    return true;
}

void list_couse::xuat_du_lieu_ra_file(string file_name) {
    ofstream f(file_name);
    if (!f.is_open()) {
        cout << "ko mo dc file" << endl;
    }
    else {
        for (int j = 0; j < p.size(); j++) {
            p[j]->xuat_du_lieu_file(file_name);
        }
    }
    f.close();
}

bool list_couse::delete_lop_hoc(string ma_lop, string file_name) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->get_ma_lop_hoc() == ma_lop) {
            if (p[i]->get_cur_sv() != 0) {

                cout << "ko the xoa lop hoc vi da co sinh vien dang ky!" << endl;
                return false;
            }
            subject* y = p[i]->get_mon_hoc();
            if (!y->xoa_ma_lop_hoc(ma_lop)) {
                cout << "xoa ma lop hoc khoi mon hoc that bai!" << endl;
                return false;
            }

            giangvien *x = p[i]->get_gv();
            if(!x->xoa_couse_da_day_id(ma_lop)){
                cout<<"xoa lop hoc khoi giang vien that bai!"<<endl;
                return false;
            }
            if(!x->xoa_lich_day(p[i]->get_time())){
                cout<<"Xoá lịch dạy giảng viên thất bại!";
                return false;
            }
            delete p[i];
            p.erase(p.begin() + i);
            cout << "xoa lop hoc khoi danh sach thanh cong!" << endl;
            // Cập nhật lại file sau khi xóa
            xuat_du_lieu_ra_file(file_name);
            cout << "cap nhat file sau xoa lop hoc thanh cong!" << endl;
            return true;
        }
    }
    cout << "ko tim thay lop hoc de xoa!" << endl;
    return false;
}




