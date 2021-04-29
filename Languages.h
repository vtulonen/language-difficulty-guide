#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <QStringList>
#include <QObject>

// The Foreign Service Institute (FSI) has created a list to show the approximate time you need to learn a specific language as an English speaker

//Source https://effectivelanguagelearning.com/language-guide/language-difficulty/

struct Languages
{
    QStringList easiest { QObject::tr("Afrikaans"), QObject::tr("Danish"), QObject::tr("Dutch"), QObject::tr("French"), QObject::tr("Italian"), QObject::tr("Norwegian"), QObject::tr("Portuguese"), QObject::tr("Romanian"), QObject::tr("Spanish"), QObject::tr("Swedish") };
    QStringList easy { QObject::tr("German")};
    QStringList medium { QObject::tr("Indonesian"), QObject::tr("Malaysian"),	"Swahili"};
    QStringList hard {     QObject::tr("Albanian"),     QObject::tr("Amharic"),     QObject::tr("Armenian"),     QObject::tr("Azerbaijani"),     QObject::tr("Bengali"),     QObject::tr("Bosnian"),     QObject::tr("Bulgarian"),     QObject::tr("Burmese"),     QObject::tr("Croatian"),     QObject::tr("Czech"),     QObject::tr("Estonian"),     QObject::tr("Finnish"),     QObject::tr("Georgian"),     QObject::tr("Greek"),     QObject::tr("Hebrew"),     QObject::tr("Hindi"),     QObject::tr("Hungarian"),     QObject::tr("Icelandic"),     QObject::tr("Khmer"),     QObject::tr("Lao"),     QObject::tr("Latvian"),     QObject::tr("Lithuanian"),     QObject::tr("Macedonian"),     QObject::tr("Mongolian"),     QObject::tr("Nepali"),     QObject::tr("Pashto"),     QObject::tr("Persian"),     QObject::tr("Farsi"),     QObject::tr("Tajik"),     QObject::tr("Polish"),     QObject::tr("Russian"),     QObject::tr("Serbian"),     QObject::tr("Sinhala"),     QObject::tr("Slovak"),     QObject::tr("Slovenian"),     QObject::tr("Tagalog"),     QObject::tr("Thai"),     QObject::tr("Turkish"),     QObject::tr("Ukrainian"),     QObject::tr("Urdu"),     QObject::tr("Uzbek"),     QObject::tr("Vietnamese"),     QObject::tr("Xhosa"),     QObject::tr("Zulu")};
    QStringList hardest { QObject::tr("Arabic"), QObject::tr("Cantonese"), QObject::tr("Mandarin"), QObject::tr("Japanese"), QObject::tr("Korean")};
    QStringList all = easiest + easy + medium + hard + hardest;
};

struct LanguagesNoTr
{
    QStringList easiest {"Afrikaans", "Danish", "Dutch", "French", "Italian", "Norwegian", "Portuguese", "Romanian", "Spanish", "Swedish"};
    QStringList easy { "German"};
    QStringList medium { "Indonesian", "Malaysian",	"Swahili"};
    QStringList hard {     "Albanian",     "Amharic",     "Armenian",     "Azerbaijani",     "Bengali",     "Bosnian",     "Bulgarian",     "Burmese",     "Croatian",     "Czech",     "Estonian",     "Finnish",     "Georgian",     "Greek",     "Hebrew",     "Hindi",     "Hungarian",     "Icelandic",     "Khmer",     "Lao",     "Latvian",     "Lithuanian",     "Macedonian",     "Mongolian",     "Nepali",     "Pashto",     "Persian",     "Farsi",     "Tajik",     "Polish",     "Russian",     "Serbian",     "Sinhala",     "Slovak",     "Slovenian",     "Tagalog",     "Thai",     "Turkish",     "Ukrainian",     "Urdu",     "Uzbek",     "Vietnamese",     "Xhosa",     "Zulu" };
    QStringList hardest { "Arabic", "Cantonese", "Mandarin", "Japanese", "Korean" };
    QStringList all = easiest + easy + medium + hard + hardest;
};

enum class Category
{
  easiest,
  easy,
  medium,
  hard,
  hardest,
  all,
};


#endif // LANGUAGES_H
