#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

template <class Type>
void print_elements(Type elem) {
    cout << elem << " ";
}

void (*pfi)(int) = print_elements;
void (*pfs)(string) = print_elements;

int main(int argc, char *argv[])
{
    int ia[] = { 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, };
    vector<int> vec(ia, ia+10);
    vector<int>::iterator vec_iter;
    vec_iter = unique(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), pfi);
    cout << "\n\n";

    vec.erase(vec_iter, vec.end());
    for_each(vec.begin(), vec.end(), pfi);
    cout << "\n\n";

    string sa[] = {
        "enough", "is", "enough",
        "enough", "is", "enough",
    };

    vector<string> svec(sa, sa+6);
    vector<string> vec_result(svec.size());
    vector<string>::iterator svec_iter;
    sort(svec.begin(), svec.end());
    svec_iter = unique_copy(svec.begin(), svec.end(), vec_result.begin());
    for_each(vec_result.begin(), svec_iter, pfs);
    cout << "\n\n";

    return 0;
}
