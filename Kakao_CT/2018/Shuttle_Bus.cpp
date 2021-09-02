#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(string a, string b)
{
    if(stoi(a.substr(0, 2)) == stoi(b.substr(0, 2)))
        return stoi(a.substr(3, 2)) <= stoi(b.substr(3, 2));
    return stoi(a.substr(0, 2)) < stoi(b.substr(0, 2));
}

bool Can_Bus(string crew, int bus_time[2])
{   
    if(stoi(crew.substr(0, 2)) == bus_time[0])
        return stoi(crew.substr(3, 2)) <= bus_time[1];
    
    return stoi(crew.substr(0, 2)) <= bus_time[0];
}

string digit_Time(int h, int m)
{   
    string ret;
    
    if(h < 10) ret += '0';
    ret += to_string(h);
    
    ret += ':';
    
    if(m < 10) ret += '0';
    ret += to_string(m);
    
    return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    sort(timetable.begin(), timetable.end(), cmp);
    
	int bus_time[2] = {9, 0};
    int crew_index = 0, bus_cnt;
    for(int i = 1; i <= n; i++)
    {   
		bus_cnt = 0;

		cout << "===== " << bus_time[0] << " : " << bus_time[1] << " =====" << endl;
		while(crew_index < timetable.size() && Can_Bus(timetable[crew_index], bus_time))
		{
			cout << timetable[crew_index] << endl;
			crew_index++;
			bus_cnt++;

			if(bus_cnt == m) break;
		}

		if(i != n && crew_index < timetable.size())
		{
			bus_time[1] += t;
			if(bus_time[1] >= 60)
			{
				bus_time[1] -= 60;
				bus_time[0] += 1;
			}
		}
	}

	if(bus_cnt != m)
		answer += digit_Time(bus_time[0], bus_time[1]);

	else
	{
		int hour = stoi(timetable[crew_index - 1].substr(0, 2));
		int minute = stoi(timetable[crew_index - 1].substr(3, 2));
		
		if(minute == 0)
		{
			hour -= 1;
			minute = 60;
		}

		answer += digit_Time(hour, minute - 1);
	}


    return answer;
}

int main()
{
    int n, t, m; cin >> n >> t >> m;

    vector<string> timetable;

    string input;
    while(1)
    {  
        cin >> input;
        timetable.push_back(input);

        if(cin.get() == '\n') break;
    }  

    cout << solution(n, t, m, timetable);

    return 0;
}


