//
// Created by Lukasz Nowakowski on 2021-12-15.
//

#define PI 3.14159265

#include <iostream>
#include <vector>


template<class T>
class Rotation {
public:
    Rotation() {
        rot = std::vector<std::vector<T>>(3,std::vector<T>(3));
        for (int i = 0; i < 3; ++i) {
            rot[i][i] = 1;
        }
    }

    virtual Rotation<T>& rotation()=0;

    std::vector<T>& operator[] (int x) {
        return this->rot[x];
    }

    friend std::ostream& operator<< (std::ostream& os, const Rotation<T>& obj) {
        for (auto i : obj.rot) {
            for (auto j : i) {
                os << j << " ";
            }
            os << '\n';
        }
        os << "\n";
        return os;
    }

private:
    std::vector<std::vector<T>> rot;
};

template <class T>
class Displacement {
public:
    Displacement() {
        disp = std::vector<T>(3,0);
    }

    virtual Displacement<T>& displacement()=0;

    T& operator[] (int x) {
        return disp[x];
    }

    friend std::ostream& operator<< (std::ostream& os, const Displacement<T>& obj) {
        for (auto i : obj.disp) {
            os << i << '\n';
        }
        os << '\n';
        return os;
    }

private:
    std::vector<T> disp;
};

template<class T>
class Transform : public Rotation<T>, public Displacement<T> {
public:
    Transform() {
    }

    virtual Rotation<T>& rotation() {
        Rotation<T> &r = *this;
        return r;
    }

    virtual Displacement<T>& displacement() {
        Displacement<T> &d = *this;
        return d;
    }



    friend std::ostream& operator<< (std::ostream& os, Transform<T>& obj) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                os << obj.rotation()[i][j] << ' ';
            }
            os << obj.displacement()[i] << '\n';
        }
        os << 0 << ' ' << 0 << ' ' << 0 << ' ' << 1 << '\n';
        return os;
    }
private:
    std::vector<std::vector<T>> affine;
};

int main() {

    Transform<float> a;
    Rotation<float> &r_ref = a;
    std::cout << a.rotation();
    //std::cout << a.displacement();
    //std::cout << a;

    a.rotation()[0][0] = 20;
    std::cout << a.rotation();

    return 0;
}
