class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        int fleet = 0;
        double LastTime = 0;

        for (auto& car : cars) {
            int pos = car.first;
            int speed = car.second;

            double time = (double)(target - pos) / speed;

            if (time > LastTime) {
                fleet++;
                LastTime = time;
            }
        }
        return fleet;
    }
};