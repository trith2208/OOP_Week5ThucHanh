#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class NhanVien{
    protected:
        string ten, ngaySinh;
    public:
        void virtual Nhap(){
            cin.ignore();
            cout << "Nhap ho va ten: ";
            getline(cin , ten);
            cout << "Nhap ngay sinh: ";
            cin >> ngaySinh;
        };
        int virtual TinhLuong(){
            return 0;
        }
        void virtual Xuat(){
            cout << "Ho ten: " << ten << endl;
            cout << "Ngay sinh: " << ngaySinh << endl;
        }
};

class NVVanPhong : public NhanVien{
    private:    
        int ngaycong;
    public:
        void Nhap() override{
            NhanVien::Nhap();
            cout << "Nhap so ngay cong: ";
            cin >> ngaycong;
        }
        int TinhLuong() override{
            return ngaycong * 100000;
        }
        void Xuat() override{
            NhanVien::Xuat();
            cout << "Luong thang: " << TinhLuong() << endl;
        }
};

class NVSanXuat : public NhanVien{
    private:    
        int luongCoBan, SoSanPham;
    public:
        void Nhap() override{
            NhanVien::Nhap();
            cout << "Nhap luong co ban: ";
            cin >> luongCoBan;
            cout << "Nhap so san pham: ";
            cin >> SoSanPham;
        }
        int TinhLuong() override{
            return luongCoBan + SoSanPham * 5000;
        }
        void Xuat() override{
            NhanVien::Xuat();
            cout << "Luong thang: " << TinhLuong() << endl;
        }
};

class ListNhanVien{
    private:
        vector<NhanVien*> DSnhanvien;
    public:
        void NhapDS(){
            int n;
            cout << "Nhap so luong nhan vien: ";
            cin >> n;
            for (int i = 1; i <= n; i++){
                int loai;
                cout << "Nhap thong tin nhan vien " << i << endl;
                cout << "Nhap so tuong ung voi loai nhan vien: Van phong (1), San xuat (2)" << endl;
                cin >> loai;
                NhanVien* temp;
                if (loai == 1){
                    temp = new NVVanPhong;
                }
                else temp = new NVSanXuat;
                temp->Nhap();
                DSnhanvien.push_back(temp);
            }
        }
        void XuatDS(){
            cout << "___DANH SACH NHAN VIEN____" << endl;
            for (int i = 0; i < DSnhanvien.size(); i++){
                cout << "Thong tin nhan vien thu " << i + 1 << endl;
                DSnhanvien[i]->Xuat();
            }
        }
        void TongLuong(){
            long long sum = 0;
            for (int i = 0; i < DSnhanvien.size(); i++){
                sum += DSnhanvien[i]->TinhLuong();
            }
            cout << "Tong luong cong ty can tra la: " << sum << endl;
        }
        void SearchNhanVienSalaryMax(){
            int max_salary = -1;
            NhanVien *temp = nullptr;
            for (int i = 0; i < DSnhanvien.size(); i++){
                if (DSnhanvien[i]->TinhLuong() > max_salary){
                    max_salary = DSnhanvien[i]->TinhLuong();
                    temp = (NhanVien*) DSnhanvien[i];
                }
            }
            if (max_salary == -1){
                cout << "Danh sach trong" << endl;
            }
            else{
                cout << "Thong tin nhan vien co luong cao nhat" << endl;
                temp->Xuat();
            }
        }
        void SearchNhanVienSalaryMin(){
            int min_salary = 1e9;
            NhanVien *temp = nullptr;
            for (int i = 0; i < DSnhanvien.size(); i++){
                if (DSnhanvien[i]->TinhLuong() < min_salary){
                    min_salary = DSnhanvien[i]->TinhLuong();
                    temp = (NhanVien*) DSnhanvien[i];
                }
            }
            if (min_salary == -1){
                cout << "Danh sach trong" << endl;
            }
            else{
                cout << "Thong tin nhan vien co luong cao nhat" << endl;
                temp->Xuat();
            }
        }
};

int main(){
    ListNhanVien employee;
    employee.NhapDS();
    employee.XuatDS();
    employee.TongLuong();
    employee.SearchNhanVienSalaryMax();
    employee.SearchNhanVienSalaryMin();
}
