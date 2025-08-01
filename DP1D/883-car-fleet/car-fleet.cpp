class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        for(int i=0;i<position.size();i++){
            pair<int,double> temp ={position[i],(double)(target-position[i])/speed[i]};
            cars.push_back(temp);
        } 
        sort(cars.begin(),cars.end());
        int count=0;
        double prev=0;
        for(int i=cars.size()-1;i>=0;i--){
            if(cars[i].second>prev){
                count++;
                prev=cars[i].second;
            }
        }
        return count;
    }
};