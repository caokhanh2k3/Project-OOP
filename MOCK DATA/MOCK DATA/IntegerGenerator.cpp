#include "IntegerGenerator.h"

IntegerGenerator* IntegerGenerator::instance() {
    if (_instance == NULL) {
        _instance = new IntegerGenerator();
    }

    return _instance;
}

IntegerGenerator::IntegerGenerator() {
    srand(time(NULL));
}

IntegerGenerator::~IntegerGenerator() {
    delete _instance;
}

int IntegerGenerator::next() {
    int result = rand();
    return result;
}

int IntegerGenerator::next(int max) {
    int result = rand() % max;
    return result;
}

int IntegerGenerator::next(int left, int right) {
    int result = rand() % (right - left + 1) + left;
    return result;
}