#include <iostream>
using namespace std;

// #define DEBUG
#define MIN(a,b) (((a)<(b)) ? a : b)

int main() {
    int i, j;
    i = 100;
    j = 10;
    #ifdef DEBUG
        std::cerr << "Trace: Inside main function" << std::endl;
    #endif

    #if 0
        /* 这是注释部分 */
        cout << MKSTR(HELLO C++) << endl;
    #endif

    cout <<"The minimum is " << MIN(i, j) << endl;

    #ifdef DEBUG
        cerr <<"Trace: Coming out of main function" << endl;
    #endif
    return 0;
}
