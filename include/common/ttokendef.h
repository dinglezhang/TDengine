/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TD_COMMON_TOKEN_H_
#define _TD_COMMON_TOKEN_H_

#define TK_OR                               1
#define TK_AND                              2
#define TK_UNION                            3
#define TK_ALL                              4
#define TK_MINUS                            5
#define TK_EXCEPT                           6
#define TK_INTERSECT                        7
#define TK_NK_BITAND                        8
#define TK_NK_BITOR                         9
#define TK_NK_LSHIFT                       10
#define TK_NK_RSHIFT                       11
#define TK_NK_PLUS                         12
#define TK_NK_MINUS                        13
#define TK_NK_STAR                         14
#define TK_NK_SLASH                        15
#define TK_NK_REM                          16
#define TK_NK_CONCAT                       17
#define TK_CREATE                          18
#define TK_ACCOUNT                         19
#define TK_NK_ID                           20
#define TK_PASS                            21
#define TK_NK_STRING                       22
#define TK_ALTER                           23
#define TK_PPS                             24
#define TK_TSERIES                         25
#define TK_STORAGE                         26
#define TK_STREAMS                         27
#define TK_QTIME                           28
#define TK_DBS                             29
#define TK_USERS                           30
#define TK_CONNS                           31
#define TK_STATE                           32
#define TK_USER                            33
#define TK_ENABLE                          34
#define TK_NK_INTEGER                      35
#define TK_SYSINFO                         36
#define TK_DROP                            37
#define TK_GRANT                           38
#define TK_ON                              39
#define TK_TO                              40
#define TK_REVOKE                          41
#define TK_FROM                            42
#define TK_SUBSCRIBE                       43
#define TK_NK_COMMA                        44
#define TK_READ                            45
#define TK_WRITE                           46
#define TK_NK_DOT                          47
#define TK_WITH                            48
#define TK_DNODE                           49
#define TK_PORT                            50
#define TK_DNODES                          51
#define TK_RESTORE                         52
#define TK_NK_IPTOKEN                      53
#define TK_FORCE                           54
#define TK_LOCAL                           55
#define TK_QNODE                           56
#define TK_BNODE                           57
#define TK_SNODE                           58
#define TK_MNODE                           59
#define TK_VNODE                           60
#define TK_DATABASE                        61
#define TK_USE                             62
#define TK_FLUSH                           63
#define TK_TRIM                            64
#define TK_COMPACT                         65
#define TK_IF                              66
#define TK_NOT                             67
#define TK_EXISTS                          68
#define TK_BUFFER                          69
#define TK_CACHEMODEL                      70
#define TK_CACHESIZE                       71
#define TK_COMP                            72
#define TK_DURATION                        73
#define TK_NK_VARIABLE                     74
#define TK_MAXROWS                         75
#define TK_MINROWS                         76
#define TK_KEEP                            77
#define TK_PAGES                           78
#define TK_PAGESIZE                        79
#define TK_TSDB_PAGESIZE                   80
#define TK_PRECISION                       81
#define TK_REPLICA                         82
#define TK_VGROUPS                         83
#define TK_SINGLE_STABLE                   84
#define TK_RETENTIONS                      85
#define TK_SCHEMALESS                      86
#define TK_WAL_LEVEL                       87
#define TK_WAL_FSYNC_PERIOD                88
#define TK_WAL_RETENTION_PERIOD            89
#define TK_WAL_RETENTION_SIZE              90
#define TK_WAL_ROLL_PERIOD                 91
#define TK_WAL_SEGMENT_SIZE                92
#define TK_STT_TRIGGER                     93
#define TK_TABLE_PREFIX                    94
#define TK_TABLE_SUFFIX                    95
#define TK_NK_COLON                        96
#define TK_MAX_SPEED                       97
#define TK_START                           98
#define TK_TIMESTAMP                       99
#define TK_END                            100
#define TK_TABLE                          101
#define TK_NK_LP                          102
#define TK_NK_RP                          103
#define TK_STABLE                         104
#define TK_ADD                            105
#define TK_COLUMN                         106
#define TK_MODIFY                         107
#define TK_RENAME                         108
#define TK_TAG                            109
#define TK_SET                            110
#define TK_NK_EQ                          111
#define TK_USING                          112
#define TK_TAGS                           113
#define TK_BOOL                           114
#define TK_TINYINT                        115
#define TK_SMALLINT                       116
#define TK_INT                            117
#define TK_INTEGER                        118
#define TK_BIGINT                         119
#define TK_FLOAT                          120
#define TK_DOUBLE                         121
#define TK_BINARY                         122
#define TK_NCHAR                          123
#define TK_UNSIGNED                       124
#define TK_JSON                           125
#define TK_VARCHAR                        126
#define TK_MEDIUMBLOB                     127
#define TK_BLOB                           128
#define TK_VARBINARY                      129
#define TK_GEOMETRY                       130
#define TK_DECIMAL                        131
#define TK_COMMENT                        132
#define TK_MAX_DELAY                      133
#define TK_WATERMARK                      134
#define TK_ROLLUP                         135
#define TK_TTL                            136
#define TK_SMA                            137
#define TK_DELETE_MARK                    138
#define TK_FIRST                          139
#define TK_LAST                           140
#define TK_SHOW                           141
#define TK_PRIVILEGES                     142
#define TK_DATABASES                      143
#define TK_TABLES                         144
#define TK_STABLES                        145
#define TK_MNODES                         146
#define TK_QNODES                         147
#define TK_FUNCTIONS                      148
#define TK_INDEXES                        149
#define TK_ACCOUNTS                       150
#define TK_APPS                           151
#define TK_CONNECTIONS                    152
#define TK_LICENCES                       153
#define TK_GRANTS                         154
#define TK_QUERIES                        155
#define TK_SCORES                         156
#define TK_TOPICS                         157
#define TK_VARIABLES                      158
#define TK_CLUSTER                        159
#define TK_BNODES                         160
#define TK_SNODES                         161
#define TK_TRANSACTIONS                   162
#define TK_DISTRIBUTED                    163
#define TK_CONSUMERS                      164
#define TK_SUBSCRIPTIONS                  165
#define TK_VNODES                         166
#define TK_ALIVE                          167
#define TK_LIKE                           168
#define TK_TBNAME                         169
#define TK_QTAGS                          170
#define TK_AS                             171
#define TK_INDEX                          172
#define TK_FUNCTION                       173
#define TK_INTERVAL                       174
#define TK_COUNT                          175
#define TK_LAST_ROW                       176
#define TK_TOPIC                          177
#define TK_META                           178
#define TK_CONSUMER                       179
#define TK_GROUP                          180
#define TK_DESC                           181
#define TK_DESCRIBE                       182
#define TK_RESET                          183
#define TK_QUERY                          184
#define TK_CACHE                          185
#define TK_EXPLAIN                        186
#define TK_ANALYZE                        187
#define TK_VERBOSE                        188
#define TK_NK_BOOL                        189
#define TK_RATIO                          190
#define TK_NK_FLOAT                       191
#define TK_OUTPUTTYPE                     192
#define TK_AGGREGATE                      193
#define TK_BUFSIZE                        194
#define TK_LANGUAGE                       195
#define TK_REPLACE                        196
#define TK_STREAM                         197
#define TK_INTO                           198
#define TK_TRIGGER                        199
#define TK_AT_ONCE                        200
#define TK_WINDOW_CLOSE                   201
#define TK_IGNORE                         202
#define TK_EXPIRED                        203
#define TK_FILL_HISTORY                   204
#define TK_UPDATE                         205
#define TK_SUBTABLE                       206
#define TK_KILL                           207
#define TK_CONNECTION                     208
#define TK_TRANSACTION                    209
#define TK_BALANCE                        210
#define TK_VGROUP                         211
#define TK_LEADER                         212
#define TK_MERGE                          213
#define TK_REDISTRIBUTE                   214
#define TK_SPLIT                          215
#define TK_DELETE                         216
#define TK_INSERT                         217
#define TK_NULL                           218
#define TK_NK_QUESTION                    219
#define TK_NK_ARROW                       220
#define TK_ROWTS                          221
#define TK_QSTART                         222
#define TK_QEND                           223
#define TK_QDURATION                      224
#define TK_WSTART                         225
#define TK_WEND                           226
#define TK_WDURATION                      227
#define TK_IROWTS                         228
#define TK_ISFILLED                       229
#define TK_CAST                           230
#define TK_NOW                            231
#define TK_TODAY                          232
#define TK_TIMEZONE                       233
#define TK_CLIENT_VERSION                 234
#define TK_SERVER_VERSION                 235
#define TK_SERVER_STATUS                  236
#define TK_CURRENT_USER                   237
#define TK_CASE                           238
#define TK_WHEN                           239
#define TK_THEN                           240
#define TK_ELSE                           241
#define TK_BETWEEN                        242
#define TK_IS                             243
#define TK_NK_LT                          244
#define TK_NK_GT                          245
#define TK_NK_LE                          246
#define TK_NK_GE                          247
#define TK_NK_NE                          248
#define TK_MATCH                          249
#define TK_NMATCH                         250
#define TK_CONTAINS                       251
#define TK_IN                             252
#define TK_JOIN                           253
#define TK_INNER                          254
#define TK_SELECT                         255
#define TK_DISTINCT                       256
#define TK_WHERE                          257
#define TK_PARTITION                      258
#define TK_BY                             259
#define TK_SESSION                        260
#define TK_STATE_WINDOW                   261
#define TK_EVENT_WINDOW                   262
#define TK_SLIDING                        263
#define TK_FILL                           264
#define TK_VALUE                          265
#define TK_VALUE_F                        266
#define TK_NONE                           267
#define TK_PREV                           268
#define TK_NULL_F                         269
#define TK_LINEAR                         270
#define TK_NEXT                           271
#define TK_HAVING                         272
#define TK_RANGE                          273
#define TK_EVERY                          274
#define TK_ORDER                          275
#define TK_SLIMIT                         276
#define TK_SOFFSET                        277
#define TK_LIMIT                          278
#define TK_OFFSET                         279
#define TK_ASC                            280
#define TK_NULLS                          281
#define TK_ABORT                          282
#define TK_AFTER                          283
#define TK_ATTACH                         284
#define TK_BEFORE                         285
#define TK_BEGIN                          286
#define TK_BITAND                         287
#define TK_BITNOT                         288
#define TK_BITOR                          289
#define TK_BLOCKS                         290
#define TK_CHANGE                         291
#define TK_COMMA                          292
#define TK_CONCAT                         293
#define TK_CONFLICT                       294
#define TK_COPY                           295
#define TK_DEFERRED                       296
#define TK_DELIMITERS                     297
#define TK_DETACH                         298
#define TK_DIVIDE                         299
#define TK_DOT                            300
#define TK_EACH                           301
#define TK_FAIL                           302
#define TK_FILE                           303
#define TK_FOR                            304
#define TK_GLOB                           305
#define TK_ID                             306
#define TK_IMMEDIATE                      307
#define TK_IMPORT                         308
#define TK_INITIALLY                      309
#define TK_INSTEAD                        310
#define TK_ISNULL                         311
#define TK_KEY                            312
#define TK_MODULES                        313
#define TK_NK_BITNOT                      314
#define TK_NK_SEMI                        315
#define TK_NOTNULL                        316
#define TK_OF                             317
#define TK_PLUS                           318
#define TK_PRIVILEGE                      319
#define TK_RAISE                          320
#define TK_RESTRICT                       321
#define TK_ROW                            322
#define TK_SEMI                           323
#define TK_STAR                           324
#define TK_STATEMENT                      325
#define TK_STRICT                         326
#define TK_STRING                         327
#define TK_TIMES                          328
#define TK_VALUES                         329
#define TK_VARIABLE                       330
#define TK_VIEW                           331
#define TK_WAL                            332


#define TK_NK_SPACE   600
#define TK_NK_COMMENT 601
#define TK_NK_ILLEGAL 602
#define TK_NK_HEX     603  // hex number  0x123
#define TK_NK_OCT     604  // oct number
#define TK_NK_BIN     605  // bin format data 0b111

#define TK_NK_NIL 65535

#endif /*_TD_COMMON_TOKEN_H_*/
