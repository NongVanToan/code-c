#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_size_and_range(char* type) {
    if (strcmp(type, "int") == 0) {
        printf("Size of int: %lu bytes\n", sizeof(int));
        printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);
    }
    else if (strcmp(type, "float") == 0) {
        printf("Size of float: %lu bytes\n", sizeof(float));
        printf("Range of float: %E to %E\n", -FLT_MAX, FLT_MAX);
    }
    else if (strcmp(type, "double") == 0) {
        printf("Size of double: %lu bytes\n", sizeof(double));
        printf("Range of double: %E to %E\n", -DBL_MAX, DBL_MAX);
    }
    else if (strcmp(type, "char") == 0) {
        printf("Size of char: %lu byte\n", sizeof(char));
        printf("Range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    }
    else {
        printf("Invalid type\n");
    }
}

int main() {
    char type[10];
    printf("Nhập tên kiểu dữ liệu: ");
    scanf("%s", type);

    if (strcmp(type, "all") == 0) {
        printf("Size and Range of All Data Types:\n");
        print_size_and_range("int");
        print_size_and_range("float");
        print_size_and_range("double");
        print_size_and_range("char");
    }
    else {
        printf("Size and Range of %s:\n", type);
        print_size_and_range(type);
    }

    return 0;
}
