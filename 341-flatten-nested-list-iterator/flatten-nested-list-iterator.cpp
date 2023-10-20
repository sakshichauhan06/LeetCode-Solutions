/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int> data;
    int curr = 0, size;
	 
    void DFS(vector<NestedInteger> &nestedList, vector<int> &data)
    {   
        int i, n = nestedList.size();
        
        for(i=0;i<n;i++)
        {
            if(nestedList[i].isInteger())
                this->data.push_back(nestedList[i].getInteger());
            else
                DFS(nestedList[i].getList(), this->data);        
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        DFS(nestedList, this->data);
        this->size = this->data.size();            
    }
    
    int next() {
        int ans = this->data[curr];
        curr += 1;
        return ans;
    }
    
    bool hasNext() {
        if(this->curr == this->size)
            return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */