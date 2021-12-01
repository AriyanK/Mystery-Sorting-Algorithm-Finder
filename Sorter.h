#ifndef PA03_TEMPLATE_SORTER_H
#define PA03_TEMPLATE_SORTER_H
#include <iostream>
#include <chrono>
#include "include/sorting_library.h"
using namespace std;

class Sorter{
public:
    void run(int size);

private:
    void generate();
    void runAlgo(int algo);
    void resetData(int type);
    int size;
    int* data;
    int* reversed;
    int* random;
    int* tempRandom;
};





#endif //PA03_TEMPLATE_SORTER_H
