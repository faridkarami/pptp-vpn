#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

void task_02()
{
    string file = "pptpd-options";
    string dest = "/etc/ppp";

    // Generate
    std::ifstream fileTemplate("tasks/task-02/" + file + ".txt");

    std::string str((std::istreambuf_iterator<char>(fileTemplate)),
                    std::istreambuf_iterator<char>());

    std::ofstream outfile(file);

    outfile << str << std::endl;

    outfile.close();

    std::remove((dest + "/" + file).c_str());
    std::filesystem::copy(file, dest);
    std::remove(file.c_str());

    std::cout << SetForeGRN;
    std::cout << "Step 2 - pptpd-options completed";
    std::cout << RESETTEXT << std::endl;
}