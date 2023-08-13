#include <stdio.h>

#define IS_PRIME(n) (is_prime(n))

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Sử dụng: %s a b\n", argv[0]);
        return 1;
    }

    int a, b;
    sscanf(argv[1], "%d", &a);
    sscanf(argv[2], "%d", &b);

    if (a <= 0 || b <= 0 || a > b) {
        printf("Số a và b không hợp lệ\n");
        return 1;
    }

    printf("Các số nguyên tố trong khoảng từ %d đến %d là:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (IS_PRIME(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
