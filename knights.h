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
    Path pathOfMoves = moves(position);
    Path legalPath = Path();
    std::copy_if(pathOfMoves.begin(),
                 pathOfMoves.end(),
                 std::back_inserter(legalPath),
                 [size, path](const pair<int, int> & pairPos) {
                                  bool inside = (pairPos.first >= 0) && (size > pairPos.first) && (pairPos.second >= 0) && (size > pairPos.second);
                                  bool inPath = path.end() != std::find(path.begin(), path.end(), pairPos);
                                  return !inPath && inside;
                 });
    return legalPath;
}

pair<Path, bool> first_tour(const int & size, const Path & path) {

    auto startingPos = path.back();
    auto legalMoves = legal_moves(size, path, startingPos);

    std::sort(legalMoves.begin(),
              legalMoves.end(),
              [size, path](pair<int, int> & firstPair, pair<int, int> & secondPair) {

                  return legal_moves(size, path, secondPair).size() > legal_moves(size, path, firstPair).size();
              });

    for (int i = 0; i < legalMoves.size(); ++i) {
        Path copy(path);
        copy.push_back(legalMoves[i]);
        auto recursiveVar = first_tour(size, copy);
        return make_pair(recursiveVar.first, true);

    }

    if (path.size()) {
        return make_pair(path, true);
    } else {
        return make_pair(Path(), false);
    }
};




// Do not edit below this line

#endif
