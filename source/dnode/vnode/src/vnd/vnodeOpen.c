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

#include "vnodeInt.h"

static int vnodeOpenMeta(SVnode *pVnode);
static int vnodeOpenTsdb(SVnode *pVnode);
static int vnodeOpenWal(SVnode *pVnode);
static int vnodeOpenTq(SVnode *pVnode);
static int vnodeOpenQuery(SVnode *pVnode);
static int vnodeCloseMeta(SVnode *pVnode);
static int vnodeCloseTsdb(SVnode *pVnode);
static int vnodeCloseWal(SVnode *pVnode);
static int vnodeCloseTq(SVnode *pVnode);
static int vnodeCloseQuery(SVnode *pVnode);

int vnodeCreate(const char *path, SVnodeCfg *pCfg) {
  // TODO
  return 0;
}

void vnodeDestroy(const char *path) {
  // TODO
  taosRemoveDir(path);
}

int vnodeOpen(const char *path, const SVnodeCfg *pVnodeCfg, SVnode **ppVnode) {
  SVnode *pVnode;
  int     ret;

  *ppVnode = NULL;

  if (1) {
    // create a new vnode
    // 1. validate the config parameter
    // 2. create the vnode on disk (create directory and files)
  } else {
    // open an existing vnode
    // 1. load the config
    // 2. check the config
  }

  // open the vnode from the environment
  pVnode = taosMemoryCalloc(1, sizeof(*pVnode));
  if (pVnode == NULL) {
    terrno = TSDB_CODE_OUT_OF_MEMORY;
    return -1;
  }

// open buffer pool sub-system
  uint8_t heap = 0;
  ret = vnodeOpenBufPool(pVnode, heap ? 0 : pVnode->config.wsize / 3);
  if (ret < 0) {
    return -1;
  }

  // open meta sub-system
  ret = vnodeOpenMeta(pVnode);
  if (ret < 0) {
    return -1;
  }

  // open meta tsdb-system
  ret = vnodeOpenTsdb(pVnode);
  if (ret < 0) {
    return -1;
  }

  // open meta wal-system
  ret = vnodeOpenWal(pVnode);
  if (ret < 0) {
    return -1;
  }

  // open meta tq-system
  ret = vnodeOpenTq(pVnode);
  if (ret < 0) {
    return -1;
  }

  // open meta query-system
  ret = vnodeOpenQuery(pVnode);
  if (ret < 0) {
    return -1;
  }

  // make vnode start to work
  ret = vnodeBegin(pVnode);
  if (ret < 0) {
    return -1;
  }

  *ppVnode = pVnode;
  return 0;
}

void vnodeClose(SVnode *pVnode) {
  if (pVnode) {
    vnodeSyncCommit(pVnode);
    vnodeCloseQuery(pVnode);
    vnodeCloseTq(pVnode);
    vnodeCloseWal(pVnode);
    vnodeCloseTsdb(pVnode);
    vnodeCloseMeta(pVnode);
    taosMemoryFree(pVnode);
  }
}

// static methods ----------
static int vnodeOpenMeta(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeOpenTsdb(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeOpenWal(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeOpenTq(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeOpenQuery(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeCloseMeta(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeCloseTsdb(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeCloseWal(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeCloseTq(SVnode *pVnode) {
  // TODO
  return 0;
}

static int vnodeCloseQuery(SVnode *pVnode) {
  // TODO
  return 0;
}
