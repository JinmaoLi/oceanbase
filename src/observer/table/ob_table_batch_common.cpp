/**
 * Copyright (c) 2024 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#define USING_LOG_PREFIX SERVER
#include "ob_table_batch_common.h"

using namespace oceanbase::observer;
using namespace oceanbase::common;
using namespace oceanbase::table;
using namespace oceanbase::share;

int ObTableBatchCtx::check_legality()
{
  int ret = OB_SUCCESS;

  if (OB_ISNULL(stat_event_type_) || OB_ISNULL(trans_param_) || OB_ISNULL(credential_)) {
    ret = OB_ERR_UNEXPECTED;
    LOG_WARN("unexpected null input", K(ret), KP_(stat_event_type),
      KP_(trans_param), KP_(credential));
  } else if (tablet_ids_.empty()) {
    ret = OB_ERR_UNEXPECTED;
    LOG_WARN("tablet ids is empty", K(ret));
  }

  return ret;
}