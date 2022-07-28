# Solution sketch: Farida-G
- General approach: Solve as Tree-DP
- Problem: Graph has some edges beyond a tree
- Idea: FPT solution
1. Figure a few nodes whose removal eliminates all cycles (at most m-n+1) using a greedy approach
2. Try out all independent subsets of those nodes. For each subset, treat them as axiomatically included and compute Tree-DP on the remaining graph.
3. Pick the maximum value over all DP initializations.
