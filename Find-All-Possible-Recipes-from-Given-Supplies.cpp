class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj; // ingredient -> list of recipes it helps make
        unordered_map<string, int> indegree;       // recipe -> number of missing ingredients

        // Initialize indegree for all recipes
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (auto& ing : ingredients[i]) {
                adj[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;
        // Start with all initial supplies
        for (auto& s : supplies) q.push(s);

        vector<string> ans;

        while (!q.empty()) {
            string item = q.front(); q.pop();

            // If item is an ingredient for some recipes
            for (auto& recipe : adj[item]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) {
                    ans.push_back(recipe);
                    q.push(recipe); // recipe becomes new supply
                }
            }
        }

        return ans;
    }
};
