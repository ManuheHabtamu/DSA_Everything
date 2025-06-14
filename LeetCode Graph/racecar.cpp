struct Car {
    int position;
    int speed;

    Car(int pos, int spd) : position(pos), speed(spd) {}  

    bool operator==(const Car &other) const {
        return position == other.position && speed == other.speed;
    }
};
struct CarHash {
    size_t operator()(const Car &c) const {
        return hash<int>()(c.position) ^ (hash<int>()(c.speed) << 1);
    }
};
class Solution {
public:
    int racecar(int target) {
        unordered_set<Car, CarHash> visited;
        queue<Car> q; 
        Car start(0, 1);
        q.push(start);
        visited.insert(start); 
        int steps = 0;
        while(q.size()){
            int sz= q.size();
            for(int i = 0; i < sz; i++){
                Car current = q.front();
                q.pop();
                if (current.position== target){
                    return steps;
                }

        Car forward(current.position + current.speed, current.speed * 2);
                if (abs(forward.position) <= 2 * target && !visited.count(forward)) {
                    q.push(forward);
                    visited.insert(forward);
                }

                int reverseSpeed = (current.speed > 0) ? -1 : 1;
                Car reverse(current.position, reverseSpeed);
                if (abs(reverse.position) <= 2 * target && !visited.count(reverse)) {
                    q.push(reverse);
                    visited.insert(reverse);
        }   
    }
    steps++;
        }
    return 0;
    
    }
};