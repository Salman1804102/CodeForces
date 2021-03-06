#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int move_1, move_2;
    string S;
    cin >> move_1 >> move_2 >> S;

    int length = 0;
    vector <int> segments;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '.')
        {
            length++;
        }

        if(S[i] != '.' || i == S.size() - 1)
        {
            if(length != 0)
            {
                segments.push_back(length);
            }

            length = 0;
        }
    }

    int bob_segments = 0, normal_segments = 0, big_segments = 0;
    int big_segment_size = 0;
    for(int i = 0; i < segments.size(); i++)
    {
        if(move_2 <= segments[i] && segments[i] < move_1)
        {
            bob_segments++;
        }

        if(2*move_2 <= segments[i])
        {
            big_segment_size = segments[i];

            big_segments++;
        }

        if(move_1 <= segments[i] && segments[i] < 2*move_2)
        {
            normal_segments++;
        }
    }

    if(bob_segments > 0 || big_segments > 1)
    {
        cout << "NO\n";

        return;
    }

    if(big_segments == 0)
    {
        cout << (normal_segments%2 == 1 ? "YES\n" : "NO\n");

        return;
    }

    int winning = false;
    for(int part_1 = 0; big_segment_size - move_1 - part_1 >= 0; part_1++)
    {
        int part_2 = big_segment_size - move_1 - part_1;

        if(part_1 >= 2*move_2 || (move_2 <= part_1 && part_1 < move_1)) continue;
        if(part_2 >= 2*move_2 || (move_2 <= part_2 && part_2 < move_1)) continue;


        if( (normal_segments + (part_1 >= move_1) + (part_2 >= move_1))%2 == 0)
        {
            winning = true;

            break;
        }
    }

    cout << (winning ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_tests;
    cin >> no_of_tests;

    while(no_of_tests--)
        solve();

    return 0;
}
