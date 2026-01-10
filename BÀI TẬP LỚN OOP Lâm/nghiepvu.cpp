#include<iostream>
#include<stdlib.h>
#include"nghiepvu.h"
using namespace std;
//---------------------------lớp học---------------------------
void nghiepvu::them_mon_hoc(string ma_gv, string ten_mon, string file_name) {
    /* truyền vào hàm có thể là mã gv,... nhưng truyền cả đối tượng cho trực quan */
    giangvien* c = ds_gv.tim_giangvien_theo_id(ma_gv);
    if (c == nullptr) {
        cout << "⚠ Không tìm thấy giảng viên" << endl;
        return;
    }
    subject* e = ds_mon.tim_mon_theo_ma(ten_mon);
    if (e == nullptr) {
        cout << "⚠ Không tìm thấy môn học" << endl;
        return;
    }
    ds_lop.nhap_test(c, e, file_name);
    /*    phải thêm mã  lơp shocj vào cho mon, giangvien vs time */

}

void nghiepvu::dang_ky_lop_hoc(string id_sv, string ma_lop,string file_name_pdk) {
    sinhvien* a = ds_sv.tim_sinhvien_theo_id(id_sv);
    if (a == nullptr) {
        cout << "⚠ Không tìm thấy sinh viên" << endl;
        return;
    }
    couse* b = ds_lop.tim_lop_theo_ma(ma_lop);
    if (b == nullptr) {
        cout << "⚠ Không tìm thấy lớp học" << endl;
        return;
    }
    if (b->ktra_full()) {
        cout << "⚠ Lớp học đã đầy , không thể đăng ký" << endl;
        return;
    }
    if (a->add_couse(b)) {
        b->tang_sv();
        phieu_dang_ky temp;
        temp.tao_phieu_dky(a,b);
        ds_phieu_dky.push_back(temp);
        temp.ghi_tiep_vao_file(file_name_pdk);
        doi_mau_full(2);
        cout<<"✔ Đăng ký lớp học thành công!"<<endl;
    }else{
        doi_mau_full(4);
        cout<<"❌ Đăng ký môn học không thành công"<<endl;
    }   
    doi_mau_full(7);
}

void nghiepvu::huy_dang_ky_lop_hoc(string id_sv, string ma_lop,string file_name_pdk) {
    sinhvien* a = ds_sv.tim_sinhvien_theo_id(id_sv);
    if (a == nullptr) {
        cout << "Không tìm thấy sinh viên!" << endl;
        return;
    }
    couse* b = ds_lop.tim_lop_theo_ma(ma_lop);
    if (b == nullptr) {
        cout << "Không tìm thấy lớp học!" << endl;
        return;
    }
    //Duyệt hết các phiếu đăng ký, tìm nếu có phiếu phù hợp thì huỷ đăng ký
    //=>nếu có nhiều phiếu trùng nhau thì ko sao cả vì huỷ phiếu đầu tiên( xoá nó khỏi list rồi)
    // nên trong file sẽ vẫn đúng vì ghi ra từ list trong chương trình
    for (int i = 0; i < ds_phieu_dky.size(); i++) {
        if (ds_phieu_dky[i].checkphieu(a, b)) {
            if (a->delete_couse(b)) {
                ds_phieu_dky.erase(ds_phieu_dky.begin() + i);
         //----------chú ý đoạn này nhập đường dẫn gốc vào, có j nhớ sửa----------------
                ghi_du_lieu_file_phieu_dky(file_name_pdk);
                b->giam_sv();
                doi_mau_full(10);
                cout << "Huỷ đăng ký thành công!";
                doi_mau_full(7);
                return;
            }
        }
    }
}

void nghiepvu::nhap_du_lieu_cho_couse(string file_name) {
    if (ds_lop.nhap_du_lieu_tu_file(ds_gv, ds_mon, file_name)) {
        cout << "Nhập dữ liệu cho couse từ "<<file_name<<" thành công!" << endl;
    }
}

void nghiepvu::hienthi_ds_phieu_dky(){
    cout<<"─────────────────────────────────────LỊCH SỬ ĐĂNG KÝ────────────────────────────────────"<<"\n"<<endl;
    doi_mau_full(6); // Màu vàng cho tiêu đề nổi bật
    cout << "   " << left 
               << setw(19) << "Mã SV" 
               << setw(29) << "Họ và tên" 
               << setw(25) << "Lớp đăng ký" 
               << "Thời gian" << endl;
               doi_mau_full(7); // Trả về màu trắng cho dữ liệu
               cout<<"────────────────────────────────────────────────────────────────────────────────────────"<<endl;
    for(int i = 0;i<ds_phieu_dky.size();i++){
        ds_phieu_dky[i].hien_thi_phieu_dky();
        cout << "\n";
    }
    cout << "────────────────────────────────────────────────────────────────────────────────────────";
}

void nghiepvu::ghi_du_lieu_file_phieu_dky(string file_name){
    ofstream f(file_name);
    if (!f.is_open()){
        cout<<"Lỗi không mở đc file!";
        return;
    }
        for(int i = 0;i<ds_phieu_dky.size();i++){
            f<<ds_phieu_dky[i].string_file()<<endl;
        }
        cout<<"Ghi dữ liệu vào file"<<file_name<<" thành công"<<endl;
}

void nghiepvu::nhap_du_lieu_file_phieu_dky(string file_name){
     vector<string> a;
    string line;   
    string temp = "";
    int dem = 0;
    ifstream f(file_name);
    if(!f.is_open()){  
        cout<<"Không mở đc file!"<<endl;
        return;
    }else{
        while(getline(f,line)){
            //clear a và temp ngay từ đầu cho vòng lặp tiếp 
            a.clear();
            temp = "";

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
       sinhvien *sv_temp = ds_sv.tim_sinhvien_theo_id(a[0]);
       couse *lop_temp = ds_lop.tim_lop_theo_ma(a[1]);
       if (!sv_temp || !lop_temp) {
        cout<<"Không tồn tại lớp học hoặc sinh viên, skip!"<<endl;
        continue;
    }
       if(sv_temp->check_lop_dky(lop_temp)){
            cout<<"Phát hiện trùng phiếu đăng ký trong file, tiến hành bỏ qua"<<endl;
            continue;
       }
       phieu_dang_ky temp(sv_temp,lop_temp,a[2]);
       //Kiểm tra xem có add vào ds couse của sinh viên hay ko, nếu ko thì skip
       if(sv_temp->add_couse(lop_temp)){
           ds_phieu_dky.push_back(temp);
           lop_temp->tang_sv();
            dem++;
       }else{
        cout<<"vượt mức tín chỉ tối đa của sinh viên "<<sv_temp->get_ma()<<" tiến hành bỏ qua!"<<endl;
        continue;
       }
       }
    }
    doi_mau_full(2);
    cout<<"Đã nhập thành công "<<dem<<" phiếu đăng ký từ "<<file_name<<"!"<<endl;
    doi_mau_full(7);
    f.close();
}




void nghiepvu::thaydoithongtin_couse(string ma_lop, string file_name) {
    couse* lop = ds_lop.tim_lop_theo_ma(ma_lop);
    if (lop == nullptr) {
        cout << "Không tìm thấy lớp học!";
    }
    else {
        system("cls");
        cout<<"╭──────────────────────DANH SÁCH THAY ĐỔI───────────────────╮"<<endl;
       cout<<"│"<<""<<setw(59)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"1.Thay đổi giảng viên"<<setw(32)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"2.Thay đổi môn học"<<setw(35)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"3.Thay đổi số lượng sinh viên tối đa"<<setw(17)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"4.Thay đổi thời gian học"<<setw(29)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"Nhập lựa chọn của bạn: "<<setw(30)<<""<<"│"<<endl;
       cout<<"╰───────────────────────────────────────────────────────────╯"<<endl;
       gotoxy(30,6);
       int chose;
       cin>>chose;
       cout<<endl;
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
       
        cin.ignore();
    string ma_gv;
    cout << "Nhập mã giảng viên muốn đổi: ";
    getline(cin, ma_gv);
    
    giangvien* gv_moi = ds_gv.tim_giangvien_theo_id(ma_gv);
    if (gv_moi == nullptr) {
        cout << " Không tìm thấy giảng viên!";
        pause();
        return;
    }
    else {
        if (gv_moi->get_id() == lop->get_gv()->get_id()) {
            cout << " Giảng viên này hiện đang dạy lớp này rồi!";
            pause();
            return;
        }
        else {
            // KIỂM TRA TRÙNG LỊCH BẰNG CÁCH QUÉT DANH SÁCH LỚP
            bool bi_trung = false;
            Time thoi_gian_lop = lop->get_time();

            for (int i = 0; i < ds_lop.get_size(); i++) {
                couse* l = ds_lop.get_p(i);
                // Nếu lớp đó của giảng viên mới và trùng thời gian
                if (l->get_gv()->get_id() == gv_moi->get_id()) {
                    if (l->get_time().ktra_trung_lich(thoi_gian_lop)) {
                        bi_trung = true;
                        doi_mau_full(4);
                        cout << "❌ Trùng lịch với lớp [" << l->get_ma_lop_hoc() << "] của giảng viên này!";
                        doi_mau_full(7);
                        break;
                    }
                }
            }

            if (!bi_trung) {
                // Cập nhật giảng viên mới cho lớp
                giangvien *gv_cu = lop->get_gv();
                gv_cu->xoa_couse_da_day_id(lop->get_ma_lop_hoc());
                gv_cu->xoa_lich_day(lop->get_time());
                lop->set_giangvien(gv_moi);
                gv_moi->them_couse_da_day_id(lop->get_ma_lop_hoc());
                gv_moi->them_lich_day(lop->get_time());
                cout << "Thay đổi giảng viên thành công!"<<endl;
            }
        }
    }
        break;
        }
        case 2:
        {
            cin.ignore();
            if (lop->get_cur_sv() != 0) {
                cout << "Lớp đã có sinh viên đăng ký, không thể thay đổi môn học!";
                break;
            }
            else {
                cin.ignore();
                string ten_mon;
                cout << "Nhập mã môn học muốn đổi: ";
                getline(cin, ten_mon);
                subject* mon = ds_mon.tim_mon_theo_ma(ten_mon);
                if (mon == nullptr) {
                    cout << "kHÔNG TỒN TẠI MÔN HỌC!";
                }
                else {
                    cout << "THÔNG TIN MÔN HỌC: " << endl;
                    cout<<mon;
                    if (lop->get_mon_hoc() == mon) {
                        cout << "Lớp học đang dạy môn này, không thể đổi!";
                    }
                    else {
                        subject *mon_cu = lop->get_mon_hoc();
                        mon_cu->xoa_ma_lop_hoc(lop->get_ma_lop_hoc());
                        lop->set_mon(mon);
                        mon->add_ma_lop_hoc(lop->get_ma_lop_hoc());
                        cout << "Thay đổi môn học thành công!";
                    }
                }
            }
        }
        break;
        case 3:
        {
            int new_max;
            cout << "Số lượng sinh viên hiện tại: " << lop->get_cur_sv() << endl;
            cout << "Nhập số lượng sinh viên tối đa mới: ";
            cin >> new_max;

            // Kiểm tra nếu người dùng nhập chữ hoặc số âm
            if (cin.fail() || new_max < 0) {
                cin.clear(); // Xóa trạng thái lỗi
                cin.ignore(1000, '\n'); // Loại bỏ ký tự thừa
                doi_mau_full(12);
                cout << "❌ Giá trị nhập không hợp lệ!" << endl;
                doi_mau_full(7);
            } 
            else if (new_max < lop->get_cur_sv()) {
                doi_mau_full(12);
                cout << "❌ Không thể đặt tối đa " << new_max 
                    << " vì lớp đã có " << lop->get_cur_sv() << " sinh viên!" << endl;
                doi_mau_full(7);
            } 
            else {
                lop->set_max_sv(new_max);
                doi_mau_full(10);
                cout << " Thay đổi số lượng sinh viên tối đa thành công!" << endl;
                doi_mau_full(7);
            break;
        }
        case 4:
        {
        if (lop->get_cur_sv() != 0) {
        cout << "❌ Lớp đã có " << lop->get_cur_sv() << " người đăng ký, không thể thay đổi thời gian!";
        pause();
        return;
        }
    
        Time new_time;
        cout << "Nhập thời gian học mới: " << endl;
        new_time.nhap();

        giangvien* gv_hien_tai = lop->get_gv();
        bool bi_trung = false;
        string ma_lop_trung = "";

        // QUAN TRỌNG: Quét trực tiếp trên danh sách lớp học để đảm bảo dữ liệu mới nhất
        for (int i = 0; i < ds_lop.get_size(); i++) {
            couse* lop_khac = ds_lop.get_p(i);
            
            // Chỉ kiểm tra lớp của CÙNG giảng viên này 
            //tìm tất cả các lớp khác lớp đang xét có cùng gv dạy vs lớp đang xét
            if (lop_khac->get_gv()->get_id() == gv_hien_tai->get_id() && lop_khac->get_ma_lop_hoc() != lop->get_ma_lop_hoc()) {
                
                if (lop_khac->get_time().ktra_trung_lich(new_time)) {
                    bi_trung = true;
                    ma_lop_trung = lop_khac->get_ma_lop_hoc();
                    break;
                }
            }
        }

        if (bi_trung) {
            doi_mau_full(12);
            cout << "❌ Lỗi: Giảng viên " << gv_hien_tai->get_name() 
                << " đã có lịch dạy lớp [" << ma_lop_trung << "] vào thời gian này!" << endl;
            doi_mau_full(7);
            pause();
            return;
        }
        else {
            // Nếu không trùng, tiến hành cập nhật
            Time old_time = lop->get_time();
            lop->set_time(new_time);
            gv_hien_tai->xoa_lich_day(old_time);
            gv_hien_tai->them_lich_day(new_time);

            // Đồng bộ lại lịch dạy trong object giảng viên (để hiển thị cho đúng)
            // Bạn nên viết một hàm gv->cap_nhat_lich(old_time, new_time) nếu cần
            
            cout << " Thay đổi lịch học thành công!";
            pause();
            }
            break;
                }
                default:
                {
                doi_mau_full(4);
                    cout << "Lựa chọn không hợp lệ";
                    doi_mau_full(7);
                    pause();
                    return;
                    break;
                }

            }
            ds_lop.xuat_du_lieu_ra_file_full(file_name);
            pause();
        }
    } 
}

void nghiepvu::tim_kiem_lop_hoc(){
       cout << space() <<"╭───────────────────────TÌM KIẾM LỚP HỌC────────────────────╮"<<endl;
       cout << space() <<"│"<<""<<setw(59)<<""<<"│"<<endl;
       cout << space() <<"│"<<setw(6)<<""<<"1.Tìm kiếm lớp học theo môn học"<<setw(22)<<""<<"│"<<endl;
       cout << space() <<"│"<<setw(6)<<""<<"2.Tìm kiếm lớp học theo mã lớp học"<<setw(19)<<""<<"│"<<endl;
       cout << space() <<"│"<<setw(6)<<""<<"3.Tìm kiếm lớp học theo mã giảng viên"<<setw(16)<<""<<"│"<<endl;
       cout << space() <<"│"<<setw(6)<<""<<"4.Tìm kiếm lớp học theo số tín chỉ"<<setw(19)<<""<<"│"<<endl;
       cout << space() <<"│"<<setw(6)<<""<<"Nhập lựa chọn của bạn: "<<setw(30)<<""<<"│"<<endl;
       cout << space() <<"╰───────────────────────────────────────────────────────────╯"<<endl;
       gotoxy(55,6);
       int temp;
       cin>>temp;
       cout<<endl;
       if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        }
       switch (temp)
       {
       case 1:
       {
        system("cls");
        string temp;
        cout << space() <<"Nhập vào tên môn học: "<<endl;
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(30,2);
        cin.ignore();
        getline(cin,temp);
        system("cls");
        doi_mau_full(10);
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58 + getUTF8LenDiff(temp))<<("⌕ " + temp)<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        ds_lop.timkiem_ten(temp);
        break;
       }
       case 2:
       {
        system("cls");
        string temp;
        cout << space() <<"Nhập vào mã lớp học: "<<endl;
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(30,2);
        cin.ignore();
        getline(cin,temp);
        system("cls");
        doi_mau_full(10);
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58 + getUTF8LenDiff(temp))<<("⌕ " + temp)<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        couse *lop_temp = ds_lop.tim_lop_theo_ma(temp);
        if(lop_temp == nullptr){
            cout<<"Không tìm thấy lớp học!";
            break;
        }else{
            lop_temp->hienthi();
        }
        break;
       }
       case 3:
       {
        system("cls");
        string temp;
        cout << space() <<"Nhập vào ID giảng viên: "<<endl;
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(30,2);
        cin.ignore();
        getline(cin,temp);
        system("cls");
        doi_mau_full(10);
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58 + getUTF8LenDiff(temp))<<("⌕ " + temp)<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        hien_thi_lop_hoc_cua_gv(temp);
           break;
       }
       case 4:
       {
          system("cls");
        int temp;
        cout << space() <<"Nhập vào số tín chỉ : "<<endl;
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(30,2);
        cin>>temp;    
        if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        cin.ignore();
        break;
        }   
        system("cls");
        doi_mau_full(10);
        cout << space() <<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"  │"<<left<<setw(58 + getUTF8LenDiff(to_string(temp)))<<("⌕ " + to_string(temp))<<"│"<<endl;
        cout << space() <<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        ds_lop.hien_thi_lop_theo_tc(temp);
        cin.ignore();
        break;
       }
       
       default:
       cout<<"Lựa chọn không hợp lệ!";
       pause();
        break;
       }
       
}

void nghiepvu::hien_thi_lop_hoc_cua_gv(string ma_gv){
    giangvien *gv_temp = ds_gv.tim_giangvien_theo_id(ma_gv);
        if(gv_temp == nullptr){
        cout<<"Không tồn tại giảng viên";
        return;
        }
        string hocvi;
        if(gv_temp ->get_hoc_vi() == "Tiến Sĩ"){
            hocvi = "TS";
        }else if(gv_temp ->get_hoc_vi() == "Giáo Sư"){
            hocvi ="GS";
        }else if(gv_temp ->get_hoc_vi() == "Phó Giáo Sư"){
            hocvi ="PGS";
        }else if (gv_temp ->get_hoc_vi() == "Thạc Sĩ"){
            hocvi = "ThS";
        }else hocvi = "";
        doi_mau_full(13);
        cout << space() <<"╭──────────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"│"<<left<<setw(17)<<""<<setw(48 + getUTF8LenDiff(gv_temp->get_name()))<<("GIẢNG VIÊN  "+hocvi+"."+ gv_temp->get_name())<<"│"<<endl;
        cout << space() <<"│"<<left<<setw(3)<<""<<setw(24)<<("Mã GV:" + gv_temp->get_id())<<setw(39 + getUTF8LenDiff(gv_temp->get_bo_mon()))<<("Bộ môn: " + gv_temp->get_bo_mon())<<"│"<<endl;
        cout << space() <<"╰─────────────────DANH SÁCH LỚP HỌC ĐÃ DẠY─────────────────────╯"<<endl;
        cout<<endl;
        doi_mau_full(7);
        couse * couse_temp;
        for(int i = 0;i<gv_temp->get_size_lop();i++){
            couse_temp = ds_lop.tim_lop_theo_ma(gv_temp ->get_lop(i));
            //ĐOẠN NÀY CHẮC K CẦN CHECK VÌ TRONG VECTOR CHẮC CHẮN LÀ MÃ LỚP TỒN TẠI
            couse_temp->hienthi();
        }
        cout<<"Tìm thấy "<<gv_temp->get_size_lop()<<" kết quả";
}

void nghiepvu::hien_thi_lop_hoc_cua_sv(string ma_sv){
    sinhvien *sv_temp = ds_sv.tim_sinhvien_theo_id(ma_sv);
    if(sv_temp == nullptr){
        cout<<"Không tồn tại sinh viên";
    }else{
        string temp = to_string(sv_temp->get_cur_tc()) + "/" + to_string(sv_temp->get_max_tc());
        doi_mau_full(13);
        cout << space() <<"╭──────────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"│"<<left<<setw(17)<<""<<setw(46 + getUTF8LenDiff(sv_temp->get_name()))<<("SINH VIÊN  "+ sv_temp->get_name())<<"│"<<endl;
        cout << space() <<"│"<<left<<setw(3)<<""<<setw(30)<<("Mã SV:" + sv_temp->get_ma())<<setw(39 + getUTF8LenDiff(temp))<<("Số tín chỉ hiện tại: " + temp)<<"│"<<endl;
        cout << space() <<"│"<<left<<setw(3)<<""<<setw(23)<<("Khoá:" +to_string(sv_temp->get_khoa()))<<setw(39 + getUTF8LenDiff(sv_temp->get_chuyen_nganh()))<<("Chuyên ngành: " + sv_temp->get_chuyen_nganh())<<"│"<<endl;
        cout << space() <<"╰─────────────────DANH SÁCH LỚP HỌC ĐÃ ĐĂNG KÝ─────────────────╯"<<endl;
        cout<<endl;
        doi_mau_full(7);
        sv_temp ->hien_thi_lop_da_dky();
        cout<<"Tìm thấy "<<sv_temp->get_lop_size()<<" kết quả"<<endl;
    }
}

void nghiepvu::hien_thi_lop_hoc_cua_mon_hoc(string ma_mon){
    subject *mon_temp = ds_mon.tim_mon_theo_ma(ma_mon);
    if(mon_temp == nullptr){
        cout<<"Không tồn tại môn học";
    }else{
        doi_mau_full(13);
        cout << space() <<"╭──────────────────────────────────────────────────────────────╮"<<endl;
        cout << space() <<"│"<<left<<setw(17)<<""<<setw(48 + getUTF8LenDiff(mon_temp->get_ten()))<<("MÔN HỌC  "+ mon_temp->get_ten())<<"│"<<endl;
        cout << space() <<"│"<<left<<setw(3)<<""<<setw(30)<<("Mã môn:" + mon_temp->get_ma_mon())<<setw(34 + getUTF8LenDiff(to_string(mon_temp->get_tin_chi())))
        <<("Số tín: " + to_string(mon_temp->get_tin_chi()))<<"│"<<endl;
        cout << space() <<"╰───────────────────────DANH SÁCH LỚP HỌC──────────────────────╯"<<endl;
        cout<<endl;
        doi_mau_full(7);
        couse * couse_temp;
        for(int i = 0;i<mon_temp->get_size_lop();i++){
            couse_temp = ds_lop.tim_lop_theo_ma(mon_temp ->get_lop(i));
            //ĐOẠN NÀY CHẮC K CẦN CHECK VÌ TRONG VECTOR CHẮC CHẮN LÀ MÃ LỚP TỒN TẠI
            couse_temp->hienthi();
        }
        cout<<"Tìm thấy "<<mon_temp->get_size_lop()<<" kết quả";
    }
}



