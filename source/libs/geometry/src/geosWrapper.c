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

#include "geosWrapper.h"
#include "tdef.h"
#include "types.h"

void destroyGeosContext(SGeosContext *context) {
  if (context->WKTReader) {
    GEOSWKTReader_destroy_r(context->handle, context->WKTReader);
    context->WKTReader = NULL;
  }

  if (context->WKTWriter) {
    GEOSWKTWriter_destroy_r(context->handle, context->WKTWriter);
    context->WKTWriter = NULL;
  }

  if (context->WKBReader) {
    GEOSWKBReader_destroy_r(context->handle, context->WKBReader);
    context->WKBReader = NULL;
  }

  if (context->WKBWriter) {
    GEOSWKBWriter_destroy_r(context->handle, context->WKBWriter);
    context->WKBWriter = NULL;
  }

  if(context->handle) {
    GEOS_finish_r(context->handle);
    context->handle = NULL;
  }
}

int32_t prepareGeomFromText(SGeosContext *context) {
  int32_t code = TSDB_CODE_FAILED;

  if (context->handle == NULL) {
    context->handle = GEOS_init_r();
  }
  if (context->handle == NULL) {
    return code;
  }

  if (context->WKTReader == NULL) {
    context->WKTReader = GEOSWKTReader_create_r(context->handle);
  }
  if (context->WKTReader == NULL) {
    return code;
  }

  if (context->WKBWriter == NULL) {
    context->WKBWriter = GEOSWKBWriter_create_r(context->handle);
  }
  if (context->WKBWriter == NULL) {
    return code;
  }

  return TSDB_CODE_SUCCESS;
}

// inputWKT is a zero ending string
// need to call GEOSFree_r(context->handle, *outputGeom) later
int32_t doGeomFromText(SGeosContext *context, const char *inputWKT, unsigned char **outputGeom, size_t *size) {
  int32_t code = TSDB_CODE_FAILED;

  GEOSGeometry *geom = NULL;
  unsigned char *wkb = NULL;

  geom = GEOSWKTReader_read_r(context->handle, context->WKTReader, inputWKT);
  if (geom == NULL) {
    code = TSDB_CODE_FUNC_FUNTION_PARA_VALUE;
    goto _exit;
  }

  wkb = GEOSWKBWriter_write_r(context->handle, context->WKBWriter, geom, size);
  if (wkb == NULL) {
    goto _exit;
  }
  *outputGeom = wkb;

  code = TSDB_CODE_SUCCESS;

_exit:
  if (geom) {
    GEOSGeom_destroy_r(context->handle, geom);
    geom = NULL;
  }

  return code;
}

int32_t prepareAsText(SGeosContext *context) {
  int32_t code = TSDB_CODE_FAILED;

  if (context->handle == NULL) {
    context->handle = GEOS_init_r();
  }
  if (context->handle == NULL) {
    return code;
  }

  if (context->WKBReader == NULL) {
    context->WKBReader = GEOSWKBReader_create_r(context->handle);
  }
  if (context->WKBReader == NULL) {
    return code;
  }

  if (context->WKTWriter == NULL) {
    context->WKTWriter = GEOSWKTWriter_create_r(context->handle);
  }
  if (context->WKTWriter == NULL) {
    return code;
  }

  return TSDB_CODE_SUCCESS;
}

// outputWKT is a zero ending string
// need to call GEOSFree_r(context->handle, *outputWKT); later
int32_t doAsText(SGeosContext *context, const unsigned char *inputGeom, size_t size, char **outputWKT) {
  int32_t code = TSDB_CODE_FAILED;

  GEOSGeometry *geom = NULL;
  unsigned char *wkt = NULL;

  geom = GEOSWKBReader_read_r(context->handle, context->WKBReader, inputGeom, size);
  if (geom == NULL) {
    code = TSDB_CODE_FUNC_FUNTION_PARA_VALUE;
    goto _exit;
  }

  wkt = GEOSWKTWriter_write_r(context->handle, context->WKTWriter, geom);
  if (wkt == NULL) {
    goto _exit;
  }
  *outputWKT = wkt;

  code = TSDB_CODE_SUCCESS;

_exit:
  if (geom) {
    GEOSGeom_destroy_r(context->handle, geom);
    geom = NULL;
  }

  return code;
}

int32_t prepareMakePoint(SGeosContext *context) {
  int32_t code = TSDB_CODE_FAILED;

  if (context->handle == NULL) {
    context->handle = GEOS_init_r();
  }
  if (context->handle == NULL) {
    return code;
  }

  if (context->WKBWriter == NULL) {
    context->WKBWriter = GEOSWKBWriter_create_r(context->handle);
  }
  if (context->WKBWriter == NULL) {
    return code;
  }

  return TSDB_CODE_SUCCESS;
}

// outputWKT is a zero ending string
// need to call GEOSFree_r(context->handle, *outputGeom); later
int32_t doMakePoint(SGeosContext *context, double x, double y, unsigned char **outputGeom, size_t *size) {
  int32_t code = TSDB_CODE_FAILED;

  GEOSGeometry *geom = NULL;
  unsigned char *wkb = NULL;

  geom = GEOSGeom_createPointFromXY_r(context->handle, x, y);
  if (geom == NULL) {
    code = TSDB_CODE_FUNC_FUNTION_PARA_VALUE;
    goto _exit;
  }

  wkb = GEOSWKBWriter_write_r(context->handle, context->WKBWriter, geom, size);
  if (wkb == NULL) {
    goto _exit;
  }
  *outputGeom = wkb;

  code = TSDB_CODE_SUCCESS;

_exit:
  if (geom) {
    GEOSGeom_destroy_r(context->handle, geom);
    geom = NULL;
  }

  return code;
}
