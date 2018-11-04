#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

void calonce(float t, float x, float y, float xv, float yv)
{
    float positionx = x + xv*t;
    float positiony = y + yv*t;

    cout<<positionx<<' '<<positiony<<' '<<xv<<' '<<yv<<endl;
}

string calmulti(float t, string obj1, string obj2)
{
    vector<float> position1;
    vector<float> velocity1;
    string object1 = obj1;
    string name1;
    float x1, y1, xv1, yv1;
    istringstream is(object1);
    is>>name1>>x1>>y1>>xv1>>yv1;
    position1.push_back(x1);position1.push_back(y1);
    velocity1.push_back(xv1);velocity1.push_back(yv1);

    vector<float> position2;
    vector<float> velocity2;
    string object2 = obj2;
    string name2;
    float x2, y2, xv2, yv2;
    istringstream iss(object2);
    iss>>name2>>x2>>y2>>xv2>>yv2;
    position2.push_back(x2);position2.push_back(y2);
    velocity2.push_back(xv2);velocity2.push_back(yv2);
    float coll = (position1-position2)*(velocity1-velocity2);
    if (coll < 0)
        cout<<"collision"<<endl;
    else
    {
    float v1 = velocity1 - (velocity1-velocity2)*(position1-position2)*(position1-position2)/((position1-position2)*(position1-position2))
    float v2 = velocity2 - (velocity2-velocity1)*(position2-position1)*(position2-position1)/((position2-position1)*(position2-position1))
    }
    cout<<position1[0]<<' '<<velocity1[0]<<endl;
    cout<<position2[0]<<' '<<velocity2[0]<<endl;
}
int main(int argc, char* argv[])
{
    vector<string> t_list;//save argus to the vector
    for (int i = 0; i < argc; i++){
        string tem (argv[i]);
        t_list.push_back(tem);
        }

    sort(t_list.begin(), t_list.end());//Sort the vector and convert elements to float
    vector<float> nt_list;
    for (int i = 0; i != t_list.size(); ++i){
        //cout << t_list[i] << " ";
        float a = stringToNum<float>(t_list[i]);
        nt_list.push_back(a);
        //cout<< nt_list[i] << endl;
        }
    nt_list.erase(nt_list.begin());//Erase the redundant 0

    std::string input;//Save object info.
    vector<string> obj_list;
    while (getline(std::cin, input))
    {
        if (input.empty())
            break;
        obj_list.push_back(input);
    }

    for (auto i = nt_list.begin(); i != nt_list.end(); ++i)
    {
        std::cout<< *i<< endl;
        cout<<obj_list.size()<<endl;
        if (obj_list.size() == 1)
        {
            string object = obj_list[0];
            string name;
            float x, y, xv, yv;
            istringstream is(object);
            is>>name>>x>>y>>xv>>yv;
            calonce(*i, x, y, xv, yv);
        }
        else
        {
            cout<<"Too long"<<endl;
            for (int j = 0; j < obj_list.size()-1 ; ++j)
            {
                string object1 = obj_list[j];
                string object2 = obj_list[j+1];
                calmulti(*i, object1, object2);
                //cout<<name<<' '<<x<<' '<<y<<' '<<xv<<' '<<yv<<endl;
            }
        }
    }
    /*std::cout << *i << ' ';*/
    cout << "end"<<endl;
    return 0;
}
