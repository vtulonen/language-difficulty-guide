#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <QStringList>

// The Foreign Service Institute (FSI) has created a list to show the approximate time you need to learn a specific language as an English speaker

//Source https://effectivelanguagelearning.com/language-guide/language-difficulty/

struct Languages
{
    QStringList easiest {"Afrikaans", "Danish", "Dutch", "French", "Italian", "Norwegian", "Portuguese", "Romanian", "Spanish", "Swedish"};
    QStringList easy { "German"};
    QStringList medium { "Indonesian", "Malaysian",	"Swahili"};
    QStringList hard {     "Albanian",     "Amharic",     "Armenian",     "Azerbaijani",     "Bengali",     "Bosnian",     "Bulgarian",     "Burmese",     "Croatian",     "Czech",     "Estonian",     "Finnish",     "Georgian",     "Greek",     "Hebrew",     "Hindi",     "Hungarian",     "Icelandic",     "Khmer",     "Lao",     "Latvian",     "Lithuanian",     "Macedonian",     "Mongolian",     "Nepali",     "Pashto",     "Persian (Dari",     "Farsi",     "Tajik)",     "Polish",     "Russian",     "Serbian",     "Sinhala",     "Slovak",     "Slovenian",     "Tagalog",     "Thai",     "Turkish",     "Ukrainian",     "Urdu",     "Uzbek",     "Vietnamese",     "Xhosa",     "Zulu" };
    QStringList hardest { "Arabic", "Cantonese (Chinese)", "Mandarin (Chinese)", "Japanese", "Korean" };
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
