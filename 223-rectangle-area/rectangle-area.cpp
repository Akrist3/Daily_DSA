class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,int bx1, int by1, int bx2, int by2) {

        // Area of rectangle A
        int areaA = (ax2 - ax1) * (ay2 - ay1);

        // Area of rectangle B
        int areaB = (bx2 - bx1) * (by2 - by1);

        // Overlapping width
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1);

        // Overlapping height
        int overlapHeight = min(ay2, by2) - max(ay1, by1);

        int overlapArea = 0;

        if (overlapWidth > 0 && overlapHeight > 0) {
            overlapArea = overlapWidth * overlapHeight;
        }

        return areaA + areaB - overlapArea;
    }
};