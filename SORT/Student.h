#ifndef SELECTION_STUDENT_H
#define SELECTION_STUDENT_H
#include<string>

using namespace std;

struct Student{
    string name;
    int score;
    bool operator<(const Student &otherStudent){
        return score < otherStudent.score; 
    };

    friend ostream& operator<<(ostream &os,const Student &student ){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    };
};

#endif