#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cout << "Enter characters (no spaces, or one word): ";
    cin >> s;

    queue<char> q;
    int freq[256] = {0};

    cout << "Output: ";
    for (char ch : s) {
        freq[(int)ch]++;
        q.push(ch);

        while (!q.empty() && freq[(int)q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << "\n";
    return 0;
}