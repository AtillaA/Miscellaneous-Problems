import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        Set<String> corners = new HashSet<>(); // to track unique corners
        int totalArea = 0;

        // initialize bounding rectangle coordinates
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;

        for (int[] rect : rectangles) {
            // assign values
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];

            // update the bounding rectangle
            minX = Math.min(minX, x1);
            minY = Math.min(minY, y1);
            maxX = Math.max(maxX, x2);
            maxY = Math.max(maxY, y2);

            totalArea += (x2 - x1) * (y2 - y1); // add the area of current rectangle

            // add/remove corners
            String[] rectCorners = {
                x1 + "," + y1, // bottom-left
                x1 + "," + y2, // top-left
                x2 + "," + y1, // bottom-right
                x2 + "," + y2  // top-right
            };

            for (String corner : rectCorners) {
                if (!corners.add(corner)) { // if the corner is already in the set
                    corners.remove(corner); // remove the corner (cancel phase)
                }
            }
        }

        // if the total area matches the bounding rectangle's area
        int boundingArea = (maxX - minX) * (maxY - minY);
        if (totalArea != boundingArea) {
            return false;
        }

        // if the set contains exactly the four corners of the bounding rectangle
        if (corners.size() != 4 || 
            !corners.contains(minX + "," + minY) || 
            !corners.contains(minX + "," + maxY) || 
            !corners.contains(maxX + "," + minY) || 
            !corners.contains(maxX + "," + maxY)) {
            return false;
        }

        return true; // otherwise
    }
}
