#include<iostream>
#include<vector>
#include <climits>
using namespace std;

std::vector<int> blob_sort(std::vector<int> input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = i; j < input.size(); j++) {
            if (input[i] > input[j]) {
                int tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
        }
    }
    return input;
}


std::vector<int> insert_sort(std::vector<int> input) {
    for (int i = 1; i < input.size(); i++) {
        int curr = input[i];
        int j = i - 1;
        while (j >= 0 && curr < input[j]) {
            input[j+1] = input[j];
            j--;
        }
        input[j+1] = curr;
    }
    return input;
}


std::vector<int> select_sort(std::vector<int> input) {
    for (int i = 0; i < input.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < input.size(); j++) {
            if (input[j] < input[min_index]) min_index = j;
        }
        int tmp = input[i];
        input[i] = input[min_index];
        input[min_index] = tmp;
    }
    return input;
}



int parition(std::vector<int>& input, int low, int high) {
    int povit = input[low];
    while (low < high) {
        while (low < high && input[high] >= povit) {
            high--;
        }
        input[low] = input[high];
        while (low < high && input[low] <= povit) {
            low++;
        }
        input[high] = input[low];
    }
    input[low] = povit;
    return low;
}

std::vector<int> quick_sort(std::vector<int> &input, int low, int high) {
    if (low < high) {
        int pivot = parition(input, low, high);
        quick_sort(input, low, pivot - 1);
        quick_sort(input, pivot + 1, high);
    }
    return input;
}



void merge(std::vector<int>& input, int start, int mid, int end) {
    std::vector<int> leftArray(input.begin() + start, input.begin() + mid + 1);
    std::vector<int> rightArray(input.begin() + mid + 1, input.begin() + end + 1);
    leftArray.insert(leftArray.end(), INT_MAX);
    rightArray.insert(rightArray.end(), INT_MAX);
    int idxLeft = 0, idxRight = 0;
    for (int i = start; i < end + 1; i++) {
        if (leftArray[idxLeft] >= rightArray[idxRight]) {
            input[i] = rightArray[idxRight];
            idxRight++;
        } else {
            input[i] = leftArray[idxLeft];
            idxLeft++;
        }
    }
}

void merge_sort(std::vector<int>& input, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge_sort(input, start, mid);
    merge_sort(input, mid+1, end);
    merge(input, start, mid, end);
}



int main() {
    vector<int> ret;
    vector<int> input = {
        1, 3, 45, 42, 342, 4353, 43, 435, 1, 67, 4, 57
    };
    std::cout << "Input:\n";
    for (int i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;

    ret = blob_sort(input);
    std::cout << "Blob sort:\n";
    for (int i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;

    ret = insert_sort(input);
    std::cout << "Insert sort:\n";
    for (int i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;

    ret = select_sort(input);
    std::cout << "Select sort:\n";
    for (int i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;

    vector<int> tmp_input = input;
    ret = quick_sort(tmp_input, 0, input.size() - 1);
    std::cout << "Quick sort:\n";
    for (int i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;

    tmp_input = input;
    merge_sort(tmp_input, 0, input.size() - 1);
    std::cout << "Quick sort:\n";
    for (int i = 0; i < tmp_input.size(); i++) {
        std::cout << tmp_input[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}