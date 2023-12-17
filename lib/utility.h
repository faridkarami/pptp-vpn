#include <string>
#include <cstring>

class Utility
{
public:
    static const char *pkg(const std::string &command)
    {
        const char *pkg = config.pkg;
        const char *space = " ";
        const char *commandCStr = command.c_str();

        size_t length = strlen(pkg) + strlen(space) + strlen(commandCStr) + 1;

        char *result = new char[length];

        strcpy(result, pkg);
        strcat(result, space);
        strcat(result, commandCStr);

        return result;
    }

    static bool replace(std::string &str, const std::string &from, const std::string &to)
    {
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }

    static void replaceAll(std::string &str, const std::string &from, const std::string &to)
    {
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
    }
};
