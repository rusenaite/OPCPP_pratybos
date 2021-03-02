#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>


using namespace std;
using namespace std::chrono;

int main(){
    int x = 432, y = 15, add = 0, div = 0, sub = 0, multi = 0;

    int start_s=clock();
    add = x + y;
    int stop_s=clock();

    auto start2 = high_resolution_clock::now();
    sub = x - y;
    auto stop2 = high_resolution_clock::now();
    auto subDuration = duration_cast<microseconds>(stop2 - start2).count();

    auto start3 = high_resolution_clock::now();
    div = x / y;
    auto stop3 = high_resolution_clock::now();
    auto divDuration = duration_cast<microseconds>(stop3 - start3).count();

    auto start4 = high_resolution_clock::now();
    multi = x * y;
    auto stop4 = high_resolution_clock::now();
    auto multiDuration = duration_cast<microseconds>(stop4 - start4).count();

    cout << "Operation:\t\tResult\t\tTime taken:\n\n";
    cout << "Addition\t\t" << add << "\t\t" << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " microseconds.\n";
    cout << "Subtraction\t\t" << sub << "\t\t" << subDuration << " microseconds.\n";
    cout << "Division\t\t" << div << "\t\t" << divDuration << " microseconds.\n";
    cout << "Multiplication\t\t" << multi << "\t\t" << multiDuration << " microseconds.\n";



    return 0;
}
