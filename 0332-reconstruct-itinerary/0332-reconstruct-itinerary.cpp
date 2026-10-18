class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> itinerary;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto& entry : adj) {
            sort(entry.second.rbegin(), entry.second.rend());
        }
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

    void dfs(string airport) {
        while (!adj[airport].empty()) {
            string next = adj[airport].back();
            adj[airport].pop_back();

            dfs(next);
        }
        itinerary.push_back(airport);
    }
};