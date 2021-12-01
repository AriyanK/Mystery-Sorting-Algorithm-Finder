#include "Sorter.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
#include "include/sorting_library.h"
using namespace std;

void Sorter::run(int size) {            //Calls generate, then runs each algorithm using runAlgo()
    this->size = size;
    cout.precision(9);
    cout << fixed << showpoint;

    generate();

    cout << "Algorithm 1: " << endl;
    runAlgo(1);
    cout << endl;

    cout << "Algorithm 2: " << endl;
    runAlgo(2);
    cout << endl;

    cout << "Algorithm 3: " << endl;
    runAlgo(3);
    cout << endl;

    cout << "Algorithm 4: " << endl;
    runAlgo(4);
    cout << endl;


    cout << "Algorithm 5: " << endl;
    runAlgo(5);
    cout << endl;

    delete [] data;
    delete [] reversed;
    delete [] random;
    delete [] tempRandom;

}

void Sorter::generate() {            //Creates a sorted, reversed, and randomized array of specified size
    data = new int[size];
    reversed = new int[size];
    random = new int[size];
    tempRandom = new int[size];

    for(int x = 0; x < size; x++) {
        data[x] = x;
        tempRandom[x] = x;
    }
    for(int x = 0; x < size; x++){
        reversed[x] = size - (x + 1);
    }
    shuffle(tempRandom, tempRandom + size, std::mt19937(std::random_device()()));
}

void Sorter::runAlgo(int algo) {                                    //Runs each algorithm from the static library and prints timing data
    chrono::time_point<chrono::high_resolution_clock> start, end;
    chrono::duration<double> time_in_seconds;
    if(algo == 1) {
        start = chrono::high_resolution_clock::now();
        mystery01(data, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Sorted: " << time_in_seconds.count() << endl;

        start = chrono::high_resolution_clock::now();
        mystery01(reversed, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Reversed: " << time_in_seconds.count() << endl;
        resetData(0);

        resetData(1);
        start = chrono::high_resolution_clock::now();
        mystery01(random, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Randomized: " << time_in_seconds.count() << endl;
        resetData(1);
    }
    if(algo == 2){
        start = chrono::high_resolution_clock::now();
        mystery02(data, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Sorted: " << time_in_seconds.count() << endl;

        start = chrono::high_resolution_clock::now();
        mystery02(reversed, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Reversed: " << time_in_seconds.count() << endl;
        resetData(0);

        resetData(1);
        start = chrono::high_resolution_clock::now();
        mystery02(random, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Randomized: " << time_in_seconds.count() << endl;
        resetData(1);
    }
    if(algo == 3){
        start = chrono::high_resolution_clock::now();
        mystery03(data, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Sorted: " << time_in_seconds.count() << endl;

        start = chrono::high_resolution_clock::now();
        mystery03(reversed, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Reversed: " << time_in_seconds.count() << endl;
        resetData(0);

        resetData(1);
        start = chrono::high_resolution_clock::now();
        mystery03(random, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Randomized: " << time_in_seconds.count() << endl;
        resetData(1);
    }
    if(algo == 4){
        start = chrono::high_resolution_clock::now();
        mystery04(data, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Sorted: " << time_in_seconds.count() << endl;

        start = chrono::high_resolution_clock::now();
        mystery04(reversed, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Reversed: " << time_in_seconds.count() << endl;
        resetData(0);

        resetData(1);
        start = chrono::high_resolution_clock::now();
        mystery04(random, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Randomized: " << time_in_seconds.count() << endl;
        resetData(1);
    }
    if(algo == 5){
        start = chrono::high_resolution_clock::now();
        mystery05(data, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Sorted: " << time_in_seconds.count() << endl;

        start = chrono::high_resolution_clock::now();
        mystery05(reversed, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Reversed: " << time_in_seconds.count() << endl;
        resetData(0);

        resetData(1);
        start = chrono::high_resolution_clock::now();
        mystery05(random, size);
        end = chrono::high_resolution_clock::now();
        time_in_seconds = end - start;
        cout << fixed << "Randomized: " << time_in_seconds.count() << endl;
        resetData(1);
    }
}

void Sorter::resetData(int type) {              //Resets the data after it has been sorted by an algorithm
    if(type == 0){
        for(int x = 0; x < size; x++){
            reversed[x] = size - (x + 1);
        }
    }
    if(type == 1){
        for(int x = 0; x < size; x++){
            random[x] = tempRandom[x];
        }
    }
}