#include "Text.h"

void TextCopy(Text* dest, const WCHAR* src, WORD attributes)
{
    while (*src)
    {
        dest->Char.UnicodeChar = *src;
        dest->Attributes = attributes;

        ++dest;
        ++src;
    }
}

int32 TextLen(const Text* text)
{
    int32 result = 0;
    while (text->Char.UnicodeChar)
    {
        ++result;
        ++text;
    }

    return result;
}