#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

float realt = 0;
float firstt = 0;
string sp = " ";
vector<string> output;

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

bool ifcoll(float t, string obj1, string obj2)
{
    float ct1, ct2, newx1, newx2, newy1, newy2;
    vector<float> position1;
    vector<float> velocity1;
    string object1 = obj1;
    string name1;
    float x1, y1, xv1, yv1;
    istringstream is(object1);
    is>>name1>>x1>>y1>>xv1>>yv1;

    vector<float> position2;
    vector<float> velocity2;
    string object2 = obj2;
    string name2;
    float x2, y2, xv2, yv2;
    istringstream iss(object2);
    iss>>name2>>x2>>y2>>xv2>>yv2;

    float a = xv1*xv1-xv1*xv2+xv2*xv2+yv1*yv1-yv1*yv2+yv2*yv2;
    float b = 2*(x1*xv1-x1*xv2-x2*xv1+x2*xv2+y1*yv1-y1*yv2-y2*yv1+y2*yv2);
    float c = x1*x1-2*x1*x2+x2*x2+y1*y1-2*y1*y2+y2*y2-100;
    float delta = b*b-4*a*c;
    float coll = (x1-x2)*(xv1-xv2)+(y1-y2)*(yv1-yv2);

    if (coll < 0)//collision happen
    {

        float newxv1 = xv1-(((xv1-xv2)*(x1-x2)+(yv1-yv2)*(y1-y2))/((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))*(x1-x2);
        float newyv1 = yv1-(((xv1-xv2)*(x1-x2)+(yv1-yv2)*(y1-y2))/((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))*(y1-y2);
        float newxv2 = xv2-(((xv2-xv1)*(x2-x1)+(yv2-yv1)*(y2-y1))/((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))*(x2-x1);
        float newyv2 = yv2-(((xv2-xv1)*(x2-x1)+(yv2-yv1)*(y2-y1))/((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))*(y2-y1);

        if (delta == 0||delta>0)
        {
            if(delta == 0)
            {
                realt = ct1 = ct2 = (-b+sqrt(delta))/(2*a);
            }
            else
            {
                ct1 = (-b+sqrt(delta))/(2*a);
                ct2 = (-b-sqrt(delta))/(2*a);

                if (ct1<ct2 && ct1>0)
                    realt = ct1;
                if (ct1>ct2 && ct2>0)
                    realt = ct2;
            }
            if(realt < firstt)
                firstt = realt;
        }
        return true;
    }
    else
    {
        return false;
    }
}

string calColl(float t, string obj1, string obj2)
{
    float ct1, ct2, newx1, newx2, newy1, newy2, T;
    vector<float> position1;
    vector<float> velocity1;
    string object1 = obj1;
    string name1;
    float x1, y1, xv1, yv1;
    istringstream is(object1);
    is>>name1>>x1>>y1>>xv1>>yv1;

    vector<float> position2;
    vector<float> velocity2;
    string object2 = obj2;
    string name2;
    float x2, y2, xv2, yv2;
    istringstream iss(object2);
    iss>>name2>>x2>>y2>>xv2>>yv2;

    float a = xv1*xv1-xv1*xv2+xv2*xv2+yv1*yv1-yv1*yv2+yv2*yv2;
    float b = 2*(x1*xv1-x1*xv2-x2*xv1+x2*xv2+y1*yv1-y1*yv2-y2*yv1+y2*yv2);
    float c = x1*x1-2*x1*x2+x2*x2+y1*y1-2*y1*y2+y2*y2-100;
    float delta = b*b-4*a*c;
    float coll = (x1-x2)*(xv1-xv2)+(y1-y2)*(yv1-yv2);
}

string calNoColl(float t, string obj1, string obj2)
{
    float ct1, ct2, newx1, newx2, newy1, newy2, T;
    string input1, input2;

    vector<float> position1;
    vector<float> velocity1;
    string object1 = obj1;
    string name1;
    float x1, y1, xv1, yv1;
    istringstream is(object1);
    is>>name1>>x1>>y1>>xv1>>yv1;

    vector<float> position2;
    vector<float> velocity2;
    string object2 = obj2;
    string name2;
    float x2, y2, xv2, yv2;
    istringstream iss(object2);
    iss>>name2>>x2>>y2>>xv2>>yv2;
    T = t;
    newx1 = x1+T*xv1;
    newy1 = y1+T*yv1;
    newx2 = x2+T*xv2;
    newy2 = y2+T*yv2;

    input1=name1+sp+to_string(newx1)+sp+to_string(newy1)+sp+to_string(xv1)+sp+to_string(yv1);
    input2=name2+sp+to_string(newx2)+sp+to_string(newy2)+sp+to_string(xv2)+sp+to_string(yv2);

    if(find(output.begin(),output.end(),input1) == output.begin())
        output.push_back(input1);
    if(find(output.begin(),output.end(),input2) == output.begin())
        output.push_back(input2);
    /*cout<<name1<<" "<<newx1<<" "<<newy1<<" "<<xv1<<" "<<yv1<<endl;
    cout<<name2<<' '<<newx2<<" "<<newy2<<" "<<xv2<<" "<<yv2<<endl;*/
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
        float a = stringToNum<float>(t_list[i]);
        nt_list.push_back(a);
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
        firstt = *i;
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
            realt = *i;
            for (int j = 0; j < obj_list.size(); j++)
            {
                for (int k = 1; k < obj_list.size(); k++)
                {
                    string object1 = obj_list[j];
                    string object2 = obj_list[k];
                    if(ifcoll(realt, object1, object2) == true)
                    /*if(ifcoll(realt, object1, object2) == true)
                        cout<<"Collision"<<endl;
                    else
                        calNoColl(realt, object1, object2);*/
                }
            }
        }
        /*for(int n=0;n!=output.size();n++)
        {
            cout<<output[n]<<endl;*/
        }
    }
    /*std::cout << *i << ' ';*/
    cout << "end"<<endl;
    return 0;
}
