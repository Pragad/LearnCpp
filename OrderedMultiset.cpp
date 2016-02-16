#include <iostream>
#include <set>
#include <map>
using namespace std;

/*
struct ScoreIndex
{
    double score;
    unsigned int index;

    bool operator<(const ScoreIndex& buyRhs) const
    {
        return score > buyRhs.score;
    }
};
*/

struct Samp
{
    double amount;
    std::string item;
};

struct myCompGreater
{
    bool operator() (const Samp& lhs, const Samp& rhs) const
    {
        return lhs.amount > rhs.amount;
    }
};

int main()
{
    std::multiset<Samp, myCompGreater> amountMap;

    // I want to insert these items in the same order as below.
    amountMap.emplace(Samp{8.0, "cat"});
    amountMap.emplace(Samp{8.0, "dog"});
    amountMap.emplace(Samp{8.0, "apple"});

    for (auto itr = amountMap.begin(); itr != amountMap.end(); itr++)
    {
        cout << itr->item << " : " << itr->amount << endl;
    }


    return 0;
}

