#include <stdio.h>
#include <stdlib.h>

struct Product {
    char name[100];
    float price;
};
enum ProductType {
    CLOTHING,
    FOOTWEAR,
    ELECTRONICS
};
union ProductInfo {
    int size; // Kích cỡ (dùng cho quần áo và giày dép)
    float weight; // Trọng lượng (dùng cho điện tử)
};
int main() {
    int n; // Số lượng sản phẩm
    printf("Enter the number of products: ");
    scanf("%d", &n);

    // Khai báo mảng các cấu trúc để lưu trữ thông tin sản phẩm
    struct Product products[n];

    for (int i = 0; i < n; i++) {
        printf("Enter information for product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Price: ");
        scanf("%f", &products[i].price);
        printf("Type (0: Clothing, 1: Footwear, 2: Electronics): ");
        int type;
        scanf("%d", &type);

        // Kiểm tra loại sản phẩm và nhập thông tin kích cỡ hoặc trọng lượng tương ứng
        switch (type) {
            case CLOTHING:
            case FOOTWEAR:
                printf("Size: ");
                scanf("%d", &products[i].info.size);
                break;
            case ELECTRONICS:
                printf("Weight: ");
                scanf("%f", &products[i].info.weight);
                break;
            default:
                printf("Invalid product type.\n");
                break;
        }
    }
    // Nhập tên sản phẩm cần tra cứu
char searchName[100];
printf("Enter the name of the product to retrieve information: ");
scanf("%s", searchName);

// Duyệt qua mảng sản phẩm để tìm sản phẩm có tên tương ứng
for (int i = 0; i < n; i++) {
    if (strcmp(searchName, products[i].name) == 0) {
        // In ra thông tin sản phẩm
        printf("\nProduct Information:\n");
        printf("Name: %s\n", products[i].name);
        printf("Price: %.2f\n", products[i].price);

        // Kiểm tra loại sản phẩm và in ra thông tin kích cỡ hoặc trọng lượng tương ứng
        switch (type) {
            case CLOTHING:
                printf("Type: Clothing\n");
                printf("Size: %d\n", products[i].info.size);
                break;
            case FOOTWEAR:
                printf("Type: Footwear\n");
                printf("Size: %d\n", products[i].info.size);
                break;
            case ELECTRONICS:
                printf("Type: Electronics\n");
                printf("Weight: %.2f\n", products[i].info.weight);
                break;
            default:
                printf("Invalid product type.\n");
                break;
        }

        break;
    }
}
    // TODO: Thêm code để cho phép người dùng tra cứu thông tin sản phẩm qua tên sản phẩm

    return 0;
}