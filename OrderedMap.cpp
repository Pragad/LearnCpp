#include <iostream>
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
    std::map<Samp, uint32_t, myCompGreater> amountMap;

    // I want to insert these items in the same order as below.
    amountMap.emplace(Samp{8.0, "cat"}, 0);
    amountMap.emplace(Samp{8.0, "dog"}, 1);
    amountMap.emplace(Samp{8.0, "apple"}, 2);

    for (auto itr = amountMap.begin(); itr != amountMap.end(); itr++)
    {
        cout << itr->first.item << " : " << itr->first.amount << endl;
    }


    return 0;
}

