
#include <iostream> 
#include <cstdlib>
using namespace std;

bool test(const int a) {
    return(a % 1 == 0 && a % 2 == 0);
}
int main() {
    int a;
    cin >> a;
    cout << (test(a) ? "True" : "False") << endl;
    return 0;
}