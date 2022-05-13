#pragma once

#include "AsstPort.h"

namespace asst
{
    class Assistant;
}

#ifdef __cplusplus
extern "C" {
#endif
    typedef asst::Assistant* AsstHandle;
    typedef int TaskId;
    typedef void(ASST_CALL* AsstApiCallback)(int msg, const char* detail_json, void* custom_arg);

    bool ASSTAPI AsstLoadResource(const char* path);

    AsstHandle ASSTAPI AsstCreate();
    AsstHandle ASSTAPI AsstCreateEx(AsstApiCallback callback, void* custom_arg);
    void ASSTAPI AsstDestroy(AsstHandle handle);

    bool ASSTAPI AsstConnect(AsstHandle handle, const char* adb_path, const char* address, const char* config);

    TaskId ASSTAPI AsstAppendTask(AsstHandle handle, const char* type, const char* params);
    bool ASSTAPI AsstSetTaskParams(AsstHandle handle, TaskId id, const char* params);

#ifdef _WIN32
    TaskId ASSTAPI AsstAppendTaskWithGBK(AsstHandle handle, const char* type, const char* params);
    bool ASSTAPI AsstSetTaskParamsWithGBK(AsstHandle handle, TaskId id, const char* params);
#endif

    bool ASSTAPI AsstStart(AsstHandle handle);
    bool ASSTAPI AsstStop(AsstHandle handle);

    unsigned long long ASSTAPI AsstGetImage(AsstHandle handle, void* buff, unsigned long long buff_size);
    bool ASSTAPI AsstCtrlerClick(AsstHandle handle, int x, int y, bool block);

    ASSTAPI_PORT const char* ASST_CALL AsstGetVersion();
    void ASSTAPI AsstLog(const char* level, const char* message);

#ifdef __cplusplus
}
#endif
