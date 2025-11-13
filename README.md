# 🎒 Knapsack Problem Solver (DAA SProject)

This mini project demonstrates two classic algorithms in **Design and Analysis of Algorithms (DAA)**:

1. **Fractional Knapsack (Greedy Approach)**
2. **0/1 Knapsack (Dynamic Programming)**

---

## 🧠 Algorithms

### 1️⃣ Fractional Knapsack (Greedy)
- Sort items by profit/weight ratio.
- Take full items until capacity allows; take fractional part of next.
- **Time Complexity:** O(n²)

### 2️⃣ 0/1 Knapsack (Dynamic Programming)
- Either take or skip an item.
- Build DP table to maximize profit.
- **Time Complexity:** O(n × W)

---

## ⚙️ How to Run

```bash
git clone https://github.com/your-username/knapsack-solver-c.git
cd knapsack-solver-c
gcc main.c -o knapsack
./knapsack
