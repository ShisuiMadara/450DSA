#define tii tuple<int, int, int>
#define pii pair<int, int>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pii> adjList[n];
        for(auto& flight: flights){
            int source = flight[0], dest = flight[1], price = flight[2];
            adjList[source].push_back({dest, price});
        }
        return dijkstraVariation(adjList, n, src, dst, k);
    }
    
    int dijkstraVariation(vector<pii> adjList[], int n, int node, int dst, int k){
        priority_queue<tii, vector<tii>, greater<tii>> minHeap;
        vector<int> stops(n, INT_MAX), distance(n, INT_MAX);
        
        int minDist = INT_MAX;
        stops[node] = 0;
        distance[node] = 0;
        minHeap.push({0,node,0});
        
        while(!minHeap.empty()){
            auto [curDist, curNode, curStops] = minHeap.top();
            
            minHeap.pop();
            if(curNode == dst) return curDist;
            if(curStops == k+1) continue;
            
            auto neighbors = adjList[curNode];
            for(auto& neighborPair :neighbors){
                int neighbor = neighborPair.first, edgeWt = neighborPair.second;
                int nextDistance = curDist + edgeWt, nextStops = curStops+1;
                
                //This if check is same as normal Dijkstraz: Don't forget to update both distance and stops.
                if(distance[neighbor] > nextDistance ){
                    distance[neighbor] = nextDistance;
                    stops[neighbor] = nextStops;
                    minHeap.push({nextDistance, neighbor, nextStops});
                }
                
                //This is main variation from Dijkstra: Don't forget to update both distance and stops.
                else if(nextStops < stops[neighbor]){
                    distance[neighbor] = nextDistance;
                    stops[neighbor] = nextStops;
                    minHeap.push({nextDistance, neighbor, nextStops});
                }
            }
        }
        return -1;
    }
};