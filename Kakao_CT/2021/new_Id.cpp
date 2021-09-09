#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // step 1 & 2
    for(int i = 0; i < new_id.length(); i++)
    {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
	        new_id[i] += ('a' - 'A');
        
        else if(new_id[i] >= 'a' && new_id[i] <= 'z')
                continue;
        
        else if(new_id[i] >= '0' && new_id[i] <= '9')
                continue;
        
        else if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            continue;
        
        else
            new_id[i] = '*';
    }
    
    // step 3 & 4
    for(int i = 0; i < new_id.length(); i++)
    {
        if(new_id[i] == '*')
            continue;
        
        if(new_id[i] == '.')
        {
            if(answer.length() == 0 || answer.back() == '.')
                continue;
        }
        
       	answer += new_id[i];
    }
    
    // step 4
    if(answer.back() == '.')
		answer.erase(answer.length() - 1, 1);            
    
    // step 5
    if(answer.empty())
        answer += "a";
    
    // step 6
    if(answer.length() >= 16)
        answer.erase(15, answer.length() - 15);
    
    if(answer.back() == '.')
		answer.erase(answer.length() - 1, 1);            
    
    // step 7
    if(answer.length() <= 2)
    {
        while(answer.length() != 3)
        {
            answer += answer.back(); 
        }
    }
    
    return answer;
}
