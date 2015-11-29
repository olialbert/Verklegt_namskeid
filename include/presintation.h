#ifndef PRESINTATION_H
#define PRESINTATION_H


class presintation
{
    public:
        presintation(string progName, string progGender, int progBirthday, int progAge);
        void getName();
    protected:
    private:
        string name;
        string gender;
        int birthday;
        int age;
};

#endif // PRESINTATION_H
