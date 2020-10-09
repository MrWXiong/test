#ifndef _LOG4CPLUS_UTILS_H_
#define _LOG4CPLUS_UTILS_H_
#define _KMLOG4CPLUS     //开启日志打印功能
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <string>
#include<iostream>
#include <QtCore/qglobal.h>
#include <log4cplus/logger.h>
#include<log4cplus/loggingmacros.h>

#if defined(KMLOGGER_LIBRARY)
#  define KMLOGGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define KMLOGGERSHARED_EXPORT Q_DECL_IMPORT
#endif


// 从指定的配置文件logfile中读取配置信息，并初始化log4cplus，这个函数在进程的入口处调用
KMLOGGERSHARED_EXPORT void InitializeLog4cplus(const char * logcfgFilepath,const char * platform=nullptr);
KMLOGGERSHARED_EXPORT void ReleaseLog4cplus(); // 用于释放 log4cplus ，在进程的结束处调用
KMLOGGERSHARED_EXPORT log4cplus::Logger& getLoger();

//各日志子类宏定义   __VA_ARGS__ 是一个可变参数的宏,宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,否则会编译出错
#    define LogDebug(...)    LOG4CPLUS_DEBUG_FMT(getLoger(),__VA_ARGS__)
#    define LogInfo(...)     LOG4CPLUS_INFO_FMT(getLoger(),__VA_ARGS__)
#    define LogWarn( ...)    LOG4CPLUS_WARN_FMT(getLoger(),__VA_ARGS__)
#    define LogError(...)    LOG4CPLUS_ERROR_FMT(getLoger(),__VA_ARGS__)


#endif
