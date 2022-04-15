#include <iostream>
#include <CkMailMan.h>
#include <CkEmail.h>
using namespace std;

int main()
{
    string user;
    cin >> user;
    cout << endl;

    string from;
    cin >> from;
    cout << endl;

    string pass;
    cin >> pass;
    cout << endl;

    string to;
    cin >> to;
    cout << endl;

    string subject;
    cin >> subject;
    cout << endl;

    string body;
    cin >> body;
    cout << endl;

    kMailMan mailman;
    mailman.put_SmtpHost("smtp.google.com");
    mailman.put_SmtpUsername(user);
    mailman.put_SmtpPassword(pass);
    CkEmail email;
    email.put_Subject(subject);
    email.put_Body(body);
    bool success = email.AddTo(from,to);
    success = mailman.SendEmail(email);
    if (success != true) {
        std::cout << mailman.lastErrorText() << "\r\n";
        return;
    }
    success = mailman.CloseSmtpConnection();
    if (success != true) {
        std::cout << "Connection to SMTP server not closed cleanly." << "\r\n";
    }

    std::cout << "Mail Sent!" << "\r\n";
    return '0';
}
