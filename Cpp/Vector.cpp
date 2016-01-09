#include <iostream>

using namespace std;

class Vector
{
private:
    int N;
    int* c;
public:
    Vector() {}
    Vector(int n): N(n) {}
    Vector(int *v, int n): c(v), N(n) {}
    int getSize() {
        return N;
    }
    void setSize(int n) {
        N = n;
        c = new int[N];
    }
    int* getCoordinates() {
        return c;
    }
    void setCoordinates(int* v) {
        c = v;
    }
    /* сложение векторов */
    Vector operator+(Vector &b) {
        Vector v = Vector();
        v.setSize( N );

        int* b_c   = b.getCoordinates(); 
        int* new_c = new int[N];
        for (int i = 0; i < N; i++) {
            new_c[i] = c[i] + b_c[i];
        }
        v.setCoordinates( new_c );
        return v;
    }
    /* вычитание векторов */
    Vector operator-(Vector &b) {
        Vector v = Vector();
        v.setSize( N );
        int* b_c   = b.getCoordinates(); 
        int* new_c = new int[N];
        for (int i = 0; i < N; i++)
            new_c[i] = c[i] - b_c[i];
        v.setCoordinates( new_c );
        return v;
    }
    /* задание 2 */
    /* векторное произведение */
    Vector operator*(Vector &b) {
        Vector v = Vector(N);
        int x1 = c[0];
        int y1 = c[1];
        int z1 = c[2];
        int* b_c = b.getCoordinates();
        int x2 = b_c[0];
        int y2 = b_c[1];
        int z2 = b_c[2];
        int* v_c = new int[N];
        v_c[0] = z1*z2 - z1*y2;
        v_c[1] = z1*x2 - x1*z2;
        v_c[2] = x1*y2 - y1*x2;
        v.setCoordinates( v_c );
        return v;
    }
    /* умножение вектора на число */
    void operator*(int n) {
        for (int i = 0; i < N; i++)
            c[i] = n*c[i];
    }
    /* задание 3 */
    /* деление вектора на число */
    friend Vector operator/(Vector& a, int n) {
        int N = a.getSize();
        Vector b = Vector( N );
        int* a_c   = a.getCoordinates(); 
        int* b_c = new int[ N ];
        for (int i = 0; i < N; i++) 
            b_c[i] = a_c[i] / n;
        b.setCoordinates( b_c );
        return b;
    }
    /* присваивание */
    Vector operator=(Vector v) {
        if (this == &v)
            return *this;
        int* v_c = v.getCoordinates();
        for (int i = 0; i < N; i++)
            c[i] = v_c[i];
        return *this;
    }
    /* вывод */
    friend ostream& operator<<(ostream& os, Vector& v) {
        os << "{";
        int N = v.getSize();
        int* c = v.getCoordinates();
        for (int i = 0; i < N; i++) {
            os << width << c[i];
            if (i != N-1)
                os << ", ";
        }
        os << "}" << endl;
        return os;
    }
    /* ввод */
    friend istream& operator>>(istream& is, Vector& v) {
        int N = v.getSize();
        int* c = v.getCoordinates();
        for (int i = 0; i < N; i++)
            is >> c[i];
        return is;
    }
    /* манипулятор */
    static ostream& width(ostream& os) {    
        os.width(5);
        return os;
    }
};
