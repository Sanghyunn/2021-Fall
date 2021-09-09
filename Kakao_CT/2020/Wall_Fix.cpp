#include <string>
#include <vector>
#include <algorithm>

#define MAX 201

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = MAX;
    int w_size = weak.size();
    
    weak.resize(2 * w_size);
    for(int i = w_size; i < weak.size(); i++)
    	weak[i] = weak[i - w_size] + n;
            
    sort(dist.begin(), dist.end());
    
    do
    {
    	for(int i = 0; i < w_size; i++)
    	{
            int start = weak[i];
            int finish = weak[i + w_size - 1];
            for(int j = 0; j < dist.size(); j++)
            {
               start += dist[j]; 
               if(start >= finish)
               {
                   answer = min(answer, j + 1);
                   break; 
               }
                
                int next = upper_bound(weak.begin(), weak.end(), start) - weak.begin();
                start = weak[next];
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
        
    if(answer == MAX) answer = -1;
    return answer;
}
