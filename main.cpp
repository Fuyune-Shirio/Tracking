
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Option) jeder späteren
    veröffentlichten Version, weiterverbreiten und/oder modifizieren.

    Dieses Programm wird in der Hoffnung, dass es nützlich sein wird, aber
    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License für weitere Details.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
 */



int main()
{
        int sel;
        char ex;
cout << setfill('#') << setw(52)<< "" << endl;
cout << setfill('#') << setw(1) << "" << "  Author: Daniele Wohlgezogen aka. Fuyune Shirio  " << setfill('#') << setw(1) <<"" << endl;
cout << setfill('#') << setw(1) << "" << "  Contact: Fuyune@live.de or E.V.E Ingame mail    " << setfill('#') << setw (1) << "" << endl;
cout << setfill('#') << setw(1) << "" << "  Programm version 0.0.1                          " << setfill('#') << setw(1) << "" << endl;
cout << setfill('#') << setw(52)<< "" << endl;
cout << endl;

    do
    {
    cout << endl;
    cout << "Please choose your operation!" << endl;
    cout << "1: Turret Tracking\n";
    cout << "2: Missiles Damage\n";
    cin >> sel;
    switch(sel)
    {
        case 1:

                double sigres,sigrad,trans,tracking,range,optimal,falloff;
                double blob,hit,first,second;

                cout <<"please insert target signature resoluton: ";
                cin >> sigres;
                cout << "please insert target signature radius: ";
                cin >> sigrad;
                cout << "please insert Target transversal vel.: ";
                cin >> trans;
                cout << "please insert range to target: ";
                cin >> range;
                cout << "please insert your turret optimal range: ";
                cin >> optimal;
                cout << "please insert your turret falloff range: ";
                cin >> falloff;
                cout << "please insert your turret trackingspeed: ";
                cin >> tracking;
                cout << endl;
                first=pow(((trans*sigres)/(tracking*range*sigrad)),2.0);
                second=pow(((max(0.0,(range-optimal)))/falloff),2.0);
                blob=first+second;
                hit=pow(0.5,blob);
                cout << "hitchance: " << hit << endl;
                cout << endl;
                break;


        case 2:
            double damage,basedmg,sigradious,explrad,explvel,targvel,drf;
            cout << "please insert Missiles base damage: ";
            cin >> basedmg;
            cout << "please insert Missiles explosion radius: ";
            cin >> explrad;
            cout << "please insert Missiles explosion velocity: ";
            cin >> explvel;
            cout << "please insert signature radius: ";
            cin >> sigradious;
            cout << "please insert target velocity: ";
            cin >> targvel;
            cout << "please insert damage reduction factor: ";
            cin >> drf;
            damage=basedmg*min(min(1.0,(sigradious/explrad)),pow(((sigradious/explrad)*(explvel/targvel)),((log(drf))/(log(5.5)))));
            cout << "Average missiles damage: " << damage << endl;
            break;

        default:
            cout << "wrong input!\n";
        }

    cout << "do you want to continue? (y/n)";
    cin >> ex;
    system("cls");
    }

while((ex !='n')&&(ex !='N'));
    cout << endl;
    cout << endl;
    cout << "cya arround and thank's using my tools!";
    cout << endl;
    cout << endl;
    system("pause");

}
