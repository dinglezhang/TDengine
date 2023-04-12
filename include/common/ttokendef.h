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

#define TK_OR                   1
#define TK_AND                  2
#define TK_UNION                3
#define TK_ALL                  4
#define TK_MINUS                5
#define TK_EXCEPT               6
#define TK_INTERSECT            7
#define TK_NK_BITAND            8
#define TK_NK_BITOR             9
#define TK_NK_LSHIFT            10
#define TK_NK_RSHIFT            11
#define TK_NK_PLUS              12
#define TK_NK_MINUS             13
#define TK_NK_STAR              14
#define TK_NK_SLASH             15
#define TK_NK_REM               16
#define TK_NK_CONCAT            17
#define TK_CREATE               18
#define TK_ACCOUNT              19
#define TK_NK_ID                20
#define TK_PASS                 21
#define TK_NK_STRING            22
#define TK_ALTER                23
#define TK_PPS                  24
#define TK_TSERIES              25
#define TK_STORAGE              26
#define TK_STREAMS              27
#define TK_QTIME                28
#define TK_DBS                  29
#define TK_USERS                30
#define TK_CONNS                31
#define TK_STATE                32
#define TK_USER                 33
#define TK_ENABLE               34
#define TK_NK_INTEGER           35
#define TK_SYSINFO              36
#define TK_DROP                 37
#define TK_GRANT                38
#define TK_ON                   39
#define TK_TO                   40
#define TK_REVOKE               41
#define TK_FROM                 42
#define TK_SUBSCRIBE            43
#define TK_NK_COMMA             44
#define TK_READ                 45
#define TK_WRITE                46
#define TK_NK_DOT               47
#define TK_DNODE                48
#define TK_PORT                 49
#define TK_DNODES               50
#define TK_NK_IPTOKEN           51
#define TK_FORCE                52
#define TK_LOCAL                53
#define TK_QNODE                54
#define TK_BNODE                55
#define TK_SNODE                56
#define TK_MNODE                57
#define TK_DATABASE             58
#define TK_USE                  59
#define TK_FLUSH                60
#define TK_TRIM                 61
#define TK_COMPACT              62
#define TK_IF                   63
#define TK_NOT                  64
#define TK_EXISTS               65
#define TK_BUFFER               66
#define TK_CACHEMODEL           67
#define TK_CACHESIZE            68
#define TK_COMP                 69
#define TK_DURATION             70
#define TK_NK_VARIABLE          71
#define TK_MAXROWS              72
#define TK_MINROWS              73
#define TK_KEEP                 74
#define TK_PAGES                75
#define TK_PAGESIZE             76
#define TK_TSDB_PAGESIZE        77
#define TK_PRECISION            78
#define TK_REPLICA              79
#define TK_VGROUPS              80
#define TK_SINGLE_STABLE        81
#define TK_RETENTIONS           82
#define TK_SCHEMALESS           83
#define TK_WAL_LEVEL            84
#define TK_WAL_FSYNC_PERIOD     85
#define TK_WAL_RETENTION_PERIOD 86
#define TK_WAL_RETENTION_SIZE   87
#define TK_WAL_ROLL_PERIOD      88
#define TK_WAL_SEGMENT_SIZE     89
#define TK_STT_TRIGGER          90
#define TK_TABLE_PREFIX         91
#define TK_TABLE_SUFFIX         92
#define TK_NK_COLON             93
#define TK_MAX_SPEED            94
#define TK_START                95
#define TK_WITH                 96
#define TK_TIMESTAMP            97
#define TK_END                  98
#define TK_TABLE                99
#define TK_NK_LP                100
#define TK_NK_RP                101
#define TK_STABLE               102
#define TK_ADD                  103
#define TK_COLUMN               104
#define TK_MODIFY               105
#define TK_RENAME               106
#define TK_TAG                  107
#define TK_SET                  108
#define TK_NK_EQ                109
#define TK_USING                110
#define TK_TAGS                 111
#define TK_COMMENT              112
#define TK_BOOL                 113
#define TK_TINYINT              114
#define TK_SMALLINT             115
#define TK_INT                  116
#define TK_INTEGER              117
#define TK_BIGINT               118
#define TK_FLOAT                119
#define TK_DOUBLE               120
#define TK_BINARY               121
#define TK_NCHAR                122
#define TK_UNSIGNED             123
#define TK_JSON                 124
#define TK_VARCHAR              125
#define TK_MEDIUMBLOB           126
#define TK_BLOB                 127
#define TK_VARBINARY            128
#define TK_GEOMETRY             129
#define TK_DECIMAL              130
#define TK_MAX_DELAY            131
#define TK_WATERMARK            132
#define TK_ROLLUP               133
#define TK_TTL                  134
#define TK_SMA                  135
#define TK_DELETE_MARK          136
#define TK_FIRST                137
#define TK_LAST                 138
#define TK_SHOW                 139
#define TK_PRIVILEGES           140
#define TK_DATABASES            141
#define TK_TABLES               142
#define TK_STABLES              143
#define TK_MNODES               144
#define TK_QNODES               145
#define TK_FUNCTIONS            146
#define TK_INDEXES              147
#define TK_ACCOUNTS             148
#define TK_APPS                 149
#define TK_CONNECTIONS          150
#define TK_LICENCES             151
#define TK_GRANTS               152
#define TK_QUERIES              153
#define TK_SCORES               154
#define TK_TOPICS               155
#define TK_VARIABLES            156
#define TK_CLUSTER              157
#define TK_BNODES               158
#define TK_SNODES               159
#define TK_TRANSACTIONS         160
#define TK_DISTRIBUTED          161
#define TK_CONSUMERS            162
#define TK_SUBSCRIPTIONS        163
#define TK_VNODES               164
#define TK_ALIVE                165
#define TK_LIKE                 166
#define TK_TBNAME               167
#define TK_QTAGS                168
#define TK_AS                   169
#define TK_INDEX                170
#define TK_FUNCTION             171
#define TK_INTERVAL             172
#define TK_COUNT                173
#define TK_LAST_ROW             174
#define TK_TOPIC                175
#define TK_META                 176
#define TK_CONSUMER             177
#define TK_GROUP                178
#define TK_DESC                 179
#define TK_DESCRIBE             180
#define TK_RESET                181
#define TK_QUERY                182
#define TK_CACHE                183
#define TK_EXPLAIN              184
#define TK_ANALYZE              185
#define TK_VERBOSE              186
#define TK_NK_BOOL              187
#define TK_RATIO                188
#define TK_NK_FLOAT             189
#define TK_OUTPUTTYPE           190
#define TK_AGGREGATE            191
#define TK_BUFSIZE              192
#define TK_LANGUAGE             193
#define TK_STREAM               194
#define TK_INTO                 195
#define TK_TRIGGER              196
#define TK_AT_ONCE              197
#define TK_WINDOW_CLOSE         198
#define TK_IGNORE               199
#define TK_EXPIRED              200
#define TK_FILL_HISTORY         201
#define TK_UPDATE               202
#define TK_SUBTABLE             203
#define TK_KILL                 204
#define TK_CONNECTION           205
#define TK_TRANSACTION          206
#define TK_BALANCE              207
#define TK_VGROUP               208
#define TK_LEADER               209
#define TK_MERGE                210
#define TK_REDISTRIBUTE         211
#define TK_SPLIT                212
#define TK_DELETE               213
#define TK_INSERT               214
#define TK_NULL                 215
#define TK_NK_QUESTION          216
#define TK_NK_ARROW             217
#define TK_ROWTS                218
#define TK_QSTART               219
#define TK_QEND                 220
#define TK_QDURATION            221
#define TK_WSTART               222
#define TK_WEND                 223
#define TK_WDURATION            224
#define TK_IROWTS               225
#define TK_ISFILLED             226
#define TK_CAST                 227
#define TK_NOW                  228
#define TK_TODAY                229
#define TK_TIMEZONE             230
#define TK_CLIENT_VERSION       231
#define TK_SERVER_VERSION       232
#define TK_SERVER_STATUS        233
#define TK_CURRENT_USER         234
#define TK_CASE                 235
#define TK_WHEN                 236
#define TK_THEN                 237
#define TK_ELSE                 238
#define TK_BETWEEN              239
#define TK_IS                   240
#define TK_NK_LT                241
#define TK_NK_GT                242
#define TK_NK_LE                243
#define TK_NK_GE                244
#define TK_NK_NE                245
#define TK_MATCH                246
#define TK_NMATCH               247
#define TK_CONTAINS             248
#define TK_IN                   249
#define TK_JOIN                 250
#define TK_INNER                251
#define TK_SELECT               252
#define TK_DISTINCT             253
#define TK_WHERE                254
#define TK_PARTITION            255
#define TK_BY                   256
#define TK_SESSION              257
#define TK_STATE_WINDOW         258
#define TK_EVENT_WINDOW         259
#define TK_SLIDING              260
#define TK_FILL                 261
#define TK_VALUE                262
#define TK_VALUE_F              263
#define TK_NONE                 264
#define TK_PREV                 265
#define TK_NULL_F               266
#define TK_LINEAR               267
#define TK_NEXT                 268
#define TK_HAVING               269
#define TK_RANGE                270
#define TK_EVERY                271
#define TK_ORDER                272
#define TK_SLIMIT               273
#define TK_SOFFSET              274
#define TK_LIMIT                275
#define TK_OFFSET               276
#define TK_ASC                  277
#define TK_NULLS                278
#define TK_ABORT                279
#define TK_AFTER                280
#define TK_ATTACH               281
#define TK_BEFORE               282
#define TK_BEGIN                283
#define TK_BITAND               284
#define TK_BITNOT               285
#define TK_BITOR                286
#define TK_BLOCKS               287
#define TK_CHANGE               288
#define TK_COMMA                289
#define TK_CONCAT               290
#define TK_CONFLICT             291
#define TK_COPY                 292
#define TK_DEFERRED             293
#define TK_DELIMITERS           294
#define TK_DETACH               295
#define TK_DIVIDE               296
#define TK_DOT                  297
#define TK_EACH                 298
#define TK_FAIL                 299
#define TK_FILE                 300
#define TK_FOR                  301
#define TK_GLOB                 302
#define TK_ID                   303
#define TK_IMMEDIATE            304
#define TK_IMPORT               305
#define TK_INITIALLY            306
#define TK_INSTEAD              307
#define TK_ISNULL               308
#define TK_KEY                  309
#define TK_MODULES              310
#define TK_NK_BITNOT            311
#define TK_NK_SEMI              312
#define TK_NOTNULL              313
#define TK_OF                   314
#define TK_PLUS                 315
#define TK_PRIVILEGE            316
#define TK_RAISE                317
#define TK_REPLACE              318
#define TK_RESTRICT             319
#define TK_ROW                  320
#define TK_SEMI                 321
#define TK_STAR                 322
#define TK_STATEMENT            323
#define TK_STRICT               324
#define TK_STRING               325
#define TK_TIMES                326
#define TK_VALUES               327
#define TK_VARIABLE             328
#define TK_VIEW                 329
#define TK_WAL                  330

#define TK_NK_SPACE   600
#define TK_NK_COMMENT 601
#define TK_NK_ILLEGAL 602
#define TK_NK_HEX     603  // hex number  0x123
#define TK_NK_OCT     604  // oct number
#define TK_NK_BIN     605  // bin format data 0b111

#define TK_NK_NIL 65535

#endif /*_TD_COMMON_TOKEN_H_*/
