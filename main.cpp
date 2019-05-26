//
// Created by Nerijus on 2019-05-22.
//

#include "main.h"
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
    Timer t;  // Paleisti

    NVector<int> a(1e7,1);
    NVector<int> b(1e7,2);
    NVector<int> c;
    c = a + b;

    std::cout << c.size() << " elementų sudėtis užtruko: " << t.elapsed() << " s\n";

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
    std::cout << e.front() << " < " << e.back() << " < " << e.capacity() << " < " << e.size() << "\n";

    NVector<int> f(99999);

    return 0;
}