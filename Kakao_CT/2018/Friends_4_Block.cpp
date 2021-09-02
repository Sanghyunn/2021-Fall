#include <iostream>
#include <string>
#include <vector>

#define MAX 31

using namespace std;

int m, n;
int answer = 0;
vector<string> board;

int four_square(int a, int b)
{   
    if(a + 1 >= m || b + 1 >= n)
        return 0;
    
    int ret = 0;
    
    for(int i = 1; i < 4; i++)
    {   
        if(toupper(board[a][b]) != toupper(board[a + i / 2][b + i % 2]))
            return 0;
    }
    
    for(int i = 0; i < 4; i++)
    {   
        if(board[a + i / 2][b + i % 2] <= 'Z')
        {   
            board[a + i / 2][b + i % 2] += ('a' - 'A');
            ret += 1;
        }
    }
    
    return ret;
}

void arrange()
{   
    for(int i = m - 1; i > 0; i--)
    {   
        for(int j = n - 1; j >= 0; j--)
        {   
            if(board[i][j] >= 'a')
            {   
                int k = 1;
                while(board[i - k][j] >= 'a' && i - k > 0)
                {   
                    k++;
                }
                
                char temp = board[i][j];
                board[i][j] = board[i - k][j];
                board[i - k][j] = temp;
            }
        }
    }
}
        
int solution()
{
    int answer = 0;
    int cnt = 1;

    while(cnt != 0)
    {   
        cnt = 0;
        for(int i = 0; i < m; i++)
        {   
            for(int j = 0; j < n; j++)
            {   
                cnt += four_square(i, j); 
            }   
        }   

        answer += cnt;

        arrange();
    }   

    return answer;
}

int main()
{
    cin >> m >> n;

    string input;
    for(int i = 0; i < m; i++)
    {   
        cin >> input;
        board.push_back(input);
    }   

    cout << solution();

    return 0;
}
