#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

void task_03()
{
    string file = "chap-secrets";
    string dest = "/etc/ppp";

    // Generate
    std::ifstream fileTemplate("tasks/task-03/" + file + ".txt");

    std::string str((std::istreambuf_iterator<char>(fileTemplate)),
                    std::istreambuf_iterator<char>());

    std::ofstream outfile(file);

    outfile << str << std::endl;

    outfile.close();

    std::remove((dest + "/" + file).c_str());
    std::filesystem::copy(file, dest);
    std::remove(file.c_str());

    std::cout << SetForeGRN;
    std::cout << "Step 3 - chap-secrets completed";
    std::cout << RESETTEXT << std::endl;
}