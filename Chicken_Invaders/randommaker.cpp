#include "RandomMaker.h"
using namespace std;
int RandomMaker::RandNum(int n,int first){
    int a=rand()%n+first;
    return a;
}
vector <int> RandomMaker::RandShuffle(int n,int begin){ // create shuffled Vector 0 to n (included n)
    srand(time(0));
    vector <int> myVector;
    for(int i=begin;i<=n;i++){
        myVector.push_back(i);
    }
    random_shuffle(myVector.begin(),myVector.end());
    return myVector;
}
vector <int> RandomMaker::RandShuffle(vector<int> InputVec){ // create shuffled Vector 0 to n (included n)
    srand(time(0));
    random_shuffle(InputVec.begin(),InputVec.end());
    return InputVec;
}

