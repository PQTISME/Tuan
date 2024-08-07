#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

string toUpperCase(const string &str)
{
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

class NguyenVong
{
public:
    string tenNganh;
    string khoiXetTuyen;

    NguyenVong(string ten, string khoi) : tenNganh(toUpperCase(ten)), khoiXetTuyen(toUpperCase(khoi)) {}
};

class ThiSinh
{
private:
    string maThiSinh;
    string hoTen;
    string gioiTinh;
    string queQuan;
    float diemUuTien;
    float diemToan;
    float diemVan;
    float diemAnh;
    float diemMon1;
    float diemMon2;
    float diemMon3;
    string khoiThi;
    vector<NguyenVong> nguyenVong;

public:
    void nhapThongTin()
    {
        cin.ignore();
        cout << "Nhap ma thi sinh: ";
        getline(cin, maThiSinh);
        maThiSinh = toUpperCase(maThiSinh);

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        hoTen = toUpperCase(hoTen);

        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
        gioiTinh = toUpperCase(gioiTinh);

        cout << "Nhap que quan: ";
        getline(cin, queQuan);
        queQuan = toUpperCase(queQuan);

        cout << "Nhap diem uu tien: ";
        cin >> diemUuTien;
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
        cout << "Nhap diem Van: ";
        cin >> diemVan;
        cout << "Nhap diem Anh: ";
        cin >> diemAnh;

        while (true)
        {
            cout << "Nhap khoi thi (KHTN hoac KHXH): ";
            cin >> khoiThi;
            khoiThi = toUpperCase(khoiThi);

            if (khoiThi == "KHTN" || khoiThi == "khtn")
            {
                cout << "Nhap diem Ly: ";
                cin >> diemMon1;
                cout << "Nhap diem Hoa: ";
                cin >> diemMon2;
                cout << "Nhap diem Sinh: ";
                cin >> diemMon3;
                break;
            }
            else if (khoiThi == "KHXH" || khoiThi == "khxh")
            {
                cout << "Nhap diem Lich Su: ";
                cin >> diemMon1;
                cout << "Nhap diem Dia Ly: ";
                cin >> diemMon2;
                cout << "Nhap diem Giao Duc Cong Dan: ";
                cin >> diemMon3;
                break;
            }
            else
            {
                cout << "Khoi thi khong hop le! Vui long nhap lai. \n"
                     << endl;
            }
        }

        int soNguyenVong;
        cout << "Nhap so nguyen vong: ";
        cin >> soNguyenVong;
        cin.ignore();

        for (int i = 0; i < soNguyenVong; i++)
        {
            string tenNganh, khoiXetTuyen;
            cout << "Nhap ten nganh nguyen vong " << (i + 1) << ": ";
            getline(cin, tenNganh);
            cout << "Nhap khoi xet tuyen nganh nguyen vong " << (i + 1) << ": ";
            getline(cin, khoiXetTuyen);
            nguyenVong.emplace_back(toUpperCase(tenNganh), toUpperCase(khoiXetTuyen));
        }
    }

    void xuatThongTinCoBan() const
    {
        cout << "| " << setw(14) << left << maThiSinh
             << "| " << setw(17) << left << hoTen
             << "| " << setw(11) << left << gioiTinh
             << "| " << setw(16) << left << queQuan
             << "| " << setw(15) << left << diemUuTien
             << "| " << setw(15) << left << nguyenVong.size() << "|\n";
    }

    void xuatDanhSachDiem(int stt) const
    {
        if (stt == 1)
        {
            cout << "+-----+------------+------------------+------------+------------+------------+------------+------------+------------+---------+\n";
            cout << "| STT | Ma Thi Sinh| Ho Ten           | Diem Toan  | Diem Van   | Diem Anh   | Diem Mon 1 | Diem Mon 2 | Diem Mon 3 | Khoi Thi|\n";
            cout << "+-----+------------+------------------+------------+------------+------------+------------+------------+------------+---------+\n";
        }
        cout << "| " << setw(4) << left << stt++
             << "| " << setw(11) << left << maThiSinh
             << "| " << setw(17) << left << hoTen
             << "| " << setw(11) << left << diemToan
             << "| " << setw(11) << left << diemVan
             << "| " << setw(11) << left << diemAnh
             << "| " << setw(11) << left << diemMon1
             << "| " << setw(11) << left << diemMon2
             << "| " << setw(11) << left << diemMon3
             << "| " << setw(8) << left << khoiThi << "|\n";
        cout << "+-----+------------+------------------+------------+------------+------------+------------+------------+------------+---------+\n";
    }

    void hienThiDanhSachNguyenVong(const vector<ThiSinh> &danhSachThiSinh) const
    {
        cout << "+----+--------------------+--------------------+--------+----------------+\n";
        cout << "|MaTS| Ho Ten             | Nganh              | Khoi   | Thu Tu NV      |\n";
        cout << "+----+--------------------+--------------------+--------+----------------+\n";
        int stt = 1;
        for (const auto &ts : danhSachThiSinh)
        {
            int thuTuNV = 1;
            for (const auto &nv : ts.layNguyenVong())
            {
                cout << "| " << setw(3) << left << ts.layMaThiSinh()
                     << "| " << setw(19) << left << ts.layTenThiSinh()
                     << "| " << setw(19) << left << nv.tenNganh
                     << "| " << setw(7) << left << nv.khoiXetTuyen
                     << "| " << setw(15) << left << thuTuNV++ << "|\n";
            }
            stt++;
        }
        cout << "+----+--------------------+--------------------+--------+----------------+\n";
    }

    float tinhDiemTong(string khoiXetTuyen) const
    {
        if (khoiXetTuyen == "A00")
        {
            return diemToan + diemMon1 + diemMon2 + diemUuTien;
        }
        else if (khoiXetTuyen == "A01")
        {
            return diemToan + diemMon1 + diemAnh + diemUuTien;
        }
        else if (khoiXetTuyen == "B00")
        {
            return diemToan + diemMon2 + diemMon3 + diemUuTien;
        }
        else if (khoiXetTuyen == "C00")
        {
            return diemVan + diemMon1 + diemMon2 + diemUuTien;
        }
        else if (khoiXetTuyen == "D00")
        {
            return diemToan + diemVan + diemAnh + diemUuTien;
        }
        return 0;
    }

    bool xetTuyen(float diemChuan, string khoiXetTuyen) const
    {
        float diemTong = tinhDiemTong(khoiXetTuyen);
        return diemTong >= diemChuan;
    }

    float layDiemTong(string khoiXetTuyen) const
    {
        return tinhDiemTong(khoiXetTuyen);
    }
    ThiSinh() = default;
    ThiSinh(string maTS, string ht, string gt, string qq, float dut, float dt, float dv, float da, string kt, float dm1, float dm2, float dm3, vector<NguyenVong> nv)
        : maThiSinh(maTS), hoTen(ht), gioiTinh(gt), queQuan(qq), diemUuTien(dut), diemToan(dt), diemVan(dv), diemAnh(da), khoiThi(kt), diemMon1(dm1), diemMon2(dm2), diemMon3(dm3), nguyenVong(nv) {}

    string layMaThiSinh() const { return maThiSinh; }
    string layTenThiSinh() const { return hoTen; }
    string layGioiTinh() const { return gioiTinh; }
    string layQueQuan() const { return queQuan; }
    float layDiemUuTien() const { return diemUuTien; }
    float layDiemToan() const { return diemToan; }
    float layDiemVan() const { return diemVan; }
    float layDiemAnh() const { return diemAnh; }
    string layKhoiThi() const { return khoiThi; }
    float layDiemMon1() const { return diemMon1; }
    float layDiemMon2() const { return diemMon2; }
    float layDiemMon3() const { return diemMon3; }
    const vector<NguyenVong> &layNguyenVong() const { return nguyenVong; }

    void setHoTen(const string &ht) { hoTen = ht; }
    void setGioiTinh(const string &gt) { gioiTinh = gt; }
    void setQueQuan(const string &qq) { queQuan = qq; }
    void setDiemUuTien(float dut) { diemUuTien = dut; }
    void setDiemToan(float dt) { diemToan = dt; }
    void setDiemVan(float dv) { diemVan = dv; }
    void setDiemAnh(float da) { diemAnh = da; }
    void setDiemMon1(float dm1) { diemMon1 = dm1; }
    void setDiemMon2(float dm2) { diemMon2 = dm2; }
    void setDiemMon3(float dm3) { diemMon3 = dm3; }
    void addNguyenVong(const NguyenVong &nv) { nguyenVong.push_back(nv); }
    void updateNguyenVong(size_t index, const string &tenNganh, const string &khoiXetTuyen)
    {
        if (index < nguyenVong.size())
        {
            nguyenVong[index].tenNganh = tenNganh;
            nguyenVong[index].khoiXetTuyen = khoiXetTuyen;
        }
    }
    void removeNguyenVong(size_t index)
    {
        if (index < nguyenVong.size())
        {
            nguyenVong.erase(nguyenVong.begin() + index);
        }
    }
};

class SuaThongTin
{
public:
    static void suaThongTin(vector<ThiSinh> &danhSachThiSinh, const string &maTS)
    {
        auto it = find_if(danhSachThiSinh.begin(), danhSachThiSinh.end(),
                          [&maTS](const ThiSinh &ts)
                          { return ts.layMaThiSinh() == maTS; });

        if (it != danhSachThiSinh.end())
        {
            int luaChon;
            cout << "\n--- Sua thong tin thi sinh ---" << endl;
            cout << "1. Sua ho ten: " << it->layTenThiSinh() << endl;
            cout << "2. Sua gioi tinh: " << it->layGioiTinh() << endl;
            cout << "3. Sua que quan: " << it->layQueQuan() << endl;
            cout << "4. Sua diem uu tien: " << it->layDiemUuTien() << endl;
            cout << "5. Sua diem Toan: " << it->layDiemToan() << endl;
            cout << "6. Sua diem Van: " << it->layDiemVan() << endl;
            cout << "7. Sua diem Anh: " << it->layDiemAnh() << endl;
            cout << "8. Sua diem mon khoi KHTN/KHXH: " << endl;

            if (it->layKhoiThi() == "KHTN" || it->layKhoiThi() == "khtn")
            {
                cout << "  8.1. Sua diem Ly: " << it->layDiemMon1() << endl;
                cout << "  8.2. Sua diem Hoa: " << it->layDiemMon2() << endl;
                cout << "  8.3. Sua diem Sinh: " << it->layDiemMon3() << endl;
            }
            else if (it->layKhoiThi() == "KHXH" || it->layKhoiThi() == "khxh")
            {
                cout << "  8.1. Sua diem Lich Su: " << it->layDiemMon1() << endl;
                cout << "  8.2. Sua diem Dia Ly: " << it->layDiemMon2() << endl;
                cout << "  8.3. Sua diem Giao Duc Cong Dan: " << it->layDiemMon3() << endl;
            }

            cout << "9. Sua nguyen vong: " << endl;
            for (size_t i = 0; i < it->layNguyenVong().size(); ++i)
            {
                cout << "  " << i + 1 << ". Nganh: " << it->layNguyenVong()[i].tenNganh
                     << ", Khoi: " << it->layNguyenVong()[i].khoiXetTuyen << endl;
            }

            cout << "0. Huy bo" << endl;
            cout << "Chon thong tin ban muon sua: ";
            cin >> luaChon;

            cin.ignore();
            switch (luaChon)
            {
            case 1:
            {
                string hoTenMoi;
                cout << "Nhap ho ten moi: ";
                getline(cin, hoTenMoi);
                it->setHoTen(hoTenMoi);
            }
            break;
            case 2:
            {
                string gioiTinhMoi;
                cout << "Nhap gioi tinh moi: ";
                getline(cin, gioiTinhMoi);
                it->setGioiTinh(gioiTinhMoi);
            }
            break;
            case 3:
            {
                string queQuanMoi;
                cout << "Nhap que quan moi: ";
                getline(cin, queQuanMoi);
                it->setQueQuan(queQuanMoi);
            }
            break;
            case 4:
            {
                float diemUuTienMoi;
                cout << "Nhap diem uu tien moi: ";
                cin >> diemUuTienMoi;
                it->setDiemUuTien(diemUuTienMoi);
            }
            break;
            case 5:
            {
                float diemToanMoi;
                cout << "Nhap diem Toan moi: ";
                cin >> diemToanMoi;
                it->setDiemToan(diemToanMoi);
            }
            break;
            case 6:
            {
                float diemVanMoi;
                cout << "Nhap diem Van moi: ";
                cin >> diemVanMoi;
                it->setDiemVan(diemVanMoi);
            }
            break;
            case 7:
            {
                float diemAnhMoi;
                cout << "Nhap diem Anh moi: ";
                cin >> diemAnhMoi;
                it->setDiemAnh(diemAnhMoi);
            }
            break;
            case 8:
                if (it->layKhoiThi() == "KHTN" || it->layKhoiThi() == "khtn")
                {
                    float diemMon1Moi, diemMon2Moi, diemMon3Moi;
                    cout << "  8.1. Nhap diem Ly moi: ";
                    cin >> diemMon1Moi;
                    it->setDiemMon1(diemMon1Moi);
                    cout << "  8.2. Nhap diem Hoa moi: ";
                    cin >> diemMon2Moi;
                    it->setDiemMon2(diemMon2Moi);
                    cout << "  8.3. Nhap diem Sinh moi: ";
                    cin >> diemMon3Moi;
                    it->setDiemMon3(diemMon3Moi);
                }
                else if (it->layKhoiThi() == "KHXH" || it->layKhoiThi() == "khxh")
                {
                    float diemMon1Moi, diemMon2Moi, diemMon3Moi;
                    cout << "  8.1. Nhap diem Lich Su moi: ";
                    cin >> diemMon1Moi;
                    it->setDiemMon1(diemMon1Moi);
                    cout << "  8.2. Nhap diem Dia Ly moi: ";
                    cin >> diemMon2Moi;
                    it->setDiemMon2(diemMon2Moi);
                    cout << "  8.3. Nhap diem Giao Duc Cong Dan moi: ";
                    cin >> diemMon3Moi;
                    it->setDiemMon3(diemMon3Moi);
                }
                break;
            case 9:
                cout << "\n--- Sua nguyen vong ---" << endl;
                cout << "1. Them nguyen vong moi" << endl;
                cout << "2. Sua nguyen vong hien co" << endl;
                cout << "3. Xoa nguyen vong" << endl;
                cout << "0. Huy bo" << endl;
                cout << "Lua chon cua ban: ";
                cin >> luaChon;

                if (luaChon == 1)
                {
                    string tenNganhMoi, khoiMoi;
                    cout << "Nhap ten nganh moi: ";
                    cin.ignore();
                    getline(cin, tenNganhMoi);
                    cout << "Nhap khoi xet tuyen moi: ";
                    getline(cin, khoiMoi);
                    it->addNguyenVong(NguyenVong(tenNganhMoi, khoiMoi));
                }
                else if (luaChon == 2)
                {
                    size_t viTri;
                    cout << "Chon so thu tu nguyen vong muon sua (1-" << it->layNguyenVong().size() << "): ";
                    cin >> viTri;
                    if (viTri > 0 && viTri <= it->layNguyenVong().size())
                    {
                        string tenNganhMoi, khoiMoi;
                        cout << "Nhap ten nganh moi: ";
                        cin.ignore();
                        getline(cin, tenNganhMoi);
                        cout << "Nhap khoi xet tuyen moi: ";
                        getline(cin, khoiMoi);
                        it->updateNguyenVong(viTri - 1, tenNganhMoi, khoiMoi);
                    }
                    else
                    {
                        cout << "Vi tri nguyen vong khong hop le!" << endl;
                    }
                }
                else if (luaChon == 3)
                {
                    size_t viTri;
                    cout << "Chon so thu tu nguyen vong muon xoa (1-" << it->layNguyenVong().size() << "): ";
                    cin >> viTri;
                    if (viTri > 0 && viTri <= it->layNguyenVong().size())
                    {
                        it->removeNguyenVong(viTri - 1);
                    }
                    else
                    {
                        cout << "Vi tri nguyen vong khong hop le!" << endl;
                    }
                }
                else
                {
                    cout << "Huy bo sua doi nguyen vong." << endl;
                }
                break;
            case 0:
                cout << "Huy bo viec sua thong tin." << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long thu lai!" << endl;
            }
        }
        else
        {
            cout << "Khong tim thay ma thi sinh nay." << endl;
        }
    }

    static void xoaThongTin(vector<ThiSinh> &danhSachThiSinh, const string &maTS)
    {
        auto it = find_if(danhSachThiSinh.begin(), danhSachThiSinh.end(),
                          [&maTS](const ThiSinh &ts)
                          { return ts.layMaThiSinh() == maTS; });

        if (it != danhSachThiSinh.end())
        {
            danhSachThiSinh.erase(it);
            cout << "Da xoa thong tin thi sinh co ma: " << maTS << endl;
        }
        else
        {
            cout << "Khong tim thay ma thi sinh nay." << endl;
        }
    }

    static void suaHoacXoaThongTin(vector<ThiSinh> &danhSachThiSinh)
    {
        int luaChonSuaXoa;
        string maTS;
        cout << "Nhap ma thi sinh de sua hoac xoa: ";
        cin >> maTS;
        cout << "Ban muon (1) sua, (2) xoa thi sinh nay, hay (0) huy? ";
        cin >> luaChonSuaXoa;

        if (luaChonSuaXoa == 1)
        {
            suaThongTin(danhSachThiSinh, maTS);
        }
        else if (luaChonSuaXoa == 2)
        {
            xoaThongTin(danhSachThiSinh, maTS);
        }
        else if (luaChonSuaXoa == 0)
        {
            cout << "Huy bo va quay lai menu chinh." << endl;
        }
        else
        {
            cout << "Lua chon khong hop le, quay lai menu." << endl;
        }
    }
};

class DiemChuan
{
public:
    float diemChuanCNTT_A00;
    float diemChuanCNTT_A01;
    float diemChuanCNTT_D00;

    float diemChuanY_B00;
    float diemChuanY_A00;

    float diemChuanKinhTe_C00;
    float diemChuanKinhTe_D00;

    float diemChuanLuat_C00;
    float diemChuanLuat_D00;

    float diemChuanKeToan_A00;
    float diemChuanKeToan_A01;
    float diemChuanKeToan_D00;

    float diemChuanQTKD_A00;
    float diemChuanQTKD_A01;
    float diemChuanQTKD_D00;

    void nhapDiemChuan()
    {
        cout << "Nhap diem chuan cua tung nganh: " << endl;

        cout << "CNTT - A00 (Toan, Ly, Hoa): ";
        cin >> diemChuanCNTT_A00;
        cout << "CNTT - A01 (Toan, Ly, Anh): ";
        cin >> diemChuanCNTT_A01;
        cout << "CNTT - D00 (Toan, Van, Anh): ";
        cin >> diemChuanCNTT_D00;

        cout << "Y - B00 (Toan, Hoa, Sinh): ";
        cin >> diemChuanY_B00;
        cout << "Y - A00 (Toan, Ly, Hoa): ";
        cin >> diemChuanY_A00;

        cout << "Kinh te - C00 (Van, Su, Dia): ";
        cin >> diemChuanKinhTe_C00;
        cout << "Kinh te - D00 (Toan, Van, Anh): ";
        cin >> diemChuanKinhTe_D00;

        cout << "Luat - C00 (Van, Su, Dia): ";
        cin >> diemChuanLuat_C00;
        cout << "Luat - D00 (Toan, Van, Anh): ";
        cin >> diemChuanLuat_D00;

        cout << "Ke toan - A00 (Toan, Ly, Hoa): ";
        cin >> diemChuanKeToan_A00;
        cout << "Ke toan - A01 (Toan, Ly, Anh): ";
        cin >> diemChuanKeToan_A01;
        cout << "Ke toan - D00 (Toan, Van, Anh): ";
        cin >> diemChuanKeToan_D00;

        cout << "QTKD - A00 (Toan, Ly, Hoa): ";
        cin >> diemChuanQTKD_A00;
        cout << "QTKD - A01 (Toan, Ly, Anh): ";
        cin >> diemChuanQTKD_A01;
        cout << "QTKD - D00 (Toan, Van, Anh): ";
        cin >> diemChuanQTKD_D00;
    }

    void xuatDiemChuan() const
    {
        cout << "\n+---------- Danh sach diem chuan ---------+" << endl;
        cout << "|CNTT - A01 (Toan, Ly, Anh):         " << fixed << setprecision(2) << diemChuanCNTT_A01 << "|" << endl;
        cout << "|CNTT - A00 (Toan, Ly, Hoa):         " << fixed << setprecision(2) << diemChuanCNTT_A00 << "|" << endl;
        cout << "|CNTT - D00 (Toan, Van, Anh):        " << fixed << setprecision(2) << diemChuanCNTT_D00 << "|" << endl;

        cout << "|Y - B00 (Toan, Hoa, Sinh):          " << fixed << setprecision(2) << diemChuanY_B00 << "|" << endl;
        cout << "|Y - A00 (Toan, Ly, Hoa):            " << fixed << setprecision(2) << diemChuanY_A00 << "|" << endl;

        cout << "|Kinh te - C00 (Van, Su, Dia):       " << fixed << setprecision(2) << diemChuanKinhTe_C00 << "|" << endl;
        cout << "|Kinh te - D00 (Toan, Van, Anh):     " << fixed << setprecision(2) << diemChuanKinhTe_D00 << "|" << endl;

        cout << "|Luat - C00 (Van, Su, Dia):          " << fixed << setprecision(2) << diemChuanLuat_C00 << "|" << endl;
        cout << "|Luat - D00 (Toan, Van, Anh):        " << fixed << setprecision(2) << diemChuanLuat_D00 << "|" << endl;

        cout << "|Ke toan - A00 (Toan, Ly, Hoa):      " << fixed << setprecision(2) << diemChuanKeToan_A00 << "|" << endl;
        cout << "|Ke toan - A01 (Toan, Ly, Anh):      " << fixed << setprecision(2) << diemChuanKeToan_A01 << "|" << endl;
        cout << "|Ke toan - D00 (Toan, Van, Anh):     " << fixed << setprecision(2) << diemChuanKeToan_D00 << "|" << endl;

        cout << "|QTKD - A00 (Toan, Ly, Hoa):         " << fixed << setprecision(2) << diemChuanQTKD_A00 << "|" << endl;
        cout << "|QTKD - A01 (Toan, Ly, Anh):         " << fixed << setprecision(2) << diemChuanQTKD_A01 << "|" << endl;
        cout << "|QTKD - D00 (Toan, Van, Anh):        " << fixed << setprecision(2) << diemChuanQTKD_D00 << "|" << endl;

        cout << "+-----------------------------------------+" << endl;
    }

    void hienThiSinhVienTrungTuyen(const vector<ThiSinh> &danhSachThiSinh)
    {
        cout << "\n--- Danh sach thi sinh trung tuyen ---" << endl;
        cout << "+----------+------------------------+-------+--------+------------------------+----------------+\n";
        cout << "| MaTS     | Ten Thi Sinh           |Diem   | Nganh  | Khoi                   | Nguyen Vong    |\n";
        cout << "+----------+------------------------+-------+--------+------------------------+----------------+\n";

        int stt = 1;
        for (const auto &ts : danhSachThiSinh)
        {
            bool trungTuyen = false;
            const vector<NguyenVong> &nguyenVongs = ts.layNguyenVong();
            for (const auto &nv : nguyenVongs)
            {
                float diemChuanValue = -1;

                if (nv.tenNganh == "CNTT" && (nv.khoiXetTuyen == "A00" || nv.khoiXetTuyen == "A01" || nv.khoiXetTuyen == "D00"))
                {
                    if (nv.khoiXetTuyen == "A00")
                        diemChuanValue = diemChuanCNTT_A00;
                    else if (nv.khoiXetTuyen == "A01")
                        diemChuanValue = diemChuanCNTT_A01;
                    else if (nv.khoiXetTuyen == "D00")
                        diemChuanValue = diemChuanCNTT_D00;
                }
                else if ((nv.tenNganh == "Y" or nv.tenNganh == "y") && (nv.khoiXetTuyen == "B00" || nv.khoiXetTuyen == "A00"))
                {
                    if (nv.khoiXetTuyen == "B00")
                        diemChuanValue = diemChuanY_B00;
                    else if (nv.khoiXetTuyen == "A00")
                        diemChuanValue = diemChuanY_A00;
                }
                else if ((nv.tenNganh == "Kinh te" || nv.tenNganh == "KINH TE") && (nv.khoiXetTuyen == "C00" || nv.khoiXetTuyen == "D00"))
                {
                    if (nv.khoiXetTuyen == "C00")
                        diemChuanValue = diemChuanKinhTe_C00;
                    else if (nv.khoiXetTuyen == "D00")
                        diemChuanValue = diemChuanKinhTe_D00;
                }
                else if ((nv.tenNganh == "Luat" || nv.tenNganh == "LUAT") && (nv.khoiXetTuyen == "C00" || nv.khoiXetTuyen == "D00"))
                {
                    if (nv.khoiXetTuyen == "C00")
                        diemChuanValue = diemChuanLuat_C00;
                    else if (nv.khoiXetTuyen == "D00")
                        diemChuanValue = diemChuanLuat_D00;
                }
                else if ((nv.tenNganh == "Ke toan" || nv.tenNganh == "KE TOAN") && (nv.khoiXetTuyen == "A00" || nv.khoiXetTuyen == "A01" || nv.khoiXetTuyen == "D00"))
                {
                    if (nv.khoiXetTuyen == "A00")
                        diemChuanValue = diemChuanKeToan_A00;
                    else if (nv.khoiXetTuyen == "A01")
                        diemChuanValue = diemChuanKeToan_A01;
                    else if (nv.khoiXetTuyen == "D00")
                        diemChuanValue = diemChuanKeToan_D00;
                }
                else if (nv.tenNganh == "QTKD" && (nv.khoiXetTuyen == "A00" || nv.khoiXetTuyen == "A01" || nv.khoiXetTuyen == "D00"))
                {
                    if (nv.khoiXetTuyen == "A00")
                        diemChuanValue = diemChuanQTKD_A00;
                    else if (nv.khoiXetTuyen == "A01")
                        diemChuanValue = diemChuanQTKD_A01;
                    else if (nv.khoiXetTuyen == "D00")
                        diemChuanValue = diemChuanQTKD_D00;
                }

                if (diemChuanValue != -1 && ts.xetTuyen(diemChuanValue, nv.khoiXetTuyen))
                {
                    cout << "| " << setw(9) << left << ts.layMaThiSinh()
                         << "| " << setw(23) << left << ts.layTenThiSinh()
                         << "| " << setw(6) << left << ts.layDiemTong(nv.khoiXetTuyen)
                         << "| " << setw(7) << left << nv.tenNganh
                         << "| " << setw(23) << left << nv.khoiXetTuyen
                         << "| " << setw(15) << left << nv.tenNganh
                         << "|\n";
                    trungTuyen = true;
                    break;
                }
            }
        }
        cout << "+----------+------------------------+-------+--------+------------------------+----------------+\n";
    }
};

class FileManager
{
public:
    static void luuDanhSachThiSinh(const vector<ThiSinh> &danhSachThiSinh, const string &filename)
    {
        ofstream outfile(filename);
        if (outfile.is_open())
        {
            outfile << danhSachThiSinh.size() << endl;
            for (const auto &ts : danhSachThiSinh)
            {
                outfile << ts.layMaThiSinh() << "\n"
                        << ts.layTenThiSinh() << "\n"
                        << ts.layGioiTinh() << "\n"
                        << ts.layQueQuan() << "\n"
                        << ts.layDiemUuTien() << "\n"
                        << ts.layDiemToan() << "\n"
                        << ts.layDiemVan() << "\n"
                        << ts.layDiemAnh() << "\n"
                        << ts.layKhoiThi() << "\n"
                        << ts.layDiemMon1() << "\n"
                        << ts.layDiemMon2() << "\n"
                        << ts.layDiemMon3() << "\n";

                outfile << ts.layNguyenVong().size() << "\n";
                for (const auto &nv : ts.layNguyenVong())
                {
                    outfile << nv.tenNganh << "\n"
                            << nv.khoiXetTuyen << "\n";
                }
            }
            outfile.close();
            cout << "Da luu thong tin thi sinh vao file " << filename << endl;
        }
        else
        {
            cerr << "Khong the mo file de ghi!" << endl;
        }
    }

    static void docDanhSachThiSinh(vector<ThiSinh> &danhSachThiSinh, const string &filename)
    {
        ifstream infile(filename);
        if (infile.is_open())
        {
            size_t soThiSinh;
            infile >> soThiSinh;
            infile.ignore();

            danhSachThiSinh.clear();
            for (size_t i = 0; i < soThiSinh; i++)
            {
                string maThiSinh, hoTen, gioiTinh, queQuan, khoiThi;
                float diemUuTien, diemToan, diemVan, diemAnh, diemMon1, diemMon2, diemMon3;
                vector<NguyenVong> nguyenVong;

                getline(infile, maThiSinh);
                getline(infile, hoTen);
                getline(infile, gioiTinh);
                getline(infile, queQuan);
                infile >> diemUuTien >> diemToan >> diemVan >> diemAnh >> khoiThi;
                infile >> diemMon1 >> diemMon2 >> diemMon3;
                infile.ignore();

                size_t soNguyenVong;
                infile >> soNguyenVong;
                infile.ignore();

                for (size_t j = 0; j < soNguyenVong; j++)
                {
                    string tenNganh, khoiXetTuyen;
                    getline(infile, tenNganh);
                    getline(infile, khoiXetTuyen);
                    nguyenVong.emplace_back(tenNganh, khoiXetTuyen);
                }

                danhSachThiSinh.emplace_back(maThiSinh, hoTen, gioiTinh, queQuan, diemUuTien, diemToan, diemVan, diemAnh, khoiThi, diemMon1, diemMon2, diemMon3, nguyenVong);
            }
            infile.close();

            cout << "+------------+------------------+------------+-----------------+----------------+------------+------------+------------+------------+\n";
            cout << "| Ma Thi Sinh| Ho Ten           | Gioi Tinh  | Que Quan        | Diem Uu Tien   | Diem Toan  | Diem Van   | Diem Anh   | Khoi Thi   |\n";
            cout << "+------------+------------------+------------+-----------------+----------------+------------+------------+------------+------------+\n";
            for (const auto &ts : danhSachThiSinh)
            {
                cout << "| " << setw(11) << left << ts.layMaThiSinh()
                     << "| " << setw(17) << left << ts.layTenThiSinh()
                     << "| " << setw(11) << left << ts.layGioiTinh()
                     << "| " << setw(16) << left << ts.layQueQuan()
                     << "| " << setw(15) << left << ts.layDiemUuTien()
                     << "| " << setw(11) << left << ts.layDiemToan()
                     << "| " << setw(11) << left << ts.layDiemVan()
                     << "| " << setw(11) << left << ts.layDiemAnh()
                     << "| " << setw(11) << left << ts.layKhoiThi() << "|\n";
                cout << "+------------+------------------+------------+-----------------+----------------+------------+------------+------------+------------+\n";
            }

            cout << "\nDanh sach nguyen vong cua thi sinh:\n";
            cout << "+------+--------------------+--------------------+----------------+----------------+\n";
            cout << "| STT  | Ma Thi Sinh        | Ho Ten             | Ten Nganh      | Khoi Xet Tuyen |\n";
            cout << "+------+--------------------+--------------------+----------------+----------------+\n";
            int stt = 1;
            for (const auto &ts : danhSachThiSinh)
            {
                for (size_t j = 0; j < ts.layNguyenVong().size(); ++j)
                {
                    const auto &nv = ts.layNguyenVong()[j];
                    cout << "| " << setw(5) << left << stt++
                         << "| " << setw(19) << left << ts.layMaThiSinh()
                         << "| " << setw(19) << left << ts.layTenThiSinh()
                         << "| " << setw(15) << left << nv.tenNganh
                         << "| " << setw(15) << left << nv.khoiXetTuyen << "|\n";
                }
            }
            cout << "+------+--------------------+--------------------+----------------+----------------+\n";
        }
        else
        {
            cerr << "Khong the mo file de doc!" << endl;
        }
    }
};

class MainApp
{
private:
    vector<ThiSinh> danhSachThiSinh;
    DiemChuan diemChuan;

public:
    void run()
    {
        int luaChon;
        do
        {
            displayMenu();
            cin >> luaChon;
            handleMenuSelection(luaChon);
        } while (luaChon != 0);
    }

private:
    void displayMenu()
    {
        system("cls");

        int consoleWidth = 120;
        int menuWidth = 80;
        int paddingSides = (consoleWidth - menuWidth) / 2;

        cout << string(paddingSides, ' ') << "+--------------------------------------MENU--------------------------------------+" << endl;
        cout << string(paddingSides, ' ') << "|1. Nhap thong tin thi sinh                                                      |" << endl;
        cout << string(paddingSides, ' ') << "|2. Hien thi thong tin co ban cua thi sinh                                       |" << endl;
        cout << string(paddingSides, ' ') << "|3. Hien thi danh sach diem cua thi sinh                                         |" << endl;
        cout << string(paddingSides, ' ') << "|4. Hien thi danh sach nguyen vong cua thi sinh                                  |" << endl;
        cout << string(paddingSides, ' ') << "|5. Sua hoac xoa thong tin thi sinh                                              |" << endl;
        cout << string(paddingSides, ' ') << "|6. Nhap diem chuan tung nganh                                                   |" << endl;
        cout << string(paddingSides, ' ') << "|7. Hien thi diem chuan tung nganh                                               |" << endl;
        cout << string(paddingSides, ' ') << "|8. Hien thi sinh vien trung tuyen theo nganh                                    |" << endl;
        cout << string(paddingSides, ' ') << "|9. Ghi danh sach sinh vien vao FILE                                             |" << endl;
        cout << string(paddingSides, ' ') << "|10. Doc danh sach sinh vien tu FILE                                             |" << endl;
        cout << string(paddingSides, ' ') << "|11. Tim kiem sinh vien co cung que quan                                         |" << endl;
        cout << string(paddingSides, ' ') << "|0. Thoat chuong trinh                                                           |" << endl;
        cout << string(paddingSides, ' ') << "+--------------------------------------------------------------------------------+" << endl;
        cout << string(paddingSides, ' ') << "Lua chon cua ban: ";
    }

    void handleMenuSelection(int luaChon)
    {
        switch (luaChon)
        {
        case 1:
            nhapThongTinThiSinh();
            break;
        case 2:
            hienThiThongTinCoBan();
            break;
        case 3:
            hienThiDanhSachDiem();
            break;
        case 4:
            hienThiDanhSachNguyenVong();
            break;
        case 5:
            system("cls");
            SuaThongTin::suaHoacXoaThongTin(danhSachThiSinh);
            cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
            cin.ignore();
            cin.get();
            break;
        case 6:
            nhapDiemChuan();
            break;
        case 7:
            hienThiDiemChuan();
            break;
        case 8:
            hienThiSinhVienTrungTuyen();
            break;
        case 9:
            system("cls");
            FileManager::luuDanhSachThiSinh(danhSachThiSinh, "danhSachThiSinh.txt");
            cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
            cin.ignore();
            cin.get();
            break;
        case 10:
            system("cls");
            FileManager::docDanhSachThiSinh(danhSachThiSinh, "danhSachThiSinh.txt");
            cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
            cin.ignore();
            cin.get();
            break;
        case 11:
            hienThiSinhVienCungQueQuan();
            break;
        case 0:
            system("cls");
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le, vui long thu lai!" << endl;
        }
    }

    void nhapThongTinThiSinh()
    {
        bool tiepTuc = true;
        while (tiepTuc)
        {
            system("cls");
            ThiSinh ts;
            ts.nhapThongTin();
            danhSachThiSinh.push_back(ts);

            cout << "Ban co muon nhap them thi sinh? (1: Co, 0: Khong): ";
            int tiepTucNhap;
            cin >> tiepTucNhap;
            tiepTuc = tiepTucNhap == 1;
        }
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }

    void hienThiThongTinCoBan()
    {
        system("cls");
        cout << "+---------------+------------------+------------+-----------------+----------------+----------------+\n";
        cout << "| Ma Thi Sinh   | Ho Ten           | Gioi Tinh  | Que Quan        | Diem Uu Tien   | So Nguyen Vong |\n";
        cout << "+---------------+------------------+------------+-----------------+----------------+----------------+\n";
        for (const auto &ts : danhSachThiSinh)
        {
            ts.xuatThongTinCoBan();
            cout << "+---------------+------------------+------------+-----------------+----------------+----------------+\n";
        }
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }

    void hienThiDanhSachDiem()
    {
        system("cls");
        int stt = 1;
        for (const auto &ts : danhSachThiSinh)
        {
            ts.xuatDanhSachDiem(stt++);
        }
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }
    void hienThiDanhSachNguyenVong()
    {
        system("cls");
        ThiSinh ts;
        ts.hienThiDanhSachNguyenVong(danhSachThiSinh);
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }

    void nhapDiemChuan()
    {
        system("cls");
        diemChuan.nhapDiemChuan();
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }

    void hienThiDiemChuan()
    {
        system("cls");
        diemChuan.xuatDiemChuan();
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }

    void hienThiSinhVienTrungTuyen()
    {
        system("cls");
        diemChuan.hienThiSinhVienTrungTuyen(danhSachThiSinh);
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }

    void hienThiSinhVienCungQueQuan()
    {
        bool tiepTuc = true;
        while (true)
        {
            system("cls");
            string queQuan;
            cout << "Nhap que quan (hoac nhap 'exit' de thoat): ";
            cin.ignore();
            getline(cin, queQuan);
            queQuan = toUpperCase(queQuan);

            if (queQuan == "EXIT" || queQuan == "exit")
            {
                break;
            }

            bool found = false;
            cout << "+---------------+------------------+------------+-----------------+----------------+----------------+\n";
            cout << "| Ma Thi Sinh   | Ho Ten           | Gioi Tinh  | Que Quan        | Diem Uu Tien   | So Nguyen Vong |\n";
            cout << "+---------------+------------------+------------+-----------------+----------------+----------------+\n";
            for (const auto &ts : danhSachThiSinh)
            {
                if (ts.layQueQuan() == queQuan)
                {
                    ts.xuatThongTinCoBan();
                    found = true;
                }
            }
            cout << "+---------------+------------------+------------+-----------------+----------------+----------------+\n";

            if (!found)
            {
                cout << "Khong co sinh vien nao co que quan: " << queQuan << endl;
            }

            cout << "Ban co muon xem danh sach sinh vien tu mot que quan khac khong? (1: Co, 0: Khong): ";
            int luaChon;
            cin >> luaChon;
            tiepTuc = (luaChon == 1);
        }
        cout << "Nhan " << "\033[31m" << "Enter" << "\033[0m" << " de quay ve menu chinh.";
        cin.ignore();
        cin.get();
    }
};

int main()
{
    MainApp app;
    app.run();
    return 0;
}