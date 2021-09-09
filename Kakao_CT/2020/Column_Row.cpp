#include <string>
#include <vector>
#include <set>

#define has(a) (building.find(v[(a)])!=building.end())
#define COLUMN 0
#define ROW 1

using namespace std;

bool isValid(set<vector<int>> building)
{
    set<vector<int>>::iterator it;
    for(it = building.begin(); it != building.end(); it++)
    {
        int x = (*it)[0], y = (*it)[1], type = (*it)[2];
		if(type == COLUMN)
        {
            vector<int> v[3] = {{x, y - 1, COLUMN}, {x - 1, y, ROW}, {x, y, ROW}};
            if(y == 0 || has(0) || has(1) || has(2))
                continue;
            return false;
        }
        
        else
        {
            vector<int> v[4] = {{x, y - 1, COLUMN}, {x + 1, y - 1, COLUMN}, {x + 1, y, ROW}, {x - 1, y, ROW}};
            if(has(0) || has(1) || has(2) && has(3))
                continue;
            return false;
        }   
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> building;
    
    for(int i = 0; i < build_frame.size(); i++)
    {
        vector<int> v = {build_frame[i][0], build_frame[i][1], build_frame[i][2]};
       	if(build_frame[i][3] == 1)
        {
            building.insert(v);
            if(!isValid(building)) building.erase(v);
        }
        
        else
        {
            building.erase(v);
          	if(!isValid(building)) building.insert(v);
        }
    }
    
    set<vector<int>>::iterator it;
    for(it = building.begin(); it != building.end(); it++)
    {
		answer.push_back(*it);
    }
    
    return answer;
}
