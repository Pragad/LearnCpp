#include <iostream>
#include <queue>
#include <functional>
#include <vector>

struct ScoreIndex
{
    double score;
    unsigned int index;

    bool operator<(const ScoreIndex& buyRhs) const
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

int main()
{
    std::priority_queue<ScoreIndex> scoreIndex;
    std::priority_queue<ScoreIndexGreater> scoreIndexGreater;

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

    scoreIndexGreater.push(ScoreIndexGreater{4.4, 0});
    scoreIndexGreater.push(ScoreIndexGreater{1.1, 0});
    scoreIndexGreater.push(ScoreIndexGreater{3.3, 0});
    scoreIndexGreater.push(ScoreIndexGreater{2.2, 0});

    while (!scoreIndexGreater.empty())
    {
        std::cout << scoreIndexGreater.top().score << " : " << scoreIndexGreater.top().index << std::endl;
        scoreIndexGreater.pop();
    }


    std::cout << std::endl;
    return 0;
}
