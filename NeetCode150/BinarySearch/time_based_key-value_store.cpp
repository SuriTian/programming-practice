#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class TimeMap {
    public:
        unordered_map<string, map<int, string>> m;

        TimeMap() {}
        
        void set(string key, string value, int timestamp) {
            m[key].insert({timestamp, value}); // store map pair inside hashmaps, is automatically sorted by timestamp
        }
        
        string get(string key, int timestamp) {
            auto it = m[key].upper_bound(timestamp); 
            return it == m[key].begin() ? "" : prev(it)->second; // this is bin search because maps are red black trees
        }
};
