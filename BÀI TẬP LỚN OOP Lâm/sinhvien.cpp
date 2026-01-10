#include<iostream>
#include<string>
#include<fstream>
#include"sinhvien.h"
#include"UI.h"
using namespace std;
void sinhvien::hien_thi_lop_da_dky(){
    for( couse *p : ds_mon_dky){
        p->hienthi();
        cout<<"\n";        
    }
}
bool sinhvien::dadangky(couse* mon) {
    if (ds_mon_dky.size() == 0) {
        return false;
    }
    else {
        for (int i = 0; i < ds_mon_dky.size(); i++) {
            if (ds_mon_dky[i] == mon) {
                return true;
            }
        }
        return false;
    }
}
bool sinhvien::add_couse(couse* mon) {
    if (dadangky(mon)) {
        cout << "Môn học đã được đăng ký!" << endl;
        return false;
    }
    else if (cur_tc + mon->get_tin_chi() > max_tc) {
        cout << "Vượt quá số lượng tín chỉ, không thể thêm" << endl;
        return false;
    }
    else {
        ds_mon_dky.push_back(mon);
        cur_tc += mon->get_tin_chi();
        return true;
    }
    return false;
}
bool sinhvien::delete_couse(couse* mon) {
    if (!dadangky(mon)) {
        cout << "Không có môn học, không thể xóa!" << endl;
        return false;
    }
    else {
        for (int i = 0; i < ds_mon_dky.size(); i++) {
            if (ds_mon_dky[i] == mon) {
                ds_mon_dky.erase(ds_mon_dky.begin() + i);   // XÓA GỌN
                cur_tc -= mon->get_tin_chi();               // trừ tín chỉ đúng
                return true;
            }
        }
    }
    return false;
}
void sinhvien::hienthithongtin() {
    string title = "[ SINH VIÊN ] " + name;
    string string_bỉth = (to_string(birth[0]) + "/" + to_string(birth[1]) + "/" + to_string(birth[2]));
    doi_mau_full(9); // Màu Cyan (Xanh lơ)
    cout << "\n  "<<space() <<  "╭───────────────────────────────────────────────────────────────────╮"<< endl;

    // --- Dòng tiêu đề thẻ ---
    cout << space() << "  " << "│";
    doi_mau_full(14); // Màu Yellow (Vàng)
    cout<<"                 " <<left<< setw(50 + getUTF8LenDiff(title)) << title;
   
    doi_mau_full(9);
    cout << "│" << endl;

    // --- Đường kẻ ngang phân cách ---
     cout << space() << "  ├───────────────────────────────────────────────────────────────────┤" << endl;

    // --- Nội dung (Chia 2 cột) ---
    cout << space() << "  " << "│";
    doi_mau_full(7);
    cout << " Mã sinh viên: " << left << setw(22) << id 
         << " Ngày sinh: " << left << setw(18 + getUTF8LenDiff(string_bỉth)) << string_bỉth;
    doi_mau_full(9); cout << "│" << endl;

    cout << space() << "  " << "│";
    doi_mau_full(7);
    cout << " Giới tính: " << left << setw(25 + getUTF8LenDiff(gioi_tinh)) << gioi_tinh
         << " Số điện thoại: " << left << setw(14) << sdt;
    doi_mau_full(9); cout << "│" << endl;

    cout << space() << "  " << "│";
    doi_mau_full(7);
    cout << " Chuyên ngành: " << left << setw(22 + getUTF8LenDiff(chuyen_nganh)) << chuyen_nganh 
         << " Khoá: " << left << setw(23 + getUTF8LenDiff(to_string(khoa))) << khoa;
    doi_mau_full(9); cout << "│" << endl;

    // --- Phần thông tin tín chỉ ---
     cout<<space() << "  ├───────────────────────────────────────────────────────────────────┤" << endl;

    cout << space() << "  " << "│";
    doi_mau_full(7);
    cout << " Số tín chỉ tối đa được đăng ký: " << left << setw(4) << max_tc
         << " Số tín chỉ đã đăng ký: ";
    doi_mau_full(10); // Màu Green (Xanh lá) cho con số
    cout << left << setw(6) << cur_tc;
    doi_mau_full(9); cout << "│" << endl;

    cout << space() << "  " << "│";
    doi_mau_full(7);
    cout << " Số lớp học đã đăng ký: ";
    doi_mau_full(10); cout << left << setw(43) << ds_mon_dky.size();
    doi_mau_full(9); cout << "│" << endl;

    // --- Cạnh dưới ---
      cout << space() << "  ╰───────────────────────────────────────────────────────────────────╯" << endl;
}
void sinhvien::nhap()
{
    cout << "Nhập mã sinh viên: ";
    getline(cin, id);
    cout << "Nhập họ và tên: ";
    getline(cin, name);
    cout << "Nhập ngày tháng năm sinh: \n";
    cout << "  Ngày: ";
    cin >> birth[0];
    cout << "  Tháng: ";
    cin >> birth[1];
    cout << "  Năm: ";
    cin >> birth[2];
    cin.ignore();
    cout << "Nhập giới tính: ";
    getline(cin, gioi_tinh);
    cout << "Nhập số điện thoại: ";
    getline(cin, sdt);
    cout << "Nhập chuyên ngành: ";
    getline(cin, chuyen_nganh);
    cout << "Nhập khóa: ";
    cin >> khoa;
    cout << "Nhập số tín chỉ tối đa: ";
    cin >> max_tc;
}
bool sinhvien::nhap_du_lieu_tu_file(ifstream& f) {
    vector<string> a;
    string line;
    string temp = "";
    if (!getline(f, line)) {
        return false;
    }
    if (line.empty()) return false;
    for (char c : line) {
        if (c == '|') {
            a.push_back(temp);
            temp = "";
        }
        else {
            temp += c;
        }
    }
    a.push_back(temp);
    temp = "";
    if (a.size() != 10) return false;
    id = a[0];
    name = a[1];
    gioi_tinh = a[2];
    chuyen_nganh = a[3];
    sdt = a[4];
    birth[0] = stoi(a[5]);
    birth[1] = stoi(a[6]);
    birth[2] = stoi(a[7]);
    khoa = stoi(a[8]);
    max_tc = stoi(a[9]);
    return true;
}

void sinhvien::ghi_vao_file(ofstream &f)
{
    f << id << "|" << name << "|" << gioi_tinh << "|"
        << chuyen_nganh << "|" << sdt << "|" << birth[0] << "|"
        << birth[1] << "|" << birth[2] << "|" << khoa << "|"
        << max_tc << endl;
}
