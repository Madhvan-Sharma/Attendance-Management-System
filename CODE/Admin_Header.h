#include "user.h"

class Admin : public user
{   private:
        string username,password;
    public:
        int deleteAll();
        int ListofStuds();
        int registerStudent();
};
