#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

void task_05()
{
    string file = "rc.local";
    string dest = "/etc";

    // Generate
    std::ifstream fileTemplate("tasks/task-05/" + file + ".txt");

    std::string str((std::istreambuf_iterator<char>(fileTemplate)),
                    std::istreambuf_iterator<char>());

    std::ofstream outfile(file);

    outfile << str << std::endl;

    outfile.close();

    std::remove((dest + "/" + file).c_str());
    std::filesystem::copy(file, dest);
    std::remove(file.c_str());

    std::cout << SetForeGRN;
    std::cout << "Step 5 - rc.local completed";
    std::cout << RESETTEXT << std::endl;
}