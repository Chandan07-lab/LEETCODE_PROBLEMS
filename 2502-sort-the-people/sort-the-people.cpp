class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>v;
        int n=names.size();
        for(int i=0;i<n;i++){
            v.push_back({heights[i],names[i]});
        }
        sort(v.rbegin(),v.rend());

        for(int i=0;i<n;i++){
            names[i]=v[i].second;
        }
        return names;
    }
};
//  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         // Vector to store pairs of {height, name}
//         vector<pair<int, string>> people;
        
//         // Combine names and heights into a vector of pairs
//         for (int i = 0; i < names.size(); ++i) {
//             people.push_back({heights[i], names[i]});
//         }
        
//         // Sort the people by height in descending order
//         sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
//             return a.first > b.first;
//         });
        
//         // Extract the sorted names
//         vector<string> sortedNames;
//         for (const auto& person : people) {
//             sortedNames.push_back(person.second);
//         }
        
//         return sortedNames;
//     }