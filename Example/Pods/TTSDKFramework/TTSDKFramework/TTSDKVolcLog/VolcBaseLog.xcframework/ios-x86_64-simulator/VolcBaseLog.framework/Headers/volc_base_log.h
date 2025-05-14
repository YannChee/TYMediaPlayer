/*
 * Copyright (c) 2020 The ByteRtc project authors. All Rights Reserved.
 * @company ByteDance.Inc
 * @file volc_base_log.h
 * @version 0.1
 * @date 2023-03-10
*/

#pragma once

#ifndef VOLCBASELOG_VOLC_LOG_H
#define VOLCBASELOG_VOLC_LOG_H

#include <stdint.h>
#include <string.h>


#if defined(__cplusplus)
#define VOLCBASE_API __attribute__((__visibility__("default"))) extern "C"
  #ifdef WIN32
  #define VOLCBASE_API extern "C" __declspec(dllexport)
  #endif
#else
#define VOLCBASE_API __attribute__((__visibility__("default"))) extern
  #ifdef WIN32
  #define VOLCBASE_API __declspec(dllexport)
  #endif
#endif

enum VolcBaseLogLevel {
    kVolcLogLevelDebug = 1,
    kVolcLogLevelTrace = 2,
    kVolcLogLeveLInfo = 3,
    kVolcLogLevelWarning = 4,
    kVolcLogLevelError = 5,
    kVolcLogLevelNone = 6,
};


struct VolcBaseLogConfig {
    explicit VolcBaseLogConfig();
    /**
     * @brief log_path, path of write log, if 'log_path' is nullptr, will use the default path.
     *        default path:
     *            ios: ${HOME}/Documents/VolcBase/monitor/VolcBaseLog/
     *            android: /sdcard/VolcBase/monitor/VolcBaseLog/
     *            windows: C:\\Users\\${USER_NAME}\\AppData\\Roaming\\VolcBaseLog\\
     *            mac: ${HOME}/.VolcBase/monitor/VolcBaseLog/
     *            linux: ${HOME}/.VolcBase/monitor/VolcBaseLog/  (if HOME not set, will use the path of the current executable file)
     *        completed log path is 'log_path / business_id / device_id /'
     *        ps: Since the default path of the android platform is 'sdcard', but writing 
     *            to sdcard requires directory permissions, so it is recommended to pass in the path of the app root.
     */
    const char* log_path;
    /**
     * @brief max_log_size, The maximum value of the log storage size, when the log size exceeds the maximum value. 
     *                      When a new file is created, the first created file will be deleted according to the created time.
     *
     */
    uint32_t max_log_size_M; // = 100 // M
    /**
     * @brief single_log_size, Maximum size of a single file（Unit M）
     */
    uint32_t single_log_size_M; //= 2; // M
    /**
      * @brief log_expire_time, The expiration time of the log file. 
      *                         Files that have expired will be deleted when a new file is created. (Unit s)
      */
    uint32_t log_expire_time_s;//= 7 * 24 * 60 * 60; // s
    /**
      * @brief enable_thread_loop, Whether to enable timing polling to check the recovery task.  default is 0, takes effect only enable_thread_loop = 1
      */
    int enable_thread_loop;// = 0;
    /**
      * @brief enable_stdout, Whether to enable log output to console. default is 1.  takes effect only enable_stdout = 1
      */
    int enable_stdout; // = 1;

    /**
     * @brief enalbe_log_file, Whether to enable log output to file. default is 1.  takes effect only enalbe_log_file = 1
     */
    int enalbe_log_file; //=1

    /**
      * @brief Log level allowed to be written, default is kVolcLogLevelTrace
      */
    int log_level;// = kVolcLogLevelTrace;
    /**
     * @brief interval, interval between each active query. default is 2 minutes, min value: 10 * 1000 ms.
     *                  The minimum value is 10 * 1000 ms, if the value set is less than the minimum value,
     *                  the minimum value will be used. (unit ms)
     */
    uint64_t interval_ms;// = 2 * 60 * 1000;
    /**
     * @brief the domain name of query
     */
    const char* query_url;// = NULL;

    uint64_t http_timeout;
};

/**
 * @param config
 * @param business_id - Represents different lines of business. The log directory will be named after the incoming directory 
 *                      or the default directory + business_id. The business_id must be aligned with the server, and the unregistered 
 *                      business id cannot use the salvage service.
 * @param device_id  Uniquely identify a single device, it is necessary to ensure that different devices pass in different device ids.
 * @return - category >0  The current log handler.
 *                        Use the same business id and device id to call multiple times and return the same handler id.
 *         - category =-1 return error
 */
VOLCBASE_API int64_t VolcBaseLogInit(struct VolcBaseLogConfig config, int business_id, const char* device_id);

/**
 * @brief Destroy the created log pointer.
 *        Reference counting is used internally, and when the reference count is 0, it will be truly destroyed.
 * @param category
 */
VOLCBASE_API void VolcBaseLogUnInit(int64_t category);

/**
 * @brief Whether to actively open http loop polling to check if there is a return command
 * @param category
 * @param enabled = true: A timer will be automatically created inside the log to poll and call 'VolcBaseLogQuerySalvage'
 *                        to check whether there is a salvage task
 *        enabled = false: Turn off polling tasks.
 * @param interval interval between each active query. default is 2 minutes, min value: 10s. 
 *                 The minimum value is 10 * 1000 ms, if the value set is less than the minimum value,
 *                 the minimum value will be used. (unit ms)
 */
VOLCBASE_API void VolcBaseLogEnableThreadLoop(int64_t category, int enabled, uint32_t interval_ms);

/**
 * @brief Actively query whether there is a log recovery command
 * @param category
 */
VOLCBASE_API void VolcBaseLogQuerySalvage(int64_t category);

/**
 * @brief entrance of write log
 * @param category
 * @param log_level
 * @param log_tag
 * @param log_filename
 * @param line_num
 * @param log_content
 */
VOLCBASE_API void VolcBaseWriteLog(int64_t category, enum VolcBaseLogLevel log_level, char* log_tag, char* log_filename,
              int line_num, char* log_content);

/**
 * @brief entrance of write log
 * @param category
 * @param log_content 
 */
VOLCBASE_API void VolcBaseWriteLogContent(int64_t category, enum VolcBaseLogLevel log_level, char* log_content);

/**
 * @brief Set the Log Path
 * @param path
 */
VOLCBASE_API void VolcBaseSetLogPath(int64_t category, const char* path);

/**
 * @brief Set the Log Expire Time
 * @param expire_time 
 */
VOLCBASE_API void VolcBaseSetLogExpireTime(int64_t category, uint32_t expire_time_s);

/**
 * @brief Set the Max Log Size
 * @param max_log_size 
 */
VOLCBASE_API void VolcBaseSetMaxLogSize(int64_t category, uint32_t max_log_size_M);

/**
 * @brief Set the Single File Size
 * @param file_size 
 */
VOLCBASE_API void VolcBaseSetSingleFileSize(int64_t category, uint32_t file_size_M);

/**
 * @brief Set the Enable Stdout
 * @param enable_stdout, only enable stdcout = 1, enable this feature
 */
VOLCBASE_API void VolcBaseSetEnableStdout(int64_t category, int enable_stdout);

/**
 * @brief Set the Enable log file
 * @param enable_log_file, only enable_log_file = 1, enable this feature
 */
VOLCBASE_API void VolcBaseSetEnableLogFile(int64_t category, int enable_log_file);

/**
 * @brief Set the Query Interval
 * @param interval
 */
VOLCBASE_API void VolcBaseSetQueryInterval(int64_t category, uint64_t interval_ms);

/**
 * @brief Set the sdk log enable output
 * @param enable only enable equal 1, output sdk log. default is enable output
 */
VOLCBASE_API void VolcBaseSetSDKLogOutput(int enable);
/**
 * @brief Get the sdk log level
 * @param category The current log handler
 */
VOLCBASE_API enum VolcBaseLogLevel VolcBaseGetLogLevel(int category);
/**
 * @brief Set the sdk log level
 * @param category The current log handler
 * @param level new log level
 */
VOLCBASE_API int VolcBaseSetLogLevel(int category, enum VolcBaseLogLevel level);

/**
 * @brief Set the sdk http request timeout, default 10s
 * @param category The current log handler
 * @param timeout_ms timeout ms
 */
VOLCBASE_API int VolcBaseSetHttpTimeout(int category, int timeout_ms);
/**
 * @brief Set the sdk http upload log file timeout, default 5min
 * @param category The current log handler
 * @param timeout_ms timeout ms
 */
VOLCBASE_API int VolcBaseSetHttpUploadFileTimeout(int category, int timeout_ms);
#endif //VOLCBASELOG_VOLC_LOG_H
