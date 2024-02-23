/*
    Design time-based key-value structure, multiple vals at diff times

    Hash map, since timestamps are naturally in order, binary search

    Time: O(log n)
    Space: O(n)
*/

class TimeMap{
private:
	// Create the data structure : {key : [[ts1, v1][ts2, v2],...]}
	std::unordered_map<std::string, vector<pair<int, string>>> data;

public:
	TimeMap(){

	}

	void set(string key, string value, int timestamp){
		// Insert the data into the hashmap
		data[key].push_back({timestamp, value});
	}

	string get(string key, int timestamp){
		// If key not in data, return empty string
		if (data.find(key) == data.end()){
			return "";
		}

		// Use binary search to look for the timestamp
		int left = 0;
		int right = data[key].size() - 1;

		while (left <= right){
			int mid = ((right - left) / 2) + left;
			if (timestamp == data[key][mid].first){
				return data[key][mid].second;
			} else if (timestamp > data[key][mid].first){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
			
		}

		// if timestamp not found, return the closest smaller timestamp.
		if (right >= 0){
			return data[key][right].second;
		} else{
			return "";
		}
    }
};