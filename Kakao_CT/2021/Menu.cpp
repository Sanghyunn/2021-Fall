#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> makeCourse(vector<string>& orders, int count)
{
    vector<string> ret; 
    
    vector<string> idx;
	vector<string>::iterator it;
    vector<int> cnt;
    string temp;
    for(int i = 0; i < orders.size(); i++)
    {
        for(int j = 0; j <= orders[i].length() - count; j++)
        {
	    	temp = orders[i].substr(j, count);
            
    		it = find(idx.begin(), idx.end(), temp);
	        if(it != idx.end())
	        	cnt[it - idx.begin()] += 1;
            
	        else
	        {
	        	idx.push_back(temp);     
	            cnt.push_back(1);
	        }
	    }
    }

    int max = 0;
    for(int i = 0; i < cnt.size(); i++)
    {
        if(cnt[i] > max)
        {
            max = cnt[i];
            ret.clear();
			
			cout << "wtf" << endl;
            ret.push_back(idx[i]);
        }
        
        else if(cnt[i] == max)
            ret.push_back(idx[i]);
    }
    
    return ret;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    vector<string> temp;
    for(int i = 0; i < course.size(); i++)
    {
	    temp = makeCourse(orders, course[i]);
        
        while(!temp.empty())
        {
			answer.push_back(temp.back());
            temp.pop_back();
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
	vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
	vector<int> course = {2,3,4};

	solution(orders, course);

	return 0;
}
