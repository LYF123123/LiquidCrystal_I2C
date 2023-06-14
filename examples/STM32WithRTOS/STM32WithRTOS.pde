#include "task.hpp"
// https://community.platformio.org/t/stmf4discovery-board-init-mode-failed-unable-to-connect-to-the-target/22709
void setup()
{
    taskCreate();
    vTaskStartScheduler();
}

void loop()
{

}