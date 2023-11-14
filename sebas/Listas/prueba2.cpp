#include <iostream>
using namespace std;

main()
{
    int x;
    int *p1;
    int *p2;
    p2 = &x;
    p1 = p2;
    cout << p2;
}
