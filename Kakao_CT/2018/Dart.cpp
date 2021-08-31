#incude <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(string dartResult)
{
    int answer = 0;

	vector<int> scores;
	int i = 0;
	while(i != dartResult.length())
	{
		char current = dartResult[i];
		i++;

		if(current >= '0' && current <= '9')
		{
			int number = current - '0';
			if(current == '1' && dartResult[i] == '0')
			{
				i++;
				number = 10;
			}

			current = dartResult[i];
			i++;

			int c_score;
			switch(current)
			{
				case 'S' :
					c_score = number;
					break;

				case 'D' :
					c_score = number * number;
					break;
			
				case 'T' :
					c_score = number * number * number;
					break;
			}

			scores.push_back(c_score);

		}

		else
		{
			switch(current)
			{
				case '*' :
					scores[scores.size() - 1] *= 2;
					if(scores.size() != 1)
						scores[scores.size() - 2] *= 2;
					
					break;
					
				case '#' :
					scores[scores.size() - 1] *= -1;
					break;
			}
		}
	}

	while(!scores.empty())
	{
		answer += scores.back();
		scores.pop_back();
	}

    return answer;
}


int main()
{
	string input;
	cin >> input;

	cout << solution(input);

	return 0;
}
