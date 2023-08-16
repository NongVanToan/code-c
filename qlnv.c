#include <stdio.h>

// Định nghĩa enum cho vị trí công việc
enum ViTriCongViec {
    NHAN_VIEN,
    TRUONG_PHONG,
    GIAM_DOC
};

// Định nghĩa struct cho nhân viên
struct NhanVien {
    char ten[50];
    union {
        int tuoi;
        float luong;
    } ThongTin;
    enum ViTriCongViec viTriCongViec;
};

int main() {
    // Khai báo một nhân viên
    struct NhanVien nv;

    // Nhập thông tin cho nhân viên
    printf("Nhập tên nhân viên: ");
    scanf("%s", nv.ten);

    printf("Nhập tuổi nhân viên: ");
    scanf("%d", &nv.ThongTin.tuoi);
    printf("Tuổi: %d\n", nv.ThongTin.tuoi);
    printf("Tuổi: %d\n", &nv.ThongTin.tuoi);

    printf("Nhập lương nhân viên: ");
    scanf("%f", &nv.ThongTin.luong);

    printf("Nhập vị trí công việc (0: Nhân viên, 1: Trưởng phòng, 2: Giám đốc): ");
    scanf("%d", &nv.viTriCongViec);

    // Hiển thị thông tin của nhân viên
    printf("\nThông tin nhân viên:\n");
    printf("Tên: %s\n", nv.ten);
    printf("Tuổi: %d\n", nv.ThongTin.tuoi);
    printf("Lương: %.2f\n", nv.ThongTin.luong);

    switch (nv.viTriCongViec) {
        case NHAN_VIEN:
            printf("Vị trí công việc: Nhân viên\n");
            break;
        case TRUONG_PHONG:
            printf("Vị trí công việc: Trưởng phòng\n");
            break;
        case GIAM_DOC:
            printf("Vị trí công việc: Giám đốc\n");
            break;
        default:
            printf("Vị trí công việc không hợp lệ.\n");
            break;
    }

    return 0;
}


