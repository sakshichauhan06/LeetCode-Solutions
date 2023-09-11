class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
	vector<vector<int>> res;
	unordered_map<int,vector<int>> groups;

	for(int i=0; i<groupSizes.size(); i++){
		auto& group=groups[groupSizes[i]];
		group.push_back(i);
		if(group.size()==groupSizes[i]){
			res.push_back(group);
			group={};
		}
	}
	return res;
}
};