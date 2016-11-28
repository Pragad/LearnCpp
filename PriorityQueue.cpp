#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

struct ScoreIndex
{
    double score;
    unsigned int index;

    bool operator<(const ScoreIndex& buyRhs) const
    {
        return score < buyRhs.score;
    }

    bool operator>(const ScoreIndex& buyRhs) const
    {
        return score > buyRhs.score;
    }
};

struct ScoreIndexGreater
{
    double score;
    unsigned int index;

    bool operator<(const ScoreIndexGreater& buyRhs) const
    {
        return score < buyRhs.score;
    }
};

struct Compare
{
    bool operator()(const std::pair<int, uint32_t>& val1, const std::pair<int, uint32_t>& val2)
    {
        return val1.first < val2.first;
    }
};

int main()
{
    // Simple Priority Queue
    {
        int myInts[]= {10,60,50,20};
        std::priority_queue<int, std::vector<int>, std::greater<int> > intsInAsc (myInts, myInts + 4);
        std::priority_queue<int, std::vector<int> > intsInDesc (myInts, myInts + 4);
        std::cout << "Top Asc : " << intsInAsc.top() << std::endl;
        std::cout << "Top Desc: " << intsInDesc.top() << std::endl;
    }

    // Priority Queue that holds a pair of ints
    {
        std::priority_queue<pair<int, uint32_t>, vector<pair<int, uint32_t>>, Compare> rangeValueWithIndex1;
        std::priority_queue<pair<int, uint32_t>> rangeValueWithIndex2;
        std::priority_queue<pair<int, uint32_t>, vector<pair<int, uint32_t>>, std::greater<pair<int, uint32_t>>> rangeValueWithIndex3;

        rangeValueWithIndex1.push({3, 0});
        rangeValueWithIndex1.push({1, 1});
        rangeValueWithIndex1.push({2, 2});
        rangeValueWithIndex1.push({5, 3});
        rangeValueWithIndex1.push({4, 4});

        while (!rangeValueWithIndex1.empty())
        {
            std::cout << rangeValueWithIndex1.top().first << ", ";
            rangeValueWithIndex1.pop();
        }
        std::cout << endl;

        rangeValueWithIndex2.push({3, 0});
        rangeValueWithIndex2.push({1, 1});
        rangeValueWithIndex2.push({2, 2});
        rangeValueWithIndex2.push({5, 3});
        rangeValueWithIndex2.push({4, 4});

        while (!rangeValueWithIndex2.empty())
        {
            std::cout << rangeValueWithIndex2.top().first << ", ";
            rangeValueWithIndex2.pop();
        }
        std::cout << endl;


        rangeValueWithIndex3.push({3, 0});
        rangeValueWithIndex3.push({1, 1});
        rangeValueWithIndex3.push({2, 2});
        rangeValueWithIndex3.push({5, 3});
        rangeValueWithIndex3.push({4, 4});

        while (!rangeValueWithIndex3.empty())
        {
            std::cout << rangeValueWithIndex3.top().first << ", ";
            rangeValueWithIndex3.pop();
        }
        std::cout << endl;

    }

    // Priority Queue that holds a structure
    {
        std::priority_queue<ScoreIndex> scoreIndex;
        std::priority_queue<ScoreIndex, vector<ScoreIndex>, std::greater<ScoreIndex>> scoreIndexGreater;

        scoreIndex.push(ScoreIndex{4.4, 0});
        scoreIndex.push(ScoreIndex{1.1, 1});
        scoreIndex.push(ScoreIndex{3.3, 2});
        scoreIndex.push(ScoreIndex{2.2, 3});

        while (!scoreIndex.empty())
        {
            std::cout << scoreIndex.top().score << " : " << scoreIndex.top().index << std::endl;
            scoreIndex.pop();
        }
        std::cout << std::endl;

        scoreIndexGreater.push(ScoreIndex{4.4, 0});
        scoreIndexGreater.push(ScoreIndex{1.1, 0});
        scoreIndexGreater.push(ScoreIndex{3.3, 0});
        scoreIndexGreater.push(ScoreIndex{2.2, 0});

        while (!scoreIndexGreater.empty())
        {
            std::cout << scoreIndexGreater.top().score << " : " << scoreIndexGreater.top().index << std::endl;
            scoreIndexGreater.pop();
        }
    }

    std::cout << std::endl;
    return 0;
}
