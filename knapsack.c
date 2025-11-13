/*
 * Project: Knapsack Problem Solver
 * Author: Siddiqua Saud
 * Language: C
 * Description: Implementation of 0/1 Knapsack (DP) and Fractional Knapsack (Greedy)
 */

#include <stdio.h>

// ---------- Fractional Knapsack (Greedy) ----------
void fractionalKnapsack(int n, float weight[], float profit[], float capacity) {
    float ratio[20], total_profit = 0, temp;
    int i, j;

    // Calculate profit/weight ratio
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by ratio (descending order)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    float remaining = capacity;

    for (i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            total_profit += profit[i];
            remaining -= weight[i];
        } else {
            total_profit += ratio[i] * remaining;
            break;
        }
    }

    printf("\nFractional Knapsack (Greedy) Profit = %.2f\n", total_profit);
}

// ---------- 0/1 Knapsack (Dynamic Programming) ----------
int max(int a, int b) { return (a > b) ? a : b; }

int knapsackDP(int capacity, int weight[], int profit[], int n) {
    int i, w;
    int dp[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

// ---------- Main Function ----------
int main() {
    int n, i, capacity;

    printf("=== Knapsack Problem Solver ===\n");
    printf("Enter number of items: ");
    scanf("%d", &n);

    float weight[20], profit[20];
    for (i = 0; i < n; i++) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%f", &weight[i]);
        printf("Enter profit of item %d: ", i + 1);
        scanf("%f", &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Convert float to int arrays for DP
    int intWeight[20], intProfit[20];
    for (i = 0; i < n; i++) {
        intWeight[i] = (int)weight[i];
        intProfit[i] = (int)profit[i];
    }

    printf("\n--- Results ---\n");
    fractionalKnapsack(n, weight, profit, capacity);
    printf("0/1 Knapsack (Dynamic Programming) Profit = %d\n", knapsackDP(capacity, intWeight, intProfit, n));

    return 0;
}
