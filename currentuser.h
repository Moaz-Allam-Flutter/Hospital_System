// currentuser.h
#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <QString>

class CurrentUser {
public:
    static CurrentUser* instance() {
        if (!s_instance) {
            s_instance = new CurrentUser();
        }
        return s_instance;
    }

    void setUsername(const QString& username) { m_username = username; }
    QString getUsername() const { return m_username; }

private:
    CurrentUser() {}
    static CurrentUser* s_instance;
    QString m_username;
};

#endif // CURRENTUSER_H
