#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include "include/sorting_library.h"
#include "Sorter.h"

using namespace std;

int main() {                    //Creates a Sorter object and runs it with a specified input size
    Sorter algos;
    algos.run(100000);
}
