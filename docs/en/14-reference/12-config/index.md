---
title: Configuration Parameters
description: "Configuration parameters for client and server in TDengine"
---

## Configuration File on Server Side

On the server side, the actual service of TDengine is provided by an executable `taosd` whose parameters can be configured in file `taos.cfg` to meet the requirements of different use cases. The default location of `taos.cfg` is `/etc/taos`, but can be changed by using `-c` parameter on the CLI of `taosd`. For example, the configuration file can be put under `/home/user` and used like below

```
taosd -c /home/user
```

Parameter `-C` can be used on the CLI of `taosd` to show its configuration, like below:

```
taosd -C
```

## Configuration File on Client Side

TDengine CLI `taos` is the tool for users to interact with TDengine. It can share same configuration file as `taosd` or use a separate configuration file. When launching `taos`, parameter `-c` can be used to specify the location where its configuration file is. For example `taos -c /home/cfg` means `/home/cfg/taos.cfg` will be used. If `-c` is not used, the default location of the configuration file is `/etc/taos`. For more details please use `taos --help` to get.

```bash
taos -C
```

```bash
taos --dump-config
```

# Configuration Parameters

:::note
The parameters described in this document by the effect that they have on the system.

:::

:::note
`taosd` needs to be restarted for the parameters changed in the configuration file to take effect.

:::

## Connection Parameters

### firstEp

| Attribute     | Description                            |
| -------- | -------------------------------------------------------------- |
| Applicable | Server and Client                                           |
| Meaning       | The end point of the first dnode in the cluster to be connected to when `taosd` or `taos` is started |
| Default   | localhost:6030                                                 |

### secondEp

| Attribute     | Description                                                                                  |
| -------- | ------------------------------------------------------------------------------------- |
| Applicable | Server and Client                                           |
| Meaning       | The end point of the second dnode to be connected to if the firstEp is not available when `taosd` or `taos` is started |
| Default   | None                                                                                    |

### fqdn

| Attribute     | Description                                                              |
| ------------- | ------------------------------------------------------------------------ |
| Applicable    | Server Only                                                              |
| Meaning       | The FQDN of the host where `taosd` will be started. It can be IP address |
| Default Value | The first hostname configured for the host                             |
| Note          | It should be within 96 bytes                                             |                        |

### serverPort

| Attribute     | Description                                                              |
| -------- | ----------------------------------------------------------------------------------------------------------------------- |
| Applicable    | Server Only                                                              |
| Meaning       | The port for external access after `taosd` is started                                                                           |
| Default Value | 6030                                                                                                                            |

:::note
- Ensure that your firewall rules do not block TCP port 6042  on any host in the cluster. Below table describes the ports used by TDengine in details.
:::
| Protocol | Default Port | Description                                      | How to configure                                                                               |
| :------- | :----------- | :----------------------------------------------- | :--------------------------------------------------------------------------------------------- |
| TCP | 6030 | Communication between client and server. In a multi-node cluster, communication between nodes. serverPort |
| TCP      | 6041         | REST connection between client and server        | Prior to 2.4.0.0: serverPort+11; After 2.4.0.0 refer to [taosAdapter](/reference/taosadapter/) |
| TCP      | 6043         | Service Port of TaosKeeper                       | The parameter of TaosKeeper |
| TCP      | 6044         | Data access port for StatsD                      | Configurable through taosAdapter parameters.
| UDP      | 6045         | Data access for statsd                           | Configurable through taosAdapter parameters.
| TCP      | 6060         | Port of Monitoring Service in Enterprise version | |

### maxShellConns

| Attribute     | Description                                          |
| ------------- | ---------------------------------------------------- |
| Applicable    | Server Only                                          |
| Meaning       | The maximum number of connections a dnode can accept |
| Value Range   | 10-50000000                                          |
| Default Value | 5000                                                 |

## Monitoring Parameters

### monitor

| Attribute     | Description                                                                                                                                                                                               |
| -------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Applicable | Server only                                           |
| Meaning       | The switch for monitoring inside server. The main object of monitoring is to collect information about load on physical nodes, including CPU usage, memory usage, disk usage, and network bandwidth. Monitoring information is sent over HTTP to the taosKeeper service specified by `monitorFqdn` and `monitorProt`.
| Value Range   | 0: monitoring disabled, 1: monitoring enabled                                                                                                                                                                |
| Default   | 1                                                                                                                                                                                                  |

### monitorFqdn

| Attribute     | Description                                                    |
| -------- | -------------------------- |
| Applicable    | Server Only                                                    |
| Meaning     | FQDN of taosKeeper monitoring service |
| Default   | None                                                                                    |

### monitorPort

| Attribute     | Description                            |
| -------- | --------------------------- |
| Applicable    | Server Only                                                    |
| Meaning     | Port of taosKeeper monitoring service |
| Default Value | 6043                                                               |

### monitorInterval

| Attribute     | Description                                                                                                                                                                         |
| -------- | -------------------------------------------- |
| Applicable    | Server Only                                                                                                                                                                         |
| Meaning       | The interval of collecting system workload |
| Unit          | second                                     |
| Value Range | 1-200000                                     |
| Default Value | 30                                                                                                                                                                                   |

### telemetryReporting

| Attribute     | Description                                                                                                                                                                         |
| -------- | ---------------------------------------- |
| Applicable    | Server Only                                                                                                                                                                         |
| Meaning       | Switch for allowing TDengine to collect and report service usage information |
| Value Range   | 0: Not allowed; 1: Allowed                                                   |
| Default Value | 1                                                                                                                                                                                   |

## Query Parameters

### queryPolicy

| Attribute     | Description                          |
| -------- | ----------------------------- |
| Applicable | Client only                                           |
| Meaning     | Execution policy for query statements            |
| Unit     | None                            |
| Default   | 1                             |
| Notes | 1: Run queries on vnodes and not on qnodes |

2: Run subtasks without scan operators on qnodes and subtasks with scan operators on vnodes.

3: Only run scan operators on vnodes; run all other operators on qnodes.

### querySmaOptimize

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable | Client only                                           |
| 含义     | SMA index optimization policy |
| Unit     | None                            |
| Default Value | 0                                                 |
| Notes |

0: Disable SMA indexing and perform all queries on non-indexed data.

1: Enable SMA indexing and perform queries from suitable statements on precomputation results.|


### maxNumOfDistinctRes

| Attribute     | Description                                                                                                                                                                         |
| -------- | -------------------------------- | --- |
| Applicable    | Server Only                                                                                                                                                                         |
| Meaning       | The maximum number of distinct rows returned |
| Value Range   | [100,000 - 100,000,000]                      |
| Default Value | 100,000                                      |

## Locale Parameters

### timezone

| Attribute     | Description                                                                                                                                                                         |
| -------- | ------------------------------ |
| Applicable    | Server and Client                                                                                                      |
| Meaning       | TimeZone                        |
| Default Value | TimeZone configured in the host |

:::info
To handle the data insertion and data query from multiple timezones, Unix Timestamp is used and stored in TDengine. The timestamp generated from any timezones at same time is same in Unix timestamp. Note that Unix timestamps are converted and recorded on the client side. To make sure the time on client side can be converted to Unix timestamp correctly, the timezone must be set properly.

On Linux system, TDengine clients automatically obtain timezone from the host. Alternatively, the timezone can be configured explicitly in configuration file `taos.cfg` like below. For example:

```
timezone UTC-8
timezone GMT-8
timezone Asia/Shanghai
```

The above examples are all proper configuration for the timezone of UTC+8. On Windows system, however, `timezone Asia/Shanghai` is not supported, it must be set as `timezone UTC-8`.

The setting for timezone impacts strings that are not in Unix timestamp format and keywords or functions related to date/time. For example:

```sql
SELECT count(*) FROM table_name WHERE TS<'2019-04-11 12:01:08';
```

If the timezone is UTC+8, the above SQL statement is equal to:

```sql
SELECT count(*) FROM table_name WHERE TS<1554955268000;
```

If the timezone is UTC, it's equal to

```sql
SELECT count(*) FROM table_name WHERE TS<1554984068000;
```

To avoid the problems of using time strings, Unix timestamp can be used directly. Furthermore, time strings with timezone can be used in SQL statements. For example "2013-04-12T15:52:01.123+08:00" in RFC3339 format or "2013-04-12T15:52:01.123+0800" in ISO-8601 format are not influenced by timezone setting when converted to Unix timestamp.

:::

### locale

| Attribute     | Description               |
| ------------- | ------------------------- |
| Applicable    | Server and Client         |
| Meaning       | Location code             |
| Default Value | Locale configured in host |

:::info
A specific type "nchar" is provided in TDengine to store non-ASCII characters such as Chinese, Japanese, and Korean. The characters to be stored in nchar type are firstly encoded in UCS4-LE before sending to server side. Note that the correct encoding is determined by the user. To store non-ASCII characters correctly, the encoding format of the client side needs to be set properly.

The characters input on the client side are encoded using the default system encoding, which is UTF-8 on Linux, or GB18030 or GBK on some systems in Chinese, POSIX in docker, CP936 on Windows in Chinese. The encoding of the operating system in use must be set correctly so that the characters in nchar type can be converted to UCS4-LE.

The locale definition standard on Linux is: <Language\>\_<Region\>.<charset\>, for example, in "zh_CN.UTF-8", "zh" means Chinese, "CN" means China mainland, "UTF-8" means charset. The charset indicates how to display the characters. On Linux and Mac OSX, the charset can be set by locale in the system. On Windows system another configuration parameter `charset` must be used to configure charset because the locale used on Windows is not POSIX standard. Of course, `charset` can also be used on Linux to specify the charset.

:::

### charset

| Attribute     | Description               |
| ------------- | ------------------------- |
| Applicable    | Server and Client         |
| Meaning       | Character                 |
| Default Value | charset set in the system |

:::info
On Linux, if `charset` is not set in `taos.cfg`, when `taos` is started, the charset is obtained from system locale. If obtaining charset from system locale fails, `taos` would fail to start.

So on Linux system, if system locale is set properly, it's not necessary to set `charset` in `taos.cfg`. For example:

```
locale zh_CN.UTF-8
```

On Windows system, it's not possible to obtain charset from system locale. If it's not set in configuration file `taos.cfg`, it would be default to CP936, same as set as below in `taos.cfg`. For example

```
charset CP936
```

Refer to the documentation for your operating system before changing the charset.

On a Linux system, if the charset contained in `locale` is not consistent with that set by `charset`, the later setting in the configuration file takes precedence.

```
locale zh_CN.UTF-8
charset GBK
```

The charset that takes effect is GBK.

```
charset GBK
locale zh_CN.UTF-8
```

The charset that takes effect is UTF-8.

:::

## Storage Parameters

### dataDir

| Attribute     | Description               |
| -------- | ------------------------------------------ |
| Applicable    | Server Only                                 |
| Meaning       | All data files are stored in this directory |
| Default Value | /var/lib/taos                               |

### minimalTmpDirGB

| Attribute     | Description                            |
| -------- | ------------------------------------------------ |
| Applicable    | Server and Client         |
| Meaning       | When the available disk space in tmpDir is below this threshold, writing to tmpDir is suspended |
| Unit          | GB                            |
| Default Value | 1.0                                                                   |

### minimalDataDirGB

| Attribute     | Description                            |
| -------- | ------------------------------------------------ |
| Applicable    | Server Only                                                    |
| Meaning       | When the available disk space in dataDir is below this threshold, writing to dataDir is suspended |
| Unit          | GB                            |
| Default Value | 2.0                                                                   |

## Cluster Parameters

### supportVnodes

| Attribute     | Description                            |
| -------- | --------------------------- |
| Applicable    | Server Only                                                    |
| Meaning     | Maximum number of vnodes per dnode |
| Value Range | 0-4096                                     |
| Default Value | 256                                                    |

## Time Parameters

### statusInterval

| Attribute     | Description                            |
| -------- | --------------------------- |
| Applicable    | Server Only                                                    |
| Meaning       | the interval of dnode reporting status to mnode |
| Unit          | second                                          |
| Value Range   | 1-10                                         |
| Default Value | 1                          |

### shellActivityTimer

| Attribute     | Description                            |
| -------- | --------------------------------- |
| Applicable    | Server and Client         |
| Meaning       | The interval for TDengine CLI to send heartbeat to mnode |
| Unit          | second                                          |
| Value Range   | 1-120                                         |
| Default Value | 3                              |

## Performance Optimization Parameters

### numOfCommitThreads

| Attribute     | Description                            |
| -------- | ---------------------- |
| Applicable    | Server Only                                                    |
| Meaning       | Maximum of threads for committing to disk |
| Default Value | |

## Compression Parameters

### compressMsgSize

| Attribute     | Description                                                                                                                                                                         |
| ------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Applicable    | Server Only                                                                                                                                                                         |
| Meaning       | The threshold for message size to compress the message.                         | Set the value to 64330 bytes for good message compression. |
| Unit          | bytes                                                                            |
| Value Range   | 0: already compress; >0: compress when message exceeds it; -1: always uncompress |
| Default Value | -1                                                               |

### compressColData

| Attribute     | Description                            |
| -------- | --------------------------------------------------------------------------------------- |
| Applicable    | Server Only                                                    |
| Meaning       | The threshold for size of column data to trigger compression for the query result              |
| Unit          | bytes                                                                                                               |
| Value Range   | 0: always compress; >0: only compress when the size of any column data exceeds the threshold; -1: always uncompress |
| Default Value | -1                                                               |

## Log Parameters

### logDir

| Attribute     | Description                            |
| -------- | -------------------------------------------------- |
| Applicable    | Server and Client         |
| Meaning       | The directory for writing log files |
| Default Value | /var/log/taos                       |

### minimalLogDirGB

| Attribute     | Description                                                                                                                                                                         |
| -------- | -------------------------------------------- |
| Applicable    | Server and Client         |
| Meaning       | When the available disk space in logDir is below this threshold, writing to log files is suspended |
| Unit          | GB                            |
| Default Value | 1.0                              |

### numOfLogLines

| Attribute     | Description                            |
| -------- | ---------------------------- |
| Applicable    | Server and Client         |
| Meaning       | Maximum number of lines in single log file |
| Default Value | 10000000                            |

### asyncLog

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server and Client         |
| Meaning       | The mode of writing log file |
| Value Range   | 0: sync way; 1: async way    |
| Default Value | 1                                                 |

### logKeepDays

| Attribute     | Description                            |
| -------- | ----------------------------------------------------------------------------------- |
| Applicable    | Server and Client         |
| Meaning       | The number of days for log files to be kept                                                                                                 |
| Unit          | day                                                   |
| Default Value | 0                                                               |
| Note          | When it's bigger than 0, the log file would be renamed to "taosdlog.xxx" in which "xxx" is the timestamp when the file is changed last time |

### debugFlag

| Attribute     | Description                            |
| -------- | ------------------------------------------------------------------------------------------------- |
| Applicable    | Server and Client         |
| Meaning       | Log level                                                 |
| Value Range   | 131: INFO/WARNING/ERROR; 135: plus DEBUG; 143: plus TRACE |
| Default Value | 131 or 135, depending on the module                       |

### tmrDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server and Client         |
| Meaning       | Log level of timer module |
| Value Range   | same as debugFlag  |
| Default Value | |

### uDebugFlag

| Attribute     | Description                            |
| -------- | ---------------------- |
| Applicable    | Server and Client         |
| Meaning       | Log level of common module |
| Value Range   | same as debugFlag  |
| Default Value | |

### rpcDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server and Client         |
| Meaning       | Log level of rpc module |
| Value Range   | same as debugFlag  |
| Default Value | |

### jniDebugFlag

| Attribute     | Description                            |
| -------- | ------------------ |
| Applicable    | Client Only         |
| Meaning       | Log level of jni module |
| Value Range   | same as debugFlag  |
| Default Value | |

### qDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server and Client         |
| Meaning     | Log level of query module |
| Value Range   | same as debugFlag  |
| Default Value | |

### cDebugFlag

| Attribute     | Description                            |
| -------- | --------------------- |
| Applicable    | Client Only         |
| Meaning       | Log level of Client |
| Value Range   | same as debugFlag  |
| Default Value | |

### dDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server Only                                                    |
| Meaning       | Log level of dnode |
| Value Range   | same as debugFlag  |
| Default Value | 135                              |

### vDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server Only                                                    |
| Meaning       | Log level of vnode |
| Value Range   | same as debugFlag  |
| Default Value | |

### mDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server Only                                                    |
| Meaning     | Log level of mnode module |
| Value Range   | same as debugFlag  |
| Default Value | 135                              |

### wDebugFlag

| Attribute     | Description                            |
| -------- | ------------------ |
| Applicable    | Server Only                                                    |
| Meaning     | Log level of WAL module |
| Value Range   | same as debugFlag  |
| Default Value | 135                          |

### sDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server and Client         |
| Meaning       | Log level of sync module |
| Value Range   | same as debugFlag  |
| Default Value | 135                              |

### tsdbDebugFlag

| Attribute     | Description                            |
| -------- | ------------------- |
| Applicable    | Server Only                                                    |
| Meaning     | Log level of TSDB module |
| Value Range   | same as debugFlag  |
| Default Value | |

### tqDebugFlag

| Attribute     | Description                          |
| -------- | ----------------- |
| Applicable | Server only                                           |
| Meaning     | Log level of TQ module |
| Value Range   | same as debugFlag  |
| Default Value | |

### fsDebugFlag

| Attribute     | Description                          |
| -------- | ----------------- |
| Applicable | Server only                                           |
| Meaning     | Log level of FS module |
| Value Range   | same as debugFlag  |
| Default Value | |

### udfDebugFlag

| Attribute     | Description                            |
| -------- | ------------------ |
| Applicable    | Server Only                                                    |
| Meaning       | Log level of UDF module |
| Value Range   | same as debugFlag  |
| Default Value | |

### smaDebugFlag

| Attribute     | Description                            |
| -------- | ------------------ |
| Applicable    | Server Only                                                    |
| Meaning     | Log level of SMA module |
| Value Range   | same as debugFlag  |
| Default Value | |

### idxDebugFlag

| Attribute     | Description                            |
| -------- | -------------------- |
| Applicable    | Server Only                                                    |
| Meaning     | Log level of index module |
| Value Range   | same as debugFlag  |
| Default Value | |

### tdbDebugFlag

| Attribute     | Description                            |
| -------- | ------------------ |
| Applicable    | Server Only                                                    |
| Meaning     | Log level of TDB module |
| Value Range   | same as debugFlag  |
| Default Value | |

## Schemaless Parameters

### smlChildTableName

| Attribute     | Description                      |
| -------- | ------------------------- |
| Applicable | Client only                                           |
| Meaning     | Custom subtable name for schemaless writes |
| Type     | String                    |
| Default Value   | None                        |

### smlTagName

| Attribute     | Description                            |
| -------- | ------------------------------------ |
| Applicable | Client only                                           |
| Meaning     | Default tag for schemaless writes without tag value specified |
| Type     | String                    |
| Default Value   | _tag_null                                 |

### smlDataFormat

| Attribute     | Description                          |
| -------- | ----------------------------- |
| Applicable | Client only                                           |
| Meaning     | Whether schemaless columns are consistently ordered |
| Value Range     | 0: not consistent; 1: consistent.            |
| Default   | 1                             |

## Other Parameters

### enableCoreFile

| Attribute     | Description                                                                                         |
| -------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Applicable    | Server and Client                                                                                                                                                       |
| Meaning       | Whether to generate core file when server crashes                                                                                                                       |
| Value Range   | 0: false, 1: true                                                                                                                                                       |
| Default Value | 1                                                                                                                                                                       |
| Note          | The core file is generated under root directory `systemctl start taosd` is used to start, or under the working directory if `taosd` is started directly on Linux Shell. |

### udf

| Attribute     | Description                            |
| -------- | ------------------ |
| Applicable    | Server Only                                                    |
| Meaning     | Whether the UDF service is enabled  |
| Value Range   | 0: disable UDF; 1: enabled UDF |
| Default Value | 1                              |

## Parameter Comparison of TDengine 2.x and 3.0
| #   | **Parameter**             | **In 2.x** | **In 3.0** |
| --- | :-----------------: | ---------------    | ---------------   |
| 1   | firstEp | Yes | Yes |
| 2   | secondEp | Yes | Yes |
| 3   | fqdn | Yes | Yes |
| 4   | serverPort | Yes | Yes |
| 5   | maxShellConns | Yes | Yes |
| 6   | monitor | Yes | Yes |
| 7   | monitorFqdn | No | Yes |
| 8   | monitorPort | No | Yes |
| 9   | monitorInterval | Yes | Yes |
| 10  | monitorMaxLogs | No | Yes |
| 11  | monitorComp | No | Yes |
| 12  | telemetryReporting | Yes | Yes |
| 13  | telemetryInterval | No | Yes |
| 14  | telemetryServer | No | Yes |
| 15  | telemetryPort | No | Yes |
| 16  | queryPolicy | No | Yes |
| 17  | querySmaOptimize | No | Yes |
| 18  | queryBufferSize | Yes | Yes |
| 19  | maxNumOfDistinctRes | Yes | Yes |
| 20  | minSlidingTime | Yes | Yes |
| 21  | minIntervalTime | Yes | Yes |
| 22  | countAlwaysReturnValue | Yes | Yes |
| 23  | dataDir | Yes | Yes |
| 24  | minimalDataDirGB | Yes | Yes |
| 25  | supportVnodes | No | Yes |
| 26  | tempDir | Yes | Yes |
| 27  | minimalTmpDirGB | Yes | Yes |
| 28  | compressMsgSize | Yes | Yes |
| 29  | compressColData | Yes | Yes |
| 30  | smlChildTableName | Yes | Yes |
| 31  | smlTagName | Yes | Yes |
| 32  | smlDataFormat | No | Yes |
| 33  | statusInterval | Yes | Yes |
| 34  | shellActivityTimer | Yes | Yes |
| 35  | transPullupInterval | No | Yes |
| 36  | mqRebalanceInterval | No | Yes |
| 37  | ttlUnit | No | Yes |
| 38  | ttlPushInterval | No | Yes |
| 39  | numOfTaskQueueThreads | No | Yes |
| 40  | numOfRpcThreads | No | Yes |
| 41  | numOfCommitThreads | Yes | Yes |
| 42  | numOfMnodeReadThreads | No | Yes |
| 43  | numOfVnodeQueryThreads | No | Yes |
| 44  | numOfVnodeStreamThreads | No | Yes |
| 45  | numOfVnodeFetchThreads | No | Yes |
| 46  | numOfVnodeWriteThreads | No | Yes |
| 47  | numOfVnodeSyncThreads | No | Yes |
| 48  | numOfQnodeQueryThreads | No | Yes |
| 49  | numOfQnodeFetchThreads | No | Yes |
| 50  | numOfSnodeSharedThreads | No | Yes |
| 51  | numOfSnodeUniqueThreads | No | Yes |
| 52  | rpcQueueMemoryAllowed | No | Yes |
| 53  | logDir | Yes | Yes |
| 54  | minimalLogDirGB | Yes | Yes |
| 55  | numOfLogLines | Yes | Yes |
| 56  | asyncLog | Yes | Yes |
| 57  | logKeepDays | Yes | Yes |
| 58  | debugFlag | Yes | Yes |
| 59  | tmrDebugFlag | Yes | Yes |
| 60  | uDebugFlag | Yes | Yes |
| 61  | rpcDebugFlag | Yes | Yes |
| 62  | jniDebugFlag | Yes | Yes |
| 63  | qDebugFlag | Yes | Yes |
| 64  | cDebugFlag | Yes | Yes |
| 65  | dDebugFlag | Yes | Yes |
| 66  | vDebugFlag | Yes | Yes |
| 67  | mDebugFlag | Yes | Yes |
| 68  | wDebugFlag | Yes | Yes |
| 69  | sDebugFlag | Yes | Yes |
| 70  | tsdbDebugFlag | Yes | Yes |
| 71  | tqDebugFlag | No | Yes |
| 72  | fsDebugFlag | Yes | Yes |
| 73  | udfDebugFlag | No | Yes |
| 74  | smaDebugFlag | No | Yes |
| 75  | idxDebugFlag | No | Yes |
| 76  | tdbDebugFlag | No | Yes |
| 77  | metaDebugFlag | No | Yes |
| 78  | timezone | Yes | Yes |
| 79  | locale | Yes | Yes |
| 80  | charset | Yes | Yes |
| 81  | udf | Yes | Yes |
| 82  | enableCoreFile | Yes | Yes |
| 83  | arbitrator | Yes | No |
| 84  | numOfThreadsPerCore | Yes | No |
| 85  | numOfMnodes | Yes | No |
| 86  | vnodeBak | Yes | No |
| 87  | balance | Yes | No |
| 88  | balanceInterval | Yes | No |
| 89  | offlineThreshold | Yes | No |
| 90  | role | Yes | No |
| 91  | dnodeNopLoop | Yes | No |
| 92  | keepTimeOffset | Yes | No |
| 93  | rpcTimer | Yes | No |
| 94  | rpcMaxTime | Yes | No |
| 95  | rpcForceTcp | Yes | No |
| 96  | tcpConnTimeout | Yes | No |
| 97  | syncCheckInterval | Yes | No |
| 98  | maxTmrCtrl | Yes | No |
| 99  | monitorReplica | Yes | No |
| 100 | smlTagNullName | Yes | No |
| 101 | keepColumnName | Yes | No |
| 102 | ratioOfQueryCores | Yes | No |
| 103 | maxStreamCompDelay | Yes | No |
| 104 | maxFirstStreamCompDelay | Yes | No |
| 105 | retryStreamCompDelay | Yes | No |
| 106 | streamCompDelayRatio | Yes | No |
| 107 | maxVgroupsPerDb | Yes | No |
| 108 | maxTablesPerVnode | Yes | No |
| 109 | minTablesPerVnode | Yes | No |
| 110 | tableIncStepPerVnode | Yes | No |
| 111 | cache | Yes | No |
| 112 | blocks | Yes | No |
| 113 | days | Yes | No |
| 114 | keep | Yes | No |
| 115 | minRows | Yes | No |
| 116 | maxRows | Yes | No |
| 117 | quorum | Yes | No |
| 118 | comp | Yes | No |
| 119 | walLevel | Yes | No |
| 120 | fsync | Yes | No |
| 121 | replica | Yes | No |
| 122 | partitions | Yes | No |
| 123 | quorum | Yes | No |
| 124 | update | Yes | No |
| 125 | cachelast | Yes | No |
| 126 | maxSQLLength | Yes | No |
| 127 | maxWildCardsLength | Yes | No |
| 128 | maxRegexStringLen | Yes | No |
| 129 | maxNumOfOrderedRes | Yes | No |
| 130 | maxConnections | Yes | No |
| 131 | mnodeEqualVnodeNum | Yes | No |
| 132 | http | Yes | No |
| 133 | httpEnableRecordSql | Yes | No |
| 134 | httpMaxThreads | Yes | No |
| 135 | restfulRowLimit | Yes | No |
| 136 | httpDbNameMandatory | Yes | No |
| 137 | httpKeepAlive | Yes | No |
| 138 | enableRecordSql | Yes | No |
| 139 | maxBinaryDisplayWidth | Yes | No |
| 140 | stream | Yes | No |
| 141 | retrieveBlockingModel | Yes | No |
| 142 | tsdbMetaCompactRatio | Yes | No |
| 143 | defaultJSONStrType | Yes | No |
| 144 | walFlushSize | Yes | No |
| 145 | keepTimeOffset | Yes | No |
| 146 | flowctrl | Yes | No |
| 147 | slaveQuery | Yes | No |
| 148 | adjustMaster | Yes | No |
| 149 | topicBinaryLen | Yes | No |
| 150 | telegrafUseFieldNum | Yes | No |
| 151 | deadLockKillQuery | Yes | No |
| 152 | clientMerge | Yes | No |
| 153 | sdbDebugFlag | Yes | No |
| 154 | odbcDebugFlag | Yes | No |
| 155 | httpDebugFlag | Yes | No |
| 156 | monDebugFlag | Yes | No |
| 157 | cqDebugFlag | Yes | No |
| 158 | shortcutFlag | Yes | No |
| 159 | probeSeconds | Yes | No |
| 160 | probeKillSeconds | Yes | No |
| 161 | probeInterval | Yes | No |
| 162 | lossyColumns | Yes | No |
| 163 | fPrecision | Yes | No |
| 164 | dPrecision | Yes | No |
| 165 | maxRange | Yes | No |
| 166 | range | Yes | No |