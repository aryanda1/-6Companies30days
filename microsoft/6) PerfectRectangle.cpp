class Solution {
    long dd = 2e5+1;//maxx value
    int c = 1e5;//value to be added to each co-odinates
    long co_ord[4];
    
    long Area(vector<int>&a){
        return (a[2]-a[0])*(long)(a[3]-a[1]);
    }
    
    void tr(vector<int>&a){
        co_ord[0] =  dd*(a[0]+c)+a[1]+c;
        co_ord[1] =  dd*(a[0]+c)+a[3]+c;
        co_ord[2] =  dd*(a[2]+c)+a[1]+c;
        co_ord[3] =  dd*(a[2]+c)+a[3]+c;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<long>corner;
        long area = 0;
        
        for(auto &rect:rectangles){
            area += Area(rect);
            tr(rect);
            for(int i = 0;i<4;i++)
                if(!corner.insert(co_ord[i]).second)
                    corner.erase(co_ord[i]);
        }
        if(corner.size()!=4) return 0;
        
        auto &rect = rectangles[0];
        rect = {INT_MAX,INT_MAX,INT_MIN,INT_MIN};
        for(auto &it:corner){
            int x = it/dd, y = it%dd;
            rect[0] = min(rect[0],int(x));
            rect[1] = min(rect[1],int(y));
            rect[2] = max(rect[2],int(x));
            rect[3] = max(rect[3],int(y));
        }
        return Area(rectangles[0])==area;
    }
};