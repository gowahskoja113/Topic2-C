#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

int arr[MAX];
int n = 0;

// nhap mang 
void inputArray() {
    do {
        printf("Nhap so luong phan tu (1-100): ")
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// in ra mang da nhap
void outputArray() {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// sap xep giam dan 
void sortDescending() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep giam dan: ");
    outputArray();
}

// kiem tra so le trong mang
void checkAllOdd() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("Mang co 1 hoac nhieu gia tri khong phai so le.\n");
            return;
        }
    }
    printf("Mang toan so le.\n");
}

// tim kiem gia tri trong mang
void searchValue() {
    int x, count = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    printf(" Co %d lan gia tri %d xuat hien trong mang.\n", count, x);
}

// check so nguyen to 
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// in ra so nguyen to 
void displayPrimes() {
    printf("Cac so nguyen to trong mang: ");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to trong mang.");
    }
    printf("\n");
}

//menu
int main() {
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap mang\n");
        printf("2. Xuat mang\n");
        printf("3. Sap xep giam dan\n");
        printf("4. Kiem tra mang co phai toan so le hay khong\n");
        printf("5. Kiem tra so lan gia tri xuat hien trong mang\n");
        printf("6. In ra so cac nguyen to trong mang\n");
        printf("7. Thoat chuong trinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputArray(); break;
            case 2: outputArray(); break;
            case 3: sortDescending(); break;
            case 4: checkAllOdd(); break;
            case 5: searchValue(); break;
            case 6: displayPrimes(); break;
            case 7: 
                printf("Ban co chac muon thoat khong? (1: co, 0: khong): ");
                int confirm;
                scanf("%d", &confirm);
                if (confirm == 1) {
                    printf("Thoat chuong trinh.\n");
                    exit(0);
                }
                break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (1);

    return 0;
}
