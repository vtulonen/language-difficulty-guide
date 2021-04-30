#include "languageinfo.h"
#include <QObject>

LanguageInfo::LanguageInfo()
{

}
/**
 * @brief LanguageInfo::LanguageInfo contains description, and time to learn the language based on @category
 * @param category decides what values are created for the class
 */
LanguageInfo::LanguageInfo(Category category)
{
    switch(category)
    {
         case Category::easiest:
             setDescription(QObject::tr("language is closely related to English"));
             setHoursToLearn(600);
             setWeeksToLearn(24);
             break;

         case Category::easy:
             setDescription(QObject::tr("language is similar to English"));
             setHoursToLearn(750);
             setWeeksToLearn(30);
             break;

         case Category::medium:
            setDescription(QObject::tr("language has linguistic and/or cultural differences from English"));
            setHoursToLearn(900);
            setWeeksToLearn(36);
            break;

         case Category::hard:
            setDescription(QObject::tr("language has significant linguistic and/or cultural differences from English"));
            setHoursToLearn(1100);
            setWeeksToLearn(44);
            break;

         case Category::hardest:
            setDescription(QObject::tr("language is considered exceptionally difficult for native English speakers"));
            setHoursToLearn(2200);
            setWeeksToLearn(88);
            break;

         default:
            setDescription(QObject::tr("Unknown category"));
            setHoursToLearn(0);
            setWeeksToLearn(0);
    }

}

void LanguageInfo::setDescription(QString description)
{
    description_ = description;
}

void LanguageInfo::setWeeksToLearn(int weeks)
{
    weeksToLearn_ = weeks;
}

void LanguageInfo::setHoursToLearn(int hours)
{
    hoursToLearn_ = hours;
}

QString LanguageInfo::getDescription()
{
    return description_;
}

int LanguageInfo::getWeeksToLearn()
{
    return weeksToLearn_;
}

int LanguageInfo::getHoursToLearn()
{
    return hoursToLearn_;
}




