#include "../../incl/global.hpp"

void User::password_cmd(std::vector<std::string> cmd)
{
    if (is_password_passed)
        adam_sender(_fd, ERR_ALREADYREGISTRED(_nickname));
    else if (cmd.size() == 1)
        adam_sender(_fd, ERR_NEEDMOREPARAMS(_nickname, cmd[0]));
    else if (cmd.size() != 2 || !(cmd[1] == Server::password || (cmd[1][0] == ':' && cmd[1].substr(1) == Server::password)))
        adam_sender(_fd, ERR_PASSWDMISMATCH(_nickname));
    else
        is_password_passed = true;
}

void User::nickname_cmd(std::vector<std::string> cmd)
{
    if (!is_password_passed)
        adam_sender(_fd, ERR_NOTREGISTERED(_nickname));
    else if (cmd.size() == 1)
        adam_sender(_fd, ERR_NONICKNAMEGIVEN(_nickname));
    else if (!is_nickname_valid(cmd[1]))
        adam_sender(_fd, ERR_ERRONEUSNICKNAME(_nickname, cmd[1]));
    else if (server->is_nickname_available(cmd[1]) != -1)
        adam_sender(_fd, ERR_NICKNAMEINUSE(_nickname, cmd[1]));
    else
    {
        this->_nickname = cmd[1];
        this->is_nickname_passed = true;
    }
}

void User::username_cmd(std::vector<std::string> cmd)
{
    if (!is_password_passed)
    {
        adam_sender(_fd, ERR_NOTREGISTERED(_nickname));
        return;
    }
    split(cmd, 4);
    if (cmd.size() != 4)
        adam_sender(_fd, ERR_NEEDMOREPARAMS(_nickname, cmd[0]));
    else if (!server->is_username_available(cmd[0]))
        adam_sender(_fd, ERR_ALREADYREGISTRED(cmd[0]));
    else
    {
        this->_username = cmd[0];
        this->_realname = cmd[3][0] == ':' ? cmd[3].substr(1) : cmd[3];
        is_username_passed = true;
    }
}
