#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item {
    int weight, value;
    float ratio; // Value per weight (how much bang for your buck)
};

struct Node {
    int level;      // How deep we are in the decision tree
    int profit;     // Current total value
    int weight;     // Current total weight
    float bound;    // The "What if" maximum profit if we keep going
};

// Sort items by greediness (value/weight)
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Calculate the upper bound (the "optimistic" ceiling)
float calculateBound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0; // Overweight? Trash it.

    float profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    // Fill the bag with whole items when we can
    while (j < n && total_weight + items[j].weight <= W) {
        total_weight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    // If there's room left, take a "bite" of the next best item (fractional)
    if (j < n)
        profit_bound += (W - total_weight) * items[j].ratio;

    return profit_bound;
}

int knapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    int n = items.size();

    queue<Node> q;
    Node u, v;

    // Root node (nothing in the bag yet, pooraf)
    u.level = -1; u.profit = 0; u.weight = 0;
    q.push(u);

    int maxProfit = 0;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        // If we haven't reached the end of the item list
        if (u.level == n - 1) continue;

        v.level = u.level + 1;

        // Path A: We take the item
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxProfit) q.push(v);

        // Path B: We leave the item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, W, items);

        if (v.bound > maxProfit) q.push(v);
    }

    return maxProfit;
}

int main() {
    int W = 10;
    vector<Item> items = {{2, 40, 20}, {5, 30, 6}, {10, 50, 5}, {5, 10, 2}};

    cout << "Max loot we can carry: " << knapsack(W, items) << endl;
    return 0;
}
