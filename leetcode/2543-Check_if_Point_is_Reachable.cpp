class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        
        while (targetX >= 1 && targetY >= 1) {
            while (targetX % 2 == 0) {
                targetX /= 2;
            }
            while (targetY % 2 == 0) {
                targetY /= 2;
            }
            if (targetX == 1 || targetY == 1) return true;
            if (targetX == targetY) return false;
            if (targetX > targetY) swap(targetX, targetY);
            targetY += targetX;
        }
        return targetX == 1 && targetY == 1;
    }
};
