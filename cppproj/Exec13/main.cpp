#include <iostream>
#include "tabtenn0.h"

using namespace std;

int main()
{
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    RatedPlayer rplayer1(1140, "Mellory", "Duck", true);
    RatedPlayer rplayer2(4445, player2);

    TableTennisPlayer &rt = rplayer1;
    rt.Name();
    cout << endl;

    TableTennisPlayer *pt = &rplayer2;
    pt->Name();
    cout << endl;

    rplayer1.Name();
    cout << ", rating: " << rplayer1.Rating();
    cout << endl;

    rplayer2.Name();
    cout << ", rating: " << rplayer2.Rating();
    cout << endl;

    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();

    if (player2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    return 0;
}
