/*
    This file is part of TON Blockchain Library.

    TON Blockchain Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    TON Blockchain Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with TON Blockchain Library.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2017-2019 Telegram Systems LLP
*/
#include "validator-options.hpp"

#include "ton/ton-shard.h"

namespace ton {

namespace validator {

td::Ref<ValidatorManagerOptions> ValidatorManagerOptions::create(
    BlockIdExt zero_block_id, BlockIdExt init_block_id, std::function<bool(ShardIdFull)> check_shard,
    bool allow_blockchain_init, td::ClocksBase::Duration sync_blocks_before, td::ClocksBase::Duration block_ttl,
    td::ClocksBase::Duration state_ttl, bool initial_sync_disabled) {
  return td::make_ref<ValidatorManagerOptionsImpl>(zero_block_id, init_block_id, std::move(check_shard),
                                                   allow_blockchain_init, sync_blocks_before, block_ttl, state_ttl,
                                                   initial_sync_disabled);
}

}  // namespace validator

}  // namespace ton