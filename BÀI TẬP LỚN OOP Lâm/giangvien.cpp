#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"giangvien.h"
using namespace std;
void giangvien::nhapthongtin(){
        cout << "\n=== NHAP THONG TIN GIANG VIEN ===\n";
        
        // Nhập tên giảng viên
        cout << "Nhap ten giang vien: ";
        getline(cin, ten_giang_vien);
        
        // Nhập giới tính với kiểm tra
        while (true) {
            cout << "Nhap gioi tinh (Nam/Nu): ";
            getline(cin, gioi_tinh);
            if (gioi_tinh == "Nam" || gioi_tinh == "Nu" || 
                gioi_tinh == "nam" || gioi_tinh == "nu") {
                // Chuẩn hóa: viết hoa chữ cái đầu
                gioi_tinh[0] = toupper(gioi_tinh[0]);
                break;
            }
            cout << "Gioi tinh khong hop le! Vui long nhap lai.\n";
        }
        
        // Nhập ngày sinh với kiểm tra
        cout << "--- Nhap ngay sinh ---\n";
        
        // Nhập năm
        while (true) {
            cout << "Nam sinh (1950-2005): ";
            cin >> birth[2];
            if (birth[2] >= 1950 && birth[2] <= 2005) break;
            cout << "Nam sinh khong hop le! Vui long nhap lai.\n";
        }
        
        // Nhập tháng
        while (true) {
            cout << "Thang sinh (1-12): ";
            cin >> birth[1];
            if (birth[1] >= 1 && birth[1] <= 12) break;
            cout << "Thang sinh khong hop le! Vui long nhap lai.\n";
        }
        
        // Nhập ngày với kiểm tra theo tháng
        while (true) {
            cout << "Ngay sinh: ";
            cin >> birth[0];
            
            bool hop_le = true;
            if (birth[0] < 1) {
                hop_le = false;
            } else {
                // Kiểm tra ngày theo tháng
                int ngay_max;
                if (birth[1] == 4 || birth[1] == 6 || birth[1] == 9 || birth[1] == 11) {
                    ngay_max = 30;
                } else if (birth[1] == 2) {
                    // Kiểm tra năm nhuận
                    bool nam_nhuan = (birth[2] % 4 == 0 && birth[2] % 100 != 0) || 
                                     (birth[2] % 400 == 0);
                    ngay_max = nam_nhuan ? 29 : 28;
                } else {
                    ngay_max = 31;
                }
                
                if (birth[0] > ngay_max) {
                    hop_le = false;
                    cout << "Thang " << birth[1] << " chi co toi da " << ngay_max << " ngay!\n";
                }
            }
            
            if (hop_le) break;
            cout << "Ngay sinh khong hop le! Vui long nhap lai.\n";
        }
        
        cin.ignore();  // Xóa bộ đệm
        cout<<"nhap hoc vi giang vien: ";
        getline(cin,hoc_vi);
          while (true) {
            cout << "\nNhap so dien thoai (10-11 so): ";
            getline(cin, sdt);
            
            // Kiểm tra chỉ chứa số
            bool valid = true;
            for (char c : sdt) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid && sdt.length() >= 10 && sdt.length() <= 11) {
                break;
            }
            cout << "So dien thoai khong hop le! Vui long nhap lai.\n";
        }
        cin.ignore();
        cout<<"nhap bo mon giang vien: ";
        getline(cin,bo_mon);
}

void giangvien::hienthithongtin(){
        cout << "\n📋 CHI TIET GIANG VIEN: " << ten_giang_vien << "\n";
        cout << "==========================================\n";
        
        // Nhóm thông tin
        cout << "\n📌 THONG TIN CA NHAN:\n";
        cout << "  - Gioi tinh: " << gioi_tinh << endl;
        cout << "  - Ngay sinh: " << birth[0] << "/" << birth[1] << "/" << birth[2] << endl;
        
        int tuoi = 2025 - birth[2];
        cout << "  - Tuoi: " << tuoi<<endl;
        cout << "  - SDT: " << sdt << endl;
        
        cout << "\n🎓 THONG TIN CHUYEN MON:\n";
        cout << "  - Hoc vi: " << hoc_vi << endl;
        cout << "  - Bo mon: " << bo_mon << endl;

        // cout << "\n📚 MON DA GIANG DAY:\n";
        // if (mon_da_day.empty()) {
        //     cout << "  - Chua co mon nao duoc phan cong\n";
        // } else {
        //     cout << "  - Tong so mon: " << mon_da_day.size() << endl;
        // cout << "==========================================\n";
        // }
}

bool giangvien::nhap_du_lieu_tu_file(ifstream &f){
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
        if(a.size() != 9) return false;
        id = a[0];
        ten_giang_vien = a[1];
        gioi_tinh = a[2];
        hoc_vi = a[3];
        sdt = a[4];
        bo_mon = a[5];
        birth[0] = stoi(a[6]);
        birth[1] = stoi(a[7]);
        birth[2] = stoi(a[8]);
    return true;
}

bool giangvien::kra_trung_lich(Time a){
    for(auto i : lich_day){
        if(i.ktra_trung_lich(a)){
            return true;
        }
    }
    lich_day.push_back(a);
    return false;
}

bool giangvien::xoa_couse_da_day_id(string ma_lop){
    for(int i = 0;i<couse_da_day.size();i++){
        if(couse_da_day[i] == ma_lop){
            couse_da_day.erase(couse_da_day.begin()+i);
            cout<<"da xoa lop hoc "<<ma_lop<<" khoi danh sach mon da day cua giang vien "<<ten_giang_vien<<endl;
            return true;
        }
    }
    return false;
}

void giangvien::xoa_lich_day(Time a){
    for(int i = 0;i<lich_day.size();i++){
        if(lich_day[i] == a){
            lich_day.erase(lich_day.begin()+i);
        }
    }
}