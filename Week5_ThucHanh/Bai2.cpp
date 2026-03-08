#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class GiaSuc{
    protected:
        int soluong;
        int tongsua;
    public: 
        GiaSuc(int sl){
            this->soluong = sl;
            tongsua = 0;
        } 
        virtual string PhatTiengKeu() = 0;
        int virtual ChoSua() {return 0;};
        int virtual SinhCon() {return 0;};
        void TinhTongSua() {
            for (int i = 1; i <= soluong; i++){
                int LaySua = ChoSua();
                tongsua += LaySua;
            }
        }
        void TinhThemKhiSinh() {
            int SoConMoi = 0;
            for (int i = 1; i <= soluong; i++){
                SoConMoi += SinhCon();
            }
            soluong += SoConMoi;
        } 
        int GetSua() { return tongsua;};
        int GetSoLuong() {return soluong;};
};

class Bo : public GiaSuc{
    public:
        Bo(int SlBo) : GiaSuc(SlBo){};
        string PhatTiengKeu() override{
            return "Ngu nhu bo";
        }
        int ChoSua() override{
            return rand() % 21;
        }
        int SinhCon() override{
            return rand() % 2 + 1; //De tu 1-2 con
        }
};
class De : public GiaSuc{
    public:
        De(int SlDe) : GiaSuc(SlDe){};
        string PhatTiengKeu() override{
            return "dê xòm";
        }
        int ChoSua() override{
            return rand() % 11;
        }
        int SinhCon() override{
            return rand() % 3 + 1; //De tu 1-3 con
        }
};
class Cuu : public GiaSuc{
    public:
        Cuu(int SlCuu) : GiaSuc(SlCuu){};
        string PhatTiengKeu() override{
            return "Non nhu cuu";
        }
        int ChoSua() override{
            return rand() % 6;
        }
        int SinhCon() override{
            return rand() % 4 + 1; //De tu 1-4 con
        }
};

class DanhSach{
    private:
        vector<GiaSuc*> DSgiasuc;
    public:
        void NhapDS(){
            int SlBo, SlCuu, SlDe;
            cout << "Nhap so luong con bo: ";
            cin >> SlBo;
            cout << "Nhap so luong con cuu: ";
            cin >> SlCuu;
            cout << "Nhap so luong con de: ";
            cin >> SlDe;
            //Khoi tao
            DSgiasuc.push_back(new Bo(SlBo));
            DSgiasuc.push_back(new De(SlDe));
            DSgiasuc.push_back(new Cuu(SlCuu));
        }
        void InTiengKeu(){
            cout << endl;
            cout << "____BAI 1____ " << endl;
            cout << "So tieng keu trong nong trai: " << endl;
            //So tieng keu = so luong moi loai + tieng keu cua chung
            for (auto it : DSgiasuc){
                for (int i = 0; i < it->GetSoLuong(); i++){
                    cout << it->PhatTiengKeu() << " ";
                }
            }
        }
        void TinhSuaCuaTatCa(){
            int sum_Sua = 0;
            for (int i = 0; i < DSgiasuc.size(); i++){
                DSgiasuc[i]->TinhTongSua();
                sum_Sua += DSgiasuc[i]->GetSua();
            }
            cout << "Tong luong sua cua trang trai la: " << sum_Sua << " lit" << endl;
        }
        void InSoLuong(){
            for (int i = 0; i < DSgiasuc.size(); i++){
                DSgiasuc[i]->TinhThemKhiSinh();
            }
            cout << endl;
            cout << "___BAI 2___" << endl;
            cout << "Ket qua sau luot sinh con va cho sua"  << endl;
            cout << "So luong bo: " << DSgiasuc[0]->GetSoLuong() << endl;
            cout << "So luong de: " << DSgiasuc[1]->GetSoLuong() << endl;
            cout << "So luong cuu: " << DSgiasuc[2]->GetSoLuong() << endl;
        }
};

int main()
{
    srand(time(0));
    DanhSach farm;
    farm.NhapDS();
    farm.InTiengKeu();
    farm.InSoLuong();
    farm.TinhSuaCuaTatCa();
}