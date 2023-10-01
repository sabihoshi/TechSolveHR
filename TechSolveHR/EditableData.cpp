#include "EditableData.h"

#include "console.h"

void EditableData::EditData(const std::vector<std::string*>& items, const int spacing, const int x, const int y, const int maxCharacters)
{
    XY(x, y);

    for (const auto& item : items)
    {
        auto current = XY();
        std::cout << *item;
        XY(current);
        MoveCursor(CursorDirection::Down, spacing);
    }

    XY(x, y);

    // Up/Down to Navigate
    // Enter to select, Enter to confirm
    // Esc to cancel editing

    int index = 0;
    auto* input = new std::string;
    bool isEditing = false;
    auto position = XY();

    while (true)
    {
        switch (const int c = _getch())
        {
            case KEY_UP:
                if (isEditing)
                    break;

                if (index > 0)
                {
                    index--;
                    position = MoveCursor(CursorDirection::Up, spacing);
                }
                else
                {
                    index = items.size() - 1;
                    position = XY(x, y + (items.size() - 1) * spacing);
                }
                break;
            case KEY_DOWN:
                if (isEditing)
                    break;

                if (index < items.size() - 1)
                {
                    index++;
                    position = MoveCursor(CursorDirection::Down, spacing);
                }
                else
                {
                    index = 0;
                    position = XY(x, y);
                }
                break;
            case KEY_ENTER:
                if (isEditing)
                {
                    delete items[index];
                    *items[index] = *input;

                    input = new std::string;
                    isEditing = false;

                    XY(position);

                    if (index < items.size() - 1)
                    {
                        index++;
                        position = MoveCursor(CursorDirection::Down, spacing);
                    }
                    else
                    {
                        index = 0;
                        position = XY(x, y);
                    }
                }
                else
                {
                    isEditing = true;

                    std::cout << Repeat(" ", maxCharacters);
                    XY(position);
                }
                break;
            case KEY_ESC:
                if (isEditing)
                {
                    delete input;
                    input = new std::string;
                    isEditing = false;

                    XY(position);
                    std::cout << Repeat(" ", maxCharacters);
                    XY(position);
                    std::cout << *items[index];
                    XY(position);
                }
                else
                {
                    return;
                }
                break;
            case BACKSPACE:
                if (isEditing && input->length() > 0)
                {
                    input->pop_back();
                    std::cout << "\b \b";
                }
                break;
            default:
                if (isEditing && isalpha(c) && input->length() < maxCharacters)
                {
                    *input += static_cast<char>(c);
                    std::cout << static_cast<char>(c);
                }
                break;
        }
    }
}

void EditableData::PrintData() {}
