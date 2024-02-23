#include <gtest/gtest.h>

#include <iostream>

#include "templatized_base_class_access.h"

TEST(test_effective, templatized_base_class_access_unit_test) {
    effective::MsgSender<effective::CompanyA> company_a_sender;
    company_a_sender.SendClear("Hello World!");

    effective::MsgSender<effective::CompanyZ> company_z_sender;
    company_z_sender.SendSecret("Hello World!");

    effective::LoggingMsgSender<effective::CompanyB> logging_sender;
    logging_sender.SendClearMsg("Hello World!");
}