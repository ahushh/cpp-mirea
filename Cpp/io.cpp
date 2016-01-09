#include <fstream>
#include "Vector.cpp"

using namespace std;

int main() {
    Vector v;
    ifstream input;
    input.open("input.txt", ios::in);
    input >> v;
    input.close();
    v * 10;
    ofstream output;
    output.open("output.txt", ios::out);
    output << v;
    output.close();

    int c1[3] = {1,2,3};
    int c2[3] = {4,5,6};

    Vector a(c1, 3), b(c2, 3), c;
    c.setSize(3);
    
    cout << a.width << "a " << a;
    cout << "b " << b;
    c = a - b;
    cout << "a-b " << c;
    cout << "Vector product of vectors a and b: " << endl;
    c = a*b;
    cout << c;
    cout << "Division of vector a by 2: " << endl;
    c = a / 2;
    cout << c;
    return 0;
}
