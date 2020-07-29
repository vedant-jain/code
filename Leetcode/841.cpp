class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> toVisit;
        int room;        
        vector<int> unlocked(rooms.size(), 0);
        
        toVisit.push(0);
        
        while(!toVisit.empty()) {
            room = toVisit.front();
            toVisit.pop();
            
            if (!unlocked[room]) {
                unlocked[room] = 1;
                for (auto i: rooms[room]) {
                    toVisit.push(i);
                }
            }
        }
        
        int locked = -1;
        
        for (int i = 0; i < unlocked.size(); i++) {
            if (unlocked[i] == 0) {
                locked = i;
                break;
            }
        }
        
        return (locked == -1);
    }
};