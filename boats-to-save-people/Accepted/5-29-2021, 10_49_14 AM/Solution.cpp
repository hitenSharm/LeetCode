// https://leetcode.com/problems/boats-to-save-people

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:

void countSort(vector<int>& arr,int limit)
{
    int max = limit;
    int min = 0;
    int range = max - min + 1;
 
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
 
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
 

    int numRescueBoats(vector<int>& people, int limit) {
        // sort(people.begin(),people.end());
        countSort(people,limit);
        int i=0;
        int j=people.size()-1;
        int boats=0;
        while(i<=j)
        {
          if (people[i]+people[j]<=limit)
          {
            i++;
            j--;
            boats++;
            continue;
          }
          if(people[i]+people[j]>limit)
          {
            j--;
            boats++;
            continue;            
          }
        }
        return boats;
    }
};