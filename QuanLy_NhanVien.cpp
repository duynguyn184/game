//còn thiếu phần thanh toán, gọi món
//bàn đã gọi món rồi có thể gọi thêm món nữa, nhưng bàn tính tiền rồi thì không được tính tiền nữa, code thêm điều kiện cho nó
//code cho gọn lại theo chuẩn
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;


typedef struct 
{
    uint8_t STT;
    uint8_t ID;
    char    TEN_MON[30];
    uint16_t GIA; 
}Thuc_don;

typedef struct 
{
    // Thuc_don THONG_TIN_MON;
    char    TEN_MON[30];  
    uint16_t GIA;   
    uint8_t SO_LUONG;
}so_luong_mon;

typedef struct 
{
    uint8_t SO_BAN;
    uint8_t TRANG_THAI;
    vector<so_luong_mon> DATA_MON;
}thong_tin_ban;


    vector<Thuc_don> Database_thuc_don;
    vector<thong_tin_ban> Database_thong_tin_ban(9);        //9 bàn
    vector<so_luong_mon> Database_thong_tin_mon;        //9 bàn
class Menu{
     public:
        Menu();
};

class QuanLy{
    private:
        uint8_t ID;
    public:
        QuanLy();
        void ThemMon();
        void SuaMon();        
        void XoaMon();
        void HienThiDanhSach();        
};

class NhanVien{
    private:
        void ChonBan(uint8_t SoBan);        
    public:
        NhanVien();
        void GoiMon(uint8_t SoBan);
        void TinhTien(uint8_t SoBan);
};
// -------------------------MENU--------------------------------------
Menu::Menu(){
    int phim;
    
    printf("Nhan 1: Vao Che Do Quan Ly\n");
    printf("Nhan 2: Vao Che Do Nhan Vien\n");
    printf("Nhan 3: Thoat Chuong Trinh\n"); 
    scanf("%d", &phim);    
    switch (phim)
    {
    case 1:
        QuanLy();
        break;
    case 2:
        NhanVien();
        break;    
    case 3:
        exit(0);
        break;            
    default:
        break;
    }
}
// -------------------CHẾ ĐỘ QUẢN LÝ--------------------------
QuanLy::QuanLy(){
    QuanLy:
    printf("DAY LA TRANG QUAN LY\n");

    int phim;
    
    printf("Nhan 1: Them Mon\n");
    printf("Nhan 2: Chinh Sua Mon\n");
    printf("Nhan 3: Xoa Mon\n"); 
    printf("Nhan 4: Hien Thi Danh Sach\n");            
    printf("Nhan 5: Quay Lai Trang Chu Menu\n");     

    scanf("%d", &phim);

    switch (phim)
    {
    case 1:
        ThemMon:
        ThemMon();
        printf("Nhan 1: Tiep Tuc Them Mon\n");
        printf("Nhan 2: Quay Lai Trang Quan Ly\n");    
        scanf("%d", &phim);        
        switch (phim)
        {
            case 1:
                goto ThemMon;
                break;
            case 2:
                goto QuanLy;
                break;                  
            default:
                break;
        }     
        break;
    case 2:
        SuaMon:
        SuaMon();
        printf("Nhan 1: Tiep Tuc Sua Mon\n");
        printf("Nhan 2: Quay Lai Trang Quan Ly\n");    
        scanf("%d", &phim);        
        switch (phim)
        {
            case 1:
                goto SuaMon;
                break;
            case 2:
                goto QuanLy;
                break;                  
            default:
                break;
        }          
        break;   
    case 3:
        XoaMon:
        XoaMon();
        printf("Nhan 1: Tiep Tuc Xoa Mon\n");
        printf("Nhan 2: Quay Lai Trang Quan Ly\n");    
        scanf("%d", &phim);        
        switch (phim)
        {
            case 1:
                goto XoaMon;
                break;
            case 2:
                goto QuanLy;
                break;                  
            default:
                break;
        }         
        break;
    case 4:
        HienThiDanhSach();
        printf("Nhan 1: Quay Lai Trang Quan Ly\n");    
        scanf("%d", &phim);   
        if(phim)      goto QuanLy;      
        break;         
    case 5:
        Menu(); 
        break;                  
    default:
        break;
    }
}

void QuanLy::ThemMon(){
    Thuc_don td;

    static uint8_t id = 100; //0x01 = 100
    td.ID = id;
    id++;
    // td.STT = Database_thuc_don.size() + 1;
    printf("THEM MON\n");
    printf("Nhap Ten Mon: ");
    scanf("%s", td.TEN_MON);
    printf("Nhap Gia: ");    
    scanf("%u", &td.GIA);

    Database_thuc_don.push_back(td);
}

void QuanLy::SuaMon()
{    
    uint8_t id;
    printf("SUA MON\n");
    printf("Nhap vao ID: ");
    scanf("%hhd", &id);

    bool found = false;
    for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
    {
        if (Database_thuc_don[i].ID == id)
        {
            Thuc_don td = Database_thuc_don[i];            
            printf("Nhap Ten Mon: ");
            scanf("%s", td.TEN_MON);
            printf("Nhap Gia: ");    
            scanf("%u", &td.GIA);

            Database_thuc_don[i] = td;
            found = true;
            break;
        }
    }
    if (!found)
    {
        printf("Khong tim thay sinh vien co ID la %d\n", id);
    }
}

void QuanLy::XoaMon()
{
    uint8_t id;
    printf("XOA MON\n");
    printf("Nhap vao ID: ");
    scanf("%hhd", &id);

    bool found = false;
    for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
    {
        if (Database_thuc_don[i].ID == id)
        {
            Thuc_don td = Database_thuc_don[i];
            Database_thuc_don.erase(Database_thuc_don.begin()+i);
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Khong tim thay sinh vien co ID la %d\n", id);
    }
}

void QuanLy::HienThiDanhSach(){
    // system("clear");
    system("cls");
    printf("HIEN THI THONG TIN SINH VIEN\n"); 
    printf("STT\tID\tTen Mon\t\tGia\n");    
   for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
   {    
        printf("%d\t%d\t%s\t\t%u\n", i + 1 , Database_thuc_don[i].ID, Database_thuc_don[i].TEN_MON, Database_thuc_don[i].GIA);                               
   }  
}
// -----------------------------------CHẾ ĐỘ NHÂN VIÊN--------------------------------------------

NhanVien::NhanVien(){
    printf("DAY LA CHE DO NHAN VIEN\n");

    for(uint8_t i =0; i<9; i++)
    {
        // Database_thong_tin_ban[i].TRANG_THAI = 0;
        printf("BAN %d\t", i+1);
    }
    printf("\n");    
    for(uint8_t i = 0; i<9; i++)
    {
        if(Database_thong_tin_ban[i].TRANG_THAI == 0) printf("  -  \t");
        else printf("  x  \t");
    }  
    printf("\n");
    //Chọn bàn
    int ban;
    printf("Nhan 1-9 de chon ban 1-9\n");
    printf("Nhan 0 de quay ve trang chu Menu");
    scanf("%d", &ban);
    for(uint8_t i = 1; i<10; i++)
    {
        if(ban == i)     
        {
            printf("DA CHON BAN SO %d\n", i);            
            ChonBan(i);
        }
        else
        {         
            Menu();
        }
    }
}

void NhanVien::ChonBan(uint8_t SoBan)
{

    int phim;
    ChonBan:    
    printf("Nhap chuong trinh ban muon\n");
    printf("Nhan 1: Goi Mon\n");
    printf("Nhan 2: Tinh Tien\n");
    printf("Nhan 3: Quay Lai Trang Nhan Vien\n");  
    scanf("%d", &phim);

    switch (phim)
    {
    case 1:
        GoiMon(SoBan);
        NhanVien();
        break;
    case 2:
        TinhTien(SoBan);
        NhanVien();       
        break;  
    case 3:
        Menu(); 
        break;                            
    default:
        break;
    }  
}

void NhanVien::GoiMon(uint8_t SoBan){
    printf("Goi mon ban so %d\n", SoBan);
    // so_luong_mon ttm = Database_thong_tin_mon[SoBan - 1];
    // printf("Nhap vao ten mon: \n");
    // scanf("%s", ttm.TEN_MON);

    // bool found = false;
    // for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
    // {
    //     if (strcmp(Database_thuc_don[i].TEN_MON,ttm.TEN_MON)==0)
    //     {
    //         ttm.GIA = Database_thuc_don[i].GIA;
    //         found = true;
    //         break;
    //     }
    // }
    // if (!found)
    // {
    //     printf("Khong tim thay mon co ten la %d\n", Database_thong_tin_mon[SoBan - 1].TEN_MON);
    // } 
    
    // printf("Nhap vao so luong: \n");
    // scanf("%d", &(Database_thong_tin_mon[SoBan - 1].SO_LUONG));

    // Database_thong_tin_mon[SoBan - 1] = ttm;

    Database_thong_tin_ban[SoBan-1].TRANG_THAI = 1; //gọi món xong chuyển sang dấu x
}
void NhanVien::TinhTien(uint8_t SoBan){
    printf("Tinh Tien ban so %d\n", SoBan);

    Database_thong_tin_ban[SoBan-1].TRANG_THAI = 0; //tính tiền xong chuyển sang dấu -    
}

int main(int argc, char const *argv[])
{
    Menu m;
    // QuanLy qu;
    return 0;
}
