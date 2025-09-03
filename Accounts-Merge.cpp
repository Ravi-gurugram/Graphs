class Solution {
public:
    unordered_map<string, string> parent;  // email -> parent
    unordered_map<string, string> owner;   // email -> name

    string find(string s) {
        if (parent[s] != s)
            parent[s] = find(parent[s]);
        return parent[s];
    }

    void unite(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Step 1: Initialize parent and owner
        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                parent[acc[i]] = acc[i];  // self-parent
                owner[acc[i]] = name;
            }
        }

        // Step 2: Union emails in the same account
        for (auto &acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                unite(acc[1], acc[i]);  // connect first email with others
            }
        }

        // Step 3: Group emails by root parent
        unordered_map<string, vector<string>> groups;
        for (auto &p : parent) {
            string root = find(p.first);
            groups[root].push_back(p.first);
        }

        // Step 4: Build result
        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), owner[g.first]); // add name
            result.push_back(emails);
        }

        return result;
    }
};
