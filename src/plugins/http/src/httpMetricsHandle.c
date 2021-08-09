//
// Created by slzhou on 8/6/21.
//
#define _DEFAULT_SOURCE
#include "os.h"
#include "taoserror.h"
#include "tfs.h"

#include "httpMetricsHandle.h"
#include "dnode.h"
#include "httpLog.h"

static HttpDecodeMethod metricsDecodeMethod = {"metrics", metricsProcessRequest};

void metricsInitHandle(HttpServer* pServer) {
  httpAddMethod(pServer, &metricsDecodeMethod);
}

bool metricsProcessRequest(HttpContext* pContext) {
  httpDebug("context:%p, fd:%d, user:%s, process admin grant msg", pContext, pContext->fd, pContext->user);

  JsonBuf* jsonBuf = httpMallocJsonBuf(pContext);
  if (jsonBuf == NULL) {
    httpError("failed to allocate memory for metrics");
    httpSendErrorResp(pContext, TSDB_CODE_HTTP_NO_ENOUGH_MEMORY);
    return false;
  }

  httpInitJsonBuf(jsonBuf, pContext);
  httpWriteJsonBufHead(jsonBuf);

  httpJsonToken(jsonBuf, JsonObjStt);
  {
      int32_t dnodeId = dnodeGetDnodeId();
      char* keyDnodeId = "dnode_id";
      httpJsonPairIntVal(jsonBuf, keyDnodeId, (int32_t)strlen(keyDnodeId), dnodeId);
  }

  {
     if (tsDnodeStartTime != 0) {
       int64_t now = taosGetTimestampMs();
       int64_t upTime = now-tsDnodeStartTime;
       char* keyUpTime = "up_time";
       httpJsonPairInt64Val(jsonBuf, keyUpTime, (int32_t)strlen(keyUpTime), upTime);
     }
  }

  {
    int32_t cpuCores = taosGetCpuCores();
    char* keyCpuCores = "cpu_cores";
    httpJsonPairIntVal(jsonBuf, keyCpuCores, (int32_t)strlen(keyCpuCores), cpuCores);

    float sysCpuUsage = 0;
    float procCpuUsage = 0;
    bool  succeeded = taosGetCpuUsage(&sysCpuUsage, &procCpuUsage);
    if (!succeeded) {
      httpError("failed to get cpu usage");
    } else {
      if (sysCpuUsage <= procCpuUsage) {
        sysCpuUsage = procCpuUsage + 0.1f;
      }
      char* keyCpuSystem = "cpu_system";
      char* keyCpuEngine = "cpu_engine";
      httpJsonPairFloatVal(jsonBuf, keyCpuSystem, (int32_t)strlen(keyCpuSystem), sysCpuUsage);
      httpJsonPairFloatVal(jsonBuf, keyCpuEngine, (int32_t)strlen(keyCpuEngine), procCpuUsage);
    }
  }

  {
    float sysMemoryUsedMB = 0;
    bool succeeded = taosGetSysMemory(&sysMemoryUsedMB);
    if (!succeeded) {
      httpError("failed to get sys memory info");
    } else {
      char* keyMemSystem = "mem_system";
      httpJsonPairFloatVal(jsonBuf, keyMemSystem, (int32_t)strlen(keyMemSystem), sysMemoryUsedMB);
    }

    float procMemoryUsedMB = 0;
    succeeded = taosGetProcMemory(&procMemoryUsedMB);
    if (!succeeded) {
      httpError("failed to get proc memory info");
    } else {
      char* keyMemEngine = "mem_engine";
      httpJsonPairFloatVal(jsonBuf, keyMemEngine, (int32_t)strlen(keyMemEngine), procMemoryUsedMB);
    }
  }

  {
    int64_t bytes = 0, rbytes = 0, tbytes = 0;
    bool succeeded = taosGetCardInfo(&bytes, &rbytes, &tbytes);
    if (!succeeded) {
      httpError("failed to get network info");
    } else {
      char* keyNetIn = "net_in";
      char* keyNetOut = "net_out";
      httpJsonPairInt64Val(jsonBuf, keyNetIn, (int32_t)strlen(keyNetIn), rbytes);
      httpJsonPairInt64Val(jsonBuf, keyNetOut, (int32_t)strlen(keyNetOut), tbytes);
    }
  }

  {
    int64_t rchars = 0;
    int64_t wchars = 0;
    bool succeeded = taosReadProcIO(&rchars, &wchars);
    if (!succeeded) {
      httpError("failed to get io info");
    } else {
      char* keyIORead = "io_read";
      char* keyIOWrite = "io_write";
      httpJsonPairInt64Val(jsonBuf, keyIORead, (int32_t)strlen(keyIORead), rchars);
      httpJsonPairInt64Val(jsonBuf, keyIOWrite, (int32_t)strlen(keyIOWrite), wchars);
    }
  }

  {
    const int8_t numTiers = 3;
    SFSMeta      fsMeta;
    STierMeta* tierMetas = calloc(numTiers, sizeof(STierMeta));
    tfsUpdateInfo(&fsMeta, tierMetas, numTiers);
    {
      char* keyDiskUsed = "disk_used";
      char* keyDiskTotal = "disk_total";
      httpJsonPairInt64Val(jsonBuf, keyDiskTotal, (int32_t)strlen(keyDiskTotal), fsMeta.tsize);
      httpJsonPairInt64Val(jsonBuf, keyDiskUsed, (int32_t)strlen(keyDiskUsed), fsMeta.used);
      char* keyDisks = "disks";
      httpJsonPairHead(jsonBuf, keyDisks, (int32_t)strlen(keyDisks));
      httpJsonToken(jsonBuf, JsonArrStt);
      for (int i = 0; i < numTiers; ++i) {
        httpJsonItemToken(jsonBuf);
        httpJsonToken(jsonBuf, JsonObjStt);
        char* keyDataDirLevelUsed = "datadir_used";
        char* keyDataDirLevelTotal = "datadir_total";
        httpJsonPairInt64Val(jsonBuf, keyDataDirLevelUsed, (int32_t)strlen(keyDataDirLevelUsed), tierMetas[i].used);
        httpJsonPairInt64Val(jsonBuf, keyDataDirLevelTotal, (int32_t)strlen(keyDataDirLevelTotal), tierMetas[i].size);
        httpJsonToken(jsonBuf, JsonObjEnd);
      }
      httpJsonToken(jsonBuf, JsonArrEnd);
    }
    free(tierMetas);
  }

  {
    SStatisInfo info = dnodeGetStatisInfo();
    {
      char* keyReqHttp = "req_http";
      char* keyReqSelect = "req_select";
      char* keyReqInsert = "req_insert";
      httpJsonPairInt64Val(jsonBuf, keyReqHttp, (int32_t)strlen(keyReqHttp), info.httpReqNum);
      httpJsonPairInt64Val(jsonBuf, keyReqSelect, (int32_t)strlen(keyReqSelect), info.queryReqNum);
      httpJsonPairInt64Val(jsonBuf, keyReqInsert, (int32_t)strlen(keyReqInsert), info.submitReqNum);
    }
  }

  httpJsonToken(jsonBuf, JsonObjEnd);

  httpWriteJsonBufEnd(jsonBuf);
  pContext->reqType = HTTP_REQTYPE_OTHERS;
  httpFreeJsonBuf(pContext);
  return false;
}