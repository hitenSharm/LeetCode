class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>wordsInt(words.size(),0);
		vector<int>wordLen(words.size(),0);
		for(int i=0;i<words.size();i++)
		{
			int word_int=0;
			for(int j=0;j<words[i].size();j++)
			{
				word_int=word_int|(1<<(words[i][j]-'a'));
				//this kinda makes a word exists array in int form
				//a=0
				//b=10
				//c=110 and so on
			}
			wordsInt[i]=word_int;//store the number formed
			wordLen[i]=words[i].size();
		}
		int ans=0;
		for(int i=0;i<words.size()-1;i++)
		{
			for(int j=i+1;j<words.size();j++)
			{
				if((wordsInt[i] & wordsInt[j])==0)//this cheks if any bit matches
				ans=max(ans,wordLen[i]*wordLen[j]);
			}
		}
		return ans;
    }
};