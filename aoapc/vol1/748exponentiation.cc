#include <iostream>

using namespace std;

int main() {
    long double tmp;
    tmp = 0.4321;
    for (int i = 0; i < 20; i++)
        tmp = tmp * tmp;
    cout << scientific << tmp << endl;
    return 0;
}
