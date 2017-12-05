#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdint>

// Do not add any extra #includes without asking on the KEATS discussion forum

using std::pair;
using std::make_pair;
using std::vector;

typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// TODO - your code goes here

Path moves(const pair<int, int> & initialPair) {

    Path path = Path();
    path.emplace_back(initialPair.first+1, initialPair.second+2); path.emplace_back(initialPair.first+2, initialPair.second+1);
    path.emplace_back(initialPair.first+2, initialPair.second-1); path.emplace_back(initialPair.first+1, initialPair.second-2);
    path.emplace_back(initialPair.first-1, initialPair.second-2); path.emplace_back(initialPair.first-2, initialPair.second-1);
    path.emplace_back(initialPair.first-2, initialPair.second+1); path.emplace_back(initialPair.first-1, initialPair.second+2);
    return path;
}

Path legal_moves(const int & size, const Path & path, const pair<int, int> & position) {
    // TODO
}

pair<Path, bool> first_tour(const int & size, const Path & path) {
    // TODO
};




// Do not edit below this line

#endif
