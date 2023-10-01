#pragma once

#pragma execution_character_set("utf-8")

#include <string>
#include <vector>

class EditableData
{
protected:
    static void EditData(const std::vector<std::string*>& items, const int spacing, const int x, const int y, const int maxCharacters);

public:
    virtual ~EditableData() = default;

    virtual void PrintData() = 0;

    virtual void EditData() = 0;
};