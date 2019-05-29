//
// Created by Nerijus on 2019-05-22.
//

#include "main.h"
#include "vector"
#include <chrono>

class Timer {
private:
    // per using sutrumpiname ilgus chrono bibliotekos tipus
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
    std::chrono::time_point<hrClock> start;

public:
    Timer() : start{hrClock::now()} {}
    void reset() { start = hrClock::now(); }
    double elapsed() const {
        return durationDouble(hrClock::now() - start).count();
    }
};

int main() {

    std::cout << "Paleisti" << std::endl;

    NVector<int> a(1e7,1);
    NVector<int> b(1e7,2);
    NVector<int> c;
    c = a + b;



    std::cout << "c[100000] = " << c[100000] << std::endl; // Patikriname ar tikrai sudėjo

    NVector<int> d;
    std::cout << "Size: " << d.size() << ", Capacity: " << d.capacity() << "\n";
    d.push_back(1);
    std::cout << "Size: " << d.size() << ", Capacity: " << d.capacity() << "\n";
    d.push_back(1);
    std::cout << "Size: " << d.size() << ", Capacity: " << d.capacity() << "\n";
    for(int i = 0; i < 100; i++)
        d.push_back(i);
    std::cout << "Size: " << d.size() << ", Capacity: " << d.capacity() << "\n";
    d.shrink_to_fit();
    std::cout << "Size: " << d.size() << ", Capacity: " << d.capacity() << "\n";
    std::cout << d[2] << "\n";

    NVector<int> e{0,1,2,3};
    std::cout << e[2] << "\n";
    std::cout << e.at(2) << "\n";
    std::cout << e.front() << " < " << e.back() << " < " << e.capacity() << " < " << e.size() << "\n";
    e.insert(e.begin(), -100);
    e.insert(e.end(), -200);
    std::cout << e.front() << " < " << e.back() << " < " << e.capacity() << " < " << e.size() << "\n";
    e.reserve(9);
    std::cout << e.front() << " < " << e.back() << " < " << e.capacity() << " < " << e.size() << "\n";
    std::cout << e.max_size() << "\n";

    NVector<int> f(99999);

    // Pradėti v1 užpildymo laiko matavimą
    Timer t;  // Paleisti
    unsigned int sz = 10000000;  // 100000, 1000000, 10000000, 100000000
    int cap_moves = 0;
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i){
        if(v1.size() == v1.capacity())
            cap_moves++;
        v1.push_back(i);
    }
// Baigti v1 užpildymo laiko matavimą
    std::cout << v1.size() << " elementų sudėtis užtruko: " << t.elapsed() << " s\n";
    std::cout << cap_moves << "\n";

// Pradėti v2 užpildymo laiko matavimą
    Timer t1;  // Paleisti
    NVector<int> v2;
    for (int i = 1; i <= sz; ++i)
        v2.push_back(i);
// Baigti v2 užpildymo laiko matavimą
    std::cout << v2.size() << " elementų sudėtis užtruko: " << t1.elapsed() << " s\n";
    std::cout << v2.cap_moves() << "\n";

    return 0;
}