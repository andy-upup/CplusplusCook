#ifndef TEMPLATIZED_BASE_CLASS_ACCESS_H__
#define TEMPLATIZED_BASE_CLASS_ACCESS_H__
#include <iostream>

// 43
namespace effective {

class CompanyA {
 public:
	void SendCleartext(const std::string &msg) {
        std::cout << "CompanyA::SendCleartext " << msg << std::endl;
    }
	void SendEncrypted(const std::string &msg) {
        std::cout << "CompanyA::SendEncrypted " << msg << std::endl;
    }
};

class CompanyB {
 public:
	void SendCleartext(const std::string &msg) {
        std::cout << "CompanyB::SendCleartext " << msg << std::endl;
    }
	void SendEncrypted(const std::string &msg) {
        std::cout << "CompanyB::SendEncrypted " << msg << std::endl;
    }
};

class CompanyZ {
 public:
	void SendEncrypted(const std::string &msg) {
        std::cout << "CompanyZ::SendEncrypted " << msg << std::endl;
    }
};

template <typename Company>
class MsgSender {
 public:
    void SendClear(const std::string &msg) {
        Company company;
        company.SendCleartext(msg);
    }

    void SendSecret(const std::string &msg) {
		Company company;
		company.SendEncrypted(msg);
    }
};

template <>
class MsgSender<CompanyZ> {
 public:
    void SendSecret(const std::string &msg) {
        CompanyZ company;
        company.SendEncrypted(msg);
    }
};

template <typename Company>
class LoggingMsgSender : public MsgSender<Company> {
 public:
    using MsgSender<Company>::SendClear;
    void SendClearMsg(const std::string &msg) {
        // Combine using MsgSender<Company>::SendClear
        SendClear(msg);
        // Members in base class templates can be specified through "this->" in derived class templates.
        this->SendClear(msg);
        // base class qualifer: "MsgSender<Company>::"
        MsgSender<Company>::SendClear(msg);
    }
};

} // namespace effective
#endif