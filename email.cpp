#include <CkMailMan.h>
#include <CkEmail.h>
void ChilkatSample(void)
    {
    CkMailMan mailman;
    mailman.put_SmtpHost("smtp.chilkatsoft.com");
    mailman.put_SmtpUsername("SandeepTV");
    mailman.put_SmtpPassword("123456");
    CkEmail email;
    email.put_Subject("simple text message");
    email.put_Body("Hello all I’m Sandeep");
    bool success = email.AddTo("Sandeep ","tvsandeep2002@gmail.com");
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
    } 
