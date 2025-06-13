class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin(),deadends.end());
        queue<pair<string,int>>x;
        unordered_set<string>visited;
        if(dead.find("0000")==dead.end()){
            x.push({"0000",0});
            visited.insert("0000");
        }
        while(!x.empty()){
            pair<string,int> current = x.front();
            x.pop();
            string t = current.first;
            int count= current.second;
            if(t==target){
                return count;
            }
            for(int i=0;i<4;i++){
                string temp=t;
                string tempo=t;
                temp[i] = (t[i] - '0' + 1) % 10 + '0'; 
                tempo[i] = (t[i] - '0' - 1 + 10) % 10 + '0';
                
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    x.push({temp,count+1});
                    visited.insert(temp);
                    }
                
                if(dead.find(tempo)==dead.end()&&visited.find(tempo)==visited.end()){
                    x.push({tempo,count+1});
                    visited.insert(tempo);
                    }
            }
            
        }
        return -1;
    }
};