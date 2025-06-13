class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        stack<int> mystack;
        visited.insert(0);
        mystack.push(0); 
        while(!mystack.empty()){
            int currentroom= mystack.top();
            mystack.pop();
            if(visited.find(currentroom)==visited.end()){
                visited.insert(currentroom);
                }
            for(const auto&key:rooms[currentroom]){
                if(visited.find(key)==visited.end()){
                    mystack.push(key);
                }
            }
        }
        return visited.size()==rooms.size();
        
    }
};