class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        using ll = long long;
        int maxX=INT_MIN;
        int maxY=INT_MIN;
        int minX=INT_MAX;
        int minY=INT_MAX;
        ll area=0;
        set<pair<int,int>> st;
        for(auto r : rectangles){
            int x1=r[0]   ,y1=r[1];
            int x2=r[2]   ,y2=r[3];
            minX=min(minX,x1);
            minY=min(minY,y1);
            maxX=max(maxX,x2);
            maxY=max(maxY,y2);
            vector<pair<int,int>> v ={{x1,y1},{x1,y2},{x2,y1},{x2,y2}} ;
            for(auto& c : v){
                if (st.count(c)) {
                    st.erase(c); // Cancel if already present
                } else {
                    st.insert(c); // Add if not present
                }
            }
            area+=(ll)(x2-x1)*(y2-y1);
        }
        ll boundingArea = (ll)(maxX - minX) * (maxY - minY);
        if(area!=boundingArea) return false;
        if(st.size()!=4) return false;
        if (!st.count({minX, minY}) ||
            !st.count({minX, maxY}) ||
            !st.count({maxX, minY}) ||
            !st.count({maxX, maxY})) {
            return false;
        }
        return true;
        
    }
};