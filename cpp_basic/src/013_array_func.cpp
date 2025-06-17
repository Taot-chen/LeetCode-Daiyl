#include <iostream>

double avg(int arr[], int size);

int main() {
    int a[5] = {1, 2, 3, 4};
    double ret;

    ret = avg(a, 5);
    std::cout << ret << std::endl;
    return 0;
}

double avg(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) (sum * 1.0 / size);
}
