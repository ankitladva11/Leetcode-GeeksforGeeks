class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // vector <int> flow;
        // flow=flowebed;
        if(n==0){
            return true;
        }
        int size=flowerbed.size();
         if(size<3 && flowerbed[0]==1){
            return false;
        }
        if(size==2 && flowerbed[1]==1){
            return false;
        }
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
       
        
        
        for(int i=1;i<size+1;i++){
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]!=1){
                n--;
                flowerbed[i]=1;
            }
        }
        if(n<1 ){
            return true;
        }
        return false;
    }
};