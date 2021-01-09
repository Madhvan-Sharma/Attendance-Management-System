#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

//Made by Madhvan
class user{
    private:
        string username,password;
    public:
        int adminLogin();
        int adminDisplay();
        int teacherlogin();
        int studentDisplay();
        int studentLogin();
};