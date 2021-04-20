#ifndef LANGUAGEINFO_H
#define LANGUAGEINFO_H
#include "Languages.h"

#include <QString>

class LanguageInfo
{
public:
    LanguageInfo();
    LanguageInfo(Category category);
    void setDescription(QString description);
    void setWeeksToLearn(int weeks);
    void setHoursToLearn(int hours);

    QString getDescription();
    int getWeeksToLearn();
    int getHoursToLearn();


private:
    QString description_;
    int weeksToLearn_;
    int hoursToLearn_;

};



#endif // LANGUAGEINFO_H
