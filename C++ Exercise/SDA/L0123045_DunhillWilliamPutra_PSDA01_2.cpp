#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// Stack to keep track of visited websites
stack<string> history;

// Stack to keep track of back button events
stack<string> visited;

/**
 * @brief Visits a given website and pushes it onto the history stack
 * @param site The website to visit
 */
void visit(string site) {
    history.push(site);
    cout << "- Mengunjungi " << site << endl;
}

/**
 * @brief Moves one step back in the history and adds the current top of
 *        the history stack to the visited stack
 */
void back() {
    visited.push(history.top());
    history.pop();
    cout << "- Mengunjungi " << history.top() << endl;
}

/**
 * @brief Moves one step forward in the history by popping the top of the
 *        visited stack and pushing it back to the history stack
 */
void forward() {
    history.push(visited.top());
    visited.pop();
    cout << "- Mengunjungi " << history.top() << endl;
}

int main() {
    // Visit a series of websites
    visit("google.com");
    visit("instagram.com");
    visit("github.com");
    visit("efishery.com");

    // Move back through the history
    back();
    back();
    back();

    // Move forward through the history
    forward();
    forward();

    // Visit another website
    visit("stackoverflow.com");

/*
Output:
- Mengunjungi google.com
- Mengunjungi instagram.com
- Mengunjungi github.com
- Mengunjungi efishery.com
- Mengunjungi github.com
- Mengunjungi instagram.com
- Mengunjungi google.com
- Mengunjungi instagram.com
- Mengunjungi github.com
- Mengunjungi stackoverflow.com
*/

    return 0;
}