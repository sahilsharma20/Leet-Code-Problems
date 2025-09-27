class Solution {
public: 
    
    double distance(vector<int>&a, vector<int>&b){
        return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1])) ;
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();

        double area = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                double a = distance(points[i], points[j]); 
                for (int k = j + 1; k < n; k++) {
                    double b = distance(points[j], points[k]); 
                    double c = distance(points[k], points[i]);
                    
                    double cosTheta = (a*a + b*b - c*c) / (2*a*b);
                    double sinTheta = sqrt(1 - cosTheta*cosTheta);
                    double result = 0.5*a*b*sinTheta; 
                    area = max(area, result);
                }
            }
        }

        return area;
    }
};
