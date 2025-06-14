class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target){
            return 0;}
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < routes.size(); ++i) {
            for (const int stop : routes[i]) {
                graph[stop].push_back(i);
            }
        }
        if (graph.find(source) == graph.end() || graph.find(target) == graph.end()) {
            return -1;
        }queue<int> q;
        q.push(source);
        unordered_set<int> visitedStops = {source}; 
        unordered_set<int> usedBuses; 
        while (!q.empty()) {
            int sz = q.size();
            ++steps;
            for (int i = 0; i < sz; ++i) {
                int currStop = q.front();
                q.pop();
                for (const int bus : graph[currStop]) {
                    if (usedBuses.insert(bus).second) { 
                        for (const int nextStop : routes[bus]) {
                            if (nextStop == target) {
                                return steps;
                            }
                            if (visitedStops.insert(nextStop).second) { 
                                q.push(nextStop);
                            }
                        }
                    }
                }
            }
        }
        return -1; 
    }
};