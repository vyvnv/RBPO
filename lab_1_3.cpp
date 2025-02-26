#include <iostream>
#include <string>
using namespace std;

class ILogger {
public:
    virtual void Log(const string& logText) = 0;
};

class FileLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << "Siving log in file " << endl;
    }
};

class DatabaseLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << "Saving log in databasw " << endl;
    }
};

class SmtpMailer {
private:
    ILogger* logger; 
public:
    SmtpMailer(ILogger* logInstance) : logger(logInstance) {}

    void SendMessage(const string& message) {
        cout << "sending " << message << endl;
        logger->Log(message + " was sent");
    }
};


int main() {
    FileLogger fileLogger;
    DatabaseLogger dbLogger;

    std::cout << "1) File logger" << std::endl;
    SmtpMailer mailer1(&fileLogger);
    mailer1.SendMessage("sum text");

    std::cout << "\n2) DB logger" << std::endl;
    SmtpMailer mailer2(&dbLogger);
    mailer2.SendMessage("sum text 2");

    return 0;
}
