#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;
    
    vector <int> longest_chain_from(length + 1, 1);
    for(int i = length - 1; i >= 1; i--)
    {
        if(S[i - 1] == '<')
        {
            longest_chain_from[i] = 1 + longest_chain_from[i + 1];
        }
    }
    
    vector <int> shortest_lis(length + 1);
    for(int i = length, last = 1; i >= 1; last++)
    {
        int j = i;
        for(j = i; j >= 1 && longest_chain_from[j] + 1 == longest_chain_from[j - 1]; j--)
        {   //cout << "J = " << j << "\n";
            last++;
        }
        
        shortest_lis[i] = last;
        
        //cout << "J = " << j << " i = " << i << "\n";
        for(int k = i - 1; k >= j; k--)
        {
            shortest_lis[k] = shortest_lis[k + 1] - 1;
        }
        
        i = j - 1;
    }
    
    for(int i = 1; i <= length; i++)
    {
        cout << shortest_lis[i] << " ";
    }
    
    cout << "\n";
    
    vector <int> longest_lis(length + 1);
    for(int i = 1, last = 1; i <= length; i++, last++)
    {
        int j = i;
        for(j = i; (j <= length - 1 && S[j - 1] == '>'); j++)
        {
            last++;
        }
        //cout << "J = " << j << "\n";
        longest_lis[i] = last;
        for(int k = i + 1; k <= j; k++)
        {
            longest_lis[k] = longest_lis[k - 1] - 1;
        }
            
        i = j;
    }
    
    for(int i = 1; i <= length; i++)
    {
        cout << longest_lis[i] << " ";
    }
    
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
