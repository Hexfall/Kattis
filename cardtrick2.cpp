#include <iostream>
#include <deque>

using namespace std;

void printDeq(deque<int> deq)
{
    for (auto d : deq)
        cout << d << " ";
    cout << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++)
    {
        deque<int> cards;
        int card;
        cin >> card;
        for (; card > 0; card--)
        {
            cards.push_front(card);
            for (int i = 0; i < card % cards.size(); i++)
            {
                int c = cards.back();
                cards.pop_back();
                cards.push_front(c);
            }
        }
        printDeq(cards);
    }
}
