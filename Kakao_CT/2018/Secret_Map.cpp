#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++)
    {
        string temp;
        for(int j = pow(2, n - 1); j >= 1; j /= 2)
        {
            if(arr1[i] / j == 0 && arr2[i] / j == 0)
				temp += " ";           
            
            else
            	temp += "#";
            
            arr1[i] %= j;
            arr2[i] %= j;
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}

int main()
{
    int n; cin >> n;
    
   	int input;
    vector<int> arr1;
   	for(int i = 0; i < n ; i++)
    {
        cin >> input;
       	arr1.push_back(input);
    }
    
    vector<int> arr2;
   	for(int i = 0; i < n ; i++)
    {
        cin >> input;
       	arr2.push_back(input);
    }

    vector<string> ans = solution(n, arr1, arr2);
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}
