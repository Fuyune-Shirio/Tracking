
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

    Dieses Programm ist Freie Software: Sie k�nnen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Option) jeder sp�teren
    ver�ffentlichten Version, weiterverbreiten und/oder modifizieren.

    Dieses Programm wird in der Hoffnung, dass es n�tzlich sein wird, aber
    OHNE JEDE GEW�HRLEISTUNG, bereitgestellt; sogar ohne die implizite
    Gew�hrleistung der MARKTF�HIGKEIT oder EIGNUNG F�R EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License f�r weitere Details.

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
cout << setfill('#') << setw(1) << "" << "  Programm version 0.0.2                          " << setfill('#') << setw(1) << "" << endl;
cout << setfill('#') << setw(52)<< "" << endl;
cout << endl;

    do
    {
    cout << endl;
    cout << "Please choose your operation!" << endl;
    cout << "1: Turret Tracking\n";
    cout << "2: Missiles Damage\n";
    cout << "3: Effective Refining Yield\n";
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

        case 3:
            double Effective_Refining_Yield,Station_Equipment_Yield,Refining_Skill_Level,Refining_Efficiency_Skill_Level,Ore_Specific_Processing_Skill_Level,base_yield,take;
            cout << "please enter Station Equipment base Yield :";
            cin >> base_yield;
            cout <<"please enter the tax: ";
            cin >> take;
            cout << "please enter Refining Skill Level; ";
            cin >> Refining_Skill_Level;
            cout << "please enter Refining Efficiency Skill Level: ";
            cin >> Refining_Efficiency_Skill_Level;
            cout << "please enter Ore_Specific Processing Skill Level: ";
            cin >> Ore_Specific_Processing_Skill_Level;
            cout << endl;
            Station_Equipment_Yield=(base_yield/100)-(take/100);
            Effective_Refining_Yield = min(Station_Equipment_Yield + (0.375 * (1 + (Refining_Skill_Level * 0.02)) * (1 + (Refining_Efficiency_Skill_Level * 0.04)) * (1 + (Ore_Specific_Processing_Skill_Level * 0.05))), 1.00);
            cout << Effective_Refining_Yield*100 << "%";
            cout << endl << endl;
            break;

        default:
            cout << "wrong input!\n";
        }

    cout << "do you want to continue? (y/n): ";
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
