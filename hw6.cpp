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
        ///cout << t_list[i] << " ";
        float a = stringToNum<float>(t_list[i]);
        nt_list.push_back(a);
        cout<< nt_list[i] << endl;
        }
    nt_list.erase(nt_list.begin());//Erase the redundant 0

    std::string input;
    vector<string> obj_list;
    while (getline(std::cin, input))
    {
        if (input.empty())
            break;
        obj_list.push_back(input);
    }
    for (auto i = obj_list.begin(); i != obj_list.end(); ++i)
    std::cout << *i << ' ';
    cout << "end"<<endl;
    return 0;
}
