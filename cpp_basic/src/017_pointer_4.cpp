#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;

int* getRandom() {
    static int ret[10];
    srand( (unsigned)time( NULL ) );

    for (int i = 0; i < 10; i++) {
        ret[i] = rand();
        cout << ret[i] << endl;
    }
    return ret;
}

int main() {
    int* p = getRandom();
    for (int i = 0; i < 10; i++) {
        cout << *(p + i) << endl;
    }
    return 0;
}
