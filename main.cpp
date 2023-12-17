#include <iostream>
#include <string>
#include <stdlib.h>
#include "config.h"
#include "lib/colors.h"
#include "lib/utility.h"
#include "tasks/requirement.h"
#include "tasks/task-01/task-01.h"
#include "tasks/task-02/task-02.h"
#include "tasks/task-03/task-03.h"
#include "tasks/task-04/task-04.h"
#include "tasks/task-05/task-05.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::cout << SetBackCYN << SetForeBLK << endl;
    std::cout << "PPTP Installation" << endl;
    std::cout << RESETTEXT << endl;

    requirement();
    task_01();
    task_02();
    task_03();
    task_04();
    task_05();

    std::system("systemctl enable pptpd");
    std::system("service pptpd start");

    std::cout << SetForeGRN;
    std::cout << "Successfully completed!";
    std::cout << RESETTEXT << std::endl;

    return 0;
}