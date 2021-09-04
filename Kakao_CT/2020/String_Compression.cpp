#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000;
    int length = 1;
    int index;
        
    while(length <= s.length() / 2)
    {
     	string temp;
        index = length;
        
        int cmp_index = 0;
        int cnt = 1;

        string cmp = s.substr(0, length); 
        while(index < s.length())
        {
            if(s.substr(index, length) != cmp)
            {
                if(cnt != 1)
                {
                	temp += to_string(cnt);
                 	cnt = 1;                   
                }

				temp += cmp;
				cmp_index = index;

                cmp = s.substr(cmp_index, length);
                index = cmp_index + length;
            }
                
            else
            {
                cnt++;
                index += length;
            }
        }

		if(cnt != 1)
			temp += to_string(cnt);

		temp += cmp;
            
        if(answer > temp.length())
            answer = temp.length();
        
        length++; 
    }

	if(s.length() == 1)
		answer = 1;
    
    return answer;
}

int main()
{
	string input;
	cin >> input;

	cout << solution(input);

	return 0;
}
	
