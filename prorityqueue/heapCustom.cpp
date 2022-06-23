#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Student
{
public:
    string name;
    int height;
    Student(string name, int height)
    {
        this->name = name;
        this->height = height;
    }
    void display()
    {
        cout << name << " , " << height << endl;
    }
};
class Compare
{
public:
    bool operator()(Student &s1, Student &s2)
    {
        return s1.height < s2.height; // max heap
    }
};
int main()
{

    vector<Student> v = {{"harshit", 19}, {"nikita", 18}, {"jes", 29}};
    priority_queue<Student, vector<Student>, Compare> pq;

    for(Student x : v)pq.push(x);

    while(pq.size() > 0)
    {
        cout << pq.top().name << "," << pq.top().height << endl;
        pq.pop();
    }

}