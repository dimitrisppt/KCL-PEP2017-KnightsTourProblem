#ifndef TRADE_H
#define TRADE_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdint>

// Do not add any extra #includes without asking on the KEATS discussion forum

// TODO your code goes here:

template <typename T>
int bestProfit(T begin, T end) {
    int first = *begin;
    return std::accumulate(begin, end, 0, [&first](int bProfit, const int & price) {
               if (first > price){
                    first = price;
               }

               if (bProfit < (price-first)) {
                    bProfit = price-first;
               }

               return bProfit;
    });
}





// Don't write any code below this line

#endif
