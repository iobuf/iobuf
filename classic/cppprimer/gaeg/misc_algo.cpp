#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int ia[] = { 7, 5, 2, 4, 3, };
    const vector<int> ivec(ia, ia+5);
    int mval = max(
            max(
                max(
                    max(ivec[4], ivec[3]), 
                    ivec[2]
                   ), 
                ivec[1]
               ), ivec[0]);
    cout << "the result of nested invocations of max() is: "
        << mval << endl;
    mval = min(
            min(
                min(
                    min(ivec[4], ivec[3]),
                    ivec[2]
                   ),
                ivec[1]
               ), ivec[0]);
    cout << "the result of nested invocations of min() is: "
        << mval << endl;
    vector<int>::const_iterator iter;
    iter = max_element(ivec.begin(), ivec.end());
    cout << "the result of invoking max_element() is also: "
        << *iter << endl;
    iter = min_element(ivec.begin(), ivec.end());
    cout << "the result of invoking min_element() is also: "
        << *iter << endl;
    return 0;
}
