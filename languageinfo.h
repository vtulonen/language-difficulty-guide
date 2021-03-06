#ifndef LANGUAGEINFO_H
#define LANGUAGEINFO_H
#include "Languages.h"

#include <QString>

/**
 * @brief The LanguageInfo class
 *
 *  Given a @category as constructor paramerter, it creates
 *  information about the language catageory.
 */

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
