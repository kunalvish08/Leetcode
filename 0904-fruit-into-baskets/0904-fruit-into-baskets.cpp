class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0 ; 
        int maxLenght = 0 ; 
        unordered_map < int , int > freq ;

        for(int right = 0 ;  right < n ; right++) {

            freq[fruits[right]]++ ; 

            while(freq.size() > 2 ) {
                freq[fruits[left]]-- ; 

                if( freq[fruits[left]] == 0)
                freq.erase(fruits[left]);

                left++ ; 
            }
            maxLenght = max(maxLenght , right - left + 1 );
        } 
      return maxLenght; 
    }
};