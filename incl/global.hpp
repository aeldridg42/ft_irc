#ifndef GLOBAL_HPP
# define GLOBAL_HPP

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <list>
#include <fcntl.h>
#include <unistd.h>
#include <map>
#include <sys/time.h>


#define BUFFER_SIZE 1024

# include "user.hpp"
# include "channel.hpp"
# include "server.hpp"
# include "utils.hpp"


#define RPL_WELCOME(nickname)                           (":ircserv 001 " + (nickname) + " :Welcome to the IRCServ, " + (nickname))
#define RPL_MOTDSTART(nickname)                         (":ircserv 375 " + (nickname) + " :- Message of the day -")
#define RPL_MOTD(nickname, message)                     (":ircserv 372 " + (nickname) + " :- " + (message))
#define RPL_ENDOFMOTD(nickname)                         (":ircserv 376 " + (nickname) + " :- End of /MOTD command")
#define RPL_AWAY(sender, recipient, away_message)       (":ircserv 301 " + (sender) + " " + (recipient) + " :" + (away_message))
#define RPL_UNAWAY(nickname)                            (":ircserv 305 " + (nickname) + " :You are no longer marked as being away")
#define RPL_NOWAWAY(nickname)                           (":ircserv 306 " + (nickname) + " :You have been marked as being away")

#define RPL_NOTOPIC(nickname, channel)                  (":ircserv 331 " + (nickname) + ' ' + (channel) + " :No topic is set")
#define RPL_TOPIC(nickname, channel, topic)             (":ircserv 332 " + (nickname) + ' ' + (channel) + " :" + (topic))
#define RPL_NAMREPLY(nickname, channel, nicknames)      (":ircserv 353 " + (nickname) + ' ' + (channel) + " :" + (nicknames))
#define RPL_ENDOFNAMES(nickname, channel)               (":ircserv 366 " + (nickname) + ' ' + (channel) + " :End of /NAMES list")

#define RPL_YOUREOPER(nickname)                         (":ircserv 381 " + (nickname) + " :You are now an IRC operator")
#define RPL_YOURENOTOPER(nickname)                      (":ircserv 380 " + (nickname) + " :You are no longer an IRC operator")

#define RPL_QUIT(nickname, message)                     (":ircserv " + (nickname) + " quited :" + (message))
#define RPL_PRIVMSG(sender, recipient, msg)             (":" + (sender) + " PRIVMSG " + (recipient) + " :"+ (msg))
#define RPL_NOTICE(sender, recipient, msg)              (":" + (sender) + " NOTICE " + (recipient) + " :"+ (msg))
#define RPL_JOIN(nickname, channel)                     (":" + (nickname) + " JOIN " + (channel))
#define RPL_PART(nickname, channel, reason)             (":" + (nickname) + " PART " + (channel) + " :" + (reason))
#define RPL_INVITING(nickname, nicknameInvited, channel)(":" + (nickname) + " INVITE " + (nicknameInvited) + " :" + (channel))
#define RPL_KICK(nickname, channel, user, reason)       (":" + (nickname) + " KICK " + (channel) + ' ' + (user) + " :" + (reason))
#define RPL_MODE(nickname, user, changes)               (":" + (nickname) + " MODE " + (user) + " " + (changes))

#define ERR_NOSUCHNICK(nickname, nick)                  (":ircserv 401 " + (nickname) + ' ' + (nick) + " :No such nick/channel")
#define ERR_NOSUCHCHANNEL(nickname, channel)            (":ircserv 403 " + (nickname) + ' ' + (channel) + " :No such channel")
#define ERR_NOORIGIN(nickname)                          (":ircserv 409 " + (nickname) + " :No origin specified")

#define ERR_UNKNOWNCOMMAND(nickname, command)           (":ircserv 421 " + (nickname) + ' ' + (command) + " :Unknown command")
#define ERR_CHANOPRIVSNEEDED(nickname, channel)         (":ircserv 482 " + (nickname) + ' ' + (channel) + " :You're not channel operator")
#define ERR_CHANOPRIVSNEEDED2(nickname, channel)        (":ircserv 482 " + (nickname) + ' ' + (channel) + " :Channel don't have +o mode")

#define ERR_NONICKNAMEGIVEN(nickname)                   (":ircserv 431 " + (nickname) + " :No nickname given")
#define ERR_ERRONEUSNICKNAME(nickname, nick)            (":ircserv 432 " + (nickname) + ' ' + (nick) + " :Erroneus nickname")
#define ERR_ERRONEUSNICKNAME2(username, user)           (":ircserv 432 " + (username) + ' ' + (user) + " :Erroneus username")
#define ERR_NICKNAMEINUSE(oldnickname, nickname)        (":ircserv 433 " + (oldnickname) + ' ' + (nickname) + " :Nickname is already in use")

#define ERR_NOTONCHANNEL(nickname, channel)             (":ircserv 442 " + (nickname) + ' ' + (channel) + " :You're not on that channel")
#define ERR_USERONCHANNEL(nickname, user, channel)      (":ircserv 443 " + (nickname) + ' ' + (user) + ' ' + (channel) + " :is already on channel")


#define ERR_NOTREGISTERED(nickname)                     (":ircserv 451 " + (nickname) + " :You have not registered")
#define ERR_NEEDMOREPARAMS(nickname, command)           (":ircserv 461 " + (nickname) + ' ' + (command) + " :Not enough parameters")
#define ERR_ALREADYREGISTRED(nickname)                  (":ircserv 462 " + (nickname) + " :You may not reregister")
#define ERR_PASSWDMISMATCH(nickname)                    (":ircserv 464 " + (nickname) + " :Password incorrect")


#define ERR_NORECIPIENT(nickname, command)              (":ircserv 411 " + (nickname) + " :No recipient given " + (command))
#define ERR_NOTEXTTOSEND(nickname)                      (":ircserv 421 " + (nickname) + " :No text to send")

#define ERR_UMODEUNKNOWNFLAG(nickname)                  (":ircserv 501 " + (nickname) + " :Unknown MODE flag")
#define ERR_CHANNELISFULL(nickname, channel)            (":ircserv 471 " + (nickname) + ' ' + (channel) + " :Cannot join channel (+l)")
#define ERR_INVITEONLYCHAN(nickname, channel)           (":ircserv 473 " + (nickname) + ' ' + (channel) + " :Cannot join channel (+i)")
#define ERR_NOPRIVILEGES(nickname)                      (":ircserv 481 " + (nickname) + " :Permission Denied- You're not an IRC operator")


#endif