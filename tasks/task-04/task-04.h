#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

void task_04()
{
    string file = "sysctl.conf";
    string dest = "/etc";

    // Generate
    std::ifstream fileTemplate("tasks/task-04/" + file + ".txt");

    std::string str((std::istreambuf_iterator<char>(fileTemplate)),
                    std::istreambuf_iterator<char>());

    std::ofstream outfile(file);

    outfile << str << std::endl;

    outfile.close();

    std::remove((dest + "/" + file).c_str());
    std::filesystem::copy(file, dest);
    std::remove(file.c_str());

    std::system("sysctl -p");

    std::cout << SetForeGRN;
    std::cout << "Step 4 - sysctl.conf completed";
    std::cout << RESETTEXT << std::endl;
}