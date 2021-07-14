#ifndef RANDOMMAKER_H
#define RANDOMMAKER_H
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class RandomMaker
{
public:
    int static RandNum(int,int=0);
    vector<int> static RandShuffle(int,int=0);
    vector<int> static RandShuffle(vector<int>);
};

#endif // RANDOMMAKER_H
