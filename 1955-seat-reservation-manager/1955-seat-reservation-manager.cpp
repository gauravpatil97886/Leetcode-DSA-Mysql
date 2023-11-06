class SeatManager {
public:
    priority_queue<int,vector<int>, greater<int>> pq; 
    SeatManager(int n) {
        for(int i=1; i<=n; i++) pq.push(i); 
    }
    
    int reserve() {
        int t = pq.top(); pq.pop(); 
        return t; 
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber); 
    }
};