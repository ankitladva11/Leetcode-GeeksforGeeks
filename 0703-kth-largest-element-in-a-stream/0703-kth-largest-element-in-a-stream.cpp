class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int m_k;
    KthLargest(int k, vector<int>& nums) {
        m_k=k;
        for(int x:nums){
          add(x);
        }
    }
    
    int add(int val) {
       if(minHeap.size()<m_k){
         minHeap.push(val);
       }else{
         if(val>minHeap.top()){
           minHeap.pop();
           minHeap.push(val);
         }
       }
      return minHeap.top(); 
    }
};