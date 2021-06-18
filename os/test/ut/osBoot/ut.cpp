#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "osBoot.h"

unsigned char * _s_os_section_vars;
unsigned char * _s_program_blinking_led_CM7_section_init;
unsigned char * _e_os_section_vars;
unsigned char * _e_program_blinking_led_CM7_section_init;
unsigned char * _flash_os_section_vars_start;
unsigned char * _flash_program_blinking_led_CM7_section_init;


unsigned char RAM[10] = {10};

unsigned char FLASH[10] = {0,1,2,3,4,5,6,7,8,9};

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

TEST_GROUP(osBoot)
{
    void setup() {
				_s_os_section_vars = &(RAM[0]);
				_e_os_section_vars = &(RAM[4]);

				_flash_os_section_vars_start = &(FLASH[0]);

				_s_program_blinking_led_CM7_section_init = &(RAM[5]);
				_s_program_blinking_led_CM7_section_init = &(RAM[9]);

				_flash_os_section_vars_start = &(FLASH[5]);
    }

    void teardown() {
        mock().clear();
    }

};


TEST(osBoot, simpleTest)
{
    // arrange
    mock().expectNCalls("osBoot_boot");

    osBoot_boot();
		//check if the values from FLASH are in RAM
    mock().checkExpectations();
}
