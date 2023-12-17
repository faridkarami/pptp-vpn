#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

void task_01()
{
    string file = "pptpd.conf";
    string dest = "/home/faridkarami/Documents";

    // Get IP
    std::string localIp, remoteIp;

    std::cout << "Enter local IP: ";
    std::getline(std::cin, localIp);

    std::cout << "Enter remote IP: [suggest: 10.10.0.2-200]";
    std::getline(std::cin, remoteIp);

    // Generate
    std::ifstream fileTemplate("tasks/task-01/" + file + ".txt");

    std::string str((std::istreambuf_iterator<char>(fileTemplate)),
                    std::istreambuf_iterator<char>());
    Utility::replace(str, "@LOCAL_IP", localIp);
    Utility::replace(str, "@REMOTE_IP", remoteIp);

    std::ofstream outfile(file);

    outfile << str << std::endl;

    outfile.close();

    std::remove((dest + "/" + file).c_str());
    std::filesystem::copy(file, dest);
    std::remove(file.c_str());

    std::cout << SetForeGRN;
    std::cout << "Step 1 - pptp.conf completed";
    std::cout << RESETTEXT << std::endl;
}