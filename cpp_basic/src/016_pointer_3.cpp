#include <iostream>

double avg(int* ptr, int size);

int main() {
    int arr[3] = {1, 2, 3};
    double a = avg(arr, 3);
    std::cout << a << std::endl;
    return 0;
}

double avg(int* ptr, int size) {
    int i, sum = 0;
    double ret = 0;
    for (i = 0; i < size; i++) {
        sum += ptr[i];
    }
    ret = double(sum) / size;
    return ret;
}
